#include <unistd.h>
#include <stdio.h>

int main () {
    pid_t pid = fork();
    if (pid > 0) {
        printf("i am parent process, pid : %d\n", getpid());
        sleep(1);
    } else {
        execl("helloc", "hello", NULL); // 执行成功覆盖子进程的内容
        // execl("/bin/ps", "ps", "aux", NULL);
        perror("execl");
        // 找不到的话执行本来内容
        printf("i am child process, pid : %d \n", getpid());
    }

    for (int i = 0; i < 3; i++) {
        printf("i = %d, pid = %d\n", i, getpid());
    }

    return 0;
}