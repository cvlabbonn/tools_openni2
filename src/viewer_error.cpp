#include <viewer.h>

void Viewer::error_manager(int error, bool critical){
    switch(error){
    case 1:
        printf("Initialization failed:\n%s\n", openni::OpenNI::getExtendedError());
        break;
    case 2:
        printf("Device open failed:\n%s\n", openni::OpenNI::getExtendedError());
        break;
    case 3:
        printf("No depth stream found:\n%s\n", openni::OpenNI::getExtendedError());
        break;
    case 4:
        printf("Depth stream could not start:\n%s\n", openni::OpenNI::getExtendedError());
        break;
    case 5:
        printf("No color stream found:\n%s\n", openni::OpenNI::getExtendedError());
        break;
    case 6:
        printf("Color stream could not start:\n%s\n", openni::OpenNI::getExtendedError());
        break;
    default:
        printf("An error occurred:\n%s\n", openni::OpenNI::getExtendedError());
    }

    openni::OpenNI::shutdown();
    if (critical)
        exit(1);
}
