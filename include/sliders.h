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
    void set_initial_variables();
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

    void on_starting_frame_textChanged(const QString &arg1);

    void on_padding_size_textChanged(const QString &arg1);

    void on_asciiRadioButton_toggled(bool checked);

    void on_binaryRadioButton_toggled(bool checked);

    void on_depth_checkbox_toggled(bool checked);

    void on_rgb_checkbox_toggled(bool checked);

    void on_rgbd_checkbox_toggled(bool checked);

    void on_pcd_checkbox_toggled(bool checked);

    void on_oni_checkbox_toggled(bool checked);

    void on_png_depth_toggled(bool checked);

    void on_yml_depth_toggled(bool checked);

    void on_png_rgb_toggled(bool checked);

    void on_jpg_rgb_toggled(bool checked);

    void on_tif_rgb_toggled(bool checked);

private:
    Ui::sliders *ui;
};

#endif // SLIDERS_H
