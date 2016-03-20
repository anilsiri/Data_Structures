
#include "demo.h"

int
main( int argc, char *argv[] )
{
    char buf[BUFSIZE];
    int sockfd;
    struct sockaddr_in servaddr;
    FILE *server_request, *server_reply;
    extern int close();
    //for udp
	int lengthIs;
	lengthIs = sizeof(struct sockaddr);

    
    /* Check if invoked correctly */
    if( argc != 2 ) {
	fprintf(stderr, "Usage: %s <IP address>\n", argv[0] );
	exit ( 1 );
    }
    
    /* Open up a TCP/IP socket */
    if( (sockfd = socket(AF_INET, SOCK_DGRAM, 0 )) < 0 ) {
	perror( "socket open" );
	exit( ERR_SOCKET );
    }
    
    /* initialize and prepare for connections to a server */
    bzero( &servaddr, sizeof(servaddr ));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons( CIS553_PORT );
    
    /* convert address, e.g., 127.0.0.1, to the right format */
    if( inet_pton( AF_INET, argv[1], &servaddr.sin_addr ) <= 0 ) {
	perror( "inet_pton for address" );
	exit( 99 );
    }
   
    for( putchar('>');
        (fgets( buf, BUFSIZE, stdin ) != NULL );
        putchar('>')) {

        /* send user input to server */
       int recieved = sendto(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &servaddr, sizeof(struct sockaddr));
        if (recieved < 0) {
            perror("write failure to associative memory at server");
        }
	fflush(stdout);

       /* user wants value */
 	if( (find_equals( buf ) == NULL) && (find_dollar( buf ) != NULL) ) {
 	    if( recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &servaddr, &lengthIs) < 0 ) {
 		perror( "read failure from associative memory at server");
 	    }
 	    fputs( buf, stdout );
 	}
 	
 	/* user sets value */
 	if( (find_equals( buf ) != NULL) && (find_dollar( buf ) == NULL) ) {
 	    if( recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &servaddr, &lengthIs) < 0 ) {
 		perror( "read failure from associative memory at server");
 	    }
 	}
    }
    /* shut things down */
    close( sockfd); 
    
    exit( 0 );
}
