#ifndef NOTICEITEM_H
#define NOTICEITEM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <jsonoperator.h>

class NoticeItem : public QWidget
{
    Q_OBJECT
public:
    explicit NoticeItem(QWidget *parent = nullptr);
    void setType(QString Type){ type = Type; }
    void setFriendID(QString FriendID){ friendID = FriendID; }
    void setFriendName(QString FriendName){ friendName = FriendName; }
    void setGroupID(QString GroupID){ groupID = GroupID; }
    void setGroupName(QString GroupName){ groupName = GroupName; }
    void setInfo(QString friendID,QString friendName,QString groupID,QString groupName);
    void resetButton();
signals:
    void sendsignal(QString signal);

public slots:

private:
    QLabel * noticeText;
    QPushButton *agree,*disagree,*know;
    QString type;
    QString friendID,friendName,groupID,groupName;
    JsonOperator * jsonOperator;

};

#endif // NOTICEITEM_H
