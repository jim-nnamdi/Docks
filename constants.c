#include "constants.h"
#include <stdlib.h>

int ts = 1;
int max_peers =  10;

const char *svr_err = "no such server";
const char *socket_err = "socket error";
const char *bind_err = "bind error";
const char *lis_err = "listen error";
const char *acc_err = "accept error";
const char *read_err = "read error";
const char *write_err = "write error";
const char *connect_err = "connect error";
const char *recv_err = "receive_from error";
const char *sendto_err = "sendto error";

const char *bcast_sock_err = "broadcast socket error";
const char *bcast_sendto_error = "broadcast send to error";
const char *BCAST_PUB_ADDR = "255.255.255.255";
const char *broadcast_single_peer = "looking for peers";


void docks_df(const char*msg) {
    printf("%s \n", msg);
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}