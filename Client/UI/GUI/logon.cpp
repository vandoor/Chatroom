#include "logon.h"
#include "ui_logon.h"
#include <QDebug>
#include <QMessageBox>
Logon::Logon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logon)
{
    ui->setupUi(this);

    global = new Global();

    ui->password1->setEchoMode(QLineEdit::Password);
    ui->password2->setEchoMode(QLineEdit::Password);
    //跳转到登录界面
    connect(ui->toLog,&QCommandLinkButton::clicked,this,[=](){
       emit toLog();
    });
    connect(ui->logon,&QPushButton::clicked,this,&Logon::logon);

}

Logon::~Logon()
{
    delete ui;
}

void Logon::logon(){
    signalOpt = global->signalOpt;
    uname=ui->uname->text();
    password1=ui->password1->text();
    password2=ui->password2->text();
    //用户名和密码合规性检验
    if(password1!=password2){
        int ret=QMessageBox::critical(this,tr("错误"),tr("两次输入的密码不一致"),tr("重新输入"),tr("退出"));
        if(ret) this->close();
        return ;
    }
    signalOpt->logon(uname,password1);
}

void Logon::logonSuccessfully(QString UID){
    QString info;
    info.append(tr("分配给您的ID为:"));
    info.append(UID);
    info.append(tr(",请您记好"));
    QMessageBox::information(nullptr,tr("注册成功"),info,tr("确定"));
    emit toLog();
}

void Logon::logonUnsuccessfully(){

}
