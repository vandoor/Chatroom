#ifndef LOGON_H
#define LOGON_H

#include <QWidget>
#include "signalopt.h"
#include "global.h"
#include "qpainter.h"
namespace Ui {
class Logon;
}

class Logon : public QWidget
{
    Q_OBJECT
public slots:
    void logon();
public:
    explicit Logon(QWidget *parent = nullptr);
    ~Logon();
    void logonSuccessfully(QString UID);
    void logonUnsuccessfully();
    void paintEvent(QPaintEvent *event);


private:
    Ui::Logon *ui;
    QString uname,password1,password2;


    Global * global;
    SignalOpt * signalOpt;

signals:
    void toLog();
};

#endif // LOGON_H
