#include "jsonoperator.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QDateTime>

JsonOperator::JsonOperator()
{
    global = new Global();
}


void JsonOperator::readUserInfo(){
    QFile file(global->path+"User/"+global->UID+"/UserInfo.json");
    if(!file.exists()){
        qDebug()<<"readUserInfo error";
        return;
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QByteArray text = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
        if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
            if(document.isObject()){
                QJsonObject object = document.object();
                QJsonValue UserID_value = object.value("UserID"),
                        UserName_value = object.value("UserName"),
                        UserHead_value = object.value("UserHead");
                QString UserID = UserID_value.toString(),
                        UserName = UserName_value.toString(),
                        UserHead = UserHead_value.toString();
                qDebug()<<UserID<<UserName<<UserHead;
                global->UID=UserID;
                global->UName=UserName;
                global->UHead=UserHead;
            }
        }
        file.close();
    }
}

void JsonOperator::readFriendList(){
    QFile file(global->path+"User/"+global->UID+"/FriendList.json");
    if(!file.exists()){
        qDebug()<<"readFriendList error";
        return;
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QByteArray text = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
        if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
            if(document.isObject()){
                QJsonObject object = document.object();
                QJsonValue FriendNum_value = object.value("FriendNum");
                int FriendNum=FriendNum_value.toInt();
                QJsonArray FriendList_value = object.value("FriendList").toArray();
                QList<QString> *FriendNameList = new QList<QString>;
                QList<QString> *FriendIDList = new QList<QString>;
                QList<QString> *FriendHeadList = new QList<QString>;
                for(int i=0;i<FriendNum;i++){
                    QJsonObject friendiInfo = FriendList_value[i].toObject();
                    FriendIDList->append(friendiInfo.value("FriendID").toString());
                    FriendNameList->append(friendiInfo.value("FriendName").toString());
                    FriendHeadList->append(friendiInfo.value("FriendHead").toString());
                }

                qDebug()<<FriendNum<<*(FriendIDList)<<*(FriendNameList)<<*(FriendHeadList);
                global->FriendIDList=FriendIDList;
                global->FriendNameList=FriendNameList;
                global->FriendHeadList=FriendHeadList;
            }
        }
        file.close();
    }
}

void JsonOperator::readGroupList(){
    QFile file(global->path+"User/"+global->UID+"/GroupList/GroupList.json");
    if(!file.exists()){
        qDebug()<<"readGroupList error";
        return;
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QByteArray text = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
        if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
            if(document.isObject()){
                QJsonObject object = document.object();
                QJsonValue GroupNum_value = object.value("GroupNum");
                int GroupNum=GroupNum_value.toInt();
                QJsonArray GroupList_value = object.value("GroupList").toArray();
                QList<QString> *GroupNameList = new QList<QString>;
                QList<QString> *GroupIDList = new QList<QString>;
                QList<QString> *GroupHeadList = new QList<QString>;
                for(int i=0;i<GroupNum;i++){
                    QJsonObject GroupiInfo = GroupList_value[i].toObject();
                    GroupIDList->append(GroupiInfo.value("GroupID").toString());
                    GroupNameList->append(GroupiInfo.value("GroupName").toString());
                    GroupHeadList->append(GroupiInfo.value("GroupHead").toString());
                }

                qDebug()<<GroupNum<<*(GroupIDList)<<*(GroupNameList)<<*(GroupHeadList);
                global->GroupIDList=GroupIDList;
                global->GroupNameList=GroupNameList;
                global->GroupHeadList=GroupHeadList;
            }
        }
        file.close();
    }
}

