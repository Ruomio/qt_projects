#include "MainUI.h"
#include <qboxlayout.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qplaintextedit.h>
#include <qpushbutton.h>
#include <qstringliteral.h>
#include <qdebug.h>

#include "hash.h"


MainUI::MainUI(QWidget *parent) : QWidget(parent)
{
    MainUIInit();
    ConnectInit();
    DictsInit();
}

MainUI::~MainUI() {
    if(MainWindow) {
        delete MainWindow;
    }
}

void MainUI::ShowWindow() {
    MainWindow->show();
}

void MainUI::MainUIInit() {
    MainWindow = new QWidget();
    MainWindow->setWindowTitle("OpenHash界面");
    MainWindow->resize(400,400);


    // 创建标签
    label = new QLabel("欢迎使用OpenHash");
    label->setGeometry(50, 50, 200, 30);

    // insert 组
    group_insert = new QGroupBox(MainWindow);
    group_insert->setTitle(QStringLiteral("插入组"));
    insertGroupBoxLayout = new QGridLayout(group_insert);
    insert_word = new QLabel("word:",group_insert);
    insert_trans = new QLabel("trans:", group_insert);
    insert_input_word = new QLineEdit(group_insert);
    insert_input_trans = new QLineEdit(group_insert);
    insertButton = new QPushButton(group_insert);
    insertButton->setText(QStringLiteral("插入"));
    insertGroupBoxLayout->addWidget(insert_word, 0, 0);
    insertGroupBoxLayout->addWidget(insert_input_word, 0, 1);
    insertGroupBoxLayout->addWidget(insert_trans, 1, 0);
    insertGroupBoxLayout->addWidget(insert_input_trans, 1, 1);
    insertGroupBoxLayout->addWidget(insertButton, 2, 0, 1, 2);

    // delete 组
    group_delete = new QGroupBox(MainWindow);
    group_delete->setTitle(QStringLiteral("删除组"));
    deleteGroupBoxLayout = new QGridLayout(group_delete);
    delete_word = new QLabel("word:",group_delete);
    delete_input_word = new QLineEdit(group_delete);
    deleteButton = new QPushButton(group_delete);
    deleteButton->setText(QStringLiteral("删除"));
    deleteGroupBoxLayout->addWidget(delete_word, 0, 0);
    deleteGroupBoxLayout->addWidget(delete_input_word, 0, 1);
    deleteGroupBoxLayout->addWidget(deleteButton, 2, 0, 1, 2);

    // select 组
    group_select = new QGroupBox(MainWindow);
    group_select->setTitle(QStringLiteral("查询组"));
    selectGroupBoxLayout = new QGridLayout(group_select);
    select_word = new QLabel("word:",group_select);
    select_input_word = new QLineEdit(group_select);
    selectButton = new QPushButton(group_select);
    selectButton->setText(QStringLiteral("查询"));
    selectGroupBoxLayout->addWidget(select_word, 0, 0);
    selectGroupBoxLayout->addWidget(select_input_word, 0, 1);
    selectGroupBoxLayout->addWidget(selectButton, 2, 0, 1, 2);

    // console
    console = new QPlainTextEdit(MainWindow);
    console->setMinimumHeight(200);

    showAllBtn = new QPushButton(MainWindow);
    showAllBtn->setText(QStringLiteral("显示所有"));
    clearAllBtn = new QPushButton(MainWindow);
    clearAllBtn->setText(QStringLiteral("清除"));

    
    // 布局
    layout = new QGridLayout(MainWindow);
    
    layout->addWidget(label, 0, 0, 1, 2, Qt::AlignTop );
    layout->addWidget(group_insert, 1, 0, 1, 2);
    layout->addWidget(group_delete, 2, 0, 1, 2);
    layout->addWidget(group_select, 3, 0, 1, 2);
    layout->addWidget(console, 4, 0, 1, 2);
    layout->addWidget(showAllBtn,5,0, 1, 1);
    layout->addWidget(clearAllBtn,5,1, 1, 1);
    


    
}

void MainUI::ConnectInit() {
    // 连接按钮的点击事件
    connect(insertButton, &QPushButton::clicked, this, &MainUI::InsertBtn_Slot);
    connect(deleteButton, &QPushButton::clicked, this, &MainUI::DeleteBtn_Slot);
    connect(selectButton, &QPushButton::clicked, this, &MainUI::SelectBtn_Slot);

    connect(showAllBtn, &QPushButton::clicked, this, &MainUI::ShowAllBtn_SLot);
    connect(clearAllBtn, &QPushButton::clicked, this, &MainUI::ClearAllBtn_SLot);
}


void MainUI::DictsInit() {
    dictionary = new OpenHashTable<std::string, std::string>(1000);
    addFromFile(dictionary);
}




void MainUI::InsertBtn_Slot() {
    std::string word_tem = insert_input_word->text().toStdString();
    std::string trans_tem = insert_input_trans->text().toStdString();
    dictionary->Insert(word_tem, trans_tem);
    
    tips = QStringLiteral("插入成功！！\n");
    console->insertPlainText(tips);

}

void MainUI::DeleteBtn_Slot() {
    std::string word_tem = delete_input_word->text().toStdString();
    if(dictionary->Remove(word_tem)) {
        tips = QStringLiteral("删除成功！！\n");
    }
    else {
        tips = QStringLiteral("删除失败！！\n");
    }
    console->insertPlainText(tips);
}

void MainUI::SelectBtn_Slot() {
    std::string select_tem = select_input_word->text().toStdString();
    std::string value; 
    if(dictionary->Search(select_tem, value)) {
        tips = QStringLiteral("查询成功！！\n") + QString::fromStdString(value) + QStringLiteral("\n");
    }
    else {
        tips = QStringLiteral("未查询到单词！！\n");
    }
    console->insertPlainText(tips);
}

void MainUI::ShowAllBtn_SLot() {
    tips = QStringLiteral("展示所有！！\n");
    console->insertPlainText(tips);
}

void MainUI::ClearAllBtn_SLot() {
    // tips = QStringLiteral("清除所有！！\n");
    console->clear();
}