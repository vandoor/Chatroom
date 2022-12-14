#include "mainui_rightbar.h"
#include <QMessageBox>
#include <QFileDialog>

MainUI_RightBar::MainUI_RightBar(QWidget *parent) : QWidget(parent)
{
    global = new Global();
    signalOpt = global->signalOpt;
    jsonOperator = new JsonOperator();
    fileServer = new FileServer();

    //好友聊天标题
    friendInfoTitle = new QWidget(this);
    friendName = new QLabel("好友名称",friendInfoTitle);    //好友名字
    friendHead = new QLabel("好友头像",friendInfoTitle);    //头像
    friendInfoTitle->hide();

    //群聊天标题
    groupInfoTitle = new QWidget(this);  //整个rightBar的标题
    groupName = new QLabel("群名称",groupInfoTitle);    //群名字
    groupHead = new QLabel("群头像",groupInfoTitle);    //头像
    groupInfoTitle->hide();
    inviteFriendPbn = new QPushButton("邀请好友",groupInfoTitle);
    connect(inviteFriendPbn,&QPushButton::clicked,this,&MainUI_RightBar::inviteFriend);
    groupMemberListPbn = new QPushButton("群友列表",groupInfoTitle);
    connect(groupMemberListPbn,&QPushButton::clicked,this,&MainUI_RightBar::openFirstGroupMemberList);

    //聊天记录框
    textRecord = new TextRecord(this);
    textRecord->setFixedSize(this->width(),this->height()*96/156-80);
    textRecord->move(0,50);
    textRecord->hide();

    textScrollArea = new QScrollArea(this);
    textScrollArea->move(0,50);
    textScrollArea->setFixedSize(this->width(),this->height()*96/156-80);
    textScrollArea->setVisible(false);


    //工具栏
    menuBar = new QMenuBar(this);
    QMenu * emoji = new QMenu("发送表情包",this);
    emoji->addAction(QIcon(global->path+"emoji/"+"大哭.jpg"),"大哭",this,SLOT(sendDaku()));
    emoji->addAction(QIcon(global->path+"emoji/"+"害羞.jpg"),"害羞",this,SLOT(sendHaixiu()));
    emoji->addAction(QIcon(global->path+"emoji/"+"微笑.jpg"),"微笑",this,SLOT(sendWeixiao()));
    emoji->addAction(QIcon(global->path+"emoji/"+"气.jpg"),"气",this,SLOT(sendQi()));
    emoji->addAction(QIcon(global->path+"emoji/"+"装傻.jpg"),"装傻",this,SLOT(sendZhuangsha()));
    menuBar->addMenu(emoji);

    menuBar->addAction("发送文件",this,SLOT(sendFile()));
    menuBar->addAction("发送语音");
    menuBar->hide();

    //文本编辑栏
    textEdit = new QTextEdit(this);
    textEdit->hide();

    //发送文本按钮
    sendTextPbn = new QPushButton("发送",this);
    sendTextPbn->hide();
    connect(sendTextPbn,&QPushButton::clicked,this,&MainUI_RightBar::sendText);
    clearTextPbn = new QPushButton("清空",this);
    clearTextPbn->hide();
    connect(clearTextPbn,&QPushButton::clicked,this,[=](){
       textEdit->setText("");
    });
    //收到消息
    connect(signalOpt,&SignalOpt::receiveFriendText,this,[=](QString friendID,QString text){
        jsonOperator->addFriendRecord(0,friendID,1,text);
        jsonOperator->readFriendRecord(id);
        flashTextRecord();
    });

    connect(signalOpt,&SignalOpt::receiveGroupText,this,[=](QString groupID,QString groupMemberID,QString message){
        jsonOperator->addGroupRecord(0,groupID,groupMemberID,message);
        jsonOperator->readGroupRecord(id);
        flashTextRecord();
    });
    //收到表情包
    connect(signalOpt,&SignalOpt::receiveFriendEmoji,this,[=](QString friendID,QString index){
        jsonOperator->addFriendRecord(1,friendID,1,index);
        jsonOperator->readFriendRecord(id);
        flashTextRecord();
    });

    connect(signalOpt,&SignalOpt::receiveGroupEmoji,this,[=](QString groupID,QString groupMemberID,QString index){
        jsonOperator->addGroupRecord(1,groupID,groupMemberID,index);
        jsonOperator->readGroupRecord(id);
        flashTextRecord();
    });

    //发送消息失败
    connect(signalOpt,&SignalOpt::sendFriendTextUnsuccessfully,this,[=](){
        QString friendName = jsonOperator->findFriendName(friendID);
        QMessageBox::information(this,tr("发送消息失败"),QString("你发送给好友"+friendName+"("+friendID+")的消息发送失败，对方有可能会收不到信息哦"),tr("确认"));
    });
    connect(signalOpt,&SignalOpt::sendGroupTextUnsuccessfully,this,[=](){
        QString groupName = jsonOperator->findGroupName(groupID);
        QMessageBox::information(this,tr("发送消息失败"),QString("你发送到群聊"+groupName+"("+groupID+")的消息发送失败，对方有可能会收不到信息哦"),tr("确认"));
    });

    //收到群成员列表
    connect(signalOpt,&SignalOpt::receiveGroupMemberList,this,[=](QString groupID,int groupMemberNum,QJsonArray groupMemberList){
       jsonOperator->setGroupMemberList(groupID,groupMemberNum,groupMemberList);
       jsonOperator->readGroupMemberList(groupID);
       emit flashGroupMemberList();
       openGroupMemberList();
    });
    initTextScrollBar();

}

