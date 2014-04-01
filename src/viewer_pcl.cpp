#include <viewer.h>

void Viewer::get_pcl(cv::Mat& color_mat, cv::Mat& depth_mat, pcl::PointCloud<typePoint>& cloud ){
    float x,y,z;

    for (int j = 0; j< depth_mat.rows; j ++){
        for(int i = 0; i < depth_mat.cols; i++){
            // the RGB data is created
            PCD_RGB   pcd_RGB;
            pcd_RGB.R  = color_mat.at<cv::Vec3b>(j,i)[0];
            pcd_RGB.G  = color_mat.at<cv::Vec3b>(j,i)[1];
            pcd_RGB.B  = color_mat.at<cv::Vec3b>(j,i)[2];

            typePoint vertex;
            int depth_value = (int) depth_mat.at<unsigned short>(j,i);
            // find the world coordinates
            openni::CoordinateConverter::convertDepthToWorld(depth, i, j, (openni::DepthPixel) depth_mat.at<unsigned short>(j,i), &x, &y,&z );

            // the point is created with depth and color data
            if ( limitx_min <= i && limitx_max >=i && limity_min <= j && limity_max >= j && depth_value != 0 && depth_value <= limitz_max && depth_value >= limitz_min){
                vertex.x   = (float) x;
                vertex.y   = (float) y;
                vertex.z   = (float) depth_value;
            } else {
                // if the data is outside the boundaries
                vertex.x   = bad_point;
                vertex.y   = bad_point;
                vertex.z   = bad_point;
            }
            vertex.rgb = pcd_RGB.RGB_float;

            // the point is pushed back in the cloud
            cloud.points.push_back( vertex );

        }
    }
}


void Viewer::get_images(cv::Mat& img_rgb, cv::Mat& img_depth, pcl::PointCloud<typePoint>& cloud ) {

        img_rgb = cv::Mat( cloud.height, cloud.width, CV_8UC3, 0.f );
        img_depth = cv::Mat( cloud.height, cloud.width, CV_32FC1, 0.f );

        int idx = 0;
        for( unsigned int y = 0; y < cloud.height; y++ ) {
                for( unsigned int x = 0; x < cloud.width; x++ ) {

                        const pcl::PointXYZRGB& p = cloud.points[idx];

                        cv::Vec3b px;
                        px[0] = p.b;
                        px[1] = p.g;
                        px[2] = p.r;

                        img_rgb.at< cv::Vec3b >( y, x ) = px;
                        img_depth.at< float >( y, x ) = p.z;

                        idx++;

                }
        }

}
