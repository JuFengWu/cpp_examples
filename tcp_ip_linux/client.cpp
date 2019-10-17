#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>

#define MAXLINE 1024
#define PORTNUMBER 6188
 
int main(){
    //socket的建立
    int sockfd = 0;
    sockfd = socket(AF_INET , SOCK_STREAM , 0);

    if (sockfd == -1){
        std::cout<<"Fail to create a socket."<<std::endl;
        return 0;
    }
    //socket的連線

    struct sockaddr_in info;
    bzero(&info,sizeof(info));
    info.sin_family = PF_INET;

    //localhost test
    info.sin_addr.s_addr = inet_addr("127.0.0.1");
    info.sin_port = htons(PORTNUMBER);


    int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
    if(err==-1){
        std::cout<<"Connection error"<<std::endl;
        return 0;
    }


    //Send a message to server
    char message[] = {"test abc"};
    char receiveMessage[MAXLINE] = {};
    send(sockfd,message,sizeof(message),0);
     recv(sockfd,receiveMessage,sizeof(receiveMessage),0);

    printf("%s\n",receiveMessage);
    printf("close Socket\n");
    close(sockfd);
    return 0;

}
