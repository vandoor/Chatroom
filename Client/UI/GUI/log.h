#ifndef LOG_H
#define LOG_H

#include <QWidget>
#include "signalopt.h"
#include "global.h"
#include "jsonoperator.h"

namespace Ui {
class Log;
}

class Log : public QWidget
{
    Q_OBJECT
public slots:
    void login();
public:
    explicit Log(QWidget *parent = nullptr);
    ~Log();
    QString getAccount();
    void loginSuccessfully(QString UserName);
    void loginUnsuccessfully();

private:
    Ui::Log *ui;
    QString account;
    QString password;
    QString name;

    Global * global;
    SignalOpt * signalOpt;
    JsonOperator * jsonOperator;

signals:
    void toLogon();
};

#endif // LOG_H
