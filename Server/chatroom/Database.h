#include <stdio.h>
#include <sqlite3.h>
#include <vector>
#include <string>
#include <map>

using std::string;
using std::vector;
using std::map;

class Database
{
public:
    Database();
    ~Database();
	static int nRows;
	static vector<int>v;
	static string str;
	static vector<map<string,string> > AllResult;
	int Register(const char *,const char *);
	int Login(const char*, const char *);
	string GetUsername(const char*);
	string GetGroupName(const char*);
	vector<map<string,string> > GetOfflineRecords(const char*t,const char* u);
	int DeleteOfflineRecords(const char*t, const char*u);
	int CreateGroup(const char*,const char*);
	int GetAdmin(const char*);
	int AcceptFriend(const char* recv, const char* send);
	int DeleteFriend(const char* ,const char*);
	int AskFriend(const char*,const char*);
	int Join(const char*user, const char*admin,const char*group);
	int Invite(const char*,const char*,const char*);
	int EnterGroup(const char*, const char*);
	int QuitGroup(const char*, const char*);
	int SaveOfflineMSG(const char*, const char*, const char*, const char*, int,int);
	std::vector<int> GetMember(const char*);
private:
    sqlite3 * handler;//句柄
	char * order;
    char * errormsg;//错误信息
    int val;//用来判断各种错误
	int RandomID(const char*);
	int Count(const char*,const char*, const char*);
};

