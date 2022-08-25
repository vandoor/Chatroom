#ifndef MAINUI_RIGHTBAR_H
#define MAINUI_RIGHTBAR_H

#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include <QTextEdit>
#include <QToolBar>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPalette>
#include <QScrollBar>
#include <QScrollArea>
#include "signalopt.h"
#include "global.h"
#include "mytoolbutton.h"
#include "qinputdialog.h"
#include "jsonoperator.h"
#include "fileserver.h"
#include "textrecord.h"

class MainUI_RightBar : public QWidget
{
    Q_OBJECT
public:
    explicit MainUI_RightBar(QWidget *parent = nullptr);
    void openChatWindow(MyToolButton *);
    void inviteFriend();
    void flashTextRecord();
    void initTextScrollBar();

public slots:
    void resizeEvent(QResizeEvent *);
    void sendText();
    void openGroupMemberList();
    void openFirstGroupMemberList();
    void sendFile();
    void sendEmoji(QString index);
    void sendDaku();
    void sendHaixiu();
    void sendWeixiao();
    void sendQi();
    void sendZhuangsha();
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

    TextRecord * textRecord;
    QScrollArea * textScrollArea;

    QMenuBar * menuBar;
    QTextEdit * textEdit;
    QPushButton * clearTextPbn;
    QPushButton * sendTextPbn;

    Global * global;
    SignalOpt * signalOpt;
    JsonOperator * jsonOperator;
    FileServer *fileServer;


signals:
    void flashGroupMemberList();
};

#endif // MAINUI_RIGHTBAR_H


