#include "mainui.h"
#include "ui_mainui.h"
#include <QDebug>

MainUI::MainUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainUI)
{
    ui->setupUi(this);
    ui->menubar->hide();
    //三个bar + 一个消息框
    leftBar = new MainUI_LeftBar(this);
    midBar = new MainUI_MidBar(this);
    rightBar = new MainUI_RightBar(this);


    this->setMinimumSize(800,500);
    //设置一下三个框的大小以及位置
    leftBar->setFixedSize(QSize(80,this->height()));
    midBar->move(80,0);
    midBar->setFixedSize(QSize(240,this->height()));
    rightBar->move(320,0);
    rightBar->setFixedSize(QSize(this->width()-320,this->height()));
    //用户点击leftBar相关按钮
    connect(leftBar,&MainUI_LeftBar::toSettings,midBar,&MainUI_MidBar::toSettings);
    connect(leftBar,&MainUI_LeftBar::toFriendList,midBar,&MainUI_MidBar::toFriendList);
    connect(leftBar,&MainUI_LeftBar::toRecentConversation,midBar,&MainUI_MidBar::toRecentConversation);


    //用户点击midBar相应好友栏弹出相关界面
    connect(midBar,&MainUI_MidBar::openChatWindow,rightBar,&MainUI_RightBar::openChatWindow);
    qDebug()<<leftBar->size().height()<<this->height();

}

MainUI::~MainUI()
{
    delete ui;
}


void MainUI::setUID(QString str){
    UID.append(str);
}

void MainUI::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);
//    qDebug()<<this->width()<<this->height();
    leftBar->setFixedSize(QSize(80,this->height()));
    midBar->setFixedSize(QSize(240,this->height()));
    rightBar->setFixedSize(QSize(this->width()-320,this->height()));
}





