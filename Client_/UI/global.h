#ifndef GLOBAL_H
#define GLOBAL_H
#include "signalopt.h"
#include <QString>

class Global : public QWidget
{
    Q_OBJECT
public slots:
    void loginSuccessfully(QString uName);
public:
    Global(QWidget * parent = nullptr);
    static SignalOpt *signalOpt;
    static QString UID;
    static QString UName;
    static QString UHead;
    static QString nowGroupID;
    static QList<QString> *FriendNameList;
    static QList<QString> *FriendIDList;
    static QList<QString> *FriendHeadList;
    static QList<QString> *GroupNameList;
    static QList<QString> *GroupIDList;
    static QList<QString> *GroupHeadList;
    static QList<QString> *GroupMemberNameList;
    static QList<QString> *GroupMemberIDList;
    static QList<QString> *GroupMemberHeadList;
    static QList<int> *RecordNote;
    static QList<QString> *RecordUID;
    static QList<QString> *RecordText;
    static QList<QString> *RecordTime;
    static QString path;
};

#endif // GLOBAL_H
