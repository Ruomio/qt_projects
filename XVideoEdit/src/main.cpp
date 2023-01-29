#include "xvideoui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XVideoUI w;
    w.show();
    return a.exec();
}
