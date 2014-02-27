TEMPLATE = app
CONFIG += console
QT += core gui

SOURCES += main.cpp \
    viewer.cpp \
    viewer_error.cpp \
    viewer_visualizer.cpp \
    viewer_keyio.cpp \
    viewer_pcl.cpp \
    viewer_save.cpp \
    sliders.cpp

HEADERS += \
    viewer.h \
    sliders.h

# include the files in the Include directory of openni
INCLUDEPATH += /home/cv-group/OpenNI/Include
DEPENDPATH += /home/cv-group/OpenNI/Include
# add the library in your execution path and link it
LIBS += -lQtGui -lQtCore -L$$PWD -lOpenNI2

#opencv libs
LIBS += -lopencv_highgui
LIBS += -lopencv_core
LIBS += -lopencv_imgproc

#pcl  libs
LIBS += -L/usr/lib/
LIBS += -lpcl_common
LIBS += -lpcl_filters
LIBS += -lpcl_io
LIBS += -lpcl_visualization

INCLUDEPATH += /usr/include/pcl-1.7
INCLUDEPATH += /usr/include/eigen3
INCLUDEPATH += /usr/include/vtk-5.8

# boost libs
LIBS += -lboost_system
LIBS += -lboost_thread
INCLUDEPATH += /usr/include/boost

FORMS += \
    sliders.ui
