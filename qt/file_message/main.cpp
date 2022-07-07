// widget 空窗口
//mainWindow 主窗口
//dialog 对话框
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // 管理信号与槽，管理QT中的事件响应
    QApplication a(argc, argv);
    Widget w; // 定义空窗口对象
    w.show(); // 显示窗口

    // 事件循环，不断的刷新窗口
    return a.exec();
}
