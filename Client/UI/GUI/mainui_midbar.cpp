#include "mainui_midbar.h"
#include <QDebug>
#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QApplication>
#include <QFont>
MainUI_MidBar::MainUI_MidBar(QWidget *parent) : QWidget(parent)
{
    global = new Global();
    signalOpt = global->signalOpt;
    jsonOperator = new JsonOperator();
    fileServer = new FileServer;

    //调背景色
    QPalette palette;
    palette.setColor(QPalette::Background,QColor("#c1cbd7"));
    setAutoFillBackground(true);
    setPalette(palette);
    //搜索栏

    QStringList tmp;
    tmp <<":/midBar/Icon/search.png"
        <<":/midBar/Icon/search.png"
        <<":/midBar/Icon/search.png";

    searchWho = new QLineEdit(this);
    searchPtn = new MyPushButton(tmp,this);
    tmp.clear();
    searchWho->setStyleSheet("border-radius:4px");
    searchWho->move(10,5);
    searchWho->resize(220,30);
    searchPtn->setMysize(QSize(30,30));
    searchPtn->move(200,5);


    //近期消息界面
    recentConversation = new QWidget(this);
    recentConversationLayout = new QVBoxLayout(recentConversation);
    recentConversation->hide();

    //好友列表界面
    friendListWgt = new QWidget(this);
    friendListLayout = new QVBoxLayout(friendListWgt);
    friendListWgt->hide();


    tmp << ":/midBar/Icon/friend.png"
        << ":/midBar/Icon/friend2.png"
        << ":/midBar/Icon/friend3.png";
    toFriendListPbn = new MyPushButton(tmp,this);
    tmp.clear();
    toFriendListPbn->hide();
    toFriendListPbn->move(10,40);
    connect(toFriendListPbn,&QPushButton::clicked,this,&MainUI_MidBar::toFriendList);

    //群列表界面
    groupListWgt = new QWidget(this);
    groupListLayout = new QVBoxLayout(groupListWgt);
    groupListWgt->hide();
    tmp << ":/midBar/Icon/group.png"
        << ":/midBar/Icon/group2.png"
        << ":/midBar/Icon/group3.png";
    toGroupListPbn = new MyPushButton(tmp,this);
    tmp.clear();

    toGroupListPbn->hide();
    toGroupListPbn->move(70,40);
    connect(toGroupListPbn,&QPushButton::clicked,this,&MainUI_MidBar::toGroupList);
    //添加按钮
    tmp << ":/midBar/Icon/add.png"
        << ":/midBar/Icon/add2.png"
        << ":/midBar/Icon/add3.png";
    addPbn = new MyPushButton(tmp,this);
    tmp.clear();
    addPbn->setType("add");
    addPbn->move(190,40);

    //消息按钮
    tmp << ":/midBar/Icon/notice.png"
        << ":/midBar/Icon/newmsg.png"
        << ":/midBar/Icon/notice.png";
    noticePbn = new MyPushButton(tmp,this);
    tmp.clear();
    noticePbn->setType("notice");
    noticePbn->move(130,40);
    notice = new Notice(nullptr);
    connect(noticePbn,&MyPushButton::clicked,this,&MainUI_MidBar::showNotice);

    toFriendListPbn->show();
    toGroupListPbn->show();
    addPbn->show();
    noticePbn->show();

    recentConversation->move(0,90);
    friendListWgt->move(0,90);
    groupListWgt->move(0,90);


    //创建群聊成功
    connect(signalOpt,&SignalOpt::createGroupSuccessfully,this,[=](QString groupID){
        QString info;
        info.append(tr("分配给您的群聊ID为:"));
        info.append(groupID);
        info.append(tr(",请您记好"));
        QMessageBox::information(nullptr,tr("新建群聊成功"),info,tr("确定"));
        addNewGroup(groupID,newGroupName);
    });
    //邀请好友进群、添加好友时查不到改ID
    connect(signalOpt,&SignalOpt::noSuchFriendID,this,[](QString friendID){
        QMessageBox::critical(nullptr,tr("请求发送失败"),tr("该ID(")+friendID+tr(")未注册"),tr("重新输入"));
    });

    //添加好友时，请求发送成功或失败
    connect(signalOpt,&SignalOpt::beFriendSuccessfully,this,[](QString friendID,QString friendName){
        QMessageBox::information(nullptr,tr("请求发送成功"),tr("已向")+friendName+tr("(")+friendID+tr(")发送添加好友请求"),tr("确定"));
    });
    connect(signalOpt,&SignalOpt::beFriendUnsuccessfully,this,[](){
        QMessageBox::critical(nullptr,tr("请求发送失败"),tr("发送添加好友请求失败，请重试"),tr("确定"));
    });
    //对方已同意或拒绝添加好友请求
    connect(signalOpt,&SignalOpt::vertifyFriendSuccessfully,this,[=](QString friendID,QString friendName){
        QMessageBox::information(nullptr,tr("添加好友成功"),tr("用户")+friendName+tr("(")+friendID+tr(")已同意您的添加好友请求"),tr("确定"));
        jsonOperator->addFriendtoList(friendID,friendName);
        initFriendList();
    });
    connect(signalOpt,&SignalOpt::vertifyFriendUnsuccessfully,this,[](QString friendID,QString friendName){
        QMessageBox::information(nullptr,tr("添加好友失败"),tr("用户")+friendName+tr("(")+friendID+tr(")已拒绝您的添加好友请求"),tr("确定"));
    });

    //收到添加好友请求时按钮变亮
//    connect(signalOpt,&SignalOpt::askFriend,this,[=](){});

    //同意添加好友请求时更新好友列表
    connect(notice,&Notice::agreeNewFriend,this,[=](QString friendID,QString friendName){
        jsonOperator->addFriendtoList(friendID,friendName);
        initFriendList();
    });
    //更新好友列表和群列表
    connect(notice,&Notice::flashFriendList,this,&MainUI_MidBar::initFriendList);
    connect(notice,&Notice::flashGroupList,this,&MainUI_MidBar::initGroupList);

    //加入群时，输入的群号在服务器数据库中找不到
    connect(signalOpt,&SignalOpt::noSuchGroupID,this,[=](QString groupID){
        QMessageBox::critical(nullptr,tr("请求发送失败"),tr("没有以该ID(")+groupID+tr(")为群号的群"),tr("重新输入"));
    });
    //加入群时，请求发送成功/失败
    connect(signalOpt,&SignalOpt::joinGroupSuccessfully,this,[](QString groupID,QString groupName){
        QMessageBox::information(nullptr,tr("请求发送成功"),tr("已向\"")+groupName+tr("\"(")+groupID+tr(")发送入群请求"),tr("确定"));
    });
    connect(signalOpt,&SignalOpt::joinGroupUnsuccessfully,this,[](){
        QMessageBox::critical(nullptr,tr("请求发送失败"),tr("发送加入群聊请求失败，请重试"),tr("确定"));
    });
    //群管理员已同意或拒绝入群请求
    connect(signalOpt,&SignalOpt::vertifyGroupSuccessfully,this,[=](QString groupID,QString groupName){
        QMessageBox::information(nullptr,tr("申请成功"),tr("群\"")+groupName+tr("\"(")+groupID+tr(")的管理员已同意您的入群请求"),tr("确定"));
        jsonOperator->addGrouptoList(groupID,groupName);
        initFriendList();
    });
    connect(signalOpt,&SignalOpt::vertifyGroupUnsuccessfully,this,[](QString groupID,QString groupName){
        QMessageBox::information(nullptr,tr("申请入群失败"),tr("群\"")+groupName+tr("\"(")+groupID+tr(")的管理员已拒绝您的入群请求"),tr("确定"));
    });

    //邀请某人加入群聊时，请求发送成功或失败
    connect(signalOpt,&SignalOpt::inviteGroupSuccessfully,this,[](QString friendID,QString groupName,QString groupID){
        QMessageBox::information(nullptr,tr("请求发送成功"),tr("已向用户(")+friendID+tr(")发送加入群\"")+groupName+tr("\"(")+groupID+")的邀请",tr("确定"));
    });
    connect(signalOpt,&SignalOpt::inviteGroupUnsuccessfully,this,[](){
        QMessageBox::information(nullptr,tr("请求发送失败"),tr("发送邀请入群请求失败"),tr("确定"));
    });


    //服务器接收到自己受邀同意加入群聊信息后，更新群列表或者服务器请求失败了
    connect(signalOpt,&SignalOpt::acceptInviteGroupSuccessfully,this,[=](QString groupID,QString groupName){
        QMessageBox::information(nullptr,tr("受邀成功"),tr("已经成功受邀进入群聊\"")+groupName+tr("\"(")+groupID+tr(")"),tr("确定"));
        jsonOperator->addGrouptoList(groupID,groupName);
        initGroupList();
    });
    connect(signalOpt,&SignalOpt::acceptInviteGroupUnsuccessfully,this,[=](QString groupID,QString groupName){
        QMessageBox::information(nullptr,tr("受邀失败"),tr("受邀进入群聊\"")+groupName+tr("\"(")+groupID+tr(")失败，请重新申请加入"),tr("确定"));
    });

    //"删除好友是否成功"信号的接收
    connect(signalOpt,&SignalOpt::deleteFriendSuccessfully,this,[=](QString friendID){
        QString friendName = jsonOperator->findFriendName(friendID);
        QMessageBox::information(nullptr,tr("删除好友成功"),tr("好友")+friendName+tr("(")+friendID+tr(")删除成功"));
        jsonOperator->removeFriendFromList(friendID);
        initFriendList();
    });
    //退群成功
    connect(signalOpt,&SignalOpt::quitGroupSuccessfully,this,[=](QString groupID){
        QString groupName = jsonOperator->findGroupName(groupID);
        QMessageBox::information(nullptr,tr("退群成功"),tr("已从\"")+groupName+tr("\"(")+groupID+tr(")中成功退出"));
        jsonOperator->removeGroupFromList(groupID);
        initGroupList();
    });
    //踢出去
    connect(signalOpt,&SignalOpt::kickoutGroupSuccessfully,this,[=](QString groupMemberID,QString groupID){
        QString groupMemberName = jsonOperator->findGroupMemberName(groupID,groupMemberID);
        QString groupName = jsonOperator->findGroupName(groupID);
        QMessageBox::information(nullptr,tr("踢人成功"),tr("已将\"")+groupMemberName+tr("\"(")+groupMemberID+
                                 tr(")从\"")+groupName+tr("\"(")+groupID+tr(")中踢出"));
    });
    connect(signalOpt,&SignalOpt::kickoutGroupUnsuccessfully,this,[=](QString groupMemberID,QString groupID){
        QString groupMemberName = jsonOperator->findGroupMemberName(groupID,groupMemberID);
        QString groupName = jsonOperator->findGroupName(groupID);
        QMessageBox::information(nullptr,tr("踢人失败"),tr("将\"")+groupMemberName+tr("\"(")+groupMemberID+
                                 tr(")从\"")+groupName+tr("\"(")+groupID+tr(")中踢出的请求失败"));
    });

    //收到文件
    flag=1;
    connect(signalOpt,&SignalOpt::receiveFile,this,[=](QString friendID, QString fileName, int length, int index, QString data){
        QString path=global->path+"User/"+global->UID+"/File";
        fileServer->recvFile(data.toUtf8(),length,index,path,fileName);
        if(flag){
            connect(fileServer,&FileServer::fileReceiveSuccessfully,this,[=](){
                QMessageBox::information(this,tr("传输文件成功"),QString("用户\""+jsonOperator->findFriendName(friendID)+"\"("+friendID+")给您发送的\""+fileName+"\"的文件传输成功，您可以在"+path+"查看"),tr("好的"));
            });
        }
        flag=0;
    });

    initRecentConversation();
}

