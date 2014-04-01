cmake_minimum_required (VERSION 2.6 FATAL_ERROR)
project (tools_openni2) 

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories( ${PROJECT_SOURCE_DIR}/include )

# PCL required
find_package(PCL 1.7 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

message("\n\nFound PCL\n\n")

# Boost library required
find_package( Boost 1.40 REQUIRED COMPONENTS program_options)
include_directories( ${Boost_INCLUDE_DIR} )

# Opencv required
find_package(OpenCV REQUIRED)
include_directories(${OPENCV_INCLUDE_DIRS})
link_directories(${OPENCV_LIBRARY_DIRS})
add_definitions(${OPENCV_DEFINITIONS})

message("\n\nFound OpenCV\n\n")

# Openni2 required
set(Openni2_INCLUDE $ENV{OPENNI2_INCLUDE})
if(NOT Openni2_INCLUDE)
  message(FATAL_ERROR "Could not find OPENNI2_INCLUDE environment variable")
endif(NOT Openni2_INCLUDE)

set(Openni2_REDIST $ENV{OPENNI2_REDIST})
if(NOT Openni2_REDIST)
  message(FATAL_ERROR "Could not find OPENNI2_INCLUDE environment variable")
endif(NOT Openni2_REDIST)

include_directories( ${Openni2_INCLUDE} )
link_directories( ${Openni2_REDIST} )

message("\n\nFound Openni2\n\n")

# QT4 required
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

message("\n\nFound QT4\n\n")

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# set the sources needed
set( VIEWER_SOURCES   
                src/main.cpp
		src/viewer.cpp
                src/viewer_error.cpp
		src/viewer_visualizer.cpp
		src/viewer_keyio.cpp
		src/viewer_pcl.cpp
		src/viewer_save.cpp
		src/sliders.cpp
)

# set QT headers
SET(QT_HEADERS include/sliders.h)

#set QT forms
SET(QT_FORMS ui/sliders.ui)

# create moc for QT
QT4_WRAP_CPP(QT_MOC ${QT_HEADERS})

# process ui
QT4_WRAP_UI(QT_FORMS_HEADERS ${QT_FORMS})

ADD_EXECUTABLE(viewer ${VIEWER_SOURCES} 
    ${QT_MOC} 
    ${QT_FORMS})


TARGET_LINK_LIBRARIES(viewer ${QT_LIBRARIES} ${PCL_LIBRARIES} ${OpenCV_LIBS} OpenNI2 ${Boost_PROGRAM_OPTIONS_LIBRARY})


