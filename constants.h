#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <string.h>

int ts = 1;
int max_peers =  10;

extern const char *svr_err = "no such server";
extern const char *socket_err = "socket error";
extern const char *bind_err = "bind error";
extern const char *lis_err = "listen error";
extern const char *acc_err = "accept error";
extern const char *read_err = "read error";
extern const char *write_err = "write error";
extern const char *connect_err = "connect error";

extern const char *bcast_sock_err = "broadcast socket error";
extern const char *bcast_sendto_error = "broadcast send to error";
extern const char *BCAST_PUB_ADDR = "255.255.255.255";
extern const char *broadcast_single_peer = "looking for peers";

void error(const char* msg);
void error(const char *msg) {
    perror(msg);
    exit(1);
}

#endif