#include <viewer.h>

void Viewer::key_parse(char key){
    if (key == 27){
        exitFlag = true;
    }
    // save the pcl in to memory
    else if (key==' ')    {
        saveMemory = !saveMemory;
        if (saveMemory){
            std::cout <<   "START saving in MEMORY"     << std::endl;
            rgb_images.clear();
            rgbd_images.clear();
            point_clouds.clear();
            raw_depth.clear();
            depth_show.clear();
        }
        else {
            std::cout << "STOPP saving in MEMORY - " << FRAME_COUNTER << " frames" << std::endl;
        }
        FRAME_COUNTER = 0;
    }
    // save the pcl into the disk
    else if (key=='s'||key=='S')    {
            create_dir();
            saveMemory = false;
            std::cout << "START saving in DISK" << std::endl;
            saveToDisk();
            std::cout << "STOPP saving in DISK" << std::endl;
            rgb_images.clear();
            rgbd_images.clear();
            point_clouds.clear();
            raw_depth.clear();
            depth_show.clear();
    }
}
