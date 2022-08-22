# json通信协议

## 注册用户
```
client -> server:
{
    "type": "register",
    "UserName": Uname(str),
    "Password": str
}
server -> client:
{
    "type": "register",
    "status": 0/1,
    "UserID": str
}
```

## 登录

登陆的时候还要接收几个消息（还没实现）：

- 离线好友信息
- 离线群聊信息
- 离线申请好友信息
- 离线申请加入群聊信息（所管理的群的）

```
client -> server:
{
	"type":"login",
	"UserID":str,
	"Password":s2
}
server -> client:
{
	"type":"login",
	"status":0(出错),100(用户ID或密码错误),1(成功)
	"UserName":""
}

```

## 建群
```
client -> server:
{
    "type": "creategroup",
    "UserID": str,
    "GroupName": str
}
server -> client:
{
    "type": "creategroup",
    "status": 0建群失败/1成功,
    "GroupID": groupid,
    "GroupName": str
}
```

## 加好友
```
client -> server:
{
    "type": "befriend",
    "UserID": str,
    "FriendID": str
}
server -> client:
{
    "type": "befriend",
    "status": 0出错/100查无此人/1成功,
    "FriendID": str
    "FriendName": str
}
server -> client: //朝申请对象发的
{
	"type": "askfriend",
	"ReceiverID": str,
	"SenderID": str
	"SenderName": str
}
```

### 接受添加好友

```
client -> server:
{
	"type":"acceptfriend",
	"result":0/1,
	"SenderID":"",
	"ReceiverID":""
}


server -> client: (sender 那一方)
{
	"type": "vertifyfriend",
	"result": 0/1,
	"SenderID": str, #发出添加好友请求的那个人
	"ReceiverID": str,
	"ReceiverName": str 
}
```

## 加入群聊

加入群聊的时候还要给在线群主发送申请

```
client -> server:
{
    "type": "join",
    "UserID": str,
    "GroupID": str
}
server -> client:
{
    "type": "join",
    "status": 0出错/101没有这个GroupID/1成功,
    "UserID": str,
    "GroupID": str,
    "GroupName": str
}
server -> client://朝对应群主发的
{
	"type": "askjoin",
	"ReceiverID": str,
	"SenderID": str,
	"GroupName": str,
	"GroupID": str
}

```

### 邀请好友入群

```
client -> server:
{
	"type":"invite",
	"UserID":str,
	"FriendID":str,
	"GroupID":str
}
server -> client:
{
	"type":"invite",
	"status":0出错/100查无此人/101查无此群/1成功,
	"FriendID": str,
	"GroupID": str,
	"GroupName": str
}
server -> client: (被邀请人)
{
	"type":"askinvite",
	"ReceiverID":str,
	"SenderID":str,
	"GroupID":str,
	"GroupName":str
}
```

### （管理员）同意入群

```
client -> server:
{
	"type":"approveenter",
	"result":0/1,
	"UserID":str, #UserID指的是申请人，应该用不上管理员的信息
	"GroupID":str
}

server -> client:  #申请入群那个人
{
	"type":"vertifygroup",
	"result":0/1,
	"UserID":str,
	"GroupName":str,
	"GroupID":str
}

/*应该是不要了
server -> client:
{
	"type":"approveenter",
	"status":0出错/1成功,
	"UserID":str,
	"UserName":str
	"GroupID":str,
}
*/
```

### （被邀请人）同意入群

```
client -> server:
{
	"type":"acceptinvite",
	"InviteID": str,
	"AcceptID": str, 
	"GroupID": str
}

server -> client:
{
	"type":"acceptinvite",
	"status": 0出错/1成功
	"InviteID": str,
	"AcceptID": str,
	"GroupID": str
}

```

### 私聊信息

```
client -> server:
{
	"type":"sendfriend",
	"UserID": str,
	"FriendID":str,
	"Message":str
}
server -> client: (当前client，表示是否发出去)
{
	"type":"sendfriend",
	"status":0/1
//我先不传这几个 如果要的话给我说一下
//	"UserID": str,
//	"FriendID":str
//	"Message":str
}
server -> client: (非当前client，接收信息)
{
	"type":"receivefriend",
	"SenderID":str,
	"Message":str
}
```

### 群聊信息

```
client -> server
{
	"type":"sendgroup",
	"UserID": str,
    "GroupID": str,
    "Message": str
}

server -> client: (当前client, 表示是否发出去)
{
	"type":"sendgroup",
	"status":0/1,
	"UserID":str,
	"GroupID":str,
	"Message": str
}

server -> client: (非当前client，接收信息)
{
	"type":"receivegroup",
	"GroupID":str,
	"SenderID":str,
	"Message":str
}
```

### 删除好友

```
client -> server
{
	"type": "deletefriend",
	"UserID": str,
	"FriendID": str
}
server -> client （删好友那一方）
{
	"type": "deletefriend",
    "status": 0/1, （出错或成功）
    "FriendID":str,
    "UserID":str
}

server -> client （被删好友那一方）
{
	"type": "losefriend",
	"UserID": str,
	"LoseID": str
}
```

### 退出群聊

```
client -> server
{
	"type" : "quit"
	"UserID" : str,
    "GroupID" : str
}
server -> client
{
	"type" : "quit",
	"status" : 0/1,
	"UserID" : str,
	"GroupID" : str
}
```

### 踢出群聊

```
client -> server
{
	"type" : "kickout",
	"AdminID" : str,
	"UserID" : str,
	"GroupID" : str
}
server -> client
{
	"type" : "kickout",
	"AdminID" : str,
	"status" : 0（出错）/1（成功）
	"UserID" : str
	"GroupID" : str
}
server -> client 被踢的那一个
{
	"type" : "kicked",
	"AdminID" : str,
	"UserID" : str,
	"GroupID" : str
}
```

### 获取群聊信息

```
client -> sever
{
	"type" : "getgroupinfo",
	"GroupID" : str
}

server -> client
{
	"type" : "groupinfo",
	"MemberCount" : int,
	"MemberList" : [
		{"UserID": str, "UserName": str},
		{"UserID": str, "UserName": str},
		...
	]
}
```

