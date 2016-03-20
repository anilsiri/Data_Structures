/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{
 int server_fd;
 char buf[255]; 
 int listenfd;
 struct sockaddr_in servaddr;
    
    listenfd = socket(AF_INET, SOCK_DGRAM, 0 );

    if( listenfd < 0 ) {
	printf("error");
	}
    
    bzero( &servaddr, sizeof(servaddr) );
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
    servaddr.sin_port = htons( argv[1] );
    
    bind( listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr) );  
    
	struct sockaddr client;
	int clientLength;
	clientLength=sizeof(struct sockaddr);
	
	while (recvfrom(server_fd, buf, 255, 0, &client, &clientLength) > 0) 
    {
		printf("value recieved is %s", buf);
	}
}
		