/********************************************************************************
** Form generated from reading UI file 'sliders.ui'
**
** Created: Thu Feb 27 16:13:48 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDERS_H
#define UI_SLIDERS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sliders
{
public:
    QPlainTextEdit *myTextEdit_limits_Z;
    QPushButton *myButton_update_limit_Z;
    QLabel *label_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_8;
    QSlider *mySlider_X_min;
    QSlider *mySlider_X_max;
    QVBoxLayout *verticalLayout_9;
    QLabel *x_min_val;
    QLabel *x_max_val;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_6;
    QSlider *mySlider_Y_min;
    QSlider *mySlider_Y_max;
    QVBoxLayout *verticalLayout_5;
    QLabel *y_min_val;
    QLabel *y_max_val;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_3;
    QSlider *mySlider_Z_min;
    QSlider *mySlider_Z_max;
    QVBoxLayout *verticalLayout;
    QLabel *z_min_val;
    QLabel *z_max_val;

    void setupUi(QWidget *sliders)
    {
        if (sliders->objectName().isEmpty())
            sliders->setObjectName(QString::fromUtf8("sliders"));
        sliders->resize(1047, 291);
        myTextEdit_limits_Z = new QPlainTextEdit(sliders);
        myTextEdit_limits_Z->setObjectName(QString::fromUtf8("myTextEdit_limits_Z"));
        myTextEdit_limits_Z->setGeometry(QRect(650, 240, 131, 31));
        myButton_update_limit_Z = new QPushButton(sliders);
        myButton_update_limit_Z->setObjectName(QString::fromUtf8("myButton_update_limit_Z"));
        myButton_update_limit_Z->setGeometry(QRect(790, 240, 98, 27));
        label_7 = new QLabel(sliders);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 250, 571, 17));
        widget = new QWidget(sliders);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 1001, 218));
        verticalLayout_10 = new QVBoxLayout(widget);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_7->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_7->addWidget(label_2);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        mySlider_X_min = new QSlider(widget);
        mySlider_X_min->setObjectName(QString::fromUtf8("mySlider_X_min"));
        mySlider_X_min->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(mySlider_X_min);

        mySlider_X_max = new QSlider(widget);
        mySlider_X_max->setObjectName(QString::fromUtf8("mySlider_X_max"));
        mySlider_X_max->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(mySlider_X_max);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        x_min_val = new QLabel(widget);
        x_min_val->setObjectName(QString::fromUtf8("x_min_val"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(x_min_val->sizePolicy().hasHeightForWidth());
        x_min_val->setSizePolicy(sizePolicy);
        x_min_val->setMinimumSize(QSize(100, 0));
        x_min_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_9->addWidget(x_min_val);

        x_max_val = new QLabel(widget);
        x_max_val->setObjectName(QString::fromUtf8("x_max_val"));
        sizePolicy.setHeightForWidth(x_max_val->sizePolicy().hasHeightForWidth());
        x_max_val->setSizePolicy(sizePolicy);
        x_max_val->setMinimumSize(QSize(100, 0));
        x_max_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_9->addWidget(x_max_val);


        horizontalLayout_3->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        mySlider_Y_min = new QSlider(widget);
        mySlider_Y_min->setObjectName(QString::fromUtf8("mySlider_Y_min"));
        mySlider_Y_min->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(mySlider_Y_min);

        mySlider_Y_max = new QSlider(widget);
        mySlider_Y_max->setObjectName(QString::fromUtf8("mySlider_Y_max"));
        mySlider_Y_max->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(mySlider_Y_max);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        y_min_val = new QLabel(widget);
        y_min_val->setObjectName(QString::fromUtf8("y_min_val"));
        sizePolicy.setHeightForWidth(y_min_val->sizePolicy().hasHeightForWidth());
        y_min_val->setSizePolicy(sizePolicy);
        y_min_val->setMinimumSize(QSize(100, 0));
        y_min_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(y_min_val);

        y_max_val = new QLabel(widget);
        y_max_val->setObjectName(QString::fromUtf8("y_max_val"));
        sizePolicy.setHeightForWidth(y_max_val->sizePolicy().hasHeightForWidth());
        y_max_val->setSizePolicy(sizePolicy);
        y_max_val->setMinimumSize(QSize(100, 0));
        y_max_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(y_max_val);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_10->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mySlider_Z_min = new QSlider(widget);
        mySlider_Z_min->setObjectName(QString::fromUtf8("mySlider_Z_min"));
        mySlider_Z_min->setMinimum(1);
        mySlider_Z_min->setMaximum(3000);
        mySlider_Z_min->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(mySlider_Z_min);

        mySlider_Z_max = new QSlider(widget);
        mySlider_Z_max->setObjectName(QString::fromUtf8("mySlider_Z_max"));
        mySlider_Z_max->setMaximum(3000);
        mySlider_Z_max->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(mySlider_Z_max);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        z_min_val = new QLabel(widget);
        z_min_val->setObjectName(QString::fromUtf8("z_min_val"));
        sizePolicy.setHeightForWidth(z_min_val->sizePolicy().hasHeightForWidth());
        z_min_val->setSizePolicy(sizePolicy);
        z_min_val->setMinimumSize(QSize(100, 0));
        z_min_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(z_min_val);

        z_max_val = new QLabel(widget);
        z_max_val->setObjectName(QString::fromUtf8("z_max_val"));
        sizePolicy.setHeightForWidth(z_max_val->sizePolicy().hasHeightForWidth());
        z_max_val->setSizePolicy(sizePolicy);
        z_max_val->setMinimumSize(QSize(100, 0));
        z_max_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(z_max_val);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_10->addLayout(horizontalLayout);


        retranslateUi(sliders);

        QMetaObject::connectSlotsByName(sliders);
    } // setupUi

    void retranslateUi(QWidget *sliders)
    {
        sliders->setWindowTitle(QApplication::translate("sliders", "Form", 0, QApplication::UnicodeUTF8));
        myButton_update_limit_Z->setText(QApplication::translate("sliders", "updateLimitZ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("sliders", "The Z values are in mili meters and the X and Y values are in pixels.", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sliders", "x min", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("sliders", "x max", 0, QApplication::UnicodeUTF8));
        x_min_val->setText(QApplication::translate("sliders", "0", 0, QApplication::UnicodeUTF8));
        x_max_val->setText(QApplication::translate("sliders", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("sliders", "y min", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("sliders", "y max", 0, QApplication::UnicodeUTF8));
        y_min_val->setText(QApplication::translate("sliders", "0", 0, QApplication::UnicodeUTF8));
        y_max_val->setText(QApplication::translate("sliders", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("sliders", "z min", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("sliders", "z max", 0, QApplication::UnicodeUTF8));
        z_min_val->setText(QApplication::translate("sliders", "0", 0, QApplication::UnicodeUTF8));
        z_max_val->setText(QApplication::translate("sliders", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sliders: public Ui_sliders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDERS_H
