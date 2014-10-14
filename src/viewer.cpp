#include "viewer.h"

Viewer::Viewer(int argc, char *argv[])
{
    std::cout << "Initializing device and sensors" << std::endl;
    // initialize global variables
    exitFlag = false;
    saveMemory = false;
    saveDisk = false;
    save_depth = true;
    save_rgb = true;
    save_pcd = false;
    save_rgbd = false;
    save_yml = false;
    img_type = ".png";
    limitx_min = 0;
    limitx_max = 0;
    limity_min = 0;
    limity_max = 0;
    limitz_min = 0;
    limitz_max = 0;
    frame_width = 640;
    frame_height = 480;

    // initialize device and sensors
    rc = openni::OpenNI::initialize();
    if (rc != openni::STATUS_OK)
        error_manager(1);


    rc = device.open(openni::ANY_DEVICE);
    if (rc != openni::STATUS_OK)
        error_manager(2);


    rc = depth.create(device, openni::SENSOR_DEPTH);
    if (rc != openni::STATUS_OK)
        error_manager(3);

    // set the new resolution and fps
    openni::VideoMode depth_videoMode  = depth.getVideoMode();
    depth_videoMode.setResolution(frame_width,frame_height);
    depth_videoMode.setFps(30);
    depth.setVideoMode(depth_videoMode);

    rc = depth.start();

    only_depth = false;

    if (rc != openni::STATUS_OK)
        error_manager(4, true);
        // try to read the color stream
        const openni::SensorInfo* tmp= device.getSensorInfo(openni::SENSOR_COLOR);
        if (tmp != NULL){
            rc = color.create(device, openni::SENSOR_COLOR);
            if (rc != openni::STATUS_OK){
                error_manager(5, true);
            }
            // set the new resolution and fps
            openni::VideoMode color_videoMode  = color.getVideoMode();
            color_videoMode.setResolution(frame_width,frame_height);
            color_videoMode.setFps(30);
            color.setVideoMode(color_videoMode);

            rc = color.start();
            if (rc != openni::STATUS_OK)
                error_manager(6, true);

            // align the depth and color image
            device.setImageRegistrationMode(openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR );
        } else {
            only_depth = true;
        }

    std::cout << "Sensors initialized" << std::endl;
}

void Viewer::close_all(){
    std::cout << "Stopping sensors" << std::endl;
    depth.stop();
    depth.destroy();
    if (!only_depth){
        color.stop();
        color.destroy();
    }
    device.close();
    recorder.stop();
    recorder.destroy();
    //QFile::remove("recording.oni");
    openni::OpenNI::shutdown();
    std::cout << "Sensors stopped" << std::endl;
}

Viewer::~Viewer(){
    close_all();
}
