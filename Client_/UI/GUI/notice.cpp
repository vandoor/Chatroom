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
    this->setMinimumSize(400,400);
    this->resize(this->minimumSize());

    //好友申请的回复
    connect(signalOpt,&SignalOpt::askFriend,this,[=](QString friendID,QString friendName){
        NoticeItem *noticeItem = new NoticeItem(this);
        noticeItem->setType("askFriend");
        noticeItem->setMinimumSize(500,100);
        noticeItem->resize(500,100);
        noticeItem->setInfo(friendID,friendName,"","");
        noticeItem->resetButton();
        item.append(noticeItem);
        noticeItem->show();
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="agree"){
                signalOpt->acceptFriend(1,friendID,global->UID);
                emit agreeNewFriend(friendID,friendName);
                item.removeOne(noticeItem);
                noticeItem->hide();
            }
            else if(signal=="disagree"){
                signalOpt->acceptFriend(0,friendID,global->UID);
                item.removeOne(noticeItem);
                noticeItem->hide();
            }
            resetNotice();
        });
        resetNotice();
    });
    //入群申请的回复
    connect(signalOpt,&SignalOpt::askJoinGroup,this,[=](QString senderID,QString groupID,QString groupName){
        NoticeItem *noticeItem = new NoticeItem(this);
        noticeItem->setType("askJoinGroup");
        noticeItem->setMinimumSize(500,100);
        noticeItem->resize(500,100);
        noticeItem->setInfo(senderID,"",groupID,groupName);
        noticeItem->resetButton();
        item.append(noticeItem);
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="agree"){
                signalOpt->approveEnterGroup(1,senderID, groupID);
                item.removeOne(noticeItem);
                noticeItem->hide();
            }
            else if(signal=="disagree"){
                signalOpt->approveEnterGroup(0,senderID, groupID);
                item.removeOne(noticeItem);
                noticeItem->hide();
            }
            resetNotice();
        });
        resetNotice();
    });
    //受邀加入群聊请求的回复
    connect(signalOpt,&SignalOpt::askInviteGroup,this,[=](QString senderID,QString groupID,QString groupName){
        qDebug()<<"askInviteGroup";
        NoticeItem *noticeItem = new NoticeItem(this);
        noticeItem->setType("askInviteGroup");
        noticeItem->setMinimumSize(500,100);
        noticeItem->resize(500,100);
        noticeItem->setInfo(senderID,"",groupID,groupName);
        noticeItem->resetButton();
        item.append(noticeItem);
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="agree"){
                signalOpt->acceptInviteGroup(senderID, global->UID, groupID);
                item.removeOne(noticeItem);
                noticeItem->hide();
            }
            else if(signal=="disagree"){
                item.removeOne(noticeItem);
                noticeItem->hide();
            }
            resetNotice();
        });
        resetNotice();
    });
    //被删除好友的消息
    connect(signalOpt,&SignalOpt::loseFriend,this,[=](QString loseID){
        NoticeItem *noticeItem = new NoticeItem(this);
        noticeItem->setType("loseFriend");
        noticeItem->setMinimumSize(500,100);
        noticeItem->resize(500,100);
        QString loseName = jsonOperator->findFriendName(loseID);
        jsonOperator->removeFriendFromList(loseID);
        noticeItem->setInfo(loseID,loseName,"","");
        noticeItem->resetButton();
        item.append(noticeItem);
        emit flashFriendList();
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="know"){
                item.removeOne(noticeItem);
                noticeItem->hide();
            }
            resetNotice();
        });
        resetNotice();
    });
    //被踢出群聊的消息
    connect(signalOpt,&SignalOpt::kickedFromGroup,this,[=](QString adminID,QString groupID){
        NoticeItem *noticeItem = new NoticeItem(this);
        noticeItem->setType("kickedoutFromGroup");
        noticeItem->setMinimumSize(500,100);
        noticeItem->resize(500,100);
        QString groupName = jsonOperator->findGroupName(groupID);
        jsonOperator->removeGroupFromList(groupID);
        noticeItem->setInfo(adminID,"",groupID,groupName);
        noticeItem->resetButton();
        item.append(noticeItem);
        emit flashGroupList();
        connect(noticeItem,&NoticeItem::sendsignal,this,[=](QString signal){
            if(signal=="know"){
                item.removeOne(noticeItem);
                noticeItem->hide();
            }
            resetNotice();
        });
        resetNotice();
    });
}

void Notice::resetNotice(){
    int nowHeight=5;
    for(int i=0;i<item.length();i++){
        item[i]->move(0,nowHeight);
        item[i]->show();
        item[i]->resize(500,100);
        nowHeight+=item[i]->height();
    }
    if(item.length()*50>this->height()) this->resize(this->width(),item.length()*50+10);
    else this->resize(400,400);
    return ;
}


Notice::~Notice()
{
    delete ui;
}
