#include "viewer.h"
#include <openni/XnPropNames.h>

Viewer::Viewer()
{
    std::cout << "Initializing device and sensors" << std::endl;
    // initialize global variables
    exitFlag = false;
    saveMemory = false;
    saveDisk = false;
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
    if (rc != openni::STATUS_OK)
        error_manager(4);
    rc = color.create(device, openni::SENSOR_COLOR);
    if (rc != openni::STATUS_OK)
        error_manager(5);

    // set the new resolution and fps
    openni::VideoMode color_videoMode  = color.getVideoMode();
    color_videoMode.setResolution(frame_width,frame_height);
    color_videoMode.setFps(30);
    color.setVideoMode(color_videoMode);

    rc = color.start();
    if (rc != openni::STATUS_OK)
        error_manager(6);
    std::cout << "Sensors initialized" << std::endl;

    // align the depth and color image
    device.setImageRegistrationMode(openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR );

}

void Viewer::close_all(){
    std::cout << "Stopping sensors" << std::endl;
    depth.stop();
    depth.destroy();
    color.stop();
    color.destroy();
    device.close();
    openni::OpenNI::shutdown();
    std::cout << "Sensors stopped" << std::endl;
}

Viewer::~Viewer(){
    close_all();
}
