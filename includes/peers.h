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

int listen_for_peers(int p);