#include <utmpx.h>
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>

int main(int ac, char **av) {
    struct utmpx u[6];
    //char *file = "/var/run/utmpx";
    //int fd = open(file, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);;
    int fd2 = open("test_utmp", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);;

    memset(&u, 0, sizeof(struct utmpx) * 6);
    write(fd2, &u, sizeof(struct utmpx) * 6);

    printf("sizeof: %lu\n", sizeof(struct utmpx));
    return 0;
}
