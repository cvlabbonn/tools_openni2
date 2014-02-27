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
