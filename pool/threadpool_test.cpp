#include "threadpool.h"
#include <features.h>
#include <iostream>
#include <unistd.h>
volatile int g_i = 0;

void ThreadLogTask(int i, int cnt) {
    int j = 10;
     std::cout << "ThreadLogTask thread #"<< std::this_thread::get_id() << "to do the task " << '\n';
    while(j--) {
        g_i++;
        sleep(1);
    }
    std::cout << "ThreadLogTask thread #"<< std::this_thread::get_id() << ", g_i: " << g_i << '\n';
}

void TestThreadPool() {
    ThreadPool threadpool(2);
  
    threadpool.AddTask(std::bind(ThreadLogTask, 11, 1000));
    sleep(1);
    threadpool.AddTask(std::bind(ThreadLogTask, 11, 1000));
    getchar();
    // std::cout << g_i << std::endl;
}

int main() {
    TestThreadPool();
    return 0;
}