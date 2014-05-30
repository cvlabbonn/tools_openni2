#include <viewer.h>
#include <sliders.h>
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Viewer viewer(argc, argv);
    sliders s;
    s.viewer = &viewer;
    s.set_sliders_max();
    s.set_initial_variables();
    s.show();
    int ret  = viewer.loop();
    if (ret == 0){
        viewer.~Viewer();
        exit(0);
    }


    return a.exec();
}

