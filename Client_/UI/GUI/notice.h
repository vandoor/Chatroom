#ifndef NOTICE_H
#define NOTICE_H

#include <QWidget>
#include <QVBoxLayout>
#include "global.h"
#include "noticeitem.h"
#include "jsonoperator.h"

namespace Ui {
class Notice;
}

class Notice : public QWidget
{
    Q_OBJECT

public:
    explicit Notice(QWidget *parent = nullptr);
    ~Notice();
    void resetNotice();
private:
    Ui::Notice *ui;

    int nowHeight;
    QList<NoticeItem *> item;
    Global * global;
    SignalOpt * signalOpt;
    JsonOperator *jsonOperator;
signals:
    void agreeNewFriend(QString friendID,QString friendName);
    void flashFriendList();
    void flashGroupList();


};

#endif // NOTICE_H