void MainUI_MidBar::toRecentConversation(){
    initRecentConversation();
    qDebug()<<"toRecentConversation";
}

void MainUI_MidBar::toFriendList(){
    initFriendList();
    qDebug()<<"toFriendList";
}

void MainUI_MidBar::toGroupList(){
    initGroupList();
    qDebug()<<"toGroupList";
}

void MainUI_MidBar::toSettings(){
    qDebug()<<"toSettings";
}

void MainUI_MidBar::showNotice(){
    notice->show();
}


void MainUI_MidBar::addNewGroup(QString groupID,QString groupName){
    jsonOperator->addGrouptoList(groupID,groupName);
    initGroupList();
}

void MainUI_MidBar::initRecentConversation(){
    QList<QString> recentCNamelist,recentCIDList,recentCHeadList;

    int n = recentCNamelist.size();
    delete recentConversation;
    recentConversation = new QWidget(this);
    recentConversation->move(0,80);
    recentConversationLayout = new QVBoxLayout(recentConversation);
    for(int i=0;i<n;i++){
        MyToolButton* toolbtn = new MyToolButton(recentConversation);
        toolbtn->setIconSize(QSize(40,40));
        toolbtn->setObjectName(recentCIDList[i]);  //按键名为id
        toolbtn->setStyleSheet("QToolButton{color:rgb(0,0,0);border:none;font-size:20px;}");
        toolbtn->setIcon(QIcon(recentCHeadList[i]));
        toolbtn->setText(" "+recentCNamelist[i]);
        //这里先默认为好友，而非群聊
        toolbtn->setType("friend");
        toolbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(toolbtn,&QToolButton::clicked,this,&MainUI_MidBar::openConversation);
        //删除好友请求发送
        recentConversationLayout->addWidget(toolbtn);
    }
    recentConversationLayout->addStretch();
    recentConversation->show();
    friendListWgt->hide();
    groupListWgt->hide();
}

void MainUI_MidBar::initGroupList(){
    jsonOperator->readGroupList();
    QList<QString> *groupNameList = global->GroupNameList,
            *groupIDList = global->GroupIDList,
            *groupHeadList = global->GroupHeadList;

    int n = groupIDList->size();
    delete groupListWgt;
    groupListWgt = new QWidget(this);
    groupListWgt->move(0,80);
    groupListLayout = new QVBoxLayout(groupListWgt);
    for(int i=0;i<n;i++){
        MyToolButton* toolbtn = new MyToolButton(groupListWgt);
        toolbtn->setIconSize(QSize(40,40));
        toolbtn->setObjectName((*groupIDList)[i]);  //按键名为id
        toolbtn->setStyleSheet("QToolButton{color:rgb(0,0,0);border:none;font-size:20px;}");
        toolbtn->setIcon(QIcon(global->path+"Head/"+(*groupHeadList)[i]));
        toolbtn->setText(" "+(*groupNameList)[i]);
        toolbtn->setType("group");
        toolbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(toolbtn,&QToolButton::clicked,this,&MainUI_MidBar::openConversation);
        groupListLayout->addWidget(toolbtn);
    }
    groupListLayout->addStretch();
    recentConversation->hide();
    friendListWgt->hide();
    groupListWgt->show();
}

