#include <QApplication>
#include "MainUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainUI w;
    w.ShowWindow();

    return a.exec();
}
