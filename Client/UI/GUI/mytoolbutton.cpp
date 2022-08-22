#include "mytoolbutton.h"

MyToolButton::MyToolButton(QWidget *parent):
    QToolButton (parent)
{
    type = QString("");
    global = new Global();
    signalOpt = global->signalOpt;
}


void MyToolButton::setType(QString Type){
    type=Type;
}

QString MyToolButton::getType(){
    return type;
}

void MyToolButton::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton){
        QMenu *menu = new QMenu(this);
        menu->move(mapToGlobal(event->pos()));
        if(type=="friend") menu->addAction("删除好友",this,SLOT(deleteFriend()));
        else if(type=="group") menu->addAction("退群",this,SLOT(quitGroup()));
        else if(type=="groupMember") menu->addAction("踢出去",this,SLOT(kickoutGroupMember()));
        menu->show();
    }
    else emit clicked();
}

void MyToolButton::deleteFriend(){
    signalOpt->deleteFriend(global->UID,objectName());
}
void MyToolButton::quitGroup(){
    signalOpt->leaveGroup(global->UID,objectName());
}

void MyToolButton::kickoutGroupMember(){
    signalOpt->kickoutGroup(global->UID,objectName(),global->nowGroupID);
}
