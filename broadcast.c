#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/event.h>
#include <netinet/in.h>
#include <netdb.h>

int broadcast(int p) {
    int s, c;
    size_t snd, rcv;
    char buf[BUFSIZ];
    struct sockaddr_in sv, cv;
    socklen_t svz, cvz;

    s = socket(AF_INET, SOCK_DGRAM, 0);
}