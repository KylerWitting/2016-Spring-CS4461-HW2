/*
 ** talker.c -- a datagram "client" demo
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVERPORT "4950"	// the port users will be connecting to

int main(int argc, char *argv[])
{
    struct addrinfo hints, *servinfo, *p;
    int rv, numbytes, i=0, sockfd, j;
    char message[1024], *split, *send[1024], buffer[4];

    if (argc != 3) {
        fprintf(stderr,"usage: talker hostname message\n");
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and make a socket
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                        p->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "talker: failed to create socket\n");
        return 2;
    }

    strcpy( message, argv[2] );
    split= strtok ( message, " ");

    while ( split != NULL) {
        send[i] = split;
        split = strtok (NULL, " ");
        i++;

    }
    sprintf( buffer, "%d", i ); 

    printf("talker: sending a %s word message\n", buffer );
    if ((numbytes = sendto( sockfd, buffer, strlen(buffer), 0,
                    p->ai_addr, p->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }
    printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);

    for( j = 0; j < i; j++ ) {
        if ((numbytes = sendto( sockfd, send[j], strlen(send[j]), 0,
                        p->ai_addr, p->ai_addrlen)) == -1) {
            perror("talker: sendto");
            exit(1);
        }
        printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);
    }

    freeaddrinfo(servinfo);
    close(sockfd);

    printf("talker: done sending message\n");

    return 0;
}
