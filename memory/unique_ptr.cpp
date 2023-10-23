#include <iostream>
#include <memory>

using namespace std;

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass Destructor" << std::endl;
    }

    void print() {
        std::cout << "Hello, unique_ptr!" << std::endl;
    }
};

int main() {
    {
        std::unique_ptr<MyClass> ptr(new MyClass()); // 创建unique_ptr对象，管理MyClass的实例

        if (ptr) {
            ptr->print(); // 使用箭头操作符访问ptr所管理的对象的成员函数
        }
        std::unique_ptr<MyClass> ptr2(std::move(ptr)); // ptr2接管了ptr所指向的对象的所有权，ptr不再指向该对象
        if (ptr) {
            ptr->print();
        }
    } // ptr超出作用域，离开其作用域时会自动调用析构函数销毁所指对象

    std::cout << "After ptr is out of scope" << std::endl;

    return 0;
}