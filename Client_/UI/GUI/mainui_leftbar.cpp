#include "mainui_leftbar.h"

#include <QPalette>
#include <QPixmap>
#include <QDebug>


MainUI_LeftBar::MainUI_LeftBar(QWidget *parent) : QWidget(parent)
{
    global = new Global();
    //signalOpt = global->signalOpt;

    QStringList tmp;
    tmp << ":/leftBar/Icon/chat.png"
        << ":/leftBar/Icon/chat2.png"
        << ":/leftBar/Icon/chat3.png";
    recentConversation=new MyPushButton(tmp,this);
    tmp.clear();

    tmp << ":/leftBar/Icon/contact.png"
        << ":/leftBar/Icon/contact2.png"
        << ":/leftBar/Icon/contact3.png";
    friendList = new MyPushButton(tmp,this);
    tmp.clear();

    tmp << ":/leftBar/Icon/settings.png"
        << ":/leftBar/Icon/settings2.png"
        << ":/leftBar/Icon/settings3.png";
    settings = new MyPushButton(tmp,this);

    headPhoto = new QLabel(this);
    //头像
    headPhoto->move(20,15);
    QPixmap pixmap = QPixmap(":/leftBar/jiuge.jpg");
    pixmap=pixmap.scaled(40,40,Qt::IgnoreAspectRatio);
    headPhoto->setPixmap(pixmap);
    headPhoto->show();
    recentConversation->setFixedSize(40,40);
    friendList->setFixedSize(40,40);
    settings->setFixedSize(40,40);

    recentConversation->move(20,80);
    friendList->move(20,130);
    settings->move(20,180);
    
    //背景色
    QPalette palette;
    palette.setColor(QPalette::Background,QColor("#8696a7"));
    setAutoFillBackground(true);
    setPalette(palette);

    connect(recentConversation,&MyPushButton::clicked,this,[=](){
        qDebug()<<"toRecentConversation";
        emit toRecentConversation();
    });
    connect(friendList,&MyPushButton::clicked,this,[=](){
        emit toFriendList();
    });
    connect(settings,&MyPushButton::clicked,this,[=](){
        emit toSettings();
    });
}

void MainUI_LeftBar::resizeEvent(QResizeEvent *event){


}