void JsonOperator::readGroupMemberList(QString GroupID){
    qDebug()<<"readGroupMemberList";
    QFile file(global->path+"User/"+global->UID+"/GroupList/"+GroupID+".json");
    if(!file.exists()){
        qDebug()<<"readGroupMemberList error";
        return;
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QByteArray text = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
        if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
            if(document.isObject()){
                QJsonObject object = document.object();
                QJsonValue GroupMemberNum_value = object.value("GroupMemberNum");
                int GroupMemberNum=GroupMemberNum_value.toInt();
                QJsonArray GroupMemberList_value = object.value("GroupMemberList").toArray();
                QList<QString> *GroupMemberNameList = new QList<QString>;
                QList<QString> *GroupMemberIDList = new QList<QString>;
                QList<QString> *GroupMemberHeadList = new QList<QString>;
                for(int i=0;i<GroupMemberNum;i++){
                    QJsonObject GroupMemberiInfo = GroupMemberList_value[i].toObject();
                    GroupMemberIDList->append(GroupMemberiInfo.value("GroupMemberID").toString());
                    GroupMemberNameList->append(GroupMemberiInfo.value("GroupMemberName").toString());
                    GroupMemberHeadList->append(GroupMemberiInfo.value("GroupMemberHead").toString());
                }

                qDebug()<<GroupMemberNum<<*(GroupMemberIDList)<<*(GroupMemberNameList)<<*(GroupMemberHeadList);
                global->GroupMemberIDList=GroupMemberIDList;
                global->GroupMemberNameList=GroupMemberNameList;
                global->GroupMemberHeadList=GroupMemberHeadList;
            }
        }
        file.close();
    }
}

void JsonOperator::setGroupMemberList(QString GroupID,int GroupMemberNum,QJsonArray GroupMemberList){
    QFile groupMemberListFile(global->path+"User/"+global->UID+"/GroupList/"+GroupID+".json");
    if(groupMemberListFile.exists()){
        groupMemberListFile.remove();
    }
    groupMemberListFile.open(QIODevice::WriteOnly|QIODevice::Text);
    groupMemberListFile.close();
    if(groupMemberListFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        QJsonObject object = QJsonObject();
        object.insert("GroupMemberNum",GroupMemberNum);
        QJsonArray resetGroupMemberList=QJsonArray();
        for(int i=0;i<GroupMemberNum;i++){
            QJsonObject groupMemberiInfo = GroupMemberList[i].toObject();
            QString groupMemberID = groupMemberiInfo.value("UserID").toString();
            QString groupMemberName = groupMemberiInfo.value("UserName").toString();
            groupMemberiInfo = QJsonObject();
            groupMemberiInfo.insert("GroupMemberID",groupMemberID);
            groupMemberiInfo.insert("GroupMemberName",groupMemberName);
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            groupMemberiInfo.insert("GroupMemberHead","head3.png");
            resetGroupMemberList.append(QJsonValue(groupMemberiInfo));
        }
        object.insert("GroupMemberList",resetGroupMemberList);
        QJsonDocument doc = QJsonDocument(object);
        groupMemberListFile.write(doc.toJson());
    }

}

void JsonOperator::readFriendRecord(QString FriendID){
    QFile file(global->path+"User/"+global->UID+"/FriendRecord/"+FriendID+".json");
    if(!file.exists()){
        qDebug()<<"readFriendRecord error";
        return;
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QByteArray text = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
        if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
            if(document.isObject()){
                QJsonObject object = document.object();
                QJsonValue RecordNum_value = object.value("RecordNum");
                int RecordNum=RecordNum_value.toInt();
                QJsonArray RecordList_value = object.value("RecordList").toArray();
                QList<int> *RecordNote = new QList<int>;
                QList<QString> *RecordUID = new QList<QString>;
                QList<QString> *RecordText = new QList<QString>;
                QList<QString> *RecordTime = new QList<QString>;
                for(int i=0;i<RecordNum;i++){
                    QJsonObject RecordI = RecordList_value[i].toObject();
                    RecordNote->append(RecordI.value("Note").toInt());
                    RecordUID->append(RecordI.value("UID").toString());
                    RecordText->append(RecordI.value("Text").toString());
                    RecordTime->append(RecordI.value("Time").toString());
                }

                qDebug()<<RecordNum<<*(RecordUID)<<*(RecordText)<<*(RecordTime);
                global->RecordNote=RecordNote;
                global->RecordUID=RecordUID;
                global->RecordText=RecordText;
                global->RecordTime=RecordTime;
            }
        }
        file.close();
    }
}

