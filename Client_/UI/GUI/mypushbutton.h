#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
#include <QMenu>
#include "signalopt.h"
#include "global.h"
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QStringList iconList,QWidget* parent = nullptr);

public slots:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setImage(QString icon);
    void setType(QString type){this->type = type;}
    void setMysize(QSize size);
    void addFriend();
    void buildGroup();
    void joinGroup();

private:
    QString defaultIcon,inIcon,clickedIcon;
    QString type;
    QSize mysize;
    Global * global;
    SignalOpt *signalOpt;

};

#endif // MYPUSHBUTTON_H
