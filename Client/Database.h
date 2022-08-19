#include <stdio.h>
#include <sqlite3.h>

class Database
{
public:
    Database();
    ~Database();
	static int nRows;
    int Register(const char *,const char *);
	int CreateGroup(const char*,const char*);	
	int AskFriend(const char*,const char*);
	int Join(const char*,const char*);
	int Invite(const char*,const char*,const char*);
private:
    sqlite3 * handler;//句柄
	char * order;
    char * errormsg;//错误信息
    int val;//用来判断各种错误
	int RandomID(const char*);
	int Count(const char*,const char*, const char*);
};
