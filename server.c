#include "./includes/server.h"

int serve(int p) {
    int s, c;
    size_t r, w;
    struct sockaddr_in sv, cv;
    socklen_t svz, cvz;
    char buf[BUFSIZ];

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0 ) error(socket_err);
    
    int opt = 1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&sv, 0, sizeof(sv));
    sv.sin_family = AF_INET;
    sv.sin_port = htons(p);
    sv.sin_addr.s_addr = INADDR_ANY;

    svz = sizeof (sv);
    int b = bind(s, (struct sockaddr*) &sv, svz);
    if (b < 0) error(bind_err);

    int l = listen(s, max_peers);
    if (l < 0) error(lis_err);

    cvz = sizeof (cv);
    c = accept(s, (struct sockaddr*) &cv, &cvz);
    if (c < 0) error(acc_err);

    while (ts) {
        memset(buf, 0, sizeof(buf));
        w = read(c, buf, sizeof(buf) - 1);
        if (w < 0) error(write_err);
        buf[w] = 0;
        printf("client:%s \n", buf);

        fgets(buf, sizeof(buf), stdin);
        r = write(c, buf, w);
        if (r < 0) error(read_err);
    }

    close(s);
    return (0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage : %s <port>", argv[0]);
        return (1);
    }
    char *p = argv[1];
    int s = serve(atoi(p));
    return s;
}