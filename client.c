#include "./includes/client.h"

int client(int p, const char* svr) {
    int s, c;
    size_t r, w;
    struct sockaddr_in sv;
    socklen_t svz;
    struct hostent* sn;
    char buf[BUFSIZ];

    s =  socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) error(socket_err);

    sn = gethostbyname(svr);
    if (sn == NULL) error(svr_err);

    sv.sin_family = AF_INET;
    sv.sin_port = htons(p);
    sv.sin_addr.s_addr = INADDR_ANY;
    sv.sin_len = sizeof(sv);

    svz = sizeof (sv);
    c =  connect(s, (struct sockaddr*)&sv, svz);
    if (c < 0) error(connect_err);

    while (ts) {
        r = send(c, buf, sizeof(buf), 0);
        if (r < 0) error(read_err);

        w = recv(c, buf, strlen(buf), 0);
        if (w < 0) error(write_err);
    }

    close(c);
    close(s);
    return (0);
}

int main(int argc, char **argv) {
    char* s = argv[1];
    char* p = argv[2];
    int c = client(atoi(p), s);
    return c;
}