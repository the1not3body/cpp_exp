#include <iostream>
#include <thread>
#include <mutex>

volatile int g_i = 0;
std::mutex g_i_mutex;  // protects g_i

void safe_increment(int iterations) {
    std::cout << "thread #"  << std::this_thread::get_id() << "try to get the lock" << "\n";
    std::unique_lock<std::mutex> locker(g_i_mutex);
    std::cout << "thread #"  << std::this_thread::get_id() << "get the lock" << "\n";
    while (iterations-- > 0) {
        ++g_i; // t1 和 t2 对 g_i 的修改是互斥的
    }
    std::cout << "thread #"<< std::this_thread::get_id() << ", g_i: " << g_i << '\n';
} // 加上unique_lock后，意味着离开作用域才会释放锁，所以当t1执行完后，t2才能执行

// unique_lock 和 lock_guard 解决RAII 问题


void unsafe_increment(int iterations) {
    while (iterations-- > 0) {
        ++g_i;
    }
    std::cout << "thread #"<< std::this_thread::get_id() << ", g_i: " << g_i << '\n';
}

int main() {
    auto test = [](std::string fun_name, auto fun) {
        g_i = 0;
        std::cout << fun_name << ":\nbefore, g_i = " << g_i << '\n'; 
        
        {
            std::thread t1(fun, 100000000);
            std::thread t2(fun, 100000000);
            t1.join();
            t2.join();
        }
        std::cout << "after,g_i = " << g_i << '\n';
    };
    test("safe_increment", safe_increment);
    test("unsafe_increment", unsafe_increment);
}