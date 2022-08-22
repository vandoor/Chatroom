#ifndef USER_H
#define USER_H

#include <QString>
#include <QIcon>

class User
{
public:
    User(QString uID,QString uName,QString uhead);
    QIcon getHead();
    QString getUName();

private:
    QString UName;
    QString UID;
    QString UHead;
};

#endif // USER_H

Q_DECLARE_TYPEINFO(User, Q_MOVABLE_TYPE);

#ifndef QT_NO_DATASTREAM
Q_CORE_EXPORT QDataStream &operator<<(QDataStream &, const User &);
Q_CORE_EXPORT QDataStream &operator>>(QDataStream &, User &);
#endif

#ifndef QT_NO_DEBUG_STREAM
Q_CORE_EXPORT QDebug operator<<(QDebug, const User &);
#endif