void JsonOperator::readGroupRecord(QString GroupID){
    qDebug()<<"readGroupRecord";
    QFile file(global->path+"User/"+global->UID+"/GroupRecord/"+GroupID+".json");
    if(!file.exists()){
        qDebug()<<"readGroupRecord error";
        return;
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QByteArray text = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
        if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
            if(document.isObject()){
                QJsonObject object = document.object();
                QJsonValue RecordNum_value = object.value("RecordNum");
                int RecordNum=RecordNum_value.toInt();
                QJsonArray RecordList_value = object.value("RecordList").toArray();
                QList<int> *RecordNote = new QList<int>;
                QList<QString> *RecordUID = new QList<QString>;
                QList<QString> *RecordText = new QList<QString>;
                QList<QString> *RecordTime = new QList<QString>;
                for(int i=0;i<RecordNum;i++){
                    QJsonObject RecordI = RecordList_value[i].toObject();
                    RecordNote->append(RecordI.value("Note").toInt());
                    RecordUID->append(RecordI.value("UID").toString());
                    RecordText->append(RecordI.value("Text").toString());
                    RecordTime->append(RecordI.value("Time").toString());
                }

                qDebug()<<*(RecordUID)<<*(RecordText)<<*(RecordTime);
                global->RecordNote=RecordNote;
                global->RecordUID=RecordUID;
                global->RecordText=RecordText;
                global->RecordTime=RecordTime;
            }
        }
        file.close();
    }
}

void JsonOperator::addFriendtoList(QString friendID, QString friendName){
    qDebug()<<"addFriendtoList";
    QFile file(global->path+"User/"+global->UID+"/FriendList.json");
    if(!file.exists()){
        qDebug()<<"addFriendtoList error";
        return;
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
        file.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue FriendNum_value = object.value("FriendNum");
            int FriendNum=FriendNum_value.toInt();
            QJsonArray FriendList_value = object.value("FriendList").toArray();
            int flag=0;
            for(int i=0;i<FriendNum;i++){
                QJsonObject friendiInfo = FriendList_value[i].toObject();
                if(friendiInfo.value("FriendID").toString()==friendID) flag=1;
            }
            if(!flag){
                QJsonObject *newFriendInfo = new QJsonObject();
                newFriendInfo->insert("FriendID",friendID);
                newFriendInfo->insert("FriendName",friendName);
                qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
                int rand = qrand() % 3;
                QString randNum;
                if(rand==1) randNum=1;
                else if(rand==2) randNum=2;
                else randNum=3;
                newFriendInfo->insert("FriendHead","head"+randNum+".png");
                FriendList_value.append(QJsonValue(*newFriendInfo));
                FriendNum++;
                object = QJsonObject();
                object.insert("FriendNum",FriendNum);
                object.insert("FriendList",FriendList_value);
                document = QJsonDocument(object);
                if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
                    file.write(document.toJson());
                }
                //创建聊天记录.json文件
                QFile recordfile(global->path+"User/"+global->UID+"/FriendRecord/"+friendID+".json");
                recordfile.open(QIODevice::WriteOnly);
                recordfile.close();
                QJsonObject newRecord;
                newRecord.insert("RecordNum",0);
                newRecord.insert("RecordList",QJsonValue());
                recordfile.open(QIODevice::WriteOnly|QIODevice::Text);
                QJsonDocument doc = QJsonDocument(newRecord);
                recordfile.write(doc.toJson());
                recordfile.close();
            }
        }
    }
}

