#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include "string.h"



int main(int argc,char *argv[])
{
	int sock, length, port_number;
	int n;
	socklen_t fromlen;
	struct sockaddr_in server;
	struct sockaddr_in from;
	char buf[1024];
	
	
	if(argc<2)
	{
		fprintf(stderr,"ERROR, no port provided\n");
		exit(0);
	}
	
	sock=socket(AF_INET,SOCK_DGRAM,0);
	
	if(sock < 0)
	{
			printf("Opening socket\n");
			exit(0);
	}
	
	length = sizeof(server);
	bzero((char *)&server,sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(atoi(argv[1]));
	if(bind(sock,(struct sockaddr *)&server,length)<0)
	{
			printf("binding\n");
			exit(0);
	}
	fromlen = sizeof(from);
	while(1)
	{
		n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);

		if(n<0)
		{
			printf("recvfrom\n");
			exit(0);
		}
		write(1,"recieved a datagram: ",21);
		write(1,buf,n);
		
		n = sendto(sock,"Got your message\n",17,0,(struct sockaddr *)&from,sizeof(from));
				
		if(n < 0)
		{
			printf("sendto\n");
			exit(0);
		}
	}
}
	