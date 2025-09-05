#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <string.h>

int ts = 1;
int max_peers =  10;

extern const char *svr_err;
extern const char *socket_err;
extern const char *bind_err;
extern const char *lis_err;
extern const char *acc_err;
extern const char *read_err;
extern const char *write_err;
extern const char *connect_err;
extern const char *recv_err;
extern const char *connect_err;

extern const char *bcast_sock_err;
extern const char *bcast_sendto_error;
extern const char *BCAST_PUB_ADDR;
extern const char *broadcast_single_peer;

void error(const char* msg);
void docks_df(const char* msg);

void docks_df(const char*msg) {
    printf("%s \n", msg);
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

#endif