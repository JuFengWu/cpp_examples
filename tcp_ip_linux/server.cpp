#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
 
#define MAXLINE 1024
#define PORTNUMBER 6188

int main(int argc, char** argv){
    int  listenfd, connfd;
    struct sockaddr_in  servaddr;
    char  buff[MAXLINE];
    int  n;
 
    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        std::cout<<"create socket error:"<<strerror(errno)<<", and errno is"<<errno<<std::endl;
        return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORTNUMBER);

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        std::cout<<"bind socket error:"<<strerror(errno)<<", and errno is"<<errno<<std::endl;
        return 0;
    }

    if( listen(listenfd, 10) == -1){
         std::cout<<"listen socket error:"<<strerror(errno)<<", and errno is"<<errno<<std::endl;
         return 0;
    }

    std::cout<<"waiting client"<<std::endl; 
 
     while(true){
         if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
             std::cout<<"accept socket error:"<<strerror(errno)<<", and errno is"<<errno<<std::endl;
             continue;
         }
         char message[] = {"send form server"};
         send(connfd,message,sizeof(message),0);
         n = recv(connfd, buff, MAXLINE, 0);
         buff[n] = '\0';
         std::cout<<"recv msg from client: "<<buff<<std::endl;
         close(connfd);
     }
     close(listenfd);
     return 0;
}
