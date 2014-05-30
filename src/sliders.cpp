#include "sliders.h"
#include "ui_sliders.h"

sliders::sliders(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sliders)
{
    ui->setupUi(this);
}

sliders::~sliders()
{
    delete ui;
}

void sliders::on_mySlider_Z_min_actionTriggered(int action)
{
    viewer->limitz_min =  ui->mySlider_Z_min->value();
    ui->z_min_val->setText(QString::number(ui->mySlider_Z_min->value()));
}

void sliders::on_mySlider_Z_max_actionTriggered(int action)
{
    viewer->limitz_max =  ui->mySlider_Z_max->value();
    ui->z_max_val->setText(QString::number(ui->mySlider_Z_max->value()));
}

void sliders::on_mySlider_Y_min_actionTriggered(int action)
{
    viewer->limity_min =  ui->mySlider_Y_min->value();
    ui->y_min_val->setText(QString::number(ui->mySlider_Y_min->value()));
}

void sliders::on_mySlider_Y_max_actionTriggered(int action)
{
    viewer->limity_max =ui->mySlider_Y_max->value();
    ui->y_max_val->setText(QString::number(ui->mySlider_Y_max->value()));
}

void sliders::on_mySlider_X_min_actionTriggered(int action)
{
    viewer->limitx_min =  ui->mySlider_X_min->value();
    ui->x_min_val->setText(QString::number(ui->mySlider_X_min->value()));
}

void sliders::on_mySlider_X_max_actionTriggered(int action)
{
    viewer->limitx_max =  ui->mySlider_X_max->value();
    ui->x_max_val->setText(QString::number(ui->mySlider_X_max->value()));
}

void sliders::on_myButton_update_limit_Z_clicked()
{

    int limit = ui->myTextEdit_limits_Z->toPlainText().toInt();
    ui->mySlider_Z_min->setMaximum( +limit );
    ui->mySlider_Z_max->setMaximum( +limit );
}

void sliders::set_sliders_max(){
    ui->mySlider_X_min->setRange(0, viewer->frame_width);
    ui->mySlider_X_max->setRange(0, viewer->frame_width);

    ui->mySlider_Y_min->setRange(0, viewer->frame_height);
    ui->mySlider_Y_max->setRange(0, viewer->frame_height);

    ui->mySlider_X_min->setValue(0);
    ui->mySlider_X_max->setValue(ui->mySlider_X_max->maximum());
    ui->mySlider_Y_min->setValue(0);
    ui->mySlider_Y_max->setValue(ui->mySlider_Y_max->maximum());
    ui->mySlider_Z_min->setValue(0);
    ui->mySlider_Z_max->setValue(ui->mySlider_Z_max->maximum());

    viewer->limitz_min =  ui->mySlider_Z_min->value();
    ui->z_min_val->setText(QString::number(ui->mySlider_Z_min->value()));
    viewer->limitz_max =  ui->mySlider_Z_max->value();
    ui->z_max_val->setText(QString::number(ui->mySlider_Z_max->value()));
    viewer->limity_min =  ui->mySlider_Y_min->value();
    ui->y_min_val->setText(QString::number(ui->mySlider_Y_min->value()));
    viewer->limity_max =ui->mySlider_Y_max->value();
    ui->y_max_val->setText(QString::number(ui->mySlider_Y_max->value()));
    viewer->limitx_min =  ui->mySlider_X_min->value();
    ui->x_min_val->setText(QString::number(ui->mySlider_X_min->value()));
    viewer->limitx_max =  ui->mySlider_X_max->value();
    ui->x_max_val->setText(QString::number(ui->mySlider_X_max->value()));


}

void sliders::on_whiteBalance_toggled(bool checked)
{
    openni::CameraSettings* settings = viewer->color.getCameraSettings();
    settings->setAutoWhiteBalanceEnabled(checked);
}

void sliders::on_auto_exposure_toggled(bool checked)
{
    openni::CameraSettings* settings = viewer->color.getCameraSettings();
    settings->setAutoExposureEnabled(checked);
    if(checked){
        settings->setExposure(0);
        ui->exposure_value->setText("");
    } else {
        settings->setExposure(ui->exposure_sliders->value());
        ui->exposure_value->setText(QString::number(ui->exposure_sliders->value()));
    }
}


void sliders::on_exposure_sliders_actionTriggered(int action)
{
    ui->auto_exposure->setChecked(false);
    openni::CameraSettings* settings = viewer->color.getCameraSettings();
    settings->setAutoExposureEnabled(true);
    settings->setExposure(ui->exposure_sliders->value());
    ui->exposure_value->setText(QString::number(ui->exposure_sliders->value()));
}
