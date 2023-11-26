/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-11-26 16:11:20
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-11-26 23:16:55
 * @FilePath: /Simple_geometric_expert_system/code/include/RuleEdit.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _RULE_EDIT_H__
#define _RULE_EDIT_H__

#include <iostream>
#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

class RuleEdit : public QWidget
{
    Q_OBJECT
    
public:
    explicit RuleEdit(QWidget *parent = nullptr);
    ~RuleEdit();

    void InitWidget();
    void InitSlot();
    void ShowWindows();

private:
    QWidget *rule_edit_widget = nullptr;
    QPushButton *create_btn = nullptr;
    QPushButton *cancel_btn = nullptr;


signals:

};

#endif