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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XVideoUI
{
public:

    void setupUi(QWidget *XVideoUI)
    {
        if (XVideoUI->objectName().isEmpty())
            XVideoUI->setObjectName("XVideoUI");
        XVideoUI->resize(800, 600);

        retranslateUi(XVideoUI);

        QMetaObject::connectSlotsByName(XVideoUI);
    } // setupUi

    void retranslateUi(QWidget *XVideoUI)
    {
        XVideoUI->setWindowTitle(QCoreApplication::translate("XVideoUI", "XVideoUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XVideoUI: public Ui_XVideoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XVIDEOUI_H
