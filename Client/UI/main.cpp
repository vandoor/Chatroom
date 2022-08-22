#include "widget.h"
#include <QApplication>
#include <jsonoperator.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.hide();
    return a.exec();
}