void JsonOperator::addGrouptoList(QString groupID,QString groupName){
    qDebug()<<"addGrouptoList";
    QFile file(global->path+"User/"+global->UID+"/GroupList/GroupList.json");
    if(!file.exists()){
        qDebug()<<"addGrouptoList error";
        return;
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
        file.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue GroupNum_value = object.value("GroupNum");
            int GroupNum=GroupNum_value.toInt();
            QJsonArray GroupList_value = object.value("GroupList").toArray();
            int flag=0;
            for(int i=0;i<GroupNum;i++){
                QJsonObject GroupiInfo = GroupList_value[i].toObject();
                if(GroupiInfo.value("GroupID").toString()==groupID) flag=1;
            }
            if(!flag){
                QJsonObject *newGroupInfo = new QJsonObject();
                newGroupInfo->insert("GroupID",groupID);
                newGroupInfo->insert("GroupName",groupName);
                newGroupInfo->insert("GroupHead","grouphead.png");
                GroupList_value.append(QJsonValue(*newGroupInfo));
                GroupNum++;
                object = QJsonObject();
                object.insert("GroupNum",GroupNum);
                object.insert("GroupList",GroupList_value);
                document = QJsonDocument(object);
                if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
                    file.write(document.toJson());
                }
                //创建聊天记录.json文件
                QFile recordfile(global->path+"User/"+global->UID+"/GroupRecord/"+groupID+".json");
                recordfile.open(QIODevice::WriteOnly);
                recordfile.close();
                QJsonObject newRecord;
                newRecord.insert("RecordNum",0);
                newRecord.insert("RecordList",QJsonValue());
                recordfile.open(QIODevice::WriteOnly|QIODevice::Text);
                QJsonDocument doc = QJsonDocument(newRecord);
                recordfile.write(doc.toJson());
                recordfile.close();
            }
        }
    }
}

void JsonOperator::addGroupMembertoList(QString GroupID,QString groupMemberID,QString groupMemberName){
    qDebug()<<"addGroupMembertoList";
    QFile file(global->path+"User/"+global->UID+"/GroupList/"+GroupID+".json");
    if(!file.exists()){
        qDebug()<<"addGroupMembertoList error";
        return;
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
        file.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue GroupMemberNum_value = object.value("GroupMemberNum");
            int GroupMemberNum=GroupMemberNum_value.toInt();
            QJsonArray GroupMemberList_value = object.value("GroupMemberList").toArray();
            object = QJsonObject();
            object.insert("GroupMemberID",groupMemberID);
            object.insert("GroupMemberName",groupMemberName);
            object.insert("GroupMemberHead","head3.png");
            GroupMemberList_value.append(QJsonValue(object));
            object = QJsonObject();
            object.insert("GroupMemberNum",GroupMemberNum+1);
            object.insert("GroupMemberList",GroupMemberList_value);
            document = QJsonDocument(object);
            file.open(QIODevice::WriteOnly|QIODevice::Text);
            file.write(document.toJson());
            file.close();
        }
    }

}

void JsonOperator::addFriendRecord(QString friendID,int type,QString context){
    qDebug()<<"addFriendRecord";
    QFile recordfile(global->path+"User/"+global->UID+"/FriendRecord/"+friendID+".json");
    if(!recordfile.exists()){
        qDebug()<<"addFriendRecord error";
    }
    QByteArray text;
    if(recordfile.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = recordfile.readAll();
        recordfile.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue RecordNum_value = object.value("RecordNum");
            int RecordNum=RecordNum_value.toInt();
            RecordNum++;
            QJsonArray RecordList_value = object.value("RecordList").toArray();
            QDateTime dateTime = QDateTime::currentDateTime();
            QString time = dateTime.toString("yyyyMMddhhmmss");
            QJsonObject newRecord;
            newRecord.insert("Note",RecordNum);
            //type为1表示对方发的，0表示自己发的
            if(type) newRecord.insert("UID",friendID);
            else newRecord.insert("UID",global->UID);
            newRecord.insert("Text",context);
            newRecord.insert("Time",time);
            qDebug()<<newRecord;
            RecordList_value.append(QJsonValue(newRecord));
            object = QJsonObject();
            object.insert("RecordNum",RecordNum);
            object.insert("RecordList",RecordList_value);
            document = QJsonDocument(object);
            if(recordfile.open(QIODevice::WriteOnly|QIODevice::Text)){
                recordfile.write(document.toJson());
                recordfile.close();
            }
        }
    }
}

