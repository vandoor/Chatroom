#ifndef SIGNALOPT_H
#define SIGNALOPT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>

class SignalOpt : public QWidget
{
    Q_OBJECT
public slots:
    void signalReceiver();

public:
    SignalOpt(QWidget *parent = nullptr);

    int login(QString UID,QString password);
    int logon(QString UName,QString password);
    int buildGroup(QString UID, QString groupName);
    int addFriend(QString UID, QString friendID);
    int acceptFriend(int result, QString senderID, QString receiverID); //<-- 形参变量名更改 -->
    int joinGroup(QString UID, QString groupID);
    int inviteGroup(QString UID, QString friendID, QString groupID);
    int approveEnterGroup(int result, QString userID, QString groupID);
    int acceptInviteGroup(QString inviteID, QString acceptID, QString groupID);
    int friendChat(QString UID, QString friendID, QString message);
    int groupChat(QString UID, QString groupID, QString message);
    int deleteFriend(QString UID, QString friendID);
    int leaveGroup(QString UID, QString groupID);
    int kickoutGroup(QString adminID, QString userID, QString groupID);
    int sendFilePiece(QString UID, QString friendID, QString fileName, int length, int index, char * data);
    int getGroupMemberList(QString groupID);
    int signalSender(QJsonObject json);

    QString getReceivedSignal();



private:
    QTcpSocket *client;
    QString receivedSignal;

signals:
    void loginSuccessfully(QString UserName);
    void loginUnsuccessfully();
    void logonSuccessfully(QString UserID);
    void logonUnsuccessfully();
    void createGroupSuccessfully(QString groupID);
    void createGroupUnsuccessfully();
    void noSuchFriendID(QString friendID);
    void beFriendSuccessfully(QString friendID,QString friendName);
    void beFriendUnsuccessfully();
    void vertifyFriendSuccessfully(QString friendID,QString friendName);
    void vertifyFriendUnsuccessfully(QString friendID,QString friendName);
    void askFriend(QString friendID,QString friendName);
    void noSuchGroupID(QString groupID);
    void joinGroupSuccessfully(QString groupID,QString groupName);
    void joinGroupUnsuccessfully();
    void askJoinGroup(QString senderID,QString groupID,QString groupName);
    void inviteGroupSuccessfully(QString friendID,QString groupName,QString groupID);
    void inviteGroupUnsuccessfully();
    void askInviteGroup(QString friendID,QString groupID,QString groupName);
    void vertifyGroupSuccessfully(QString groupID,QString groupName);
    void vertifyGroupUnsuccessfully(QString groupID,QString groupName);
    void acceptInviteGroupSuccessfully(QString groupID,QString groupName);
    void acceptInviteGroupUnsuccessfully(QString groupID,QString groupName);
    void sendFriendTextUnsuccessfully();
    void sendFriendTextSuccessfully();
    void sendGroupTextUnsuccessfully();
    void sendGroupTextSuccessfully();
    void receiveFriendText(QString friendID,QString message);
    void receiveGroupText(QString groupID,QString groupMemberID,QString message);
    void deleteFriendSuccessfully(QString friendID);
    void deleteFriendUnsuccessfully();
    void quitGroupSuccessfully(QString groupID);
    void quitGroupUnsuccessfully();
    void kickoutGroupSuccessfully(QString friendID,QString groupID);
    void kickoutGroupUnsuccessfully(QString friendID,QString groupID);
    void loseFriend(QString loseID);
    void receiveFile(QString friendID, QString fileName, int length, int index, QString data);
    void kickedFromGroup(QString adminID,QString groupID);
    void receiveGroupMemberList(QString groupID,int groupMemberNum,QJsonArray groupMemberList);
    void fileDuanSuccessfully();
};

#endif // SIGNALOPT_H
