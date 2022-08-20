#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fcntl.h>
#include<pthread.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<set>
#include<vector>
#include<map>
#include<netinet/in.h>
#include<arpa/inet.h>
#include "./CJsonObject/CJsonObject.hpp"
#include"Database.h"

const char hvie='\n';
const int MYPORT = 8848;
const int BUFFER_SIZE=256;

using namespace std;

int sockfd;
set<int>connList;
sockaddr_in myAddr;
int Len;
map<string,int>code;
int userid[BUFFER_SIZE];
map<int,int> connect_id;

int CODEFOR(const string&s){
	return code[s];
}
int number(const string&s){
	int ret=0;
	for(int i=0;i<s.length();i++){
		ret=ret*10+(s[i]-'0');
	}
	return ret;
}
string to_string(int n){
	string s="";
	while(n) s+=(char)(n%10+'0');
	reverse(s.begin(),s.end());
	return s;
}
void *ProcessInput(void*id)
{
	int cid=*(int*)id, op;
	cout<<cid<<' '<<"joined\n";
	char buf[BUFFER_SIZE], buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    char ID[BUFFER_SIZE], ID2[BUFFER_SIZE];
	Database DB;
	while(true)
	{
		int rec=recv(cid, buf, BUFFER_SIZE, 0);
		if(rec<=0){
			cout<<cid<<' '<<"exit"<<hvie;
			pthread_exit(NULL);
		}
		//sscanf(buf, "# %d | %s | %s", &op, buf1, buf2);
		cout<<buf<<"\n";
		neb::CJsonObject job(buf), ret;
		string tmp, s1, s2, type;
		cout<<job.ToString()<<endl;
		if(!job.Get("type", type)) continue;
		switch(CODEFOR(type)){
			case 1:{
				//Register;
				cout<<"register!\n";
				job.Get("name", s1);
				job.Get("password", s2);
				int UID=DB.Register(s1.c_str(),
					   				s2.c_str());
				cout<<UID<<'\n';
				ret.Add("type", type);
				ret.Add("status", UID>=0);
				ret.Add("ID", UID);
				break;
			}		   
			case 2:{
				//Login;
				break;
			}		   
			case 3:{
				//Create Group
				cout<<"create group!\n";
				job.Get("UserID", s1);
				job.Get("GroupName", s2);
			    int GroupID=DB.CreateGroup(s1.c_str(),s2.c_str());
				cout<<"GroupID "<<GroupID<<endl;
				ret.Add("type", type);
				ret.Add("status", GroupID>=0);
				ret.Add("ID", GroupID);
				break;
			}
			case 4:{
				//AddFriend
				cout<<"ask to be friend!\n";
				job.Get("UserID", s1);
				job.Get("FriendID", s2);
				int result=DB.AskFriend(s1.c_str(),s2.c_str());
				ret.Add("type", type);
				if(result==100){
					ret.Add("status", 100);
					ret.Add("FriendID", s1);
				}
				else if(result==-1){
					ret.Add("status", 0);
				}
				else{
					ret.Add("status", 1);
					ret.Add("FriendID", s1);
				}
				break;
			}		   
			case 5:{
				//join
				cout<<"join\n";
				job.Get("UserID", s1);
				job.Get("GroupID", s2);
				int result=DB.Join(s1.c_str(),s2.c_str());
				ret.Add("type", type);
				if(result==101){
					ret.Add("status", 101);
					ret.Add("GroupID", s2);
				}
				else if(result==-1){
					ret.Add("status", 0);
				}
				else{
					ret.Add("status", 1);
					ret.Add("FriendID", s1);
					ret.Add("GroupID", s2);
				}
				break;
			}		   
			case 6:{
				cout<<"invite\n";
				job.Get("UserID", s1);
				job.Get("FriendID",s2);
				job.Get("GroupID", tmp);
				int result=DB.Invite(s1.c_str(),s2.c_str(),tmp.c_str());
				ret.Add("type", type);
				if(result==100){
					ret.Add("status",100);
					ret.Add("FriendID", s1);
				}
				else if(result==101){
					ret.Add("status", 101);
					ret.Add("GroupID", s2);
				}
				else if(result==-1){
					ret.Add("status", 0);
				}
				else{
					ret.Add("status", 1);
					ret.Add("FriendID", s1);
					ret.Add("GroupID", s2);
				}
				break;
			}
			case 7:{
				//sent to friend
				cout<<"send to friend\n";
				job.Get("UserID", s1);
				job.Get("FriendID",s2);
				job.Get("Message",tmp);
				//process online message
				int Fid=number(s2);
				if(connect_id.count(Fid)){
					//directly send
					int connID=connect_id[Fid];
					sprintf(buf2, "%s", tmp.c_str());
					neb::CJsonObject mess;
					mess.Add("type", "receivefriend");
					mess.Add("SenderID", s1);
					mess.Add("Message", tmp);
					sprintf(buf2, mess.ToString().c_str());
					write(connID, buf2, BUFFER_SIZE);
				}
				else{
					DB.SaveOfflineMSG(s1.c_str(), s2.c_str(), NULL,
						   	tmp.c_str(), 0);
				}
				break;
			}
			case 8:{
				cout<<"send to group\n";
				job.Get("UserID", s1);
				job.Get("GroupID", s2);
				job.Get("Message", tmp);
				vector<int>memberID=DB.GetMember(s2.c_str());
				for(int i=0,cnt=memberID.size();i<cnt;i++){
					int Fid=memberID[i];
					if(connect_id.count(Fid)){
						int connID=connect_id[Fid];
						sprintf(buf2, "%s", tmp.c_str());
						neb::CJsonObject mess;
						mess.Add("type", "receivegroup");
						mess.Add("Group", "GroupID");
						mess.Add("SenderID", s1);
						mess.Add("Message", tmp);
						sprintf(buf2, mess.ToString().c_str());
						write(connID, buf2, BUFFER_SIZE);
					}
					else{
						DB.SaveOfflineMSG(s1.c_str(), to_string(Fid).c_str(), s2.c_str(),
							   	tmp.c_str(), 1);
					}
				}
				break;
			}
			default:{
				cout<<"unkwown"<<hvie;
				
			}
		}
		sprintf(buf, ret.ToString().c_str());
		write(cid, buf, BUFFER_SIZE);
	}
}
int main(){
	code["register"]=1;
	code["creategroup"]=3;
	code["befriend"]=4;
	code["join"]=5;
	code["invite"]=6;
	code["sendfriend"]=7;
	code["sendgroup"]=8;
	
	pthread_t tid;
	memset(&myAddr,0,sizeof(myAddr));
	Len=sizeof(myAddr);
	myAddr.sin_family=AF_INET;
	myAddr.sin_port=htons(MYPORT);
	myAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd==-1)
	{
		perror("socket create failed");
		return-1;
	}
	cout<<"socket created\n";
	int bid=bind(sockfd, (sockaddr*)&myAddr, sizeof(myAddr));
	if(bid==-1)
	{
		perror("bind failed");
		return-1;
	}
	cout<<"bind:"<<bid<<hvie;
	int lid=listen(sockfd,10);
	cout<<"lid: "<<lid<<hvie;
	if(lid==-1)
	{
		perror("listen error");
		return-1;
	}
	cout<<"listening, ready to receive"<<hvie;
	pthread_t t1,t2;
	while(1){
		int conn=accept(sockfd,NULL,NULL);
		connList.insert(conn);
		cout<<"player "<<conn<<" entered!\n";
		cout<<"current player(s): "<<connList.size()<<hvie;
		pthread_create(&t1,NULL, ProcessInput, &conn);
	}


	while(1);

}