void JsonOperator::addGroupRecord(QString groupID,QString groupMemberID,QString context){
    qDebug()<<"addGroupRecord";
    QFile recordfile(global->path+"User/"+global->UID+"/GroupRecord/"+groupID+".json");
    if(!recordfile.exists()){
        qDebug()<<"addGroupRecord error";
    }
    QByteArray text;
    if(recordfile.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = recordfile.readAll();
        recordfile.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue RecordNum_value = object.value("RecordNum");
            int RecordNum=RecordNum_value.toInt();
            RecordNum++;
            QJsonArray RecordList_value = object.value("RecordList").toArray();
            QDateTime dateTime = QDateTime::currentDateTime();
            QString time = dateTime.toString("yyyyMMddhhmmss");
            QJsonObject newRecord;
            newRecord.insert("Note",RecordNum);
            //type为1表示对方发的，0表示自己发的
            newRecord.insert("UID",groupMemberID);
            newRecord.insert("Text",context);
            newRecord.insert("Time",time);
            qDebug()<<newRecord;
            RecordList_value.append(QJsonValue(newRecord));
            object = QJsonObject();
            object.insert("RecordNum",RecordNum);
            object.insert("RecordList",RecordList_value);
            document = QJsonDocument(object);
            if(recordfile.open(QIODevice::WriteOnly|QIODevice::Text)){
                recordfile.write(document.toJson());
                recordfile.close();
            }
        }
    }
}

void JsonOperator::removeGroupFromList(QString GroupID){
    qDebug()<<"removeGroupFromList";
    QFile file(global->path+"User/"+global->UID+"/GroupList/GroupList.json");
    if(!file.exists()){
        qDebug()<<"removeGroupFromList error";
        return;
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
        file.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue GroupNum_value = object.value("GroupNum");
            int GroupNum=GroupNum_value.toInt();
            QJsonArray GroupList_value = object.value("GroupList").toArray();
            QList<QString> *GroupNameList = new QList<QString>;
            QList<QString> *GroupIDList = new QList<QString>;
            QList<QString> *GroupHeadList = new QList<QString>;
            int flag=GroupNum;
            for(int i=0;i<flag;i++){
                QJsonObject GroupiInfo = GroupList_value[i].toObject();
                qDebug()<<GroupiInfo.value("GroupID").toString();
                if(GroupiInfo.value("GroupID").toString()==GroupID){
                    GroupNum-=1;
                    continue;
                }
                GroupIDList->append(GroupiInfo.value("GroupID").toString());
                GroupNameList->append(GroupiInfo.value("GroupName").toString());
                GroupHeadList->append(GroupiInfo.value("GroupHead").toString());
            }
            object = QJsonObject();
            GroupList_value = QJsonArray();
            for(int i=0;i<GroupNum;i++){
                QJsonObject GroupiInfo;
                GroupiInfo.insert("GroupID",(*GroupIDList)[i]);
                GroupiInfo.insert("GroupName",(*GroupNameList)[i]);
                GroupiInfo.insert("GroupHead",(*GroupHeadList)[i]);
                GroupList_value.append(QJsonValue(GroupiInfo));
            }
            object.insert("GroupNum",GroupNum);
            object.insert("GroupList",GroupList_value);
            document = QJsonDocument(object);
            if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
                file.write(document.toJson());
                file.close();
            }
            //删除聊天记录.json文件
            QFile recordfile(global->path+"User/"+global->UID+"/GroupRecord/"+GroupID+".json");
            recordfile.remove();
        }
    }
}


