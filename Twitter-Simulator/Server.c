#include <stdio.h>
#include <string.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/mman.h>
#include <time.h>
#define PORT "3669"
#define QUEUE 10
#define MAXDATA 1024
#define UDPMSG 4000
#define FOLLOWER1 "21769"
#define FOLLOWER2 "21869"
#define FOLLOWER3 "21969"
#define FOLLOWER4 "22069"
#define FOLLOWER5 "22169"
char hash[5][10] = {FOLLOWER5,FOLLOWER4,FOLLOWER3,FOLLOWER2,FOLLOWER1};
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
void UDPSend(char *tweets,char *tweet1,char *tweet2,char *tweet3){
	int i=0;
	//printf("Tweets: %s\n",tweets);
	//printf("Tweet1: %s\n",tweet1);
	//printf("Tweet2: %s\n",tweet2);
	//printf("Tweet3: %s\n",tweet3);
	char Follower1[10] = {"ABC"};
	char Follower2[10] = {"AB"};
	char Follower3[10] = {"BC"};
	char Follower4[10] = {"B"};
	char Follower5[10] = {"ABC"};
	char num = 5;
	while(num--){
		char cTweets[UDPMSG] = "";
		if(!fork()){
		
		if(num == 0) waitFor(3);
		if(num == 1) waitFor(6);
		if(num == 2) waitFor(9);
		if(num == 3) waitFor(12);
		if(num == 4) waitFor(15);
			int socketdes;
			struct addrinfo DGRAM, *res;
			int len = 0;
			int status  = 0;
			memset(&DGRAM,0,sizeof(DGRAM));
			DGRAM.ai_family = AF_INET;
			DGRAM.ai_socktype = SOCK_DGRAM;
			//printf("num: %d\n",num);
			if((status = getaddrinfo("localhost",hash[num],&DGRAM,&res)) !=0){
				perror("getaddrinfo\n");
				exit(0);
			}
			struct addrinfo *ptr = res;
			char IPstring[INET_ADDRSTRLEN];
		socklen_t inpSockSize;
		socketdes = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
		while(ptr!=NULL){
			struct sockaddr_in *ip= (struct sockaddr_in *)ptr->ai_addr;
			inet_ntop(ptr->ai_family,&(ip->sin_addr),IPstring,INET_ADDRSTRLEN);
		//	printf("IP Address is: %s\n",IPstring);
			ptr = ptr->ai_next;
		}
		
		int id = num+1;
		if(id == 1){
			memset(cTweets,0,UDPMSG);
			for(i=0;i<strlen(Follower1);i++){
				//printf("%c\n",Follower1[i]);
				if(Follower1[i] == 'A'){
		//			printf("The server has sent Tweet%c to the Follower%d\n",Follower1[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower1[i] == 'B'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower1[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower1[i] == 'C'){
		//			printf("The server has sent Tweet%c to the Follower%d\n",Follower1[i],id);
					strcat(cTweets,tweet3);
				}
			}		
		//	printf("complied tweets: %s\n",cTweets);
		}
		else if(id == 2){
		memset(cTweets,0,UDPMSG);
				for(i=0;i<strlen(Follower2);i++){
				//printf("%c\n",Follower2[i]);
				if(Follower2[i] == 'A'){
				//	printf("The server has sent Tweet%c to the Follower%d\n",Follower2[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower2[i] == 'B'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower2[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower2[i] == 'C'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower2[i],id);
					strcat(cTweets,tweet3);
				}
			}		
	//		printf("complied tweets: %s\n",cTweets);	
		}
		else if(id == 3){
		memset(cTweets,0,UDPMSG);
					for(i=0;i<strlen(Follower3);i++){
				//printf("%c\n",Follower3[i]);
				if(Follower3[i] == 'A'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower3[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower3[i] == 'B'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower3[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower3[i] == 'C'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower3[i],id);
					strcat(cTweets,tweet3);
				}
			}		
	//		printf("complied tweets: %s\n",cTweets);
		}
		else if(id == 4){
		memset(cTweets,0,UDPMSG);
					for(i=0;i<strlen(Follower4);i++){
				//printf("%c\n",Follower4[i]);
				if(Follower4[i] == 'A'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower4[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower4[i] == 'B'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower4[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower4[i] == 'C'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower4[i],id);
					strcat(cTweets,tweet3);
				}
			}		
	//		printf("complied tweets: %s\n",cTweets);
		}
		else if(id == 5){
		memset(cTweets,0,UDPMSG);
					for(i=0;i<strlen(Follower5);i++){
				//printf("%c\n",Follower5[i]);
				if(Follower5[i] == 'A'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower5[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower5[i] == 'B'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower5[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower5[i] == 'C'){
			//		printf("The server has sent Tweet%c to the Follower%d\n",Follower5[i],id);
					strcat(cTweets,tweet3);
				}
			}		
		//	printf("complied tweets: %s\n",cTweets);
		}
		if( (len = sendto(socketdes,cTweets,strlen(cTweets),0,res->ai_addr,res->ai_addrlen)) == -1 ){
			perror("UDP\n");
			exit(0);	
		}
		
		struct sockaddr_in *ip= (struct sockaddr_in *)res->ai_addr;
		struct sockaddr_in sin;
		socklen_t leng = sizeof(sin);
		if (getsockname(socketdes, (struct sockaddr *)ip, &leng) == -1)
			perror("getsockname");
		//else
		   // printf("port number %d\n", ntohs(ip->sin_port));
		//printf("%d %s\n",n,hash[n]);
		printf("Server has UDP Port %d and IP address %s \n",ntohs(ip->sin_port),IPstring);
		if(id == 1){
			memset(cTweets,0,UDPMSG);
			for(i=0;i<strlen(Follower1);i++){
				//printf("%c\n",Follower1[i]);
				if(Follower1[i] == 'A'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower1[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower1[i] == 'B'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower1[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower1[i] == 'C'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower1[i],id);
					strcat(cTweets,tweet3);
				}
			}		
		//	printf("complied tweets: %s\n",cTweets);
		}
		else if(id == 2){
		memset(cTweets,0,UDPMSG);
				for(i=0;i<strlen(Follower2);i++){
				//printf("%c\n",Follower2[i]);
				if(Follower2[i] == 'A'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower2[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower2[i] == 'B'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower2[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower2[i] == 'C'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower2[i],id);
					strcat(cTweets,tweet3);
				}
			}		
	//		printf("complied tweets: %s\n",cTweets);	
		}
		else if(id == 3){
		memset(cTweets,0,UDPMSG);
					for(i=0;i<strlen(Follower3);i++){
				//printf("%c\n",Follower3[i]);
				if(Follower3[i] == 'A'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower3[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower3[i] == 'B'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower3[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower3[i] == 'C'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower3[i],id);
					strcat(cTweets,tweet3);
				}
			}		
	//		printf("complied tweets: %s\n",cTweets);
		}
		else if(id == 4){
		memset(cTweets,0,UDPMSG);
					for(i=0;i<strlen(Follower4);i++){
				//printf("%c\n",Follower4[i]);
				if(Follower4[i] == 'A'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower4[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower4[i] == 'B'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower4[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower4[i] == 'C'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower4[i],id);
					strcat(cTweets,tweet3);
				}
			}		
	//		printf("complied tweets: %s\n",cTweets);
		}
		else if(id == 5){
		memset(cTweets,0,UDPMSG);
					for(i=0;i<strlen(Follower5);i++){
				//printf("%c\n",Follower5[i]);
				if(Follower5[i] == 'A'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower5[i],id);
					strcat(cTweets,tweet1);
				}
				else if(Follower5[i] == 'B'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower5[i],id);
					strcat(cTweets,tweet2);
				}
				else if(Follower5[i] == 'C'){
					printf("The server has sent Tweet%c to the Follower%d\n",Follower5[i],id);
					strcat(cTweets,tweet3);
				}
			}		
		//	printf("complied tweets: %s\n",cTweets);
		}
		freeaddrinfo(res);
		close(socketdes);
		exit(0);
		}
		else{
		wait(NULL);
		}
	}
	return;
}
static int *counter;
static int *fcounter;
static char *tweets;
static char *feedback;
static char *tweet1;
static char *tweet2;
static char *tweet3;
static int *flagG;
static char *feed1;
static char *feed2;
static char *feed3;
char afeed[5][20],bfeed[5][20],cfeed[5][20];
int main(){
	counter = mmap(NULL, sizeof *counter, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	flagG = mmap(NULL, sizeof *flagG, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	tweet1 = mmap(NULL, UDPMSG*sizeof(char), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	tweet2 = mmap(NULL, UDPMSG*sizeof(char), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	tweets = mmap(NULL, UDPMSG*sizeof(char), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    fcounter = mmap(NULL, sizeof *fcounter, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    tweet3 = mmap(NULL, UDPMSG*sizeof(char), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    feed1 = mmap(NULL, MAXDATA*sizeof(char), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    feed2 = mmap(NULL, MAXDATA*sizeof(char), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    feed3 = mmap(NULL, MAXDATA*sizeof(char), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    feedback = mmap(NULL, UDPMSG*sizeof(char), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *counter = 0;
    *fcounter = 0;
    *flagG=0;
	struct addrinfo IP, *res;
	memset(&IP,0,sizeof(IP));
	int status=0;
	char IPstring[INET_ADDRSTRLEN];
	socklen_t inpSockSize;
	struct sockaddr_storage clientStruct;
	IP.ai_family = AF_INET;
	IP.ai_socktype = SOCK_STREAM;
	if((status = getaddrinfo("localhost",PORT,&IP,&res)) !=0){
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
	printf("The server has TCP port %s and IP address %s\n",PORT,IPstring);
	int socketdes =0;
	socketdes = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	bind(socketdes,res->ai_addr,INET_ADDRSTRLEN);
	freeaddrinfo(res);
	if(listen(socketdes,QUEUE) == -1){
		perror("Listen\n");
		exit(0);
	}
	//printf("Listned!\n");
	struct sockaddr_in *ip= (struct sockaddr_in *)res->ai_addr;
	//printf("PORT: %d\n",ip->sin_port);
	//printf("port is %d\n",ntohs(get_in_port((struct sockaddr *)res->ai_addr)));
	
	int childDes =0;
	while(1){
		int i=0;
		inpSockSize = sizeof(clientStruct);
		childDes = accept(socketdes,(struct sockaddr *)&clientStruct, &inpSockSize);
	//	printf("accepted!\n");
		struct sockaddr_in *ip = (struct sockaddr_in *)&clientStruct;
	 // printf("PORT: %d\n",ip->sin_port);
		//printf("port ---  is %d\n",ntohs(ip->sin_port));
		struct addrinfo *port = (struct addrinfo *)&clientStruct;
	 //   printf("port is %d\n",ntohs(get_in_port((struct sockaddr *)port->ai_addr)));
		if(childDes == -1){
			perror("accept\n");
			exit(0);
		}
		pid_t pid = fork();
		if(pid == 0){
		
			//close(socketdes);
			char msg[MAXDATA];
			int msgLen = 0;
			if((*counter) == 8){
				printf("The server has TCP port %s and IP address %s\n",PORT,IPstring);
				//printf("%s\n\n",feed1);
				//printf("%s\n\n",feed2);
				//printf("%s\n\n",feed3);
				char *split = NULL;
				split = strtok(feed1,"\n");
				while(split!=NULL){
					char temp[10] = "";
					strcpy(temp,split);
					//printf("%s\n",temp);
					if (send(childDes,temp,strlen(temp), 0) == -1)
				 	perror("send");
				 	waitFor(2);
					split = strtok(NULL,"\n");
				}
				printf("The server has sent the feedback result to TweetA\n");
				close(childDes);
			}
			else if((*counter) == 9){
				//printf("The server has TCP port %s and IP address %s\n",PORT,IPstring);
				//printf("%s\n\n",feed1);
				//printf("%s\n\n",feed2);
				//printf("%s\n\n",feed3);
				char *split = NULL;
				split = strtok(feed2,"\n");
				while(split!=NULL){
					char temp[10] = "";
					strcpy(temp,split);
					//printf("%s\n",temp);
					if (send(childDes,temp,strlen(temp), 0) == -1)
				 	perror("send");
				 	waitFor(2);
					split = strtok(NULL,"\n");
				}
				printf("The server has sent the feedback result to TweetB\n");
				close(childDes);
			}
			else if((*counter) == 10){
				//printf("The server has TCP port %s and IP address %s\n",PORT,IPstring);
				//printf("%s\n\n",feed1);
				//printf("%s\n\n",feed2);
				//printf("%s\n\n",feed3);
				char *split = NULL;
				split = strtok(feed3,"\n");
				while(split!=NULL){
					char temp[10] = "";
					strcpy(temp,split);
					//printf("%s\n",temp);
					if (send(childDes,temp,strlen(temp), 0) == -1)
				 	perror("send");
				 	waitFor(2);
					split = strtok(NULL,"\n");
				}
				printf("The server has sent the feedback result to TweetC\n");
				printf("End of Phase 2 for the server\n");
				close(childDes);
			}
			else{
				if((msgLen = recv(childDes, msg,MAXDATA-1,0)) == -1){
					perror("recv\n");
					exit(0);
				}
				msg[msgLen] = '\0';
			//printf("received msg: %s\n",msg);
			}
			if(msg[0] == '1' || msg[0] == '2' || msg[0] == '3' || msg[0] == '4' || msg[0] == '5'){
				(*fcounter)++;
				//printf("%c\n",msg[0]);
				//printf("received msg: %s\n",msg);
				if(msg[0] == '1'){
					printf("Server received the feedback from Follower%c\n",msg[0]);
				}
				else if(msg[0] == '2'){
					printf("Server received the feedback from Follower%c\n",msg[0]);
				}
				else if(msg[0] == '3'){
					printf("Server received the feedback from Follower%c\n",msg[0]);
				}
				else if(msg[0] == '4'){
					printf("Server received the feedback from Follower%c\n",msg[0]);
				}
				else if(msg[0] == '5'){
					printf("Server received the feedback from Follower%c\n",msg[0]);
				}
				waitFor(1);
				strcat(feedback,msg);
				if(*fcounter == 5){
					int A[5]={0};
					int B[5]={0};
					int C[5]={0};
					//printf("FINAL MSG\n");
					//printf("%s\n",feedback);
					char *split = NULL;
					split = strtok(feedback,"\n");
					while(split!=NULL){
						//printf("%s\n",split);
						//printf("\n");
						int integer = split[0] - '0';
						int follower = integer -1;
						if(split[1] == 'F'){
							if( strstr(split,"TweetA") != NULL){
								A[follower]++;
							}
							if( strstr(split,"TweetB") != NULL){
								B[follower]++;
							}
							if( strstr(split,"TweetC") != NULL){
								C[follower]++;
							}
						}
						else{
							if( strstr(split,"TweetA") != NULL && strstr(split,"like") != NULL ){
								A[follower]++;
							}
							if( strstr(split,"TweetB") != NULL && strstr(split,"like") != NULL){
								B[follower]++;
							}
							if( strstr(split,"TweetC") != NULL && strstr(split,"like") != NULL){
								C[follower]++;
							}
						}
						split = strtok(NULL,"\n");
					}
					//printf("\n");
					char prefix[20] = "Follower";
					
					int z=0;
					for(i=0;i<5;i++){
						//printf("%d\n",A[i]);
						if(A[i] == 1){
							int id = i+1;
							char str[2];
							sprintf(str, "%d", id);
							char t[20]="";
							strcat(t,prefix);
							strcat(t,str);
							//printf("%s\n",t);
							strcpy(afeed[z++],t); 
							strcat(feed1,t);
							strcat(feed1,"\n");
						}
						else if(A[i] == 2){
							int id = i+1;
							char str[10];
							sprintf(str, "%d", id);
							char t[20]="";
							strcat(t,prefix);
							strcat(str,"#like");
							strcat(t,str);
							//printf("%s\n",t);
							strcpy(afeed[z++],t);
							strcat(feed1,t);
							strcat(feed1,"\n");
						}
					}
					z=0;
					//printf("\n");
					for(i=0;i<5;i++){
						//printf("%d\n",B[i]);
						if(B[i] == 1){
							int id = i+1;
							char str[2];
							sprintf(str, "%d", id);
							char t[20]="";
							strcat(t,prefix);
							strcat(t,str);
							//printf("%s\n",t);
							strcpy(bfeed[z++],t);
							strcat(feed2,t);
							strcat(feed2,"\n"); 
						}
						else if(B[i] == 2){
							int id = i+1;
							char str[10];
							sprintf(str, "%d", id);
							char t[20]="";
							strcat(t,prefix);
							strcat(str,"#like");
							strcat(t,str);
							//printf("%s\n",t);
							strcpy(bfeed[z++],t);
							strcat(feed2,t);
							strcat(feed2,"\n");
						}
					}
					z=0;
					//printf("\n");
					for(i=0;i<5;i++){
						//printf("%d\n",C[i]);
						if(C[i] == 1){
							int id = i+1;
							char str[2];
							sprintf(str, "%d", id);
							char t[20]="";
							strcat(t,prefix);
							strcat(t,str);
							//printf("%s\n",t);
							strcpy(cfeed[z++],t);
							strcat(feed3,t);
							strcat(feed3,"\n"); 
						}
						else if(C[i] == 2){
							int id = i+1;
							char str[10];
							sprintf(str, "%d", id);
							char t[20]="";
							strcat(t,prefix);
							strcat(str,"#like");
							strcat(t,str);
							//printf("%s\n",t);
							strcpy(cfeed[z++],t);
							strcat(feed3,t);
							strcat(feed3,"\n");
						}
					}
					
				}				
			}
			char tweetSource = msg[5];
			(*counter)++;
			strcpy(msg,msg+7);
			strcat(tweets,msg);
			strcat(tweets,"\n");
			if((*counter) == 1){
				strcat(tweet1,"A");
				strcat(tweet1,msg);
				strcat(tweet1,"\n");
			}
			else if((*counter) == 2){
				strcat(tweet2,"B");
				strcat(tweet2,msg);
				strcat(tweet2,"\n");
			}
			else if((*counter) == 3){
				strcat(tweet3,"C");
				strcat(tweet3,msg);
				strcat(tweet3,"\n");
			}
			//printf("counter %d\n",(*counter));
			if((*flagG) ==0)
			printf("Received the tweet list from Tweet%c\n",tweetSource);
			
			if((*counter) == 3){
				printf("End of Phase 1 for the server\n");
				//printf("all tweets grouped: %s\n",tweets);
				*flagG = 1;
				UDPSend(tweets,tweet1,tweet2,tweet3);
				//printf("port ---  is %d\n",ntohs(ip->sin_port));
				//printf("Server is sending feedback!\n");
				close(childDes);
				exit(0);
			}
			close(childDes);
			//char zz[50] = "Hello pls accept me!";	
			//printf("port ---  is %d\n",ntohs(ip->sin_port));
			exit(0);
		}
		else{
			close(childDes);
			
		}
	wait(NULL);
	if((*counter) == 3)
			{
				memset(&IP,0,sizeof(IP));
				//feedsend();
			}
	
	}
	return 0;
}
