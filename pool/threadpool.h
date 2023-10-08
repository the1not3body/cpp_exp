/*
 * @Author       : mark
 * @Date         : 2020-06-15
 * @copyleft Apache 2.0
 */ 

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <semaphore>
#include <functional>
#include <assert.h>
#include <iostream>
class ThreadPool {
public:
    explicit ThreadPool(size_t threadCount = 8): pool_(std::make_shared<Pool>()) {
            assert(threadCount > 0);
            for(size_t i = 0; i < threadCount; i++) {
                std::thread([pool = pool_] {
                    std::cout << "ThreadPool thread #"  << std::this_thread::get_id() << "try to get the lock" << "\n";
                    std::unique_lock<std::mutex> locker(pool->mtx); // 加锁
                    std::cout << "ThreadPool thread #"  << std::this_thread::get_id() << "get the lock" << "\n";
                    while(true) {
                        if(!pool->tasks.empty()) {
                            auto task = std::move(pool->tasks.front());
                            pool->tasks.pop();
                            locker.unlock();
                            std::cout << "ThreadPool thread #"  << std::this_thread::get_id() << "release the lock" << "\n";
                            task(); 
                            locker.lock();
                        } 
                        else if(pool->isClosed) break;
                        else{
                            std::cout << "ThreadPool thread #"  << std::this_thread::get_id() << "wait for new task" << "\n";
                            pool->cond.wait(locker);
                        } 
                    }
                }).detach();
            }
    }

    ThreadPool() = default;

    ThreadPool(ThreadPool&&) = default;
    
    ~ThreadPool() {
        if(static_cast<bool>(pool_)) {
            {
                std::lock_guard<std::mutex> locker(pool_->mtx);
                pool_->isClosed = true;
            }
            pool_->cond.notify_all();
        }
    }

    template<class F>
    void AddTask(F&& task) {
        {
            std::lock_guard<std::mutex> locker(pool_->mtx);
            pool_->tasks.emplace(std::forward<F>(task));
            std::cout << "a new task added" << "\n";
        }
        pool_->cond.notify_one();
    }

private:
    struct Pool {
        std::mutex mtx;

        std::condition_variable cond;
        bool isClosed;
        std::queue<std::function<void()>> tasks;
    };
    std::shared_ptr<Pool> pool_;
};


#endif //THREADPOOL_H