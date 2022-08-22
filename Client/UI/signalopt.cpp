#include "signalopt.h"
#include <QMessageBox>

SignalOpt::SignalOpt(QWidget *parent) : QWidget(parent)
{
    client = new QTcpSocket(nullptr);
    //在这里修改地址
    client->connectToHost(QHostAddress("10.198.79.15"),8888);
    connect(client,&QTcpSocket::readyRead,this,&SignalOpt::signalReceiver);
}

int SignalOpt::logon(QString UName, QString password){
    //注册
    QJsonObject json;
    json.insert("type", "register");
    json.insert("UserName", UName);
    json.insert("Password", password);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"logon error!";
        return -1;
    }
    return val;
}

int SignalOpt::login(QString UID,QString password){
    //登录
    QJsonObject json;
    json.insert("type", "login");
    json.insert("UserID", UID);
    json.insert("Password", password);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"login error!";
        return -1;
    }
    return val;
}

int SignalOpt::buildGroup(QString UID, QString groupName)
{
    //建群
    QJsonObject json;
    json.insert("type", "creategroup");
    json.insert("UserID", UID);
    json.insert("GroupName", groupName);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"build group error!";
        return -1;
    }
    return val;
}

int SignalOpt::addFriend(QString UID, QString friendID)
{
    //加好友
    QJsonObject json;
    json.insert("type", "befriend");
    json.insert("UserID", UID);
    json.insert("FriendID", friendID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"add friend error!";
        return -1;
    }
    return val;
}

int SignalOpt::acceptFriend(int result, QString senderID, QString receiverID)
{
    //向服务器端发送接受（或拒绝）加好友请求的信息
    QJsonObject json;
    json.insert("type", "acceptfriend");
    json.insert("result", result);
    json.insert("SenderID", senderID);
    json.insert("ReceiverID", receiverID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"accept friend error!";
        return -1;
    }
    return val;
}

int SignalOpt::approveEnterGroup(int result, QString userID, QString groupID)
{
    //自己是群管理员，向服务器发送是否同意申请人入群的信息
    //result（0/1）：是否同意  userID：申请人的ID
    QJsonObject json;
    json.insert("type", "approveenter");
    json.insert("result", result);
    json.insert("UserID", userID);
    json.insert("GroupID", groupID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"approve enter group error!";
        return -1;
    }
    return val;
}

int SignalOpt::acceptInviteGroup(QString inviteID, QString acceptID, QString groupID)
{
    //自己同意被邀请加入群聊
    //inviteID：邀请人的ID  acceptID：自己的ID
    QJsonObject json;
    json.insert("type", "acceptinvite");
    json.insert("InviteID", inviteID);
    json.insert("AcceptID", acceptID);
    json.insert("GroupID", groupID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"accept being invited into group error!";
        return -1;
    }
    return val;
}

int SignalOpt::joinGroup(QString UID, QString groupID)
{
    //加入群聊
    QJsonObject json;
    json.insert("type", "join");
    json.insert("UserID", UID);
    json.insert("GroupID", groupID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"join group error!";
        return -1;
    }
    return val;
}

int SignalOpt::inviteGroup(QString UID, QString friendID, QString groupID)
{
    //邀请好友加入群聊
    QJsonObject json;
    json.insert("type", "invite");
    json.insert("UserID", UID);
    json.insert("FriendID", friendID);
    json.insert("GroupID", groupID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"join group error!";
        return -1;
    }
    return val;
}

int SignalOpt::friendChat(QString UID, QString friendID, QString message)
{
    //好友私聊
    QJsonObject json;
    json.insert("type", "sendfriend");
    json.insert("UserID", UID);
    json.insert("FriendID", friendID);
    json.insert("Message", message);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"friend chat error!";
        return -1;
    }
    return val;
}

int SignalOpt::groupChat(QString UID, QString groupID, QString message)
{
    //群聊
    QJsonObject json;
    json.insert("type", "sendgroup");
    json.insert("UserID", UID);
    json.insert("GroupID", groupID);
    json.insert("Message", message);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"group chat error!";
        return -1;
    }
    return val;
}

int SignalOpt::deleteFriend(QString UID, QString friendID)
{
    //删除好友
    QJsonObject json;
    json.insert("type", "deletefriend");
    json.insert("UserID", UID);
    json.insert("FriendID", friendID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"delete friend error!";
        return -1;
    }
    return val;
}

int SignalOpt::leaveGroup(QString UID, QString groupID)
{
    //退出群聊
    QJsonObject json;
    json.insert("type", "quit");
    json.insert("UserID", UID);
    json.insert("GroupID", groupID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"leave group error!";
        return -1;
    }
    return val;
}

