#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/event.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "constants.h"

int broadcast(int p) {
    int s;
    size_t snd;
    char buf[100];
    struct sockaddr_in sv;
    socklen_t svz;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) error(bcast_sock_err);

    int bcast = 1;
    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &bcast, sizeof(bcast));
    
    sv.sin_family = AF_INET;
    sv.sin_port = htons(p);
    sv.sin_addr.s_addr = inet_addr(BCAST_PUB_ADDR);

    buf[100] = broadcast_single_peer; svz = sizeof(s);
    snd = sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&sv, svz);
    if (snd < 0) error(bcast_sendto_error);

    close(s);
}