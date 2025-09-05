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

    memcpy(buf, 0, sizeof(buf));

    sv.sin_family = AF_INET;
    sv.sin_port = htons(p);
    sv.sin_addr.s_addr = INADDR_ANY;
    sv.sin_len = sizeof sv;

    svz = sizeof (sv);
    int b = bind(s, (struct sockaddr*) &sv, svz);
    if (b < 0) error(bind_err);

    int l = listen(s, max_peers);
    if (l < 0) error(lis_err);

    while (ts) {

        memcpy(buf, 0, sizeof(buf));
        cvz = sizeof (cv);
        c = accept(s, (struct sockaddr*) &cv, cvz);
        if (c < 0) error(acc_err);

        r = send(c, buf, sizeof(buf), 0);
        if (r < 0) error(read_err);

        w = recv(c, buf, strlen(buf), 0);
        if (w < 0) error(write_err);
    }

    close(c);
    close(s);
}
