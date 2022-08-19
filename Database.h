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
private:
    sqlite3 * handler;//句柄
    char * mesg;//错误信息
    int val;//用来判断各种错误
	int RandomID(const char*);
};
