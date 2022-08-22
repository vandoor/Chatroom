#ifndef MAINUI_MIDBAR_H
#define MAINUI_MIDBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QtSql>
#include <QSqlTableModel>
#include <QMenu>
#include <QMenuBar>
#include <.\accountType\user.h>
#include "signalopt.h"
#include "global.h"
#include "mytoolbutton.h"
#include "notice.h"
#include "jsonoperator.h"

class MainUI_MidBar : public QWidget
{
    Q_OBJECT
public:
    explicit MainUI_MidBar(QWidget *parent = nullptr);

public slots:
    void addFriend();
    void buildGroup();
    void addNewGroup(QString groupID,QString groupName);
    void joinGroup();
    void toRecentConversation();
    void toFriendList();
    void toGroupList();
    void toSettings();
    void showNotice();
    void initRecentConversation();
    void initFriendList();
    void initGroupList();
    void search();
    void openConversation();
signals:

public slots:

private:
    QWidget *recentConversation;
    QListWidget *friendListWgt,*groupListWgt,*settings;

    QPushButton * searchPtn;
    QLineEdit * searchWho;
    QMenu * addMenu;
    QMenuBar * addMenuBar;
    QPushButton *toFriendListPbn,*toGroupListPbn;

    QString newGroupName;
    QString newGroupID;
    QString newGroupHead;

    Notice * notice;
    QVBoxLayout *recentConversationLayout;
    QVBoxLayout *friendListLayout;
    QVBoxLayout *groupListLayout;

    Global * global;
    SignalOpt *signalOpt;
    JsonOperator * jsonOperator;


    
signals:
    void openChatWindow(MyToolButton *);


};

#endif // MAINUI_MIDBAR_H
