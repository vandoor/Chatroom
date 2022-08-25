#include "noticeitem.h"
#include <QDebug>
NoticeItem::NoticeItem(QWidget *parent) :QWidget(parent)
{
    jsonOperator = new JsonOperator();
    agree = new QPushButton("同意",this);
    disagree = new QPushButton("拒绝",this);
    know = new QPushButton("知道了",this);
    this->setMinimumSize(800,50);
    connect(agree,&QPushButton::clicked,this,[=](){
        emit sendsignal("agree");
    });
    connect(disagree,&QPushButton::clicked,this,[=](){
        qDebug()<<"disagree";
        emit sendsignal("disagree");
    });
    connect(know,&QPushButton::clicked,this,[=](){
        emit sendsignal("know");
    });
}

void NoticeItem::setInfo(QString friendID, QString friendName,QString groupID,QString groupName){
    if(type=="askFriend"){
        this->friendID = friendID;
        this->friendName = friendName;
    }
    else if(type=="askJoinGroup"){
        this->friendID = friendID;
        this->groupID = groupID;
        this->groupName = groupName;
    }
    else if(type=="askInviteGroup"){
        this->friendID = friendID;
        this->groupID = groupID;
        this->groupName = groupName;
    }
    else if(type=="loseFriend"){
        this->friendID = friendID;
        this->friendName = friendName;
    }
    else if(type=="kickedoutFromGroup"){
        this->friendID = friendID;
        this->groupID = groupID;
        this->groupName = groupName;
    }

}

void NoticeItem::resetButton(){
    if(type=="askFriend"){
        //添加好友请求
        noticeText = new QLabel(friendName+"("+friendID+")请求添加您为好友",this);
        noticeText->adjustSize();
        noticeText->show();
        agree->show();
        disagree->show();
        know->hide();
    }
    else if(type=="askJoinGroup"){
        //申请进群请求
        noticeText = new QLabel("用户"+tr("(")+friendID+")请求进入群聊\""+groupName+"\"("+groupID+")",this);
        noticeText->adjustSize();
        noticeText->show();
        agree->show();
        disagree->show();
        know->hide();
    }
    else if(type=="askInviteGroup"){
        //受邀入群请求
        noticeText = new QLabel("用户"+tr("(")+friendID+")邀请您进入群聊\""+groupName+"\"("+groupID+")",this);
        noticeText->adjustSize();
        noticeText->show();
        agree->show();
        disagree->show();
        know->hide();
    }
    else if(type=="loseFriend"){
        //被删除好友通知
        noticeText = new QLabel("用户\""+friendName+tr("\"(")+friendID+")已经将你从好友列表里删除啦!",this);
        noticeText->adjustSize();
        noticeText->show();
        agree->hide();
        disagree->hide();
        know->show();
    }
    else if(type=="kickedoutFromGroup"){
        //被踢出群聊通知
        noticeText = new QLabel("群\""+groupName+tr("\"(")+groupID+")的管理员("+friendID+")已经将你从群成员列表里删除啦!",this);
        noticeText->adjustSize();
        noticeText->show();
        agree->hide();
        disagree->hide();
        know->show();
    }
    else return ;

    qDebug()<<noticeText->text();
    noticeText->move(100,10);
    noticeText->setMinimumSize(700,20);
    noticeText->resize(700,20);
    disagree->move(300-disagree->width()-5,noticeText->height()+15);
    agree->move(300-disagree->width()-5-agree->width()-5,noticeText->height()+15);
    know->move(300-know->width()-5,noticeText->height()+15);
}


