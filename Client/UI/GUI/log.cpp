#include "log.h"
#include "ui_log.h"
#include <QDebug>
#include <QMessageBox>
#include <QCommandLinkButton>

Log::Log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);

    global = new Global();
    signalOpt = global->signalOpt;
    jsonOperator = new JsonOperator();

    setFixedSize(this->size());
    ui->password->setEchoMode(QLineEdit::Password);
    //点击登录按钮
    connect(ui->login,&QPushButton::clicked,this,&Log::login);

    //跳转到注册界面
    connect(ui->toLogon,&QCommandLinkButton::clicked,this,[=]{
        emit toLogon();
    });
}

Log::~Log()
{
    delete ui;
}


QString Log::getAccount(){
    return account;
}


void Log::login(){
    signalOpt = global->signalOpt;
    account=ui->account->text();
    password=ui->password->text();
    global->UID=account;
    qDebug()<<account<<password;
    signalOpt->login(account,password);
}

void Log::loginSuccessfully(QString UserName){
    jsonOperator->initUserData(account,UserName);
    return ;
}

void Log::loginUnsuccessfully(){
    int ret=QMessageBox::critical(this,tr("错误"),tr("用户名或密码输入错误"),tr("重新输入"),tr("退出"));
    if(ret) this->close();
}