void MainUI_RightBar::openChatWindow(MyToolButton * sender){
    //标题内容
    type = sender->getType();
    id = sender->objectName();
    if(type=="friend"){
        friendName->setText(sender->text());
        QPixmap pixmap = QPixmap(sender->icon().pixmap(25,25));
        //    pixmap=pixmap.scaled(this->size().width()*1/2,this->size().width()*1/2,Qt::IgnoreAspectRatio);
        friendHead->setPixmap(pixmap);
        //标题位置
        friendInfoTitle->setFixedSize(this->width(),50);
        friendHead->setFixedSize(25,25);
        friendHead->move(10,10);
        friendName->setFixedSize(this->width()*8/10,friendName->height());
        friendName->move(10+friendHead->width()+5,10);
        friendID = sender->objectName();
        friendInfoTitle->show();
        groupInfoTitle->hide();
    }
    else if(type=="group"){
        groupName->setText(sender->text());
        QPixmap pixmap = QPixmap(sender->icon().pixmap(25,25));
        //    pixmap=pixmap.scaled(this->size().width()*1/2,this->size().width()*1/2,Qt::IgnoreAspectRatio);
        groupHead->setPixmap(pixmap);
        //标题位置
        groupInfoTitle->setFixedSize(this->width(),50);
        groupHead->setFixedSize(25,25);
        groupHead->move(10,10);
        groupName->setFixedSize(this->width()*5/10,groupName->height());
        groupName->move(10+groupHead->width()+5,10);
        inviteFriendPbn->setStyleSheet("border:1px solid black;border-radius:4px");
        inviteFriendPbn->move(this->width()-75,10);
        inviteFriendPbn->setFixedSize(70,30);
        groupMemberListPbn->setStyleSheet("border:1px solid black;border-radius:4px");
        groupMemberListPbn->move(this->width()-150,10);
        groupMemberListPbn->setFixedSize(70,30);
        groupID = sender->objectName();
        global->nowGroupID = groupID;
        friendInfoTitle->hide();
        groupInfoTitle->show();
    }

    //聊天记录框
    if(type=="friend"){
        jsonOperator->readFriendRecord(id);
    }
    else{
        jsonOperator->readGroupRecord(id);
    }
    flashTextRecord();
    //工具栏
    menuBar->move(0,this->height()*96/156-30);
    menuBar->setFixedSize(this->width(),30);
    //文本编辑栏
    textEdit->move(0,this->height()*96/156);
    textEdit->setFixedSize(this->width(),this->height()-this->height()*96/156);

    //文本发送按钮
    sendTextPbn->setStyleSheet("border:1px solid black;border-radius:4px");
    sendTextPbn->move(this->width()-70,this->height()-40);
    sendTextPbn->setFixedSize(50,30);
    //文本清空按钮
    clearTextPbn->setStyleSheet("border:1px solid black;border-radius:4px");
    clearTextPbn->move(this->width()-130,this->height()-40);
    clearTextPbn->setFixedSize(50,30);

    //显示

    textRecord->show();
    menuBar->show();
    textEdit->show();
    sendTextPbn->show();
    clearTextPbn->show();

}


void MainUI_RightBar::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);
//    qDebug()<<this->width()<<this->height();
    friendInfoTitle->setFixedSize(this->width(),50);
    friendHead->setFixedSize(25,25);
    friendHead->move(10,10);
    friendName->setFixedSize(this->width()*8/10,friendName->height());
    friendName->move(10+friendHead->width()+5,10);
    groupInfoTitle->setFixedSize(this->width(),50);
    groupHead->setFixedSize(25,25);
    groupHead->move(10,10);
    groupName->setFixedSize(this->width()*5/10,groupName->height());
    groupName->move(10+groupHead->width()+5,10);
    inviteFriendPbn->move(this->width()-75,10);
    groupMemberListPbn->move(this->width()-150,10);
    textScrollArea->setFixedSize(this->width(),this->height()*96/156-80);
    menuBar->move(0,this->height()*96/156-30);
    menuBar->setFixedSize(this->width(),30);
    textEdit->move(0,this->height()*96/156);
    textEdit->setFixedSize(this->width(),this->height()-this->height()*96/156);
    sendTextPbn->move(this->width()-70,this->height()-40);
    clearTextPbn->move(this->width()-130,this->height()-40);
}

void MainUI_RightBar::sendText(){
    signalOpt = global->signalOpt;
    QString text = textEdit->toPlainText();
    textEdit->setText("");
    if(text=="") return ;
    if(type=="friend") {
        signalOpt->friendChat(global->UID,friendID,text);
        jsonOperator->addFriendRecord(0,friendID,0,text);
        jsonOperator->readFriendRecord(id);
        flashTextRecord();
    }
    else if(type=="group"){
        signalOpt->groupChat(global->UID,groupID,text);
//        jsonOperator->addGroupRecord(groupID,global->UID,text);
//        jsonOperator->readGroupRecord(id);
//        flashTextRecord();
    }
}
void MainUI_RightBar::sendDaku(){sendEmoji("大哭");}
void MainUI_RightBar::sendHaixiu(){sendEmoji("害羞");}
void MainUI_RightBar::sendWeixiao(){sendEmoji("微笑");}
void MainUI_RightBar::sendQi(){sendEmoji("气");}
void MainUI_RightBar::sendZhuangsha(){sendEmoji("装傻");}




void MainUI_RightBar::sendEmoji(QString index){
    if(type=="friend"){
        signalOpt->sendFriendEmoji(global->UID,friendID,index);
        jsonOperator->addFriendRecord(1,friendID,0,index);
        jsonOperator->readFriendRecord(friendID);
        flashTextRecord();
    }
    else {
        signalOpt->sendGroupEmoji(global->UID,groupID,index);
    }
}


void MainUI_RightBar::sendFile(){
    QString file = QFileDialog::getOpenFileUrl(this,tr("选择要发送的文件"),QUrl("D:/"),"").toString();
    qDebug()<<file.right(file.length()-8);
    fileServer->sendFile(file.right(file.length()-8),global->UID,id);
    connect(fileServer,&FileServer::fileSendSuccessfully,this,[=](){
       QMessageBox::information(this,tr("传输文件成功"),QString("文件传输成功"));
    });
}

void MainUI_RightBar::inviteFriend(){
    signalOpt = global->signalOpt;
    QString invitedFriendID = QInputDialog::getText(this,tr("邀请好友"),tr("请输入要邀请好友的ID"));
    signalOpt->inviteGroup(global->UID,invitedFriendID,groupID);
}

void MainUI_RightBar::openFirstGroupMemberList(){
    signalOpt->getGroupMemberList(groupID);
    openGroupMemberList();
}

