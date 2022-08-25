#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fcntl.h>
#include<pthread.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<netinet/in.h>
#include<arpa/inet.h>
#include "./CJsonObject/CJsonObject.hpp"
#include"Database.h"
//#define write(A,B,C) send((A),(B),(C),0)

const char hvie='\n';
const int MYPORT = 8848;
const int BUFFER_SIZE=1024;

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
	if(n==0)return "0";
	string s="";
	while(n) s+=(char)(n%10+'0'), n/=10;
	reverse(s.begin(),s.end());
	return s;
}

void waitfor(int x){
	x*=300;
	time_t t=clock();
	while(clock()-t<x);
}

void process_message(int cid, vector<map<string,string> > & records, Database& DB){
	int n=records.size();
	char buf[BUFFER_SIZE];
	for(int i=0;i<n;i++){
		cout<<i<<"!!\n";
		map<string,string> tpl=records[i];
		neb::CJsonObject job;
		string type=tpl["Type"], tag=tpl["Tag"];
		if(tag=="0"){
			if(type=="1"){//private chat
				job.Add("type", "receivefriend");
				job.Add("SenderID", tpl["SenderID"]);
				job.Add("Message", tpl["Message"]);
			}
			else if(type=="2"){
				job.Add("type", "receivefriendemoji");
				job.Add("SenderID", tpl["SenderID"]);
				job.Add("Index", tpl["Message"]);
			}
			else if(type=="100"){
				job.Add("type", "vertifyfriend");
				//specially proceed the situation of vertify message;
				string Message=tpl["Message"], FriendID=tpl["SenderID"];
				job.Add("result", number(Message));
				job.Add("SenderID", tpl["ReceiverID"]);
				job.Add("ReceiverID", FriendID);
				job.Add("ReceiverName", DB.GetUsername(FriendID.c_str()));
			}
			else if(type=="200"){
				//deleted by friend
				job.Add("type", "losefriend");
				job.Add("UserID", tpl["Receiver"]);
				job.Add("LoseID", tpl["Sender"]);
			}
		}
		else{//groupchat
			if(type=="1"){
				//
				job.Add("type", "receivegroup");
				job.Add("GroupID", tpl["GroupID"]);
				job.Add("SenderID", tpl["SenderID"]);
				job.Add("Message", tpl["Message"]);
			}
			else if(type=="2"){
				job.Add("type", "receivegroupemoji");
				job.Add("GroupId", tpl["GroupID"]);
				job.Add("SenderID", tpl["SenderID"]);
				job.Add("Index", tpl["Message"]);
			}
			else if(type=="101"){
				job.Add("type", "vertifygroup");
				job.Add("result", number(tpl["Message"]));
				job.Add("UserID", tpl["ReceiverID"]);
				string Gid=tpl["GroupID"];
				job.Add("GroupID", Gid);
				job.Add("GroupName", DB.GetGroupName(Gid.c_str())); 
			}
			else if(type=="201"){
				job.Add("type", "kicked");
				job.Add("UserID", tpl["Receiver"]);
				job.Add("AdminID", tpl["Sender"]);
				job.Add("GroupID", tpl["GroupID"]);
			}
		}
		sprintf(buf, job.ToString().c_str());
		write(cid, buf, strlen(buf));
		waitfor(500);
	}
}

void process_invitation(int cid, vector<map<string,string> > &records, Database&DB){
	int n=records.size();
	char buf[BUFFER_SIZE];
	for(int i=0;i<n;i++){
		map<string,string> tpl=records[i];
//		map<string,string>::iterator it=tpl.begin();
		neb::CJsonObject job;
		job.Add("type","askinvite");
		job.Add("UserID", tpl["AskID"]);
		job.Add("FriendID", tpl["ReceiverID"]);
		job.Add("GroupID", tpl["GroupID"]);
		sprintf(buf, job.ToString().c_str());
		write(cid, buf, strlen(buf));
		waitfor(500);
	}
}


