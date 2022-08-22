#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    int flag=1;
    //0 -> 用户模式,初始为登陆界面
    //1 -> 开发者模式(做了一小部分)
    //2 -> 直接进ui界面
    ui->setupUi(this);
    global = new Global();
    signalOpt = global->signalOpt;
    log = new Log(nullptr);
    logon = new Logon(nullptr);
    testBox = new TestBox(nullptr);
    testBox->setSignalOpt(signalOpt);

    logon->setFixedSize(log->size());
    this->hide();
    log->show();

    if(flag==1){
        log->show();
        testBox->show();
        mainUI = new MainUI(nullptr);
        mainUI->show();
    }
    else if(flag==2){
        log->hide();
        mainUI = new MainUI(nullptr);
        mainUI->show();
        testBox->hide();
    }
    //从登陆界面进入注册界面
    connect(log,&Log::toLogon,this,[=](){
        QPoint point = log->pos();
        log->hide();
        logon->move(point);
        logon->show();
    });

    //从注册界面进入登录界面
    connect(logon,&Logon::toLog,this,[=](){
        QPoint point = logon->pos();
        logon->hide();
        log->move(point);
        log->show();

    });

    //登陆成功

    //当登录界面或注册界面关闭时，所有界面关闭
    connect(logon,&QObject::destroyed,this,&Widget::closeAllWidget);
    connect(log,&QObject::destroyed,this,&Widget::closeAllWidget);


    //用户登录请求
    //判断是否登陆成功
    //登陆成功
    connect(signalOpt,&SignalOpt::loginSuccessfully,this,[=](QString UserName){
        mainUI = new MainUI(nullptr);
        mainUI->show();
        mainUI->setUID(log->getAccount());
        log->hide();
        //同时当主界面关闭时，所有界面关闭
        connect(mainUI,&QObject::destroyed,this,&Widget::closeAllWidget);
        log->loginSuccessfully(UserName);
    });
    //登陆失败则选择重新输入或者退出界面
    connect(signalOpt,&SignalOpt::loginUnsuccessfully,this,[=](){
        log->loginUnsuccessfully();
    });


    //服务器回应注册请求
    connect(signalOpt,&SignalOpt::logonSuccessfully,this,[=](QString UID){
        logon->logonSuccessfully(UID);
    });
    connect(signalOpt,&SignalOpt::logonUnsuccessfully,this,[=](){
        logon->logonUnsuccessfully();
    });


}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeAllWidget(){
    if(log) log->close();
    if(logon) logon->close();
    if(mainUI) mainUI->close();
    this->close();
    exit(0);
}
