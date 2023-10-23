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
    B* bptr1 = dynamic_cast<B*>(aptr1); // 下行转换，不安全
    if (bptr1 != nullptr) {
        cout << "free bptr1: " << endl;
        delete bptr1;
    } else {
        cout << "free aptr1: " << endl;
        delete aptr1;
    } 
}

void Test2() {
    A* aptr2 = new B();
    B* bptr2 = dynamic_cast<B*>(aptr2); // 下行转换，安全
     if (bptr2 != nullptr) {
        cout << "free bptr2: " << endl;
        delete bptr2;
    } else {
        cout << "free aptr2: " << endl;
        delete aptr2;
    } 
}

void Test3() {
    int a = 10;
    // char p = dynamic_cast<int>(a);
}

int main () {
   Test2();
   return 0;
}