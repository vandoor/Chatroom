#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QStringList iconList,QWidget *parent):
    QPushButton (parent)
{
    if(iconList.length()<3){
        qDebug()<<"myPushButton create error";
    }
    defaultIcon = iconList[0];
    inIcon = iconList[1];
    clickedIcon = iconList[2];

    setImage(defaultIcon);
}

void MyPushButton::enterEvent(QEvent *){
    this->setImage(inIcon);
}

void MyPushButton::leaveEvent(QEvent *){
    this->setImage(defaultIcon);
}

void MyPushButton::mousePressEvent(QMouseEvent *){
    emit clicked();
    this->setImage(clickedIcon);
}

void MyPushButton::mouseMoveEvent(QMouseEvent*){
    this->setImage(clickedIcon);
}


void MyPushButton::mouseReleaseEvent(QMouseEvent *){
    this->setImage(defaultIcon);
}

void MyPushButton::setImage(QString icon){
    QPixmap pixmap =QPixmap(icon);
    setIcon(QIcon(pixmap));
    setIconSize(QSize(40,40));
    setStyleSheet("border:none;");
}

