#ifndef XVIDEOUI_H
#define XVIDEOUI_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class XVideoUI; }
QT_END_NAMESPACE

class XVideoUI : public QWidget
{
    Q_OBJECT

public:
    XVideoUI(QWidget *parent = nullptr);
    ~XVideoUI();

private:
    Ui::XVideoUI *ui;
};
#endif // XVIDEOUI_H
