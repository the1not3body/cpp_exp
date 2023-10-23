#include<iostream>
using namespace std;

void foo() {
    static int count = 0;  // 静态变量count，在函数调用之间保持不变
    count++;
    cout << "Count: " << count << endl;
    cout << "Count addr: " << &count << endl;
}

void foo1() {
    foo();
}

class MyClass {
public:
    void f1() {
        printdata();
    }
    static void printdata() {
        data = 20;
        cout << "data: " << data << endl;
    }
    // static virtual void f1() {};
private:
    static int data;  // 静态成员变量，属于类本身，不是类的实例
};

int MyClass::data = 10;  // 静态成员变量需要在类外进行定义和初始化

static int GobalStatic  = 15;
extern int Gobal = 16;

int main() {
    // foo();
    // foo1();
    MyClass* p = new MyClass();
    // MyClass::printdata();
    p->f1();
    return 0;
}