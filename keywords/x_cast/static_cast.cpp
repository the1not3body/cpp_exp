#include <iostream>
using namespace std;

class A {
public:
    A() : a(1) {
        cout << "A created... and a = " << a << endl;
    }
    virtual ~A() {
        cout << "A Destoryed..." << endl;
    }
    virtual void fun() {};
    int a;
};
class B : public A {
public:
    B() : b(2) {
        cout << "B created... and b = " << b << endl;
    }
    virtual ~B() {
        cout << "B Destoryed..." << endl;
    }
    int b;
};

void Test1() {
    A* aptr1 = new A();
    B* bptr1 = static_cast<B*>(aptr1); // 下行转换，不安全
    delete bptr1; // 转换失败，不会调用B的析构函数
}

void Test2() {
    A* aptr2 = new B();
    B* bptr2 = static_cast<B*>(aptr2); // 下行转换，安全
    delete bptr2;
}

void Test3() {
    int a = 10;
    void* p = &a;
    int* q = static_cast<int*>(p);
    cout << *q << endl;
}

void Test4() {
    int a = 10;
    int* p = &a;
    void* q = static_cast<void*>(p);
    // cout << q << endl;
}

void Test5() {
    int a = 10;
    char p = static_cast<char>(a);
}
int main () {
   Test3();
   return 0;
}