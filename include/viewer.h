#ifndef VIEWER_H
#define VIEWER_H

#include <iostream>
#include <OpenNI.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/file_io.h>
#include <time.h>
#include <limits>
#include <QFile>


typedef pcl::PointXYZRGBA typePoint;
typedef pcl::PointXYZ colorlessPoint;
const float bad_point = std::numeric_limits<float>::quiet_NaN();

/**
  * Define the union structure for the RGB information in the PCD file
 */
union PCD_BGRA
{
    struct
    {
        uchar B; // LSB
        uchar G; // ---
        uchar R; // MSB
        uchar A; //
    };
    float RGB_float;
    uint  RGB_uint;
};


class Viewer
{
public:

    openni::Status rc;
    openni::Device device;
    cv::Mat frame, frameDepth, bgrMat;
    openni::VideoStream depth, color;
    openni::VideoFrameRef depthFrame, colorFrame;
    openni::Recorder recorder;

    std::vector<cv::Mat> rgb_images;
    std::vector<cv::Mat> raw_depth;
    std::vector<cv::Mat> depth_show;
    std::vector<cv::Mat> rgbd_images;
    std::vector< pcl::PointCloud<typePoint> > point_clouds;

    std::string folder_name;
    std::string img_type;
    int FRAME_COUNTER;
    int limitx_min;
    int limitx_max;
    int limity_min;
    int limity_max;
    int limitz_min;
    int limitz_max;
    int frame_width;
    int frame_height;
    int initial_frame;
    int padding;

    bool exitFlag;
    bool saveMemory;
    bool saveDisk;
    bool binary_mode;
    bool no_oni;
    bool only_depth;
    bool save_depth;
    bool save_rgb;
    bool save_pcd;
    bool save_rgbd;
    bool save_yml;
    bool save_both_depth;


    Viewer(int argc, char *argv[]);
    ~Viewer();
    void close_all();
    void error_manager(int error, bool critical = true);
    int loop();
    void createRGBD(cv::Mat& depth_mat, cv::Mat& color_mat, cv::Mat& dst_rgbd, cv::Mat& dst_depth);
    void key_parse(char key);
    void get_pcl(cv::Mat& color, cv::Mat& depth, pcl::PointCloud<typePoint>& cloud );
    void get_colorless_pcl(cv::Mat& depth_mat, pcl::PointCloud<colorlessPoint>& colorless_cloud );
    void get_images(cv::Mat& color_mat, cv::Mat& depth_mat, pcl::PointCloud<typePoint>& cloud );
    void create_dir();
    void saveToDisk();
};

#endif // VIEWER_H
