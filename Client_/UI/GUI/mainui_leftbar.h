#ifndef MAINUI_LEFTBAR_H
#define MAINUI_LEFTBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "signalopt.h"
#include "global.h"
#include "mypushbutton.h"

class MainUI_LeftBar : public QWidget
{
    Q_OBJECT
public:
    explicit MainUI_LeftBar(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event);

private:
    QPushButton *recentConversation,*friendList,*settings;
    QLabel * headPhoto;

    Global * global;
    SignalOpt * signalOpt;
signals:
    void toRecentConversation();
    void toFriendList();
    void toSettings();
public slots:
};

#endif // MAINUI_LEFTBAR_H