void JsonOperator::removeFriendFromList(QString FriendID){
    qDebug()<<"removeFriendFromList";
    QFile file(global->path+"User/"+global->UID+"/FriendList.json");
    if(!file.exists()){
        qDebug()<<"removeFriendFromList error";
        return;
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
        file.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue FriendNum_value = object.value("FriendNum");
            int FriendNum=FriendNum_value.toInt();
            QJsonArray FriendList_value = object.value("FriendList").toArray();
            QList<QString> *FriendNameList = new QList<QString>;
            QList<QString> *FriendIDList = new QList<QString>;
            QList<QString> *FriendHeadList = new QList<QString>;
            int flag=FriendNum;
            for(int i=0;i<flag;i++){
                QJsonObject friendiInfo = FriendList_value[i].toObject();
                if(friendiInfo.value("FriendID").toString()==FriendID) {
                    FriendNum--;
                    continue;
                }
                FriendIDList->append(friendiInfo.value("FriendID").toString());
                FriendNameList->append(friendiInfo.value("FriendName").toString());
                FriendHeadList->append(friendiInfo.value("FriendHead").toString());
            }
            object = QJsonObject();
            FriendList_value = QJsonArray();
            for(int i=0;i<FriendNum;i++){
                QJsonObject friendiInfo;
                friendiInfo.insert("FriendID",(*FriendIDList)[i]);
                friendiInfo.insert("FriendName",(*FriendNameList)[i]);
                friendiInfo.insert("FriendHead",(*FriendHeadList)[i]);
                FriendList_value.append(QJsonValue(friendiInfo));
            }
            object.insert("FriendNum",FriendNum);
            object.insert("FriendList",FriendList_value);
            document = QJsonDocument(object);
            if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
                file.write(document.toJson());
                file.close();
            }
            //删除聊天记录.json文件
            QFile recordfile(global->path+"User/"+global->UID+"/FriendRecord/"+FriendID+".json");
            recordfile.remove();
        }
    }
}


void JsonOperator::removeGroupMemberFromList(QString GroupID,QString GroupMemberID){
    qDebug()<<"removeGroupMemberFromList";
    QFile file(global->path+"User/"+global->UID+"/GroupList/"+GroupID+".json");
    if(!file.exists()){
        qDebug()<<"removeGroupMemberFromList error";
        return;
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
        file.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue GroupMemberNum_value = object.value("GroupMemberNum");
            int GroupMemberNum=GroupMemberNum_value.toInt();
            QJsonArray GroupMemberList_value = object.value("GroupMemberList").toArray();
            QJsonArray new_GroupMemberList = QJsonArray();
            int flag = GroupMemberNum;
            for(int i=0;i<flag;i++){
                QJsonObject GroupMemberiInfo = GroupMemberList_value[i].toObject();
                if(GroupMemberiInfo.value("GroupMemberID").toString()==GroupMemberID){
                    GroupMemberNum--;
                    continue;
                }
                new_GroupMemberList.append(GroupMemberiInfo);
            }
            object = QJsonObject();
            object.insert("GroupMemberNum",GroupMemberNum);
            object.insert("GroupMemberList",new_GroupMemberList);
            document = QJsonDocument(object);
            if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
                file.write(document.toJson());
                file.close();
            }
        }
    }

}

QString JsonOperator::findFriendName(QString friendID){
    QFile file(global->path+"User/"+global->UID+"/FriendList.json");
    if(!file.exists()){
        qDebug()<<"findFriendName error";
        return "";
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
        file.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue FriendNum_value = object.value("FriendNum");
            int FriendNum=FriendNum_value.toInt();
            QJsonArray FriendList_value = object.value("FriendList").toArray();
            for(int i=0;i<FriendNum;i++){
                QJsonObject friendiInfo = FriendList_value[i].toObject();
                if(friendiInfo.value("FriendID").toString()==friendID) return friendiInfo.value("FriendName").toString();
            }
        }
    }
    qDebug()<<"NoSuchFriendID";
    return "";
}


