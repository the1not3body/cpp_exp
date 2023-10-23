#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    std::shared_ptr<MyClass> ptr;
    MyClass() {
        std::cout << "Constructor called!" << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called!" << std::endl;
    }
};


void Test1() {
    std::shared_ptr<MyClass> ptr1(new MyClass());  // 创建第一个shared_ptr对象
    
    std::cout << "Reference count of ptr1: " << ptr1.use_count() << std::endl;

    {
        std::shared_ptr<MyClass> ptr2(ptr1);  // 拷贝构造，共享资源和引用计数
        std::cout << "Reference count of ptr2: " << ptr2.use_count() << std::endl;
    }

    std::cout << "Reference count of ptr1 after ptr2 is destroyed: " << ptr1.use_count() << std::endl; // 使引⽤次数减⼀并判断引⽤是否为零
}


// 循环引用 导致无法正常析构
void Test2() {
    std::shared_ptr<MyClass> ptr1(new MyClass());
    std::shared_ptr<MyClass> ptr2(new MyClass());

    ptr1->ptr = ptr2;
    ptr2->ptr = ptr1;
}

int main() {
    Test2();

    return 0;
}