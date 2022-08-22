#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <GUI\log.h>
#include <GUI\mainui.h>
#include <GUI\logon.h>
#include <GUI\testbox.h>
#include <global.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void closeAllWidget();

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Log *log;
    Logon *logon;
    MainUI *mainUI;
    TestBox * testBox;

    Global * global;
    SignalOpt * signalOpt;
};

#endif // WIDGET_H
