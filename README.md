tools_openni2
=============

Simple recording tool using OpenNI2 for Primesense cameras. Once the program starts, it will show 4 windows. The one named Limits will permit to set the x and y limits of the pointcloud (based on the x and y limit of the RGB image) and also set the limits of the depth. Depending on the camera this "z" max limit can be changed to permit changes between close and long ranged cameras.

The other 3 windows will show in real time the RGB feed from the camera (color window), the visual representation of the depth (depth window), and the visual representation of the registration of the valid depth to the color image (RGBD  window).

During the execution, it is possible to use some keys to give commands to the program. You may use the following keys:

["Esc"|"q"|"Q"]			To exit the program correctly
" "			The space key will start/stop saving the data into memory
["s"|"S"]		To save the data in memory to the hard disk (it will create a folder)

The program will generate 1 folder with 5 subfolders:
- **depth**: raw depth matrix in yml format. It was saved usin opencv and can be easily parsed using opencv again. (see notes)
- **depth_viz**: a visualization of the depth values
- **pcl**:organized point cloud files
- **rgb**: the rgb images captured by the camera
- **rgbd**: a visualization of the depth and color registration

These are the possible arguments you may pass to the program

    Allowed options:

      -h [ --help ]                help
      -t [ --imgtype ] arg (=.png) image file type
      -i [ --initial ] arg (=0)    Initial number of the frame
      -p [ --padding ] arg (=3)    Pad the number with 0 to a set amount of digits
      -a [ --ascii ]               Save pcd files in ascii mode
      --oni                        Save .oni record.


Example:
- start in frame 55, with a padding of 6, with images as .jpg and save pcd files in binary mode.

    viewer -i 55 -p 6 -t .jpg -b


Dependencies
=============

Make sure to have the following packages installed

- PCL 1.7
- Boost
- OpenCV
- Openni 2.x (must have the environment variables set)
- QT4
- CMake

Building
=============

Just run the following commands

    mkdir build
    cd build
    cmake ..
    make

Running
=============

Just go to the bin folder and run viewer executable

Notes
=============
The program was tested in Ubuntu 12.04 x64.

To retrieve the matrix from the yml file use

    cv::Mat depth;
    cv::FileStorage fs("0001.yml", cv::FileStorage::READ);
    fs[""]  >> depth;
