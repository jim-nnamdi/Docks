#include "./includes/client.h"

int client(int p, const char* svr) {
    int s, c;
    size_t r, w;
    struct sockaddr_in sv;
    socklen_t svz;
    char buf[BUFSIZ];

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) error(socket_err);

    memset(&sv, 0, sizeof(sv));
    sv.sin_family = AF_INET;
    sv.sin_port = htons(p);
    if(inet_pton(AF_INET, svr, &sv.sin_addr) <= 0)
        error(invalid_server_address);

    svz = sizeof(sv);
    c =  connect(s, (struct sockaddr*)&sv, svz);
    if (c < 0) error(connect_err);
    printf("connected to %s:%d \n", svr, p);

    while (ts) {
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);
        r = write(s, buf, strlen(buf));
        if (r < 0) error(write_err);

        w = read(s, buf, sizeof(buf) - 1);
        if (w < 0) error(read_err);
        buf[w] = 0;
        printf("server: %s \n", buf);
    }

    close(s);
    return (0);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <server> <port>", argv[0]);
        return (1);
    }
    char* s = argv[1];
    char* p = argv[2];
    int c = client(atoi(p), s);
    return c;
}