QString JsonOperator::findGroupName(QString GroupID){
    QFile file(global->path+"User/"+global->UID+"/GroupList/GroupList.json");
    if(!file.exists()){
        qDebug()<<"findGroupName error";
        return "";
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
        file.close();
    }
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue GroupNum_value = object.value("GroupNum");
            int GroupNum=GroupNum_value.toInt();
            QJsonArray GroupList_value = object.value("GroupList").toArray();
            for(int i=0;i<GroupNum;i++){
                QJsonObject GroupiInfo = GroupList_value[i].toObject();
                if(GroupiInfo.value("GroupID").toString()==GroupID) return GroupiInfo.value("GroupName").toString();
            }
        }
    }
    qDebug()<<"NoSuchGroupID";
    return "";
}

QString JsonOperator::findGroupMemberName(QString GroupID,QString GroupMemberID){
    qDebug()<<"findGroupMemberName";
    QFile file(global->path+"User/"+global->UID+"/GroupList/"+GroupID+".json");
    if(!file.exists()){
        qDebug()<<"findGroupMemberName error";
        return "";
    }
    QByteArray text;
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        text = file.readAll();
    }
    file.close();
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(text, &jsonError);
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(document.isObject()){
            QJsonObject object = document.object();
            QJsonValue GroupMemberNum_value = object.value("GroupMemberNum");
            int GroupMemberNum=GroupMemberNum_value.toInt();
            QJsonArray GroupMemberList_value = object.value("GroupMemberList").toArray();
            int flag = GroupMemberNum;
            for(int i=0;i<flag;i++){
                QJsonObject GroupMemberiInfo = GroupMemberList_value[i].toObject();
                if(GroupMemberiInfo.value("GroupMemberID").toString()==GroupMemberID){
                    return GroupMemberiInfo.value("GroupMemberName").toString();
                }
            }
        }
    }
    qDebug()<<"noSuchGroupMember";
    return "";
}

void JsonOperator::initUserData(QString UserID,QString UserName){
    QString path = global->path+"User/"+UserID;
    QDir dir;
    if(dir.exists(path)) return ;
    dir.mkpath(path);
    dir.mkpath(path+"/FriendRecord");
    dir.mkpath(path+"/GroupList");
    dir.mkpath(path+"/GroupRecord");
    dir.mkpath(path+"/File");
    QFile UserInfofile(path+"/UserInfo.json");
    QJsonObject object;
    object.insert("UserID",UserID);
    object.insert("UserName",UserName);
    object.insert("UserHead","9999.jpg");
    QJsonDocument doc = QJsonDocument(object);
    UserInfofile.open(QIODevice::WriteOnly|QIODevice::Text);
    UserInfofile.close();
    if(UserInfofile.open(QIODevice::WriteOnly|QIODevice::Text)){
        UserInfofile.write(doc.toJson());
        UserInfofile.close();
    }
    QFile FriendListfile(path+"/FriendList.json");
    object=QJsonObject();
    object.insert("FriendNum",0);
    object.insert("FriendList",QJsonArray());
    doc = QJsonDocument(object);
    FriendListfile.open(QIODevice::WriteOnly|QIODevice::Text);
    FriendListfile.close();
    if(FriendListfile.open(QIODevice::WriteOnly|QIODevice::Text)){
        FriendListfile.write(doc.toJson());
        FriendListfile.close();
    }
    QFile GroupListfile(path+"/GroupList/GroupList.json");
    object=QJsonObject();
    object.insert("GroupNum",0);
    object.insert("GroupList",QJsonArray());
    doc = QJsonDocument(object);
    GroupListfile.open(QIODevice::WriteOnly|QIODevice::Text);
    GroupListfile.close();
    if(GroupListfile.open(QIODevice::WriteOnly|QIODevice::Text)){
        GroupListfile.write(doc.toJson());
        GroupListfile.close();
    }
    return ;
}

