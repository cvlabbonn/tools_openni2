#ifndef SLIDERS_H
#define SLIDERS_H

#include <QWidget>
#include <viewer.h>

namespace Ui {
class sliders;
}

class sliders : public QWidget
{
    Q_OBJECT
    
public:
    Viewer *viewer;
    explicit sliders(QWidget *parent = 0);
    void set_sliders_max();
    ~sliders();
    
private slots:
    void on_mySlider_Z_min_actionTriggered(int action);
    void on_mySlider_Z_max_actionTriggered(int action);
    void on_mySlider_Y_min_actionTriggered(int action);
    void on_mySlider_Y_max_actionTriggered(int action);
    void on_mySlider_X_min_actionTriggered(int action);
    void on_mySlider_X_max_actionTriggered(int action);

    void on_myButton_update_limit_Z_clicked();

    void on_whiteBalance_toggled(bool checked);

    void on_auto_exposure_toggled(bool checked);

    void on_exposure_sliders_actionTriggered(int action);

private:
    Ui::sliders *ui;
};

#endif // SLIDERS_H
