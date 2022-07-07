#include "widget.h"
#include <QPushButton>
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置窗口标题
    this->setWindowTitle("更改窗口标题");
    // 设置窗口默认大小
    this->resize(400, 600);
    // 设置固定大小
    this->setFixedSize(400, 600);
    // 设置位置
    this->move(0, 0);

    // 按钮
    QPushButton *btn = new QPushButton(this);
    // 设置文本
    btn->setText("按钮");
    // 设置字体
    QFont qft("华文行楷", 18, 15, 1);
    btn->setFont(qft);
    btn->show();
    // 设置位置
    btn->move(111, 111);

    // 设置样式
//    btn->setStyleSheet() CSS 样式
}

Widget::~Widget()
{
    delete ui;
}
