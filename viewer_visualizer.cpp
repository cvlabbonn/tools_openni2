#include "viewer.h"

int Viewer::loop(){
    char key;
    // loop until esc is pressed
    //device.setImageRegistrationMode(openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR );
    while(!exitFlag)
        if(device.getSensorInfo(openni::SENSOR_DEPTH) != NULL){
            // read the next frame
            depth.readFrame(&depthFrame);
            color.readFrame(&colorFrame);
            // make sure the data is valid
            if(depthFrame.isValid() && colorFrame.isValid()){
                pcl::PointCloud<typePoint> cloud;
                cv::Mat normDepth, rgbd;
                //process both images

                // depth image
                const openni::DepthPixel* depthBuffer = (const openni::DepthPixel*)depthFrame.getData();;
                frameDepth.create(depthFrame.getHeight(), depthFrame.getWidth(), CV_16UC1);
                memcpy( frameDepth.data, depthBuffer, depthFrame.getHeight()*depthFrame.getWidth()*sizeof(uint16_t) );
                cv::normalize(frameDepth, normDepth, 0, 255, CV_MINMAX, CV_8UC1);
                cv::imshow("Depth", normDepth);

                // color image
                const openni::RGB888Pixel* imageBuffer = (const openni::RGB888Pixel*)colorFrame.getData();
                frame.create(colorFrame.getHeight(), colorFrame.getWidth(), CV_8UC3);
                memcpy( frame.data, imageBuffer, 3*colorFrame.getHeight()*colorFrame.getWidth()*sizeof(uint8_t) );
                cv::cvtColor(frame,bgrMat,CV_BGR2RGB);
                cv::imshow("Color", bgrMat);

                // create the rgbd image
                createRGBD(frameDepth, bgrMat, rgbd);
                cv::imshow("RGBD", rgbd);

                if (saveMemory){
                    // create point cloud
                    get_pcl(bgrMat, frameDepth, cloud);
                    cloud.width = frameDepth.cols;
                    cloud.height   = frameDepth.rows;

                    //store all data
                    point_clouds.push_back(cloud);
                    rgb_images.push_back( bgrMat.clone() );
                    rgbd_images.push_back( rgbd.clone());
                    depth_viz.push_back( frameDepth.clone() );
                    depth_show.push_back( normDepth.clone() );
                    FRAME_COUNTER += 1;

                }

                // get key interaction
                key = cv::waitKey(1);
                key_parse(key);

           }
        }
    return 0;
}

void Viewer::createRGBD(cv::Mat& depth_mat, cv::Mat& color_mat, cv::Mat& dst){
    dst = cv::Mat::zeros(depth_mat.rows, depth_mat.cols, CV_8UC3);
    for (int j = 0; j< depth_mat.rows; j ++){
        for(int i = 0; i < depth_mat.cols; i++){
            int depth_value = (int) depth_mat.at<unsigned short>(j,i);
            if (depth_value != 0 && depth_value <= limitz_max && depth_value >= limitz_min)
                if ( limitx_min <= i && limitx_max >=i && limity_min <= j && limity_max >= j )
                    dst.at<cv::Vec3b>(j,i)  = color_mat.at<cv::Vec3b>(j,i);
        }
    }
}
