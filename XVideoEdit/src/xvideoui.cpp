#include "xvideoui.h"
#include "./ui_xvideoui.h"

XVideoUI::XVideoUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XVideoUI)
{
    ui->setupUi(this);
}

XVideoUI::~XVideoUI()
{
    delete ui;
}

