#include <iostream>
#include <memory>
using namespace std;
class MyClass;

class MyResource {
public:
    MyResource() {
        std::cout << "MyResource acquired" << std::endl;
    }

    ~MyResource() {
        std::cout << "MyResource released" << std::endl;
    }

    void doSomething() {
        std::cout << "Doing something with MyResource" << std::endl;
    }
};

class MyClass {
public:
    std::weak_ptr<MyResource> resource;

    void setResource(std::shared_ptr<MyResource> res) {
        resource = res;
    }

    void doSomethingWithResource() {
        if (auto ptr = resource.lock()) { // 尝试获得shared_ptr的强引用
            ptr->doSomething();
        } else {
            std::cout << "Resource is no longer available" << std::endl;
        }
    }
};

void Test1() {
    std::shared_ptr<MyClass> myClass = std::make_shared<MyClass>();
    std::shared_ptr<MyResource> resource = std::make_shared<MyResource>();

    myClass->setResource(resource); // MyClass持有resource的shared_ptr

    myClass->doSomethingWithResource(); // 正常访问resource

    resource.reset(); // 释放resource的shared_ptr，但MyClass仍然持有一个weak_ptr引用

    myClass->doSomethingWithResource(); // 输出"Resource is no longer available"，资源已不可用
}

// 
void Test2() {
    shared_ptr<int> sp = make_shared<int>(10);
    weak_ptr<int> wp(sp);
    cout << "shared_ptr指针指向该内存区域：" << wp.expired() << endl; 
    sp.reset();

    cout << "shared_ptr指针指向该内存区域：" << wp.expired() << endl;  
    shared_ptr<int> ptr2 = nullptr;  
    weak_ptr<int> ptr3(ptr2);  
    cout << "weak_ptr指针是否为空：" << ptr3.expired() << endl;  
}

int main() {
   Test2();

    return 0;
}
