#include <iostream>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* thread_func(void* arg) {
    std::cout << "child_thread..." << std::endl;
    std::cout <<  "arg value: " << *(int *) arg << std::endl;
    return nullptr;
}

int main() {
    pthread_t tid;
    int num = 10;

    int ret = pthread_create(&tid, nullptr, thread_func, (void*) &num);

    if (ret != 0) {
        char* errstr = strerror(ret);
        std::cout << "error: " << errstr << std::endl;
    }

    for (int i = 0; i < 30; ++i) { // 主线程和子线程抢占资源
        std::cout << i << std::endl;
    }

    sleep(1);

    return 0;
}