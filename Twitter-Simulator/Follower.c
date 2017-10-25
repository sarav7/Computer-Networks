#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <strings.h>
#include <time.h>
#define UDPMSG 4000
#define FOLLOWER1 "21769"
#define FOLLOWER2 "21869"
#define FOLLOWER3 "21969"
#define FOLLOWER4 "22069"
#define FOLLOWER5 "22169"
#define QUEUE 10
#define EXTENSION ".txt"
#define SERVERPORT "3669"
#define PACKETLEN "500"
void *get_in_addr(struct sockaddr *sa)
{
 if (sa->sa_family == AF_INET) {
 return &(((struct sockaddr_in*)sa)->sin_addr);
 }
 return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}
char hash[5][10] = {FOLLOWER5,FOLLOWER4,FOLLOWER3,FOLLOWER2,FOLLOWER1};
char Follower[5][10] = {"Follower1","Follower2","Follower3","Follower4","Follower5"};
void tcp(int n){
		
	//printf("n: %d\n",n);
	int i=0;
	FILE *feedback;
	char feeds[4][100];
	char File[10] = "Follower";
	char id[2];
	sprintf(id,"%d",n+1);
	strcat(File,id);
	strcat(File,EXTENSION);
	feedback = fopen(File, "r");
	while (fgets(feeds[i], sizeof(feeds[i]), feedback))
    i++;
    char front[2];
    strcpy(front,id);
    for(i=0;i<4;i++){
		char *tmp = strdup(feeds[i]);
		strcpy(feeds[i],front);
		strcat(feeds[i],tmp);
	//	printf("%s",feeds[i]);
    }
    //printf("\n");
    struct addrinfo IP, *res;
	memset(&IP,0,sizeof(IP));
	int status=0;
	char IPstring[INET_ADDRSTRLEN];
	socklen_t inpSockSize;
	//struct sockaddr_storage clientStruct;
	IP.ai_family = AF_INET;
	IP.ai_socktype = SOCK_STREAM;
	if((status = getaddrinfo("localhost",SERVERPORT,&IP,&res)) !=0){
		perror("getaddrinfo\n");
		exit(0);
	}
	struct addrinfo *ptr = res;
	while(ptr!=NULL){
		struct sockaddr_in *ip= (struct sockaddr_in *)ptr->ai_addr;
		inet_ntop(ptr->ai_family,&(ip->sin_addr),IPstring,INET_ADDRSTRLEN);
	//	printf("IP Address is: %s\n",IPstring);
		ptr = ptr->ai_next;
	}
	int socketdes =0;
	socketdes = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	if(connect(socketdes,res->ai_addr,INET_ADDRSTRLEN) ==-1){
		perror("connect\n");
		exit(0);
	}
	struct sockaddr_in *ip= (struct sockaddr_in *)res->ai_addr;
	//printf("PORT: %d\n",ip->sin_port);
	//printf("port is %d\n",ntohs(get_in_port((struct sockaddr *)res->ai_addr)));
	
	
	struct sockaddr_in sin;
	socklen_t len = sizeof(sin);
	if (getsockname(socketdes, (struct sockaddr *)ip, &len) == -1)
		perror("getsockname");
	//else
	   // printf("port number %d\n", ntohs(ip->sin_port));
	//printf("%d %s\n",n,hash[n]);
	printf("%s has TCP Port %d and IP address %s for Phase 2\n",Follower[n],ntohs(ip->sin_port),IPstring);
	//printf("%s is now connected to the server\n",Follower[n]);
	freeaddrinfo(res);
	for(i=0;i<4;i++){
		//strtok(feeds[i],"\n");
		//feeds[i][strlen(feeds[i])] = '\0';
		if( send(socketdes,feeds[i],strlen(feeds[i]),0) ==-1){
			perror("send\n");
			exit(0);
		}
		//printf("%s has sent <%s> to the server\n",Follower[n],feeds[i]);
	}
	printf("Completed sending feedback for %s\n",Follower[n]);
	printf("End of phase 2 for %s\n",Follower[n]);
	close(socketdes);
	return ;
}

int main(){
	int n = 5;
	
	while(n--){
		if(!fork()){
			int id = n+1;
			struct addrinfo DGRAM, *res;
			int len=0;
			int socketdes=0;
			int status=0;
			socklen_t inpSockSize;
			char IPstring[INET_ADDRSTRLEN];
			char s[INET_ADDRSTRLEN];
			struct sockaddr_storage clientStruct;
			char msg[UDPMSG];
			memset(&DGRAM,0,sizeof(DGRAM));
			DGRAM.ai_family = AF_INET;
			DGRAM.ai_socktype = SOCK_DGRAM;
			if((status = getaddrinfo("localhost",hash[n],&DGRAM,&res)) !=0){
				perror("getaddrinfo\n");
				exit(0);
			}
			struct addrinfo *ptr = res;
			socketdes = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
			while(ptr!=NULL){
				struct sockaddr_in *ip= (struct sockaddr_in *)ptr->ai_addr;
				inet_ntop(ptr->ai_family,&(ip->sin_addr),IPstring,INET_ADDRSTRLEN);
				//	printf("IP Address is: %s\n",IPstring);
				ptr = ptr->ai_next;
			}
			bind(socketdes,res->ai_addr,INET_ADDRSTRLEN);
			inpSockSize = sizeof(clientStruct);
			//printf("n: %d\n",n);
			printf("Follower%d has UDP Port %s and IP address %s\n",id,hash[abs(n-4)],IPstring);
			if( (len = recvfrom(socketdes,msg,UDPMSG-1,0,(struct sockaddr *)&clientStruct, &inpSockSize)) ==-1){
				perror("UDP Receive\n");
				exit(0);
			}
			inet_ntop(res->ai_family, get_in_addr((struct sockaddr *)res->ai_addr),s, sizeof s);
 			//printf("client: connecting to %s\n", s);
			msg[len] = '\0';
			//printf("Packet contains: %s\n",msg);
			char *split = NULL;
			split = strtok(msg,"\n");
			while(split!=NULL){
				if(split[0] == 'A'){
					printf("Follower%d has received Tweet%c\n",id,split[0]);
				}
				else if(split[0] == 'B'){
					printf("Follower%d has received Tweet%c\n",id,split[0]);
				}
				else if(split[0] == 'C'){
					printf("Follower%d has received Tweet%c\n",id,split[0]);
				}
				//printf("%s\n",split);
				split = strtok(NULL,"\n");
			}
			close(socketdes);
			freeaddrinfo(res);
			tcp(n);
			
			exit(0);
		}
		else{
			wait(NULL);
		}		
	}

}
