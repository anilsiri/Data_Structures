#include "demo.h"

//server for UDP
struct sym_list Head;	/* head of singly-linked list */

void service(), save(), restore(), dump();

int main( argc, argv, env )
int argc;
char *argv[], *env[];
{
    int server_fd, create_service(), connection_fd;
    socklen_t len;
    struct sockaddr_in cliaddr;
    char buf[BUFSIZE];
    extern int close();
    
    server_fd = create_service();
    
//keeping running until you recieve a message from some client
    while( HELL_NOT_FROZEN ) {
	len = sizeof( cliaddr );
	restore(DATABASE);
	service(server_fd);
	save(DATABASE);
	close( connection_fd );
    }
}

void service( int fd )
{
   
    char buf[BUFSIZE];
    extern  void fix_tcl(), insert();

	//address for client
	struct sockaddr client;
	int clientLength;
	
	
	clientLength=sizeof(struct sockaddr);
	
	//client address saved in "client"
	//recvfrom saves the recieveing address in client
	//keep running till you recieve from client
    
while (recvfrom(fd, buf, BUFSIZE, 0, &client, &clientLength) > 0) 
    {
    char *ptr, *name, *value;
	fix_tcl( buf ); 

	//if equal to symbol found have to save it and send a '\n' to the client 
	if( (ptr = find_equals( buf )) != (char *) NULL ) 
	{
#ifdef EBUG
fprintf( stderr, "ASSIGN: %s\n", buf );
dump( buf );
#endif
	    *ptr = EOS;
	    name = strsave( buf ); 
	    value = strsave( ++ptr );
	    insert( name, value );
	    sprintf(buf, "\n");
		//if found message sent to client address
	    sendto(fd, buf, BUFSIZE, 0, &client, clientLength);
		fflush(stdout);
	    
	    save(DATABASE);
            #ifdef EBUG
	    fprintf( stderr, "REPLY: <not assigned>\n" );
            #endif
	}
	
	//if dollar symbol found, have to look up that pointer. 
	else if ((ptr = find_dollar( buf )) != (char *) NULL) 
        {
	    /* RETRIEVE */
	    char *reply, *find_newline; 
            #ifdef EBUG
	    fprintf(stderr, "dollar found\n");
	    dump( ptr );
            #endif
	   
	    if( (find_newline = strrchr( ptr, NEWLINE )) != NULL )
		*find_newline = EOS;
	    
	    if( (reply = lookup( ++ptr )) != NULL ) {
		sendto(fd, reply, BUFSIZE, 0, &client, clientLength);	
		fflush(stdout);	
		
        #ifdef EBUG
		fprintf( stderr, "REPLY: <%s>\n", reply );
                #endif
	    } 
            else {
		
		sprintf(buf, "\n");		
		sendto(fd, buf, BUFSIZE, 0, &client, clientLength);	
fflush(stdout);	
		
                #ifdef EBUG
		fprintf(stderr, "%s", ptr);
		fprintf( stderr, "REPLY: <unable to see vairiable>\n" );
                #endif
	    }
	} 
        else {
            #ifdef EBUG
	    fprintf( stderr, "GARBAGE\n" );
            #endif
	}
    }
    return;
}

//to open a socket
int create_service()
{
    int listenfd;
    struct sockaddr_in servaddr;
    
//socket() call
    listenfd = socket(AF_INET, SOCK_DGRAM, 0 );
    if( listenfd < 0 ) {
	perror( "creating socket for listenfd" );
	exit( ERR_SOCKET );
    }
    
    bzero( &servaddr, sizeof(servaddr) );
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
    servaddr.sin_port = htons( CIS553_PORT );
    

//to bind to the port
    if( bind( listenfd, (SA *) &servaddr, sizeof(servaddr) ) < 0 ) {
	perror( "bind on listenfd");
	exit( ERR_BIND );
    }
    return( listenfd );
}


void fix_tcl( char *buf )
{
    char *ptr;
    #define CARRIAGE_RETURN '\r'
    if( (ptr = strrchr( buf, CARRIAGE_RETURN )) != NULL )
	*ptr = EOS;
    return;
}
 
void dump( char *buf )
{
    fprintf( stderr, "strlen(buf)=%d, buf=<%s>\n", (int) strlen(buf), buf );
    int i;
    for( i=0; buf[i] != EOS; i++ )
	fprintf( stderr, "%d:%c:%x\n", i, buf[i], buf[i] );
}
