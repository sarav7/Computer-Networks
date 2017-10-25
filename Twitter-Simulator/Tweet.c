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
#define SERVERPORT "3669"
#define TWEETLEN 1024
#define EXTENSION ".txt"
#define MAXDATA 1024
#define FEEDLEN 1024
in_port_t get_in_port(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return (((struct sockaddr_in*)sa)->sin_port);
    }

    return (((struct sockaddr_in6*)sa)->sin6_port);
}
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}
char hash[3][10] = {"TweetC","TweetB","TweetA"};
void feed(){
	waitFor(60);
	int n =3;
	while(n--){
		if(!fork()){
			if(n == 0) waitFor(2);
			if(n == 1) waitFor(4);
			if(n == 2) waitFor(6);
			struct addrinfo IP, *res;
			memset(&IP,0,sizeof(IP));
			int status=0;
			char IPstring[INET_ADDRSTRLEN];
			socklen_t inpSockSize;
			struct sockaddr_storage clientStruct;
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
			printf("%s has TCP Port %d and IP address %s for Phase 2\n",hash[n],ntohs(ip->sin_port),IPstring);
			//printf("%s is now connected to the server\n",hash[n]);
			freeaddrinfo(res);
			
			int msglen=1;
			while(msglen !=0){
				char feed[FEEDLEN]="";
				if ((msglen = recv(socketdes,feed,FEEDLEN-1,0)) == -1) {          //////////////////
					 perror("recv");
					 exit(1);
				}
				feed[msglen] = '\0';
				//printf("client: received %s\n",feed);
				if(strstr(feed,"Follower1") != NULL){
					if(strstr(feed,"like") != NULL){
						printf("Follower1 has liked %s\n",hash[n]);
					}
					else{
						printf("Follower1 is following %s\n",hash[n]);
					}
				}
				else if(strstr(feed,"Follower2") != NULL){
					if(strstr(feed,"like") != NULL){
						printf("Follower2 has liked %s\n",hash[n]);
					}
					else{
						printf("Follower2 is following %s\n",hash[n]);
					}
				}
				else if(strstr(feed,"Follower3") != NULL){
					if(strstr(feed,"like") != NULL){
						printf("Follower3 has liked %s\n",hash[n]);
					}
					else{
						printf("Follower3 is following %s\n",hash[n]);
					}
				}
				else if(strstr(feed,"Follower4") != NULL){
					if(strstr(feed,"like") != NULL){
						printf("Follower4 has liked %s\n",hash[n]);
					}
					else{
						printf("Follower4 is following %s\n",hash[n]);
					}
				}
				else if(strstr(feed,"Follower5") != NULL){
					if(strstr(feed,"like") != NULL){
						printf("Follower5 has liked %s\n",hash[n]);
					}
					else{
						printf("Follower5 is following %s\n",hash[n]);
					}
				}
			}
			printf("End of Phase 2 for %s\n",hash[n]);
			close(socketdes);
			exit(0);
		}
		else{
		wait(NULL);
		}
	}		
return;
}


int main(){

	int n =3;
	while(n--){
	
		if(!fork()){

	if(n == 0) waitFor(2);
	if(n == 1) waitFor(4);
	
	FILE *fd;
	char txtFile[10];
	strcpy(txtFile,hash[n]);
	//printf("%s\n",textFile);
	strcat(txtFile,EXTENSION);
	//printf("%d --  %s\n",n,hash[n]);
	fd = fopen(txtFile,"r");
	char tweet[TWEETLEN];
	fgets(tweet,TWEETLEN,(FILE*)fd);
	strtok(tweet,"\n");
	//printf("%s\n",tweet);
	//printf("%d\n",n);
	
	struct addrinfo IP, *res;
	memset(&IP,0,sizeof(IP));
	int status=0;
	char IPstring[INET_ADDRSTRLEN];
	socklen_t inpSockSize;
	struct sockaddr_storage clientStruct;
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
printf("%s has TCP Port %d and IP address %s for Phase 1\n",hash[n],ntohs(ip->sin_port),IPstring);
printf("%s is now connected to the server\n",hash[n]);
	freeaddrinfo(res);
	char msg[TWEETLEN];
	strcat(msg,hash[n]);
	strcat(msg,tweet);
	if( send(socketdes,msg,strlen(msg),0) ==-1){
		perror("send\n");
		exit(0);
	}
	printf("%s has sent <%s> to the server\n",hash[n],tweet);
	printf("Updating the server is done for %s\n",hash[n]);
	printf("End of Phase 1 for %s\n",hash[n]);
	char final[MAXDATA];
	int msgLen =0;
	close(socketdes);
	//wait(NULL);
	exit(0);
		}
		else{
		wait(NULL);}
	}
	wait(NULL);
	feed();
	exit(-1);
	return 0;
}
