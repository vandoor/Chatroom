#ifndef JSONOPERATOR_H
#define JSONOPERATOR_H

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTime>
#include <QtGlobal>
#include "global.h"

class JsonOperator
{
public:
    JsonOperator();
    void readUserInfo();
    void readFriendList();
    void readGroupList();
    void readGroupMemberList(QString GroupID);
    void setGroupMemberList(QString GroupID,int GroupMemberNum,QJsonArray GroupMemberList);
    void readFriendRecord(QString FriendID);
    void readGroupRecord(QString GroupID);
    void addFriendtoList(QString friendID,QString friendName);
    void addGrouptoList(QString groupID,QString groupName);
    void addGroupMembertoList(QString GroupID,QString groupMemberID,QString groupMemberName);
    void addFriendRecord(QString friendID,int type,QString context);
    void addGroupRecord(QString groupID,QString groupMemberID,QString context);
    void removeFriendFromList(QString FriendID);
    void removeGroupFromList(QString GroupID);
    void removeGroupMemberFromList(QString GroupID,QString GroupMemberID);
    void initUserData(QString UserID,QString UserName);
    QString findFriendName(QString FriendID);
    QString findGroupName(QString GroupID);
    QString findGroupMemberName(QString GroupID,QString GroupMemberID);

private:
    Global *global;
};

#endif // JSONOPERATOR_H
