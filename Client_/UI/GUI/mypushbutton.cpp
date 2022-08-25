#include "mypushbutton.h"
#include <QDebug>
#include <QInputDialog>
#include <QMouseEvent>
MyPushButton::MyPushButton(QStringList iconList,QWidget *parent):
    QPushButton (parent)
{
    if(iconList.length()<3){
        qDebug()<<"myPushButton create error";
    }
    global = new Global();
    signalOpt = global->signalOpt;
    defaultIcon = iconList[0];
    inIcon = iconList[1];
    clickedIcon = iconList[2];
    mysize = QSize(40,40);
    setImage(defaultIcon);
}

void MyPushButton::enterEvent(QEvent *){
    if(type=="notice") return;
    this->setImage(inIcon);
}

void MyPushButton::leaveEvent(QEvent *){
    if(type=="notice") return;
    this->setImage(defaultIcon);
}

void MyPushButton::mousePressEvent(QMouseEvent *event){
    emit clicked();
    this->setImage(clickedIcon);
    if(type=="add"){
        QMenu *addMenu = new QMenu(this);
        addMenu->addAction("添加好友",this,SLOT(addFriend()));
        addMenu->addAction("加入群",this,SLOT(joinGroup()));
        addMenu->addAction("创建新群",this,SLOT(buildGroup()));
        qDebug()<<event->pos();
        addMenu->move(mapToGlobal(QPoint(0,40)));
        addMenu->show();
    }
}

void MyPushButton::mouseMoveEvent(QMouseEvent*){
    if(type=="notice") return;
    this->setImage(clickedIcon);
}


void MyPushButton::mouseReleaseEvent(QMouseEvent *){
    if(type=="notice") return;
    this->setImage(defaultIcon);
}
void MyPushButton::setMysize(QSize size){
    this->mysize=size;
    setImage(defaultIcon);
}

void MyPushButton::setImage(QString icon){
    QPixmap pixmap =QPixmap(icon);
    setIcon(QIcon(pixmap));
    setIconSize(mysize);
    setStyleSheet("border:none;");
}

void MyPushButton::addFriend(){
    signalOpt = global->signalOpt;
    QString friendID = QInputDialog::getText(this,tr("添加好友"),tr("请输入要添加好友的ID"));
    signalOpt->addFriend(global->UID,friendID);

}

void MyPushButton::buildGroup(){
    signalOpt = global->signalOpt;
    QString newGroupName = QInputDialog::getText(this,tr("创建群聊"),tr("请输入群名称"));
    signalOpt->buildGroup(global->UID,newGroupName);
}

void MyPushButton::joinGroup(){
    signalOpt = global->signalOpt;
    QString groupID = QInputDialog::getText(this,tr("加入群聊"),tr("请输入群ID"));
    signalOpt->joinGroup(global->UID,groupID);
}


