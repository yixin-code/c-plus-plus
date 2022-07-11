#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击按钮最大化窗口
    QPushButton *btn = new QPushButton("最大化", this);
    btn->resize(80, 40);

    connect(btn, &QPushButton::clicked, this, &Widget::showMaximized);
}

Widget::~Widget()
{
    delete ui;
}