int SignalOpt::kickoutGroup(QString adminID, QString userID, QString groupID)
{
    //把人踢出群聊
    //adminID：自己的ID  userID：要踢的人的ID
    QJsonObject json;
    json.insert("type", "quit");
    json.insert("AdminID", adminID);
    json.insert("UserID", userID);
    json.insert("GroupID", groupID);
    int val = signalSender(json);
    if(val==-1){
        qDebug()<<"kick out error!";
        return -1;
    }
    return val;
}

int SignalOpt::signalSender(QJsonObject json){
    //打包发送给服务器的信号
    QJsonDocument json_doc;
    json_doc.setObject(json);
    QByteArray array = json_doc.toJson(QJsonDocument::Compact);
    QString strJson(array);
    qDebug()<<strJson;
    qint64 val=client->write(strJson.toUtf8());
    if(val==-1){
        qDebug()<<"write error!";
        return -1;
    }
    return val;
}

void SignalOpt::signalReceiver(){
    //将从服务器接收到信号解码
    QByteArray recv = client->readAll();
    QString strtt(recv);
    qDebug()<<"receive from server: "<<strtt<<"\n";
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(recv, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue type_value = object.value("type");
            QString type = type_value.toString();
            qDebug()<<"type: "<<type;
            if(type == tr("register")){
                //注册账户
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();      //是否注册成功
                QJsonValue UID_value = object.value("UserID");
                QString UID = UID_value.toString();     //服务器分配的用户ID
                if(status == 1){
                    emit logonSuccessfully(UID);
                }
                else emit logonUnsuccessfully();
            }
            else if(type == tr("login")){
                //登录
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                QJsonValue userName_value = object.value("UserName");
                QString userName = userName_value.toString();
                if(status == 1) emit loginSuccessfully(userName);
                else emit loginUnsuccessfully();
            }
            else if(type == tr("creategroup")){
                //建群
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                QJsonValue groupID_value = object.value("GroupID"); //<-- 键名更改 -->
                QString groupID = groupID_value.toString();
                if(status == 1){
                    //建群成功
                    emit createGroupSuccessfully(groupID);
                }
                else emit createGroupUnsuccessfully();
            }
            else if(type == tr("befriend")){
                //加好友(自己是发出申请的一方，接收服务器反馈 是 否 成 功 发 出 请 求）
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                if(status == 100){
                    //查无此人
                    QJsonValue friendID_value = object.value("FriendID");
                    QString friendID = friendID_value.toString();
                    emit noSuchFriendID(friendID);
                }
                else if(status == 0){
                    //请求发送失败
                    emit beFriendUnsuccessfully();
                }
                else if(status == 1){
                    //请求发送成功
                    QJsonValue friendID_value = object.value("FriendID");
                    QString friendID = friendID_value.toString();
                    QJsonValue friendName_value = object.value("FriendName");
                    QString friendName = friendName_value.toString();
                    emit beFriendSuccessfully(friendID,friendName);
                }
            }
            else if(type == tr("vertifyfriend")){
                //加好友（自己是发出申请的一方，接收服务器反馈 对 方 是 否 同 意 请 求）
                QJsonValue result_value = object.value("result");
                int result = result_value.toInt();
                QJsonValue senderID_value = object.value("SenderID");
                QString senderID = senderID_value.toString();       //发送请求一方（自己）的ID
                QJsonValue receiverID_value = object.value("ReceiverID");
                QString receiverID = receiverID_value.toString();   //接收请求一方（对方）的ID
                QJsonValue receiverName_value = object.value("ReceiverName");
                QString receiverName = receiverID_value.toString(); //接收请求一方（对方）的用户名
                if(result == 0){
                    //对方拒绝请求
                    emit vertifyFriendSuccessfully(receiverID,receiverName);
                }
                else if(result == 1){
                    //对方同意请求
                    emit vertifyFriendUnsuccessfully(receiverID,receiverName);
                }
            }
            else if(type == tr("askfriend")){
                //加好友（自己是被申请的一方，接收申请方的信息）
                QJsonValue receiverID_value = object.value("ReceiverID");   //接收申请一方（自己）的ID
                QString receiverID = receiverID_value.toString();
                QJsonValue senderID_value = object.value("SenderID");       //发出申请一方（对方）的ID
                QString senderID = senderID_value.toString();
                QJsonValue senderName_value = object.value("SenderName");   //发出申请一方（对方）的用户名
                QString senderName = senderName_value.toString();
                emit askFriend(senderID,senderName);
            }
            else if(type == tr("join")){
                //加入群聊(自己是发出申请的一方，接收服务器反馈 是 否 成 功 发 出 请 求）
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                if(status == 101){
                    //群聊不存在
                    QJsonValue groupID_value = object.value("GroupID");
                    QString groupID = groupID_value.toString();
                    emit noSuchFriendID(groupID);
                }
                else if(status == 1){
                    //请求成功发出
                    QJsonValue groupID_value = object.value("GroupID");
                    QString groupID = groupID_value.toString();
                    QJsonValue UID_value = object.value("UserID");      //<-- 键名更改 -->
                    QString UID = UID_value.toString();
                    QJsonValue groupName_value = object.value("GroupName");
                    QString groupName = groupName_value.toString();     //<-- 新增键：群名 -->
                    emit joinGroupSuccessfully(groupID,groupName);
                }
                else if(status == 0){
                    //请求未成功发出
                    emit joinGroupUnsuccessfully();
                }
            }
            else if(type == tr("askjoin")){
                //自己是群聊群主，接收他人发出的加入群聊的请求
                QJsonValue receiverID_value = object.value("ReceiverID");
                QString receiverID = receiverID_value.toString();   //自己的ID
                QJsonValue senderID_value = object.value("SenderID");
                QString senderID = senderID_value.toString();       //申请人的ID
                QJsonValue groupID_value = object.value("GroupID");
                QString groupID = groupID_value.toString();         //<-- 新增键：群ID-->
                QJsonValue groupName_value = object.value("GroupName");
                QString groupName = groupName_value.toString();     //<-- 新增键：群名 -->
                emit askJoinGroup(senderID,groupID,groupName);
            }
            else if(type == tr("invite")){
                //邀请好友加入群聊（自己是发出邀请者，接收服务器返回的是否成功发出邀请的信号）
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                if(status == 100){
                    //好友不存在
                    QJsonValue friendID_value = object.value("FriendID");
                    QString friendID = friendID_value.toString();
                    emit noSuchFriendID(friendID);
                }
                else if(status == 101){
                    //群聊不存在
                    QJsonValue groupID_value = object.value("GroupID");
                    QString groupID = groupID_value.toString();
                    emit noSuchGroupID(groupID);
                }
                else if(status == 1){
                    //成功发出邀请
                    QJsonValue groupID_value = object.value("GroupID");
                    QString groupID = groupID_value.toString();
                    QJsonValue friendID_value = object.value("FriendID");
                    QString friendID = friendID_value.toString();
                    QJsonValue groupName_value = object.value("GroupName");
                    QString groupName = groupName_value.toString();     //<-- 新增键：群名 -->
                    emit inviteGroupSuccessfully(friendID,groupName,groupID);
                }
                else if(status == 0){
                    //失败
                    emit inviteGroupUnsuccessfully();
                }
            }
            else if(type == tr("askinvite")){
                //自己被人邀请加入群聊
                QJsonValue receiverID_value = object.value("ReceiverID");
                QString receiverID = receiverID_value.toString();   //自己的ID
                QJsonValue senderID_value = object.value("SenderID");
                QString senderID = senderID_value.toString();       //邀请发出者的ID
                QJsonValue groupID_value = object.value("GroupID");
                QString groupID = groupID_value.toString();         //群聊ID
                QJsonValue groupName_value = object.value("GroupName");
                QString groupName = groupName_value.toString();     //<-- 新增键：群名 -->
                emit askInviteGroup(senderID,groupID,groupName);
            }
            else if(type == tr("vertifygroup")){
                //自己是申请加入群聊者，接收服务器发回的是否成功加入群聊的消息
                QJsonValue result_value = object.value("result");
                int result = result_value.toInt();
                QJsonValue userID_value = object.value("UserID");
                QString userID = userID_value.toString();
                QJsonValue groupID_value = object.value("GroupID");
                QString groupID = groupID_value.toString();
                QJsonValue groupName_value = object.value("GroupName");
                QString groupName = groupName_value.toString();
                if(result == 1){
                    //成功加入群聊
                    emit vertifyGroupSuccessfully(groupID,groupName);
                }
                else if(result == 0){
                    //失败
                    emit vertifyGroupUnsuccessfully(groupID,groupName);
                }
            }
            else if(type == tr("acceptinvite")){
                //他人邀请自己加入群聊，自己已经同意加入，服务器返回是否加入成功的信息
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                QJsonValue inviteID_value = object.value("InviteID");
                QString inviteID = inviteID_value.toString();       //发出邀请者的ID
                QJsonValue acceptID_value = object.value("AcceptID");
                QString acceptID = acceptID_value.toString();       //自己的ID
                QJsonValue groupID_value = object.value("GroupID");
                QString groupID = groupID_value.toString();         //群聊ID
                QJsonValue groupName_value = object.value("GroupName");
                QString groupName = groupName_value.toString();
                if(status==1){
                    emit acceptInviteGroupSuccessfully(groupID,groupName);
                }
                else if(status==0){
                    emit acceptInviteGroupUnsuccessfully(groupID,groupName);
                }
            }
            else if(type == tr("sendfriend")){
                //好友私聊（发送方接收服务器发回的 是否发送成功 的反馈）
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                if(status == 1){
                    //发送成功
                    emit sendFriendTextSuccessfully();
                }
                else if(status == 0){
                    //发送失败
                    emit sendFriendTextUnsuccessfully();
                }
            }
            else if(type == tr("receivefriend")){
                //好友私聊（接收方接受消息）
                QJsonValue senderID_value = object.value("SenderID");
                QString senderID = senderID_value.toString(); //消息发送者ID
                QJsonValue message_value = object.value("Message");
                QString message = message_value.toString();   //消息
                emit receiveFriendText(senderID,message);
            }
            else if(type == tr("sendgroup")){
                //群聊（发送方接收服务器是否发送成功反馈）
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                QJsonValue userID_value = object.value("UserID");
                QString userID = userID_value.toString();
                QJsonValue groupID_value = object.value("GroupID");
                QString groupID = groupID_value.toString();
                QJsonValue message_value = object.value("Message");
                QString message = message_value.toString();
                if(status == 1){
                    //发送成功
                    emit sendGroupTextSuccessfully();
                }
                else if(status == 0){
                    //发送失败
                    emit sendGroupTextUnsuccessfully();
                }
            }
            else if(type == tr("receivegroup")){
                //群聊（接收者）
                QJsonValue groupID_value = object.value("GroupID"); //<-- 键名更改 -->
                QString groupID = groupID_value.toString();   //群聊ID
                QJsonValue senderID_value = object.value("SenderID");
                QString senderID = senderID_value.toString(); //消息发送者ID
                QJsonValue message_value = object.value("Message");
                QString message = message_value.toString();   //消息
                emit receiveGroupText(groupID,senderID,message);
            }
            else if(type == tr("deletefriend")){
                //自己发出删除好友请求，服务器返回是否成功删除的信息
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                QJsonValue friendID_value = object.value("FriendID");
                QString friendID = friendID_value.toString();
                QJsonValue userID_value = object.value("UserID");
                QString userID = userID_value.toString();
                if(status == 0){
                    //删除失败
                    emit deleteFriendUnsuccessfully();
                }
                else if(status == 1){
                    //删除成功
                    emit deleteFriendSuccessfully(friendID);
                }
            }
            else if(type == tr("quit")){
                //自己发出退出群聊请求，服务器返回是否成功退出的信息
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                QJsonValue userID_value = object.value("UserID");
                QString userID = userID_value.toString();
                QJsonValue groupID_value = object.value("GroupID");
                QString groupID = groupID_value.toString();
                if(status == 0){
                    //退出失败
                   emit quitGroupUnsuccessfully();
                }
                else if(status == 1){
                    //退出成功
                    emit quitGroupSuccessfully(groupID);
                }
            }
            else if(type == tr("kickout")){
                //自己是群管理员，把某人踢出群聊，接收服务器返回的是否成功踢出的信息
                QJsonValue status_value = object.value("status");
                int status = status_value.toInt();
                QJsonValue adminID_value = object.value("AdminID");
                QString adminID = adminID_value.toString();     //自己的ID
                QJsonValue userID_value = object.value("UserID");
                QString userID = userID_value.toString();       //踢出的用户的ID
                QJsonValue groupID_value = object.value("GroupID");
                QString groupID = groupID_value.toString();     //群聊ID
                if(status == 0){
                    //踢出失败
                    emit kickoutGroupUnsuccessfully(userID,groupID);
                }
                else if(status == 1){
                    //踢出成功
                    emit kickoutGroupSuccessfully(userID,groupID);
                }
            }
            else if(type == tr("losefriend")){
                QJsonValue UserID_value = object.value("UserID");
                QString UserID = UserID_value.toString();
                QJsonValue LoseID_value = object.value("LoseID");
                QString LoseID = LoseID_value.toString();
                emit loseFriend(LoseID);
            }
            else if(type == tr("kicked")){
                QJsonValue UserID_value = object.value("UserID");
                QString UserID = UserID_value.toString();
                QJsonValue AdminID_value = object.value("AdminID");
                QString AdminID = AdminID_value.toString();
                QJsonValue GroupID_value = object.value("GroupID");
                QString GroupID = GroupID_value.toString();
                emit kickedFromGroup(AdminID,GroupID);
            }
            else{
                qDebug()<<"receive format undefined!";
            }
        }
    }
    QString str(recv);
    receivedSignal.append(str);
}

QString SignalOpt::getReceivedSignal(){
    return receivedSignal;
}
