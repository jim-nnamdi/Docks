#include "peers.h"

int listen_for_peers(int p) {
    int s, c;
    size_t rcv;
    char buf[BUFSIZ];
    struct sockaddr_in sv,cv;
    socklen_t svz, cvz;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) error(bcast_sock_err);

    memset(&sv, 0, sizeof(sv));
    sv.sin_family = AF_INET;
    sv.sin_port = htons(p);
    sv.sin_addr.s_addr = INADDR_ANY;

    svz = sizeof(sv);
    int b =  bind(s, (struct sockaddr*)&sv, svz);
    if (b < 0) error(bind_err);

    while (ts) {
        memset(buf, 0, sizeof(buf));
        cvz = sizeof(cv);
        rcv = recvfrom(s, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&cv, cvz);
        if (rcv < 0) error(recv_err); 
        buf[rcv] = 0;
        if (strcmp(buf, broadcast_single_peer) == 0)
            dock_df(inet_ntoa(cv.sin_addr));
    }

    close(s);
}