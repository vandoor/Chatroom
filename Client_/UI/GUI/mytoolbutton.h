#ifndef MYTOOLBUTTON_H
#define MYTOOLBUTTON_H
#include <QToolButton>
#include <QString>
#include <QMouseEvent>
#include <QMenu>
#include "global.h"

class MyToolButton : public QToolButton
{
    Q_OBJECT
public:
    MyToolButton(QWidget *parent = nullptr);
    QString getType();
    void setType(QString);
    void mousePressEvent(QMouseEvent * event);
public slots:
    void deleteFriend();
    void quitGroup();
    void kickoutGroupMember();
private:
    QString type;
    Global * global;
    SignalOpt * signalOpt;
signals:

};

#endif // MYTOOLBUTTON_H
