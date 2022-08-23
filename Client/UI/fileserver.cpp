#include "fileserver.h"
#define MAXLEN 512

FileServer::FileServer(QObject *parent):
    QObject(parent)
{
    global = new Global();
    signalOpt = global->signalOpt;

}


void FileServer::sendFile(QString filePath, QString UID, QString friendID)
{
    if(!filePath.isEmpty()){
        QFileInfo info(filePath);
        QString fileName = info.fileName();
        qint64 size = info.size();
        QFile file(filePath);
        bool legal = file.open(QIODevice::ReadOnly);
        if(!legal){
            qDebug()<<"文件打开失败";
        }

        int index = 1;
        qint64 len = 0;

        QDataStream in(&file);
        do{
            char buf[MAXLEN+10] = {0};
            len = in.readRawData(buf, MAXLEN);

            signalOpt->sendFilePiece(UID, friendID, fileName, size, index, buf);
            QTime t;
            t.start();
            while(t.elapsed()<300) QCoreApplication::processEvents();
            index++;
        }while(len > 0);
        emit fileSendSuccessfully();
        qDebug()<<"文件传输完成";
    }
}


void FileServer::recvFile(QByteArray Data, int length, int index, QString filePath,QString fileName)
{
    QString path = filePath+"/"+fileName;
    QDir dir;
    dir.mkpath(filePath);
    qDebug()<<"filePath:"<<filePath;

    qDebug()<<"往"+path+"处传输文件，目录为"+index+"";
    QFile temp(path);
    int result;
    if(index == 1){
        result=temp.open(QIODevice::WriteOnly);
        recvSize = 0;
    }
    else{
        result=temp.open(QIODevice::WriteOnly | QIODevice::Append);
    }

    qDebug()<<"Open result:"<<result;
    recvSize+=temp.write(Data);
    temp.close();
    qDebug()<<"RecvSize:"<<recvSize;

    if(recvSize == length){
        qDebug()<< "文件接收完成";
        emit fileReceiveSuccessfully();
    }
}
