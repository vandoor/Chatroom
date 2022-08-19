#include"Database.h"
#include<stdio.h>
#include<sqlite3.h>
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

const int BUFFER_SIZE=256;
int Database::nRows=0;
Database:: Database()
{
	srand((unsigned long long)(new char));
	int val = sqlite3_open("sqlite.db",&handler);//打开数据库
    order=new char[BUFFER_SIZE];
	errormsg=new char[BUFFER_SIZE];
	if(val!=0)
    {
        printf("error");
    }
}

Database:: ~Database(){
    sqlite3_close(handler);
	delete[]order;
	delete[]errormsg;
}


int ADDONE(void*, int, char**, char**){
	Database::nRows++;
	return 0;
}

int Database:: RandomID(const char* table){
	int ID=rand();
	char order[BUFFER_SIZE];
	char *errormsg;

	while(true){
		(ID*=rand())&=0x7fffffff;
		sprintf(order, "select * from %s where userid=%d", table, ID);
		Database::nRows=0;
		int vals=sqlite3_exec(handler, order, ADDONE, NULL, &errormsg);
		if(val){
			printf("error :%s\n", errormsg);
		}
		if(!Database::nRows) break;
	}
	return ID;
}

void getTime(char* tms){
	time_t t=time(0);
	strftime(tms, 32, "%Y-%m-%d", localtime(&t));
	cout<<"get time: "<<tms<<endl;
}

int Database::Count(const char* table, const char* idType, const char* idValue){
	Database::nRows=0;
	sprintf(order, "select * from %s where %s = %s",
		   	table, idType, idValue);
	val=sqlite3_exec(handler, order, ADDONE, NULL, &errormsg);
	if(val){
		printf("counting eror! - - %s", errormsg);
		return -1;
	}
	return 0;
}

int Database:: Register(const char *UserName, const char * Password)
{
	
    int UserID=RandomID("User");
	char tms[64];
	getTime(tms);
    sprintf(order,"insert into User values(%d,'%s','%s','0',0, '%s')",
			 UserID,UserName,Password,tms);
	printf("%s\n",order);
	val = sqlite3_exec(handler,order,NULL,NULL,&errormsg);
    if(val!=0)//注册失败
    {
        printf("insertion error! - -  %s",errormsg);
        return -1;
    }
    return UserID;
}
int Database::CreateGroup(const char* UserID, const char* GroupName)
{
	int GroupID=RandomID("Group_Info");
	char tms[64];
	getTime(tms);
	sprintf(order, "insert into Group_Info values(%d,'%s','0',%d,1,'%s')",
			GroupID, GroupName, UserID, tms);
	val=sqlite3_exec(handler, order, NULL, NULL, &errormsg);
	if(val){
		printf("create group error! - - %s",errormsg);
		return -1;
	}
	sprintf(order, "insert into Group_r values(%d, %d, '%s')", GroupID, UserID, tms);
	val=sqlite3_exec(handler, order, NULL, NULL, &errormsg);
	if(val){
		printf("create group error! - - %s",errormsg);
		return -1;
	}
	return GroupID;
}
int Database::AskFriend(const char* Fid,const char* Tid){
	char tms[64];
	getTime(tms);
	if(Count("User", "UserID", Tid)) return -1;
	if(!Database::nRows){
		printf("didn't find user%s", Tid);
		return 100;	
	}
	sprintf(order, "insert into friend_request values(%s,%s,%s)", 
			Tid, Fid, tms);
	val=sqlite3_exec(handler, order, NULL, NULL, &errormsg);
	if(val){
		printf("Befriend Error! - - %s", errormsg);
		return -1;
	}
	return 1;
}
int Database::Join(const char* UserID, const char* GroupID){
	char tms[64];
	getTime(tms);
	if(Count("group_info","groupID",GroupID)) return -1;
	if(!Database::nRows){
		printf("didn't find group");
		return 101;
	}
	sprintf(order, "insert into group_request values(%s,%s,%s)",
			UserID, GroupID, tms);
	val=sqlite3_exec(handler, order, NULL, NULL, &errormsg);
	if(val){
		printf("join group request error: - - %s", errormsg);
		return -1;
	}
	return 1;
}
int Database::Invite(const char* Uid, const char* Fid, const char* Gid){
	char tms[64];
	getTime(tms);
	if(Count("User","UserID", Fid)) return -1;
	if(!Database::nRows){
		printf("didn't find user %s", Fid);
		return 100;
	}
	if(Count("Group_info", "GroupID", Gid)) return -1;
	if(!Database::nRows){
		printf("didn't find group %s", Gid);
		return 101;
	}
	sprintf(order, "insert into invite_request values (%s,%s,%s,%s)",
			Uid, Fid, Gid, tms);
	val=sqlite3_exec(handler, order, NULL, NULL, &errormsg);
	if(val){
		printf("ask to invite error: - - %s", errormsg);
		return -1;
	}
	return 1;
}