void process_join_req(int cid, vector<map<string,string> > &records, Database&DB){
	int n=records.size();
	char buf[BUFFER_SIZE];
	for(int i=0;i<n;i++){
		map<string,string> tpl=records[i];
		neb::CJsonObject job;
		job.Add("type", "askjoin");
		job.Add("SenderID", tpl["SenderID"]);
		job.Add("ReceiverID", tpl["ReceiverID"]);
		job.Add("GroupID", tpl["GroupID"]);
		sprintf(buf, job.ToString().c_str());
		write(cid, buf, strlen(buf));
		waitfor(500);
	}
}

void process_friend_req(int cid, vector<map<string,string> >&records, Database&DB){
	int n=records.size();
	char buf[BUFFER_SIZE];
	for(int i=0;i<n;i++){
		map<string,string> tpl=records[i];
		neb::CJsonObject job;
		job.Add("type","askfriend");
		string SenderID=tpl["AskID"];
		job.Add("ReceiverID", tpl["ReceiverID"]);
		job.Add("SenderID", SenderID);
		job.Add("SenderName", DB.GetUsername(SenderID.c_str()));
		cout<<"offline msg"<<job.ToString()<<endl;
		sprintf(buf, job.ToString().c_str());
		write(cid, buf, strlen(buf));
		waitfor(500);
	}
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
		memset(buf,0,BUFFER_SIZE);
		int rec=recv(cid, buf, BUFFER_SIZE, 0);
		if(rec<=0){
			cout<<cid<<' '<<"exit"<<hvie;
			if(userid[cid]){
				connect_id.erase(userid[cid]);
				userid[cid]=0;
			}
			pthread_exit(NULL);
		}
		cout<<"raw message:"<<buf<<endl;	
		neb::CJsonObject job(buf), ret;
		string tmp, s1, s2, type;
		cout<<"receive:\n"<<job.ToString()<<endl;
		job.Get("type",type);
		if(!job.Get("type", type)) continue;
		cout<<"type: "<<type<<' '<<CODEFOR(type)<<endl;
		switch(CODEFOR(type)){
			case 1:{
				//Register;
				cout<<"register!\n";
				job.Get("UserName", s1);
				job.Get("Password", s2);
				int UID=DB.Register(s1.c_str(),
					   				s2.c_str());
				cout<<UID<<'\n';
				ret.Add("type", type);
				ret.Add("status", UID>=0);
				ret.Add("UserID", to_string(UID));
				break;
			}		   
			case 2:{
				//Login;
				cout<<"login!\n";
				job.Get("UserID", s1);
				job.Get("Password", s2);
				int result=DB.Login(s1.c_str(),s2.c_str());
				string result2=DB.GetUsername(s1.c_str());
				ret.Add("type", type);
				bool ok=0;
				if(result==-1||result2.length()==0){
					ret.Add("status", 0);
				}
				else if(result==0){
					ret.Add("status", 100);
				}
				else{
					ok=1;
					ret.Add("status", 1);
					ret.Add("UserName", result2);
					userid[cid]=number(s1);
					connect_id[userid[cid]]=cid;
				}
				sprintf(buf, ret.ToString().c_str());
				write(cid, buf, strlen(buf));
				if(!ok) continue;
				waitfor(500);
				vector<map<string,string> > message, invitation, join_req, friend_req;
			//	cout<<"??\n";
				message=DB.GetOfflineRecords("UnreadMessage",s1.c_str());
				cout<<message.size()<<endl;
				invitation=DB.GetOfflineRecords("invite_request",s1.c_str());
				join_req=DB.GetOfflineRecords("group_request",s1.c_str());
				friend_req=DB.GetOfflineRecords("friend_request",s1.c_str());
				cout<<"ready to process\n";
				process_message(cid, message,DB);
				process_invitation(cid, invitation,DB);
				process_join_req(cid, join_req,DB);
				process_friend_req(cid, friend_req,DB);
				DB.DeleteOfflineRecords( "UnreadMessage",s1.c_str());
				DB.DeleteOfflineRecords( "invite_request",s1.c_str());
				DB.DeleteOfflineRecords( "group_request",s1.c_str());
				DB.DeleteOfflineRecords( "friend_request",s1.c_str());
				continue;
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
				ret.Add("GroupID", to_string(GroupID));
				ret.Add("GroupName", s2);
				break;
			}
			case 4:{
				//AddFriend
				cout<<"ask to be friend!\n";
				job.Get("UserID", s1);
				job.Get("FriendID", s2);
				string UserName=DB.GetUsername(s1.c_str());
				int Fid=number(s2);
				ret.Add("type", type);
				if(connect_id.count(Fid)){
					neb::CJsonObject req;
					req.Add("type","askfriend");
					req.Add("ReceiverID", s2);
					req.Add("SenderID", s1);
					req.Add("SenderName", UserName);
					sprintf(buf2, req.ToString().c_str());
					write(connect_id[Fid], buf2, strlen(buf2));
				//-------------------
					ret.Add("status", 1);
					ret.Add("FriendID", s2);
				}
				else{
					int result=DB.AskFriend(s1.c_str(),s2.c_str());
					if(result==100){
						ret.Add("status", 100);
						ret.Add("FriendID", s2);
					}
					else if(result==-1){
						ret.Add("status", 0);
					}
					else{
						ret.Add("status", 1);
						ret.Add("FriendID", s2);
						string FriendName=DB.GetUsername(s2.c_str());
						ret.Add("FriendName", FriendName);
					}
				}
				break;
			}
			case 5:{
				//join
				cout<<"join\n";
				job.Get("UserID", s1);
				job.Get("GroupID", s2);
				int AdminID=DB.GetAdmin(s2.c_str());
				string GroupName=DB.GetGroupName(s2.c_str());
				ret.Add("type", type);
				if(AdminID==0){
					ret.Add("status", 101);
					ret.Add("GroupID", s2);	
				}
				else if(AdminID==-1){
					ret.Add("status", 0);
				}
				else if(connect_id.count(AdminID)){
					neb::CJsonObject req;
					req.Add("type", "askjoin");
					req.Add("ReceiverID", to_string(AdminID));
					req.Add("SenderID", s1);
					req.Add("GroupID", s2);
					req.Add("GroupName", GroupName);
					sprintf(buf2, req.ToString().c_str());
					write(connect_id[AdminID], buf2, strlen(buf2));	
					//-----------------
					ret.Add("status", 1);
					ret.Add("UserID", s1);
					ret.Add("GroupID", s2);
					ret.Add("GroupName", GroupName);
				}
				else{	
					int result=DB.Join(s1.c_str(), to_string(AdminID).c_str() ,s2.c_str());
					if(result==101){
						ret.Add("status", 101);
						ret.Add("GroupID", s2);
					}
					else if(result==-1){
						ret.Add("status", 0);
					}
					else{
						ret.Add("status", 1);
						ret.Add("UserID", s1);
						ret.Add("GroupID", s2);
						ret.Add("GroupName", GroupName);
					}
				}
				break;
			}		   
			case 6:{
				//invite to group
				cout<<"invite\n";
				job.Get("UserID", s1);
				job.Get("FriendID",s2);
				job.Get("GroupID", tmp);
				int Fid=number(s2);
				string GroupName=DB.GetGroupName(tmp.c_str());
				ret.Add("type", type);
				if(connect_id.count(Fid)){
					int AdminID=DB.GetAdmin(tmp.c_str());
					if(AdminID==0){
						ret.Add("status", 101);
						ret.Add("GroupID", s2);
					}
					else if(AdminID==-1){
						ret.Add("status", 0);
					}
					else{
						neb::CJsonObject req;
						req.Add("type", "askinvite");
						req.Add("Receiver", s2);
						req.Add("Sender", s1);
						req.Add("GroupID", tmp);
						req.Add("GroupName", GroupName);
						sprintf(buf2, req.ToString().c_str());
						write(connect_id[Fid], buf2, strlen(buf2));
					//------------------------
						ret.Add("status",1);
						ret.Add("FriendID", s2);
						ret.Add("GroupID", tmp);
						ret.Add("GroupName", GroupName);
					}
				}
				else{
					int result=DB.Invite(s1.c_str(),s2.c_str(),tmp.c_str());
					if(result==100){
						ret.Add("status",100);
						ret.Add("FriendID", s2);
					}
					else if(result==101){
						ret.Add("status", 101);
						ret.Add("GroupID", tmp);
					}
					else if(result==-1){
						ret.Add("status", 0);
					}
					else{
						ret.Add("status", 1);
						ret.Add("FriendID", s2);
						ret.Add("GroupID", tmp);
						ret.Add("GroupName", GroupName);
					}
				}
				break;
			}
			case 7:{
				//send to friend
				cout<<"send to friend\n";
				job.Get("UserID", s1);
				job.Get("FriendID",s2);
				job.Get("Message",tmp);
				//process online message
				int Fid=number(s2);
				bool ok=1;
				ret.Add("type", type);
				if(connect_id.count(Fid)){
					//directly send
					int connID=connect_id[Fid];
					sprintf(buf2, "%s", tmp.c_str());
					neb::CJsonObject mess;
					mess.Add("type", "receivefriend");
					mess.Add("SenderID", s1);
					mess.Add("Message", tmp);
					sprintf(buf2, mess.ToString().c_str());
					write(connID, buf2, strlen(buf2));
				}
				else{
					int result=DB.SaveOfflineMSG(s1.c_str(), s2.c_str(), NULL,
						   	tmp.c_str(), 1, 0);
					if(result==-1) ok=0;
				}
				ret.Add("status", ok);
				break;
			}
			case 8:{
				//send to group
				cout<<"send to group\n";
				job.Get("UserID", s1);
				job.Get("GroupID", s2);
				job.Get("Message", tmp);
				vector<int>memberID=DB.GetMember(s2.c_str());
				for(int i=0,cnt=memberID.size();i<cnt;i++){
					int Fid=memberID[i];
					string fs=to_string(Fid);
					cout<<"sent to friend"<<Fid<<hvie;
					if(connect_id.count(Fid)){
						int connID=connect_id[Fid];
						sprintf(buf2, "%s", tmp.c_str());
						neb::CJsonObject mess;
						mess.Add("type", "receivegroup");
						mess.Add("GroupID", s2);
						mess.Add("SenderID", s1);
						mess.Add("Message", tmp);
						sprintf(buf2, mess.ToString().c_str());
						write(connID, buf2, strlen(buf2));
					}
					else{
						DB.SaveOfflineMSG(s1.c_str(), fs.c_str(), s2.c_str(),
							   	tmp.c_str(), 1 , 1);
					}
				}
				break;
			}
			case 9:{
				//accept friend
				cout<<"accept friend!\n";
				job.Get("ReceiverID", s1);
				job.Get("SenderID", s2);
				int vertify;
				job.Get("result", vertify);
				int SenderID=number(s2), ReceiverID=number(s1);
				cout<<"vertify "<<vertify<<' '<<SenderID<<' '<<ReceiverID<<endl;
				if(connect_id.count(SenderID)){
					neb::CJsonObject vert;
					vert.Add("type", "vertifyfriend");
					vert.Add("result", vertify);
					vert.Add("SenderID", s2);
					vert.Add("ReceiverID", s1);
					vert.Add("ReceiverName", DB.GetUsername(s1.c_str()));
					sprintf(buf1, vert.ToString().c_str());
					cout<<connect_id[SenderID]<<" "<<buf1<<' '<<strlen(buf1)<<"!!\n";
					write(connect_id[SenderID], buf1, strlen(buf1));
				}
				else{
					//the one who sends is the one who receives "befriend"
					DB.SaveOfflineMSG(s1.c_str(), s2.c_str(), NULL, to_string(vertify).c_str(), 100, 0);
				}
				if(vertify) DB.AcceptFriend(s1.c_str(),s2.c_str());
				continue;// not responding the client
			}
			case 10:{
				//delete friend
				cout<<"delete friend!\n";
				job.Get("UserID", s1);
				job.Get("FriendID", s2);
				int result=DB.DeleteFriend(s1.c_str(),s2.c_str());
				ret.Add("type", type);
				ret.Add("UserID", s1);
				ret.Add("FriendID", s2);
				if(result==-1){
					ret.Add("status", 0);
				}
				else{
					ret.Add("status", 1);
					int FriendID=number(s2);
					if(connect_id.count(FriendID)){
						neb::CJsonObject lose;
						lose.Add("type", "losefriend");
						lose.Add("UserID", s2);
						lose.Add("LoseID", s1);
						sprintf(buf2, lose.ToString().c_str());
						write(connect_id[FriendID], buf2, strlen(buf2));
					}
					else{
						DB.SaveOfflineMSG(s1.c_str(), s2.c_str(), NULL, "0", 200, 0);	
					}
				}
				break;
			}
			case 11:{
				//approve enter
				cout<<"approve enter\n";
				job.Get("UserID", s1);
				job.Get("GroupID", s2);
				int vertify;
				job.Get("result", vertify);
				int UserID=number(s1);
				if(connect_id.count(UserID)){
					neb::CJsonObject vert;
					vert.Add("type","vertifygroup");
					vert.Add("result",vertify);
					vert.Add("UserID", s1);
					vert.Add("GroupID", s2);
					vert.Add("GroupName", DB.GetGroupName(s2.c_str()));
					sprintf(buf1, vert.ToString().c_str());
					write(connect_id[UserID], buf1, strlen(buf1));
				}
				else{
					int AdminID=DB.GetAdmin(s2.c_str());
					DB.SaveOfflineMSG(to_string(AdminID).c_str(), s1.c_str(), s2.c_str(), 
							to_string(vertify).c_str(), 101, 1);
				}

				int result=DB.EnterGroup(s1.c_str(), s2.c_str());
				ret.Add("type", type);
				ret.Add("UserID", s1);
				ret.Add("GroupID", s2);
				string userName=DB.GetUsername(s1.c_str());
				ret.Add("UserName", userName);
				ret.Add("status", result==0&&(userName.length()>0));
				continue;
			}
			case 12:{
				//accept invite
				cout<<"accept invite\n";
				job.Get("InviteID", s1);
				job.Get("AcceptID", s2);
				job.Get("GroupID", tmp);
				int result=DB.EnterGroup(s2.c_str(), tmp.c_str());
				ret.Add("type",type);
				ret.Add("InviteID", s1);
				ret.Add("AcceptID", s2);
				ret.Add("GroupID", tmp);
				ret.Add("GroupName", DB.GetGroupName(tmp.c_str()));
				ret.Add("status", result==0);
				break;
			}
			case 13:{
				//quit group
				cout<<"quit group\n";
				job.Get("UserID", s1);
				job.Get("GroupID", s2);
				int result=DB.QuitGroup(s1.c_str(), s2.c_str());
				ret.Add("type", type);
				ret.Add("UserID", s1);
				ret.Add("GroupID", s2);
				ret.Add("status", result==0);
				break;
			}
			case 14:{
				//kick out from group
				cout<<"kick out from group\n";
				job.Get("AdminID", s1);
				job.Get("UserID", s2);
				job.Get("GroupID", tmp);
				int result=DB.QuitGroup(s2.c_str(), tmp.c_str());
				ret.Add("type", type);
				ret.Add("AdminID", s1);
				ret.Add("UserID", s2);
				ret.Add("GroupID", tmp);
				ret.Add("status", result==0);
				int UserID=number(s2);
				if(connect_id.count(UserID)){
					neb::CJsonObject kick;
					kick.Add("type", "kicked");
					kick.Add("AdminID", s1);
					kick.Add("UserID", s2);
					kick.Add("GroupID", tmp);
					sprintf(buf1, kick.ToString().c_str());
					write(connect_id[UserID], buf1, strlen(buf1));
				}
				else{
					int result=DB.SaveOfflineMSG(s1.c_str(), s2.c_str(), tmp.c_str(), "0", 201, 1);
				}
				break;
			}
			case 15:{
				//get group info
				cout<<"GetGroupInfo\n";
				job.Get("GroupID", s1);
				ret.Add("type", "groupinfo");
				vector<int>v=DB.GetMember(s1.c_str());
				ret.Add("MemberCount", v.size());
				ret.Add("GroupID", s1);
				ret.AddEmptySubArray("MemberList");
				for(int i=0,n=v.size();i<n;i++){
					neb::CJsonObject tup;
					string UserID= to_string(v[i]);
					string UserName= DB.GetUsername(UserID.c_str());
					tup.Add("UserID", UserID);
					tup.Add("UserName", UserName);
					ret["MemberList"].Add(tup);
				}
				break;
			}
			case 16:{
				//send files
				cout<<"send files\n";
				job.Get("UserID", s1);
				job.Get("FriendID", s2);
				int Fid=number(s2);
				neb::CJsonObject confirm;
				confirm.Add("type", "1");
				if(connect_id.count(Fid)){
					sprintf(buf1, job.ToString().c_str());
					write(connect_id[Fid], buf1, strlen(buf1));
					waitfor(220);
//					sprintf(buf, confirm.ToString().c_str());
//					write(cid, buf, strlen(buf));

				}
				continue;
			}
			case 17:{
				//send to friend emoji
				cout<<"send emoji to friend\n";
				job.Get("UserID", s1);
				job.Get("FriendID",s2);
				job.Get("Index",tmp);
				//process online message
				int Fid=number(s2);
				bool ok=1;
				ret.Add("type", type);
				if(connect_id.count(Fid)){
					//directly send
					int connID=connect_id[Fid];
					sprintf(buf2, "%s", tmp.c_str());
					neb::CJsonObject mess;
					mess.Add("type", "receivefriendemoji");
					mess.Add("SenderID", s1);
					mess.Add("Index", tmp);
					sprintf(buf2, mess.ToString().c_str());
					write(connID, buf2, strlen(buf2));
				}
				else{
					int result=DB.SaveOfflineMSG(s1.c_str(), s2.c_str(), NULL,
						   	tmp.c_str(), 2, 0);
					if(result==-1) ok=0;
				}
				ret.Add("status", ok);
				break;
			}
			case 18: {
				//send to group
				cout<<"send to group\n";
				job.Get("UserID", s1);
				job.Get("GroupID", s2);
				job.Get("Index", tmp);
				vector<int>memberID=DB.GetMember(s2.c_str());
				for(int i=0,cnt=memberID.size();i<cnt;i++){
					int Fid=memberID[i];
					string fs=to_string(Fid);
					cout<<"sent to groupmember emoji"<<Fid<<hvie;
					if(connect_id.count(Fid)){
						int connID=connect_id[Fid];
						sprintf(buf2, "%s", tmp.c_str());
						neb::CJsonObject mess;
						mess.Add("type", "receivegroupemoji");
						mess.Add("GroupID", s2);
						mess.Add("SenderID", s1);
						mess.Add("Index", tmp);
						sprintf(buf2, mess.ToString().c_str());
						write(connID, buf2, strlen(buf2));
					}
					else{
						DB.SaveOfflineMSG(s1.c_str(), fs.c_str(), s2.c_str(),
							   	tmp.c_str(), 2 , 1);
					}
				}
				break;
			}
			default:{
				cout<<"unkwown"<<hvie;
			}
		}
		cout<<"wow: "<<ret.ToString()<<endl;
		sprintf(buf, ret.ToString().c_str());
		
		write(cid, buf, strlen(buf));
		
	}
}
int main(){
	code["register"]=1;
	code["login"]=2;
	code["creategroup"]=3;
	code["befriend"]=4;
	code["join"]=5;
	code["invite"]=6;
	code["sendfriend"]=7;
	code["sendgroup"]=8;
	code["acceptfriend"]=9;
	code["deletefriend"]=10;
	code["approveenter"]=11;
	code["acceptinvite"]=12;
	code["quit"]=13;
	code["kickout"]=14;
	code["getgroupinfo"]=15;
	code["file"]=16;
	code["sendfriendemoji"]=17;
	code["sendgroupemoji"]=18;

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
