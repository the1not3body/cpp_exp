#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called!" << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called!" << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> ptr1(new MyClass());  // 创建第一个shared_ptr对象
    std::cout << "Reference count of ptr1: " << ptr1.use_count() << std::endl;

    {
        std::shared_ptr<MyClass> ptr2 = ptr1;  // 拷贝构造，共享资源和引用计数
        std::cout << "Reference count of ptr2: " << ptr2.use_count() << std::endl;
    }

    std::cout << "Reference count of ptr1 after ptr2 is destroyed: " << ptr1.use_count() << std::endl; // 使引⽤次数减⼀并判断引⽤是否为零

    return 0;
}