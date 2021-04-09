#include <stdio.h>      // Default System Calls
#include <stdlib.h>     // Needed for OS X
#include <string.h>     // Needed for Strlen
#include <sys/socket.h> // Needed for socket creating and binding
#include <netinet/in.h> // Needed to use struct sockaddr_in
#include <time.h>       // To control the timeout mechanism

int main( void )
{
    int fd;
    if ( (fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket failed");
        return 1;
    }

    struct sockaddr_in serveraddr;
    memset( &serveraddr, 0, sizeof(serveraddr) );
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons( 50037 );
    serveraddr.sin_addr.s_addr = htonl( 0x7f000001 );


    int n = (int)time(NULL);
    unsigned char timestamp[4];
    timestamp[0] = (n >> 24) & 0xFF;
    timestamp[1] = (n >> 16) & 0xFF;
    timestamp[2] = (n >> 8) & 0xFF;
    timestamp[3] = n & 0xFF;

    unsigned char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    unsigned char s[6] = "hello\0";
    memcpy(&buffer, &timestamp, 4);
    memcpy(&buffer[4], &s, strlen(s));


    for ( int i = 0; i < 2; i++ ) {
        if (sendto( fd, buffer, strlen(buffer), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0 ) {
            perror( "sendto failed" );
            break;
        }
        printf("message sent\n" );
    }

    close( fd );
}