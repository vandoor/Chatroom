#ifndef TESTBOX_H
#define TESTBOX_H

#include <QWidget>
#include <signalopt.h>
#include <global.h>
#include "noticeitem.h"

namespace Ui {
class TestBox;
}

class TestBox : public QWidget
{
    Q_OBJECT

public:
    explicit TestBox(QWidget *parent = nullptr);
    ~TestBox();
    void setSignalOpt(SignalOpt * signalOpt);

private:
    Ui::TestBox *ui;
    QString login_account,logon_uname;
    QString login_password,logon_password1,logon_password2;

    Global *global;
    SignalOpt * signalOpt;
};

#endif // TESTBOX_H
