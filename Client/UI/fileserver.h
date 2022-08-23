#ifndef FILESERVER_H
#define FILESERVER_H

#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QObject>
#include "global.h"
#include "signalopt.h"
#include <QDir>
#include <QTime>
#include <QCoreApplication>


class FileServer : public QObject
{
    Q_OBJECT
public:
    FileServer(QObject *parent = Q_NULLPTR);
    void sendFile(QString filePath, QString UID, QString friendID);
    void recvFile(QByteArray data, int length, int index, QString filePath,QString fileName);
    QFile* temp;
    qint64 recvSize;
    Global * global;
    SignalOpt * signalOpt;
signals:
    void fileSendSuccessfully();
    void fileReceiveSuccessfully();
};

#endif // FILESERVER_H
