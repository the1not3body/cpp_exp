#include <stdio.h>
#include <pthread.h>
#include <string.h>

void * callback(void * arg) {
    printf("child thread id : %ld\n", pthread_self());
    for(int i = 10; i < 20; i++) {
        printf("j = %d\n", i);
    }
    return NULL;    //相当于pthread_exit(NULL); 即子线程执行完之后也退出，不会影响其他正常运行的线程
} 

int main() {

    // 创建一个子线程
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, callback, NULL);

    if(ret != 0) {
        char * errstr = strerror(ret);
        printf("error : %s\n", errstr);
    }

    // 主线程
    for(int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    printf("tid : %ld, main thread id : %ld\n", tid ,pthread_self());

    // 让主线程退出,当主线程退出时，不会影响其他正常运行的线程。
    pthread_exit(NULL);//退出线程
    printf("main thread exit\n");//有了上面那句，这行就不会执行了

    return 0;   // exit(0);//退出进程的意思
}
