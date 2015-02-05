#include <viewer.h>

/**
  * Creates the timestamped directory structure to save the data.
  */
void Viewer::create_dir(){
    // get timestamp
    std::string folder;
    std::stringstream strstream;
    int ret = -1;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [20];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,20,"%Y.%m.%d_%H.%M.%S",timeinfo);
    strstream << buffer;
    strstream >> folder;
    // create the directory
    ret = mkdir(folder.c_str(), 0775);


    // if successfull write the name in the variable
    if (ret == 0){
        std::cout << "The folder " << folder << " was created." << std::endl;
        folder_name = folder;

        // create subfolders
        if (save_rgb && !only_depth){
            ret = mkdir((folder + "//rgb").c_str(), 0775);
            if (ret == 0){
                std::cout << "The folder " << (folder + "/rgb") << " was created." << std::endl;
            } else {
                std::cout << "The folder " << (folder + "/rgb") << " could not be created and the program will exit." << std::endl;
                exit(0);
            }
        }
        if (save_depth){
            ret = mkdir((folder + "//depth").c_str(), 0775);
            if (ret == 0){
                std::cout << "The folder " << (folder + "/depth") << " was created." << std::endl;
            } else {
                std::cout << "The folder " << (folder + "/depth") << " could not be created and the program will exit." << std::endl;
                exit(0);
            }
            if (!save_yml || save_both_depth){
                ret = mkdir((folder + "//depth" + "//png").c_str(), 0775);
                if (ret == 0){
                    std::cout << "The folder " << (folder + "/depth/png") << " was created." << std::endl;
                } else {
                    std::cout << "The folder " << (folder + "/depth/png") << " could not be created and the program will exit." << std::endl;
                    exit(0);
                }
            }
            if (save_yml || save_both_depth){
                ret = mkdir((folder + "//depth" + "//yml").c_str(), 0775);
                if (ret == 0){
                    std::cout << "The folder " << (folder + "/depth/yml") << " was created." << std::endl;
                } else {
                    std::cout << "The folder " << (folder + "/depth/yml") << " could not be created and the program will exit." << std::endl;
                    exit(0);
                }
            }
        }
        if (save_pcd){
            ret = mkdir((folder + "//pcl").c_str(), 0775);
            if (ret == 0){
                std::cout << "The folder " << (folder + "/pcl") << " was created." << std::endl;
            } else {
                std::cout << "The folder " << (folder + "/pcl") << " could not be created and the program will exit." << std::endl;
                exit(0);
            }
        }
        if (save_depth){
            ret = mkdir((folder + "//depth_viz").c_str(), 0775);
            if (ret == 0){
                std::cout << "The folder " << (folder + "/depth_viz") << " was created." << std::endl;
            } else {
                std::cout << "The folder " << (folder + "/depth_viz") << " could not be created and the program will exit." << std::endl;
                exit(0);
            }
        }
        if (save_rgbd && !only_depth){
            ret = mkdir((folder + "//rgbd").c_str(), 0775);
            if (ret == 0){
                std::cout << "The folder " << (folder + "/rgbd") << " was created." << std::endl;
            } else {
                std::cout << "The folder " << (folder + "/rgbd") << " could not be created and the program will exit." << std::endl;
                exit(0);
            }
        }
        if (!no_oni){
            ret = mkdir((folder + "//oni").c_str(), 0775);
            if (ret == 0){
                std::cout << "The folder " << (folder + "/oni") << " was created." << std::endl;
            } else {
                std::cout << "The folder " << (folder + "/oni") << " could not be created and the program will exit." << std::endl;
                exit(0);
            }
        }
    }else {
        std::cout << "The folder " << (folder) << " could not be created and the program will exit." << std::endl;
        exit(0);
    }
}


void Viewer::saveToDisk(){

    int j = initial_frame;
    //move oni file to destination
    if (!no_oni){
        QFile::rename(QString("recording.oni"), QString(QString::fromStdString(folder_name) + QString("/oni/recording.oni")));
    }
    for(int i = 0; i < (int)raw_depth.size() ; i++){
        std::cout << "Saving frame " << i << std::endl;
        // generate filenames
        std::ostringstream ss;
        ss << std::setfill('0') << std::setw(padding);
        ss << j ;
        std::string fileNamePcl = folder_name + "/pcl" + "/" + ss.str() + ".pcd";
        std::string fileNameRGB = folder_name + "/rgb" + "/" + ss.str() + img_type;
        std::string fileNameRGBD = folder_name + "/rgbd" + "/" + ss.str() + img_type;
        std::string fileNameDepthS = folder_name + "/depth_viz" + "/" + ss.str() + img_type;
        std::string fileNameDepthI = "";
        if (save_depth && (!save_yml || save_both_depth)){
            fileNameDepthI = folder_name + "/depth" + "/png" + "/" + ss.str() + ".png";
            std::cout << fileNameDepthI << std::endl;
            std::vector<int> params;
            params.push_back( CV_IMWRITE_PNG_COMPRESSION );
            params.push_back( 0 );
            cv::imwrite(fileNameDepthI, raw_depth[i], params);
        }
        if(save_depth && (save_yml || save_both_depth))  {
            fileNameDepthI = folder_name + "/depth" + "/yml"  + "/" + ss.str() + ".yml";
            cv::FileStorage fs(fileNameDepthI, cv::FileStorage::WRITE);
            fs << "depth" << raw_depth[i];
            fs.release();
        }


        // save pcl
        if (save_pcd){
            if (!only_depth){
                pcl::PointCloud<typePoint> cloud;
                get_pcl(rgb_images[i], raw_depth[i], cloud);
                cloud.width = raw_depth[i].cols;
                cloud.height   = raw_depth[i].rows;
                pcl::io::savePCDFile( fileNamePcl, cloud, binary_mode );
            } else {
                pcl::PointCloud<colorlessPoint> cloud;
                get_colorless_pcl(raw_depth[i], cloud);
                cloud.width = raw_depth[i].cols;
                cloud.height   = raw_depth[i].rows;
                pcl::io::savePCDFile( fileNamePcl, cloud, binary_mode );
            }
        }


        // save RGB, RGBD and Depths images
        if (save_rgb && !only_depth){
            cv::imwrite(fileNameRGB, rgb_images[i]);
        }
        if (save_rgbd && !only_depth){
            cv::imwrite(fileNameRGBD, rgbd_images[i]);
        }

        if (save_depth){
            cv::imwrite(fileNameDepthS, depth_show[i]);
        }

        j++;
    }
}
