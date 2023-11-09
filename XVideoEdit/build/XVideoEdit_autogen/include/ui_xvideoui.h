/********************************************************************************
** Form generated from reading UI file 'xvideoui.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XVIDEOUI_H
#define UI_XVIDEOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "/home/papillon/Documents/All_Code/Qt_projeces/XVideoEdit/src/xvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_XVideoUI
{
public:
    XVideoWidget *src1;
    QPushButton *openButton;
    QSlider *playSlider;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *bright;
    QDoubleSpinBox *contrast;
    QPushButton *setButton;
    XVideoWidget *dst;
    QPushButton *exportButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QLabel *label_3;
    QComboBox *rotateBox;
    QComboBox *flipBox;
    QLabel *label_4;
    QSpinBox *width;
    QSpinBox *high;
    QLabel *label_5;
    QSpinBox *pyup;
    QSpinBox *pydowm;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *clip_y;
    QSpinBox *clip_x;
    QSpinBox *clip_width;
    QSpinBox *clip_high;
    XVideoWidget *src2;
    QLabel *label_9;
    QComboBox *colorBox;
    QSpinBox *mark_x;
    QSpinBox *mark_y;
    QPushButton *markButton;
    QDoubleSpinBox *mark_alpha;
    QDoubleSpinBox *mark_size;
    QPushButton *blendButton;
    QDoubleSpinBox *blend_alpha;
    QPushButton *mergeButton;
    QSlider *leftSlider;
    QSlider *rightSlider;

    void setupUi(QWidget *XVideoUI)
    {
        if (XVideoUI->objectName().isEmpty())
            XVideoUI->setObjectName("XVideoUI");
        XVideoUI->resize(860, 800);
        XVideoUI->setStyleSheet(QString::fromUtf8("#XVideoUI{\n"
"	background-color: rgb(53, 53, 53);\n"
"}\n"
"\n"
"#openButton{	\n"
"	background-color: rgb(200, 200, 200);\n"
"}\n"
"\n"
"QLabel{\n"
"	color:rgb(255,255,255);\n"
"}\n"
"#playButton{\n"
"	image: url(:/img/resource/\346\222\255\346\224\2762.png);\n"
"}\n"
"#pauseButton{\n"
"	\n"
"	image: url(:/img/resource/\346\232\202\345\201\234.png);\n"
"}\n"
"\n"
""));
        src1 = new XVideoWidget(XVideoUI);
        src1->setObjectName("src1");
        src1->setGeometry(QRect(10, 20, 400, 340));
        openButton = new QPushButton(XVideoUI);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(420, 370, 51, 21));
        openButton->setFlat(false);
        playSlider = new QSlider(XVideoUI);
        playSlider->setObjectName("playSlider");
        playSlider->setGeometry(QRect(10, 340, 401, 20));
        playSlider->setMaximum(999);
        playSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(XVideoUI);
        label->setObjectName("label");
        label->setGeometry(QRect(458, 401, 61, 20));
        label_2 = new QLabel(XVideoUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 421, 81, 17));
        bright = new QSpinBox(XVideoUI);
        bright->setObjectName("bright");
        bright->setGeometry(QRect(530, 400, 61, 20));
        bright->setMaximum(100);
        bright->setSingleStep(10);
        bright->setDisplayIntegerBase(10);
        contrast = new QDoubleSpinBox(XVideoUI);
        contrast->setObjectName("contrast");
        contrast->setGeometry(QRect(530, 420, 61, 20));
        contrast->setMinimum(1.000000000000000);
        contrast->setMaximum(3.000000000000000);
        setButton = new QPushButton(XVideoUI);
        setButton->setObjectName("setButton");
        setButton->setGeometry(QRect(680, 420, 51, 21));
        setButton->setFlat(false);
        dst = new XVideoWidget(XVideoUI);
        dst->setObjectName("dst");
        dst->setGeometry(QRect(430, 20, 400, 340));
        exportButton = new QPushButton(XVideoUI);
        exportButton->setObjectName("exportButton");
        exportButton->setGeometry(QRect(680, 390, 81, 21));
        exportButton->setFlat(false);
        playButton = new QPushButton(XVideoUI);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(11, 390, 20, 20));
        playButton->setFlat(false);
        pauseButton = new QPushButton(XVideoUI);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(34, 390, 20, 20));
        pauseButton->setFlat(false);
        label_3 = new QLabel(XVideoUI);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(471, 438, 61, 20));
        rotateBox = new QComboBox(XVideoUI);
        rotateBox->addItem(QString());
        rotateBox->addItem(QString());
        rotateBox->addItem(QString());
        rotateBox->addItem(QString());
        rotateBox->setObjectName("rotateBox");
        rotateBox->setGeometry(QRect(530, 440, 60, 16));
        flipBox = new QComboBox(XVideoUI);
        flipBox->addItem(QString());
        flipBox->addItem(QString());
        flipBox->addItem(QString());
        flipBox->addItem(QString());
        flipBox->setObjectName("flipBox");
        flipBox->setGeometry(QRect(530, 458, 60, 16));
        label_4 = new QLabel(XVideoUI);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 457, 61, 20));
        width = new QSpinBox(XVideoUI);
        width->setObjectName("width");
        width->setGeometry(QRect(530, 475, 40, 20));
        width->setMaximum(9999);
        width->setDisplayIntegerBase(10);
        high = new QSpinBox(XVideoUI);
        high->setObjectName("high");
        high->setGeometry(QRect(570, 475, 40, 20));
        high->setMaximum(9999);
        high->setDisplayIntegerBase(10);
        label_5 = new QLabel(XVideoUI);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(449, 475, 71, 20));
        pyup = new QSpinBox(XVideoUI);
        pyup->setObjectName("pyup");
        pyup->setGeometry(QRect(530, 515, 61, 20));
        pyup->setMaximum(100);
        pyup->setDisplayIntegerBase(10);
        pydowm = new QSpinBox(XVideoUI);
        pydowm->setObjectName("pydowm");
        pydowm->setGeometry(QRect(530, 495, 61, 20));
        pydowm->setMaximum(100);
        pydowm->setDisplayIntegerBase(10);
        label_6 = new QLabel(XVideoUI);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(459, 495, 71, 20));
        label_7 = new QLabel(XVideoUI);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(435, 515, 91, 20));
        label_8 = new QLabel(XVideoUI);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(428, 536, 101, 20));
        clip_y = new QSpinBox(XVideoUI);
        clip_y->setObjectName("clip_y");
        clip_y->setGeometry(QRect(570, 536, 40, 20));
        clip_y->setMaximum(9999);
        clip_y->setDisplayIntegerBase(10);
        clip_x = new QSpinBox(XVideoUI);
        clip_x->setObjectName("clip_x");
        clip_x->setGeometry(QRect(530, 536, 40, 20));
        clip_x->setMaximum(9999);
        clip_x->setDisplayIntegerBase(10);
        clip_width = new QSpinBox(XVideoUI);
        clip_width->setObjectName("clip_width");
        clip_width->setGeometry(QRect(610, 536, 40, 20));
        clip_width->setMaximum(9999);
        clip_width->setDisplayIntegerBase(10);
        clip_high = new QSpinBox(XVideoUI);
        clip_high->setObjectName("clip_high");
        clip_high->setGeometry(QRect(650, 536, 40, 20));
        clip_high->setMaximum(9999);
        clip_high->setDisplayIntegerBase(10);
        src2 = new XVideoWidget(XVideoUI);
        src2->setObjectName("src2");
        src2->setGeometry(QRect(10, 420, 400, 340));
        label_9 = new QLabel(XVideoUI);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(472, 559, 50, 20));
        colorBox = new QComboBox(XVideoUI);
        colorBox->addItem(QString());
        colorBox->addItem(QString());
        colorBox->addItem(QString());
        colorBox->setObjectName("colorBox");
        colorBox->setGeometry(QRect(530, 560, 60, 16));
        mark_x = new QSpinBox(XVideoUI);
        mark_x->setObjectName("mark_x");
        mark_x->setGeometry(QRect(530, 580, 40, 20));
        mark_x->setMaximum(9999);
        mark_x->setDisplayIntegerBase(10);
        mark_y = new QSpinBox(XVideoUI);
        mark_y->setObjectName("mark_y");
        mark_y->setGeometry(QRect(570, 580, 40, 20));
        mark_y->setMaximum(9999);
        mark_y->setDisplayIntegerBase(10);
        markButton = new QPushButton(XVideoUI);
        markButton->setObjectName("markButton");
        markButton->setGeometry(QRect(430, 580, 90, 21));
        markButton->setFlat(false);
        mark_alpha = new QDoubleSpinBox(XVideoUI);
        mark_alpha->setObjectName("mark_alpha");
        mark_alpha->setGeometry(QRect(610, 580, 50, 20));
        mark_alpha->setMinimum(0.000000000000000);
        mark_alpha->setMaximum(1.000000000000000);
        mark_alpha->setSingleStep(0.100000000000000);
        mark_alpha->setValue(1.000000000000000);
        mark_size = new QDoubleSpinBox(XVideoUI);
        mark_size->setObjectName("mark_size");
        mark_size->setGeometry(QRect(660, 580, 50, 20));
        mark_size->setMinimum(0.000000000000000);
        mark_size->setMaximum(10.000000000000000);
        mark_size->setSingleStep(0.100000000000000);
        mark_size->setValue(1.000000000000000);
        blendButton = new QPushButton(XVideoUI);
        blendButton->setObjectName("blendButton");
        blendButton->setGeometry(QRect(419, 671, 70, 21));
        blendButton->setFlat(false);
        blend_alpha = new QDoubleSpinBox(XVideoUI);
        blend_alpha->setObjectName("blend_alpha");
        blend_alpha->setGeometry(QRect(497, 670, 50, 23));
        blend_alpha->setMinimum(0.000000000000000);
        blend_alpha->setMaximum(1.000000000000000);
        blend_alpha->setSingleStep(0.100000000000000);
        blend_alpha->setValue(0.500000000000000);
        mergeButton = new QPushButton(XVideoUI);
        mergeButton->setObjectName("mergeButton");
        mergeButton->setGeometry(QRect(420, 700, 70, 21));
        mergeButton->setFlat(false);
        leftSlider = new QSlider(XVideoUI);
        leftSlider->setObjectName("leftSlider");
        leftSlider->setGeometry(QRect(10, 363, 401, 10));
        leftSlider->setMaximumSize(QSize(401, 20));
        leftSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"\n"
"     border: 1px solid #999999;\n"
"\n"
"     height: 4px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"\n"
"     margin: 2px 0;\n"
"\n"
" }\n"
"\n"
"\n"
"\n"
" QSlider::handle:horizontal {\n"
"\n"
"     background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"\n"
"     border: 1px solid #5c5c5c;\n"
"\n"
"     width: 18px;\n"
"\n"
"     margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"\n"
"     border-radius: 3px;\n"
"\n"
" }"));
        leftSlider->setMaximum(999);
        leftSlider->setOrientation(Qt::Horizontal);
        rightSlider = new QSlider(XVideoUI);
        rightSlider->setObjectName("rightSlider");
        rightSlider->setGeometry(QRect(10, 374, 401, 10));
        rightSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"\n"
"     border: 1px solid #999999;\n"
"\n"
"     height: 4px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"\n"
"     margin: 2px 0;\n"
"\n"
" }\n"
"\n"
"\n"
"\n"
" QSlider::handle:horizontal {\n"
"\n"
"     background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"\n"
"     border: 1px solid #5c5c5c;\n"
"\n"
"     width: 18px;\n"
"\n"
"     margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"\n"
"     border-radius: 3px;\n"
"\n"
" }"));
        rightSlider->setMaximum(999);
        rightSlider->setValue(999);
        rightSlider->setOrientation(Qt::Horizontal);

        retranslateUi(XVideoUI);
        QObject::connect(openButton, SIGNAL(clicked()), XVideoUI, SLOT(Open()));
        QObject::connect(playSlider, SIGNAL(sliderPressed()), XVideoUI, SLOT(SliderPress()));
        QObject::connect(playSlider, SIGNAL(sliderReleased()), XVideoUI, SLOT(SliderRelease()));
        QObject::connect(playSlider, SIGNAL(sliderMoved(int)), XVideoUI, SLOT(SetPos(int)));
        QObject::connect(setButton, SIGNAL(clicked()), XVideoUI, SLOT(Set()));
        QObject::connect(exportButton, SIGNAL(clicked()), XVideoUI, SLOT(Export()));
        QObject::connect(playButton, SIGNAL(clicked()), XVideoUI, SLOT(Play()));
        QObject::connect(pauseButton, SIGNAL(clicked()), XVideoUI, SLOT(Pause()));
        QObject::connect(markButton, SIGNAL(clicked()), XVideoUI, SLOT(Mark()));
        QObject::connect(blendButton, SIGNAL(clicked()), XVideoUI, SLOT(Blend()));
        QObject::connect(mergeButton, SIGNAL(clicked()), XVideoUI, SLOT(Merge()));
        QObject::connect(leftSlider, SIGNAL(sliderMoved(int)), XVideoUI, SLOT(Left(int)));
        QObject::connect(rightSlider, SIGNAL(sliderMoved(int)), XVideoUI, SLOT(Right(int)));

        QMetaObject::connectSlotsByName(XVideoUI);
    } // setupUi

    void retranslateUi(QWidget *XVideoUI)
    {
        XVideoUI->setWindowTitle(QCoreApplication::translate("XVideoUI", "XVideoUI", nullptr));
        openButton->setText(QCoreApplication::translate("XVideoUI", "\346\211\223\345\274\200", nullptr));
        label->setText(QCoreApplication::translate("XVideoUI", "\344\272\256\345\272\246[0-100]", nullptr));
        label_2->setText(QCoreApplication::translate("XVideoUI", "\345\257\271\346\257\224\345\272\246[1.0-3.0]", nullptr));
        setButton->setText(QCoreApplication::translate("XVideoUI", "\350\256\276\347\275\256", nullptr));
        exportButton->setText(QCoreApplication::translate("XVideoUI", "\345\257\274\345\207\272", nullptr));
        playButton->setText(QString());
        pauseButton->setText(QString());
        label_3->setText(QCoreApplication::translate("XVideoUI", "\345\233\276\345\203\217\346\227\213\350\275\254", nullptr));
        rotateBox->setItemText(0, QCoreApplication::translate("XVideoUI", "0", nullptr));
        rotateBox->setItemText(1, QCoreApplication::translate("XVideoUI", "90", nullptr));
        rotateBox->setItemText(2, QCoreApplication::translate("XVideoUI", "180", nullptr));
        rotateBox->setItemText(3, QCoreApplication::translate("XVideoUI", "270", nullptr));

        flipBox->setItemText(0, QCoreApplication::translate("XVideoUI", "\345\216\237\345\233\276", nullptr));
        flipBox->setItemText(1, QCoreApplication::translate("XVideoUI", "\344\270\212\344\270\213\351\225\234\345\203\217", nullptr));
        flipBox->setItemText(2, QCoreApplication::translate("XVideoUI", "\345\267\246\345\217\263\351\225\234\345\203\217", nullptr));
        flipBox->setItemText(3, QCoreApplication::translate("XVideoUI", "\344\270\255\345\277\203\351\225\234\345\203\217", nullptr));

        label_4->setText(QCoreApplication::translate("XVideoUI", "\345\233\276\345\203\217\351\225\234\345\203\217", nullptr));
        label_5->setText(QCoreApplication::translate("XVideoUI", "\345\233\276\345\203\217\345\256\275\351\253\230W.H", nullptr));
        label_6->setText(QCoreApplication::translate("XVideoUI", "\351\253\230\346\226\257\351\207\221\345\255\227\345\241\224", nullptr));
        label_7->setText(QCoreApplication::translate("XVideoUI", "\346\213\211\346\231\256\346\213\211\346\226\257\351\207\221\345\255\227\345\241\224", nullptr));
        label_8->setText(QCoreApplication::translate("XVideoUI", "\345\233\276\345\203\217\350\243\201\345\211\252(x,y,w,h)", nullptr));
        label_9->setText(QCoreApplication::translate("XVideoUI", "\351\242\234\350\211\262\350\275\254\346\215\242", nullptr));
        colorBox->setItemText(0, QCoreApplication::translate("XVideoUI", "\345\216\237\345\233\276", nullptr));
        colorBox->setItemText(1, QCoreApplication::translate("XVideoUI", "\347\201\260\345\272\246\345\233\276", nullptr));
        colorBox->setItemText(2, QCoreApplication::translate("XVideoUI", "\344\272\214\345\200\274\345\214\226", nullptr));

        markButton->setText(QCoreApplication::translate("XVideoUI", "\346\260\264\345\215\260(x,y,alpha)", nullptr));
        blendButton->setText(QCoreApplication::translate("XVideoUI", "\350\236\215\345\220\210(alpha)", nullptr));
        mergeButton->setText(QCoreApplication::translate("XVideoUI", "\345\220\210\345\271\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XVideoUI: public Ui_XVideoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XVIDEOUI_H
