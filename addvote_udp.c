#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
int
main( int argc, char *argv[] )
{
    char buf[BUFSIZE];
	struct hostent *server;
    int sockfd;
    struct sockaddr_in servaddr;
    
	int lengthIs;
	lengthIs = sizeof(struct sockaddr);

        
    /* Open up a TCP/IP socket */
    if( (sockfd = socket(AF_INET, SOCK_DGRAM, 0 )) < 0 ) {
	printf("error\n");
    }
    
	 server = gethostbyname(argv[1]);
	 portno = atoi(argv[2]);
	
    /* initialize and prepare for connections to a server */
    bzero( &servaddr, sizeof(servaddr ));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
   
	
    int recieved = sendto(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &servaddr, sizeof(struct sockaddr));
        if (recieved < 0) {
            perror("write failure to associative memory at server");
        }
		
		printf("sent data is %d", n);
		
}
   
   
   
   
   
   
   
   
   
   
   
   
   