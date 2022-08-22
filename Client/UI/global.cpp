#include "global.h"

Global::Global(QWidget * parent):
    QWidget (parent)
{
    if(signalOpt==nullptr) signalOpt = new SignalOpt(nullptr);
    if(UID==nullptr) UID="9999";
    if(UName==nullptr) UName="测试用户";
    if(UHead==nullptr) UHead="9999.jpg";
    if(FriendNameList==nullptr) FriendNameList = new QList<QString>();
    if(FriendIDList==nullptr) FriendIDList = new QList<QString>();
    if(FriendHeadList==nullptr) FriendHeadList = new QList<QString>();
    if(GroupNameList==nullptr) GroupNameList = new QList<QString>();
    if(GroupIDList==nullptr) GroupIDList = new QList<QString>();
    if(GroupHeadList==nullptr) GroupHeadList = new QList<QString>();
    if(GroupMemberNameList==nullptr) GroupMemberNameList = new QList<QString>();
    if(GroupMemberIDList==nullptr) GroupMemberIDList = new QList<QString>();
    if(GroupMemberHeadList==nullptr) GroupMemberHeadList = new QList<QString>();
    if(RecordNote==nullptr) RecordNote = new QList<int>();
    if(RecordUID==nullptr) RecordUID = new QList<QString>();
    if(RecordText==nullptr) RecordText = new QList<QString>();
    if(RecordTime==nullptr) RecordTime = new QList<QString>();
    if(path==nullptr) path="D:/Qchat/";

    connect(signalOpt,&SignalOpt::loginSuccessfully,this,&Global::loginSuccessfully);

}

SignalOpt * Global::signalOpt;
QString Global::UID;
QString Global::UName;
QString Global::UHead;
QList<QString> *Global::FriendNameList;
QList<QString> *Global::FriendIDList;
QList<QString> *Global::FriendHeadList;
QList<QString> *Global::GroupNameList;
QList<QString> *Global::GroupIDList;
QList<QString> *Global::GroupHeadList;
QList<QString> *Global::GroupMemberNameList;
QList<QString> *Global::GroupMemberIDList;
QList<QString> *Global::GroupMemberHeadList;
QList<int> *Global::RecordNote;
QList<QString> *Global::RecordUID;
QList<QString> *Global::RecordText;
QList<QString> *Global::RecordTime;
QString Global::path;
QString Global::nowGroupID;

void Global::loginSuccessfully(QString uName){
    UName = uName;
}
