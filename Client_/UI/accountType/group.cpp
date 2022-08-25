#include "group.h"

Group::Group(QString GroupID, QString GroupName, QString GroupHead, int Size,
             QList<QString> GroupMemberID, QList<QString> GroupMemberName, QList<QString> GroupMemberHead):
    groupID(GroupID),groupName(GroupName),groupHead(GroupHead),size(Size),
    groupMemberID(GroupMemberID),groupMemberName(GroupMemberName),groupMemberHead(GroupMemberHead)
{

}
