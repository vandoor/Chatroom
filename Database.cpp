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
    if(val!=0)
    {
        printf("error");
    }
}

Database:: ~Database(){
        sqlite3_close(handler);
}


int check_exist(void*, int, char**, char**){
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
		int vals=sqlite3_exec(handler, order, check_exist, NULL, &errormsg);
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

int Database:: Register(const char *UserName, const char * Password)
{
	
    int UserID=RandomID("User");
	char order[BUFFER_SIZE];
	char* errormsg;
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
	char order[BUFFER_SIZE];
	char * errormsg;
	char tms[64];
	int val;
	getTime(tms);
	sprintf(order, "insert into Group_Info values(%d,'%s','0',%d,1,'%s')",
			GroupID, GroupName, UserID, tms);
	val=sqlite3_exec(handler, order, NULL, NULL, &errormsg);
	if(val){
		printf("create group error! - - %s",errormsg);
		return -1;
	}
	return GroupID;
}
