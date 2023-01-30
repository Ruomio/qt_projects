/********************************************************************************
** Form generated from reading UI file 'xvideoui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XVIDEOUI_H
#define UI_XVIDEOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "/home/papillon/Documents/All_Code/Qt_projeces/XVideoEdit/src/xvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_XVideoUI
{
public:
    XVideoWidget *src1;
    QPushButton *openButton;
    QSlider *playSlider;

    void setupUi(QWidget *XVideoUI)
    {
        if (XVideoUI->objectName().isEmpty())
            XVideoUI->setObjectName("XVideoUI");
        XVideoUI->resize(800, 600);
        XVideoUI->setStyleSheet(QString::fromUtf8("#XVideoUI{\n"
"	background-color: rgb(53, 53, 53);\n"
"}\n"
"\n"
"#openButton{	\n"
"	background-color: rgb(200, 200, 200);\n"
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

        retranslateUi(XVideoUI);
        QObject::connect(openButton, SIGNAL(clicked()), XVideoUI, SLOT(Open()));

        QMetaObject::connectSlotsByName(XVideoUI);
    } // setupUi

    void retranslateUi(QWidget *XVideoUI)
    {
        XVideoUI->setWindowTitle(QCoreApplication::translate("XVideoUI", "XVideoUI", nullptr));
        openButton->setText(QCoreApplication::translate("XVideoUI", "\346\211\223\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XVideoUI: public Ui_XVideoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XVIDEOUI_H
