#include "widget.h"

#include <QApplication>

// 信号触 发槽做出响应的响应
// 信号 只需声明 无需实现

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
