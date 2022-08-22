#ifndef MAINUI_RIGHTBAR_H
#define MAINUI_RIGHTBAR_H

#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include <QTextEdit>
#include <QToolBar>
#include <QPushButton>
#include <QVBoxLayout>
#include "signalopt.h"
#include "global.h"
#include "mytoolbutton.h"
#include "qinputdialog.h"
#include "jsonoperator.h"

class MainUI_RightBar : public QWidget
{
    Q_OBJECT
public:
    explicit MainUI_RightBar(QWidget *parent = nullptr);
    void openChatWindow(MyToolButton *);
    void inviteFriend();
    void flashTextRecord();

public slots:
    void resizeEvent(QResizeEvent *);
    void sendText();
    void groupMemberList();
private:
    QString type;
    QString id;

    QWidget * friendInfoTitle;  //整个rightBar的标题
    QLabel * friendName;    //好友名字
    QLabel * friendHead;    //头像
    QString friendID;

    QWidget * groupInfoTitle;  //整个rightBar的标题
    QLabel * groupName;    //群名字
    QLabel * groupHead;    //头像
    QPushButton * inviteFriendPbn;
    QPushButton * groupMemberListPbn;
    QString groupID;

    QWidget * textRecord;
    QVBoxLayout * textRecordLayout;

    QToolBar * toolBar;
    QTextEdit * textEdit;
    QPushButton * sendTextPbn;

    Global * global;
    SignalOpt * signalOpt;
    JsonOperator * jsonOperator;


signals:

};

#endif // MAINUI_RIGHTBAR_H


