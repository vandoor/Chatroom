#include "notice.h"
#include "ui_notice.h"

Notice::Notice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Notice)
{
    ui->setupUi(this);

    global = new Global();
    signalOpt = global->signalOpt;
    jsonOperator = new JsonOperator();

    widget =new QWidget(this);
    widgetLayout = new QVBoxLayout(widget);
    //好友申请的回复
    connect(signalOpt,&SignalOpt::askFriend,this,[=](QString friendID,QString friendName){
        NoticeItem *noticeItem = new NoticeItem(widget);
        noticeItem->setType("askFriend");
        noticeItem->setInfo(friendID,friendName,"","");
        noticeItem->resetButton();
        widgetLayout->addWidget(noticeItem);
        widgetLayout->addStretch();
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="agree"){
                widgetLayout->removeWidget(noticeItem);
                signalOpt->acceptFriend(1,friendID,global->UID);
                widgetLayout->addStretch();
                emit agreeNewFriend(friendID,friendName);
                noticeItem->hide();
            }
            else if(signal=="disagree"){
                widgetLayout->removeWidget(noticeItem);
                signalOpt->acceptFriend(0,friendID,global->UID);
                widgetLayout->addStretch();
                noticeItem->hide();
            }
        });
    });
    //入群申请的回复
    connect(signalOpt,&SignalOpt::askJoinGroup,this,[=](QString senderID,QString groupID,QString groupName){
        NoticeItem *noticeItem = new NoticeItem(widget);
        noticeItem->setType("askJoinGroup");
        noticeItem->setInfo(senderID,"",groupID,groupName);
        noticeItem->resetButton();
        widgetLayout->addWidget(noticeItem);
        widgetLayout->addStretch();
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="agree"){
                widgetLayout->removeWidget(noticeItem);
                signalOpt->approveEnterGroup(1,senderID, groupID);
                noticeItem->hide();
            }
            else if(signal=="disagree"){
                widgetLayout->removeWidget(noticeItem);
                signalOpt->approveEnterGroup(0,senderID, groupID);
                noticeItem->hide();
            }
        });
    });
    //受邀加入群聊请求的回复
    connect(signalOpt,&SignalOpt::askInviteGroup,this,[=](QString senderID,QString groupID,QString groupName){
        qDebug()<<"askInviteGroup";
        NoticeItem *noticeItem = new NoticeItem(widget);
        noticeItem->setType("askInviteGroup");
        noticeItem->setInfo(senderID,"",groupID,groupName);
        noticeItem->resetButton();
        widgetLayout->addWidget(noticeItem);
        widgetLayout->addStretch();
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="agree"){
                widgetLayout->removeWidget(noticeItem);
                signalOpt->acceptInviteGroup(senderID, global->UID, groupID);
                noticeItem->hide();
            }
            else if(signal=="disagree"){
                widgetLayout->removeWidget(noticeItem);
                noticeItem->hide();
            }
        });
    });
    //被删除好友的消息
    connect(signalOpt,&SignalOpt::loseFriend,this,[=](QString loseID){
        NoticeItem *noticeItem = new NoticeItem(widget);
        noticeItem->setType("loseFriend");
        QString loseName = jsonOperator->findFriendName(loseID);
        jsonOperator->removeFriendFromList(loseID);
        noticeItem->setInfo(loseID,loseName,"","");
        noticeItem->resetButton();
        emit flashFriendList();
        widgetLayout->addWidget(noticeItem);
        widgetLayout->addStretch();
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="know"){
                widgetLayout->removeWidget(noticeItem);
                noticeItem->hide();
            }
        });
    });
    //被踢出群聊的消息
    connect(signalOpt,&SignalOpt::kickedFromGroup,this,[=](QString adminID,QString groupID){
        NoticeItem *noticeItem = new NoticeItem(widget);
        noticeItem->setType("kickedoutFromGroup");
        QString groupName = jsonOperator->findGroupName(groupID);
        jsonOperator->removeGroupFromList(groupID);
        noticeItem->setInfo(adminID,"",groupID,groupName);
        noticeItem->resetButton();
        emit flashGroupList();
        widgetLayout->addWidget(noticeItem);
        widgetLayout->addStretch();
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="know"){
                widgetLayout->removeWidget(noticeItem);
                noticeItem->hide();
            }
        });
    });


}

Notice::~Notice()
{
    delete ui;
}
