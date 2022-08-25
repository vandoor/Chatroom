#include "user.h"

User::User(QString uID,QString uName,QString uhead):
    UID(uID),UName(uName),UHead(uhead)
{

}

QIcon User::getHead(){
    return QIcon(UHead);
}

QString User::getUName(){
    return UName;
}
