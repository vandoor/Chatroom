#ifndef GROUP_H
#define GROUP_H
#include <QString>
#include <QList>

class Group
{
public:
    Group(QString, QString, QString, int, QList<QString>, QList<QString>, QList<QString>);
private:
    QString groupID,groupName,groupHead;
    QList<QString> groupMemberID,groupMemberName,groupMemberHead;
    int size;

};

#endif // GROUP_H
