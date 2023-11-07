#ifndef MAINUI_H__
#define MAINUI_H__

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <cstddef>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <qvector.h>

#include "hash.h"


class MainUI : public QWidget
{

    Q_OBJECT

public:
    MainUI(QWidget *parent = nullptr);
    ~MainUI();

    void ShowWindow();

private:
    QWidget *MainWindow  = nullptr;
    QGridLayout *layout = nullptr;
    QLabel *label = nullptr;

    QGroupBox *group_insert = nullptr;
    QLabel *insert_word = nullptr;
    QLineEdit *insert_input_word = nullptr;
    QLabel *insert_trans = nullptr;
    QLineEdit *insert_input_trans = nullptr;
    QPushButton *insertButton = nullptr;
    QGridLayout *insertGroupBoxLayout = nullptr;

    QGroupBox *group_delete = nullptr;
    QLabel *delete_word = nullptr;
    QLineEdit *delete_input_word = nullptr;
    QPushButton *deleteButton = nullptr;
    QGridLayout *deleteGroupBoxLayout = nullptr;

    QGroupBox *group_select = nullptr;
    QLabel *select_word = nullptr;
    QLineEdit *select_input_word = nullptr;
    QPushButton *selectButton = nullptr;
    QGridLayout *selectGroupBoxLayout = nullptr;

    QPlainTextEdit *console = nullptr;
    QPushButton *consoleClearBtn = nullptr;

    QPushButton *showAllBtn = nullptr;
    QPushButton *clearAllBtn = nullptr;
    

private:
    // QVector<QPair<QString, QString>> dicts;
    QString tips;
    OpenHashTable<std::string, std::string> *dictionary = nullptr;
       
    void MainUIInit();
    void ConnectInit();
    void DictsInit();

public slots:
    void InsertBtn_Slot();
    void DeleteBtn_Slot();
    void SelectBtn_Slot();

    void ShowAllBtn_SLot();
    void ClearAllBtn_SLot();
};

#endif