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
int CODEFOR(const string&s){
	return code[s];
}
void *ProcessInput(void*id)
{
	int cid=*(int*)id, op;
	char buf[BUFFER_SIZE], buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    char ID[BUFFER_SIZE], ID2[BUFFER_SIZE];
	Database DB;
	while(true)
	{
		int ret=recv(cid, buf, BUFFER_SIZE, 0);
		if(ret<=0){
			pthread_exit(NULL);
		}
		//sscanf(buf, "# %d | %s | %s", &op, buf1, buf2);
		cout<<buf<<"\n";
		neb::CJsonObject job(buf);
		vector<string>Keys;
		vector<string>Values;
		while(1){
			string k,v;
			int gk=job.GetKey(k);
			if(!gk) break;
			if(job.Get(k,v)){
				Keys.push_back(k);
				Values.push_back(v);
			}
		}
		int n=Keys.size();
		if(!n) continue;
		for(int i=0;i<n;i++) cout<<Keys[i]<<':'<<Values[i]<<"\n";
		cout<<Values[0]<<' '<<CODEFOR(Values[0])<<endl;
		switch(CODEFOR(Values[0])){
			case 1:{
				//Register;
				cout<<"register!\n";
				int UID=DB.Register(Values[1].c_str(), Values[2].c_str());
				cout<<UID<<'\n';	
				break;
			}		   
			case 2:{
				//Login;
				break;
			}		   
			case 3:{
				//Create Group
				 break;
			}		   
			case 4:{
				//AddFriend or AddToGroup
				 break;
			}		   
			case 5:{
				//Invite
				 break;
			}		   
			case 6:{
				//send message
				 break;
			}
			case 7:{
				//be friend / be 
				break;
			}	   
		}
	}
}
int main(){
	code["register"]=1;
	code["creategroup"]=3;
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
