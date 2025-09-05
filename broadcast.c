#include "./includes/broadcast.h"

int broadcast(int p) {
    int s;
    size_t snd;
    char buf[BUFSIZ];
    struct sockaddr_in sv;
    socklen_t svz;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) error(bcast_sock_err);

    int bcast = 1;
    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &bcast, sizeof(bcast));

    sv.sin_family = AF_INET;
    sv.sin_port = htons(p);
    sv.sin_addr.s_addr = inet_addr(BCAST_PUB_ADDR);

    strcpy(buf, broadcast_single_peer); svz = sizeof(s);
    snd = sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&sv, svz);
    if (snd < 0) error(bcast_sendto_error);

    close(s);
}