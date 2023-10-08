#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("hello");
    printf("world");
    _exit(0);

    return 0;
}