void MainUI_MidBar::initFriendList(){
    jsonOperator->readFriendList();
    QList<QString> *friendNameList = global->FriendNameList,
            *friendIDList = global->FriendIDList,
            *friendHeadList = global->FriendHeadList;
    int n = friendIDList->size();
    delete friendListWgt;
    friendListWgt = new QWidget(this);
    friendListWgt->move(0,80);
    friendListLayout = new QVBoxLayout(friendListWgt);
    for(int i=0;i<n;i++){
        MyToolButton* toolbtn = new MyToolButton(friendListWgt);
        toolbtn->setIconSize(QSize(40,40));
        toolbtn->setObjectName((*friendIDList)[i]);  //按键名为id
        toolbtn->setStyleSheet("QToolButton{color:rgb(0,0,0);border:none;font-size:20px;}");
        toolbtn->setIcon(QIcon(global->path+"Head/"+(*friendHeadList)[i]));
        toolbtn->setText(" "+(*friendNameList)[i]);
        toolbtn->setType("friend");
        toolbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(toolbtn,&QToolButton::clicked,this,&MainUI_MidBar::openConversation);
//        connect(toolbtn,&QToolButton::clicked,this,[](){});
        friendListLayout->addWidget(toolbtn);
    }
    friendListLayout->addStretch();
    recentConversation->hide();
    friendListWgt->show();
    groupListWgt->hide();
}

void MainUI_MidBar::openConversation(){
    MyToolButton* Sender = qobject_cast<MyToolButton*>(sender());
    emit openChatWindow(Sender);
}

void MainUI_MidBar::search(){

}