void MainUI_RightBar::openGroupMemberList(){
    jsonOperator->readGroupMemberList(id);
    QWidget *groupMemberWgt = new QWidget(nullptr);
    QVBoxLayout *groupMemberLayout = new QVBoxLayout(groupMemberWgt);
    groupMemberWgt->setWindowTitle("群成员列表");
    groupMemberWgt->show();
    QList<QString> *groupMemberIDList,*groupMemberNameList,*groupMemberHeadList;
    groupMemberIDList = global->GroupMemberIDList;
    groupMemberNameList = global->GroupMemberNameList;
    groupMemberHeadList = global->GroupMemberHeadList;
    int n = groupMemberIDList->length();
    for(int i=0;i<n;i++){
        MyToolButton* toolbtn = new MyToolButton(groupMemberWgt);
        toolbtn->setIconSize(QSize(40,40));
        toolbtn->setType("groupMember");
        toolbtn->setObjectName((*groupMemberIDList)[i]);  //按键名为id
        toolbtn->setStyleSheet("QToolButton{color:rgb(0,0,0);border:none;font-size:20px;}");
        toolbtn->setIcon(QIcon((global->path+"Head/"+(*groupMemberHeadList)[i])));
        toolbtn->setText(" "+(*groupMemberNameList)[i]);
        toolbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
//        connect(toolbtn,&QToolButton::clicked,this,&MainUI_MidBar::openConversation);
        groupMemberLayout->addWidget(toolbtn);
    }
    groupMemberLayout->addStretch();
    connect(this,&MainUI_RightBar::flashGroupMemberList,groupMemberWgt,&QWidget::close);
}

void MainUI_RightBar::flashTextRecord(){
    delete textRecord;
    textRecord = new TextRecord(this);
    textRecord->setFixedSize(this->width()-30,this->height()*96/156-80);
    textRecord->move(0,50);
    textScrollArea = new QScrollArea(this);
    textScrollArea->move(0,50);
    textScrollArea->setFixedSize(this->width(),this->height()*96/156-80);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/bubble/Icon/chatBackground.jpg").scaled(QSize(textScrollArea->width(),textScrollArea->height()))));
    textScrollArea->setAutoFillBackground(true);
    textScrollArea->setPalette(palette);
    QList<int> *RecordNote;
    QList<QString> *RecordText,*RecordUID,*RecordTime;
    RecordNote = global->RecordNote;
    RecordText = global->RecordText;
    RecordUID = global->RecordUID;
    RecordTime = global->RecordTime;
    int n = RecordUID->length();
    int nowHeight =0;
    for(int i=0;i<n;i++){
        QLabel * label1 = new QLabel(textRecord);
        QLabel * label2 = new QLabel(textRecord);
        QString time = QString("");
        QString recordtime = (*RecordTime)[i];
        time.append(recordtime.left(4)+"年"+recordtime.mid(4,2)+"月"+recordtime.mid(6,2)+"日");
        time.append(recordtime.mid(8,2)+":"+recordtime.mid(10,2)+":"+recordtime.mid(12,2));
        if((*RecordNote)[i]==1){
            QPixmap pixmap = QPixmap(global->path+"emoji/"+(*RecordText)[i]+".jpg");
            pixmap=pixmap.scaled(40,40,Qt::IgnoreAspectRatio);
            label2->setPixmap(pixmap);
        }
        else {
            label2->setText("\n  "+(*RecordText)[i]+" \b\n");
            label2->adjustSize();
        }
        QPalette pal;
        if((*RecordUID)[i]==global->UID) pal.setBrush(QPalette::Background,QBrush(QPixmap(":/bubble/Icon/myBubble.jpg").scaled(QSize(label2->width(),label2->height()))));
        else pal.setBrush(QPalette::Background,QBrush(QPixmap(":/bubble/Icon/otherBubble.jpg").scaled(QSize(label2->width(),label2->height()))));
        label2->setAutoFillBackground(true);
        label2->setPalette(pal);
        if((*RecordUID)[i]==global->UID){
            label1->setText(global->UName+"  "+time);
            label1->setStyleSheet("color: rgb(0, 203, 0);");
        }
        else if(type=="friend") label1->setText(jsonOperator->findFriendName((*RecordUID)[i])+"  "+time);
        else label1->setText(jsonOperator->findGroupMemberName(groupID,(*RecordUID)[i])+"  "+time);
        label1->adjustSize();

        if((*RecordUID)[i]==global->UID){
            label1->move(this->width()-label1->width()-40,nowHeight);
            nowHeight+=label1->height();
            label2->move(this->width()-label2->width()-40,nowHeight);
        }
        else{
            label1->move(5,nowHeight);
            nowHeight+=label1->height();
            label2->move(5,nowHeight);
        }
        nowHeight+=label2->height();
        nowHeight+=20;
    }
    textRecord->setMaximumWidth(this->width()-25);
    textRecord->adjustSize();
    textRecord->setFixedWidth(this->width()-30);
    textRecord->setMinimumHeight(nowHeight);
    textScrollArea->setWidget(textRecord);
    textScrollArea->show();
}

void MainUI_RightBar::initTextScrollBar(){
    textScrollArea->hide();
}
