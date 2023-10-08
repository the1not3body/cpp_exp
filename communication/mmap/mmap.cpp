#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

    // 1.创建匿名内存映射区
    int len = 4096;
    void * ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);//如果是匿名映射MAP_ANONYMOUS，那么倒数第二个参数fd就写-1
    if(ptr == MAP_FAILED) {
        perror("mmap");
        exit(0);
    }

    // 父子进程间通信
    pid_t pid = fork();

    if(pid > 0) {
        // 父进程
        strcpy((char *) ptr, "hello, world");
        printf("parent pid %d send a msg\n", getpid());
        wait(NULL);
    }else if(pid == 0) {
        // 子进程
        sleep(1);
        printf("child pid %d get a msg %s\n", getpid(), (char *)ptr);
    }

    // 释放内存映射区
    int ret = munmap(ptr, len);
    if(ret == -1) {
        perror("munmap");
        exit(0);
    }
    
    return 0;
}