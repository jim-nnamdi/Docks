#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <string.h>

extern int ts;
extern int max_peers;

extern const char *svr_err;
extern const char *socket_err;
extern const char *bind_err;
extern const char *lis_err;
extern const char *acc_err;
extern const char *read_err;
extern const char *write_err;
extern const char *connect_err;
extern const char *recv_err;
extern const char *sendto_err;

extern const char *bcast_sock_err;
extern const char *bcast_sendto_error;
extern const char *BCAST_PUB_ADDR;
extern const char *broadcast_single_peer;

extern void error(const char* msg);
extern void docks_df(const char* msg);

#endif