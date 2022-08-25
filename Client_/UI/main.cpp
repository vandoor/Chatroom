#include "widget.h"
#include <QApplication>
#include <jsonoperator.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QFile qss(":/psblack1.css");
//    if( qss.open(QFile::ReadOnly))

//    {
//        qDebug()<<endl<<"open success";
//        QString style = QLatin1String(qss.readAll());
//        a.setStyleSheet(style);
//        qss.close();
//    }
//    else
//    {
//        qDebug()<<endl<<"Open failed";
//    }

    Widget w;
    w.show();
    w.hide();
    return a.exec();
}
