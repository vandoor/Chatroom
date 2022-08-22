#include "testbox.h"
#include "ui_testbox.h"

TestBox::TestBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestBox)
{
    ui->setupUi(this);

    global = new Global();
    signalOpt = global->signalOpt;

    connect(ui->signalSenderClear,&QPushButton::clicked,this,[=](){
       ui->signalSender->setText("");
    });
    connect(ui->signalReceiverClear,&QPushButton::clicked,this,[=](){
        ui->signalReceiver->setText("");
     });
    connect(ui->login,&QPushButton::clicked,this,[=](){
        login_account=ui->login_account->text();
        login_password=ui->login_password->text();
        signalOpt->login(login_account,login_password);
     });
    connect(ui->logon,&QPushButton::clicked,this,[=](){
        logon_uname=ui->logon_uname->text();
        logon_password1=ui->logon_password1->text();
        logon_password2=ui->logon_password2->text();
        signalOpt->logon(logon_uname,logon_password1);
     });
    connect(ui->signalReceiverFlasher,&QPushButton::clicked,this,[=](){
        ui->signalReceiver->setText(this->signalOpt->getReceivedSignal());
     });

    connect(ui->loginSuccessfully,&QPushButton::clicked,this,[=](){
        QString loginUserName = ui->loginUserName->text();
        signalOpt->loginSuccessfully(loginUserName);
    });
    connect(ui->logonSuccessfully,&QPushButton::clicked,this,[=](){
        QString logonUserID = ui->logonUserID->text();
        signalOpt->logonSuccessfully(logonUserID);
    });
    connect(ui->noSuchFriendID,&QPushButton::clicked,this,[=](){
        QString noFriendID = ui->noFriendID->text();
        signalOpt->noSuchFriendID(noFriendID);
    });
    connect(ui->beFriendSuccessfully,&QPushButton::clicked,this,[=](){
        QString beFriendID = ui->beFriendID->text();
        QString beFriendName = ui->beFriendName->text();
        signalOpt->beFriendSuccessfully(beFriendID,beFriendName);
    });
    connect(ui->vertifyFriendSuccess,&QPushButton::clicked,this,[=](){
        QString vertifyFriendID = ui->vertifyFriendID->text();
        QString vertifyFriendName = ui->vertifyFriendName->text();
        signalOpt->vertifyFriendSuccessfully(vertifyFriendID,vertifyFriendName);
    });
    connect(ui->askFriend,&QPushButton::clicked,this,[=](){
        QString askFriendFriendID = ui->askFriendID->text();
        QString askFriendName = ui->askFriendName->text();
        signalOpt->askFriend(askFriendFriendID,askFriendName);
    });
    connect(ui->deleteFriendSuccessfully,&QPushButton::clicked,this,[=](){
        QString deleteFriendID = ui->deleteFriendID->text();
        signalOpt->deleteFriendSuccessfully(deleteFriendID);
    });
    connect(ui->quitGroupSuccessfully,&QPushButton::clicked,this,[=](){
        QString quitGroupID = ui->quitGroupID->text();
        signalOpt->quitGroupSuccessfully(quitGroupID);
    });
    connect(ui->receiveFriendText,&QPushButton::clicked,this,[=](){
        QString receiveTextFriendID = ui->receiveTextFriendID->text();
        QString receiveText = ui->Text->toPlainText();
        signalOpt->receiveFriendText(receiveTextFriendID,receiveText);
    });
    connect(ui->receiveGroupText,&QPushButton::clicked,this,[=](){
        QString receiveTextGroupID = ui->receiveTextGroupID->text();
        QString receiveTextGroupMemberID = ui->receiveTextGroupMemberID->text();
        QString receiveText = ui->GroupText->toPlainText();
        signalOpt->receiveGroupText(receiveTextGroupID,receiveTextGroupMemberID,receiveText);
    });
    connect(ui->createGroupSuccessfully,&QPushButton::clicked,this,[=](){
       QString createGroupID = ui->createGroupID->text();
       signalOpt->createGroupSuccessfully(createGroupID);
    });
    connect(ui->noSuchGroupID,&QPushButton::clicked,this,[=](){
        QString groupID = ui->noGroupID->text();
        signalOpt->noSuchGroupID(groupID);
    });
    connect(ui->joinGroupSuccessfully,&QPushButton::clicked,this,[=](){
        QString groupID = ui->joinGroupID->text();
        QString groupName = ui->joinGroupName->text();
        signalOpt->joinGroupSuccessfully(groupID,groupName);
    });
    connect(ui->askJoinGroup,&QPushButton::clicked,this,[=](){
        QString askJoinGroupFriendID = ui->askJoinGroupFriendID->text();
        QString askJoinGroupID = ui->askJoinGroupID->text();
        QString askJoinGroupName = ui->askJoinGroupName->text();
        signalOpt->askJoinGroup(askJoinGroupFriendID,askJoinGroupID,askJoinGroupName);
    });

    connect(ui->kickoutGroupSuccessfully,&QPushButton::clicked,this,[=](){
        QString friendID = ui->kickoutGroupMemberID->text();
        QString groupID = ui->kickoutGroupID->text();
        signalOpt->kickoutGroupSuccessfully(friendID,groupID);
    });
    connect(ui->loseFriend,&QPushButton::clicked,this,[=](){
        QString loseFriendID = ui->loseFriendID->text();
        signalOpt->loseFriend(loseFriendID);
    });
    connect(ui->kickedFromGroup,&QPushButton::clicked,this,[=](){
       QString groupID = ui->kickedFromGroupID->text();
       signalOpt->kickedFromGroup("10086",groupID);
    });

    connect(ui->inviteGroupSuccessfully,&QPushButton::clicked,this,[=](){
       QString friendID = ui->inviteGroupFriendID->text();
       QString groupID = ui->inviteGroupID->text();
       QString groupName = ui->inviteGroupName->text();
       signalOpt->inviteGroupSuccessfully(friendID,groupName,groupID);
    });

    connect(ui->vertifyGroupSuccessfully,&QPushButton::clicked,this,[=](){
       QString groupID = ui->vertifyGroupID->text();
       QString groupName = ui->vertifyGroupName->text();
       signalOpt->vertifyGroupSuccessfully(groupID,groupName);
    });

    connect(ui->acceptInvitetoGroup,&QPushButton::clicked,this,[=](){
        QString groupID = ui->vertifyGroupID->text();
        QString groupName = ui->vertifyGroupName->text();
        signalOpt->acceptInviteGroupSuccessfully(groupID,groupName);
    });
    connect(ui->askInviteGroup,&QPushButton::clicked,this,[=](){
       QString friendID = ui->askInviteGroupFriendID->text();
       QString groupID = ui->askInviteGroupID->text();
       QString groupName = ui->askInviteGroupName->text();
       signalOpt->askInviteGroup(friendID,groupID,groupName);
    });
}

TestBox::~TestBox()
{
    delete ui;
}

void TestBox::setSignalOpt(SignalOpt *signalOpt){
    this->signalOpt = signalOpt;
}
