//Create a datagram client

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include "string.h"


int main(int argc, char *argv[])
{
	int sock,n;
	socklen_t length;
	struct sockaddr_in server, from;
	struct hostent *hp;
	char buffer[256];
	
	if(argc!=3)
	{
		printf("usage server port\n");
	}
	
	sock = socket(AF_INET, SOCK_DGRAM,0);
	if(sock < 0)
	{

		printf("Opening socket\n");
	}
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	
	if(hp==0)
	{

		printf("Unknown host\n");
	}
	bcopy((char *)hp->h_addr,(char *)&server.sin_addr,hp->h_length);
	
	bzero( &server, sizeof(server ));
    server.sin_family = AF_INET;
 
	
	server.sin_port = htons(atoi(argv[1]));
	length = sizeof(from);
	
	printf("Please enter the message\n");
	bzero(buffer,256);
	fgets(buffer,255,stdin);
	n = sendto(sock,buffer,strlen(buffer),0,(struct sockaddr *)&server,sizeof(server));
	if(n<0)
	{
		printf("send to\n");
	}
	n = recvfrom(sock,buffer,256,0,(struct sockaddr *)&from,&length);
	if(n<0)
	{
		printf("recvfrom\n");
	}
	write(1,"Got an ack: ",12);
	write(1,buffer,n);
}