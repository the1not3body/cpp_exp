#include <iostream>
using namespace std;

class A {
public:
    A() : b(1) {
        cout << "A created..." << endl;
    }
    virtual ~A() {
        cout << "A Destoryed..." << endl;
    }
    virtual void fun() {};
    int b;
};
class B : public A {
public:
    B() : d(2) {
        cout << "B created..." << endl;
    }
    virtual ~B() {
        cout << "B Destoryed..." << endl;
    }
    int d;
};

void Test1() {
    A* aptr1 = new A();
    B* bptr1 = static_cast<B*>(aptr1); // 下行转换
    cout << bptr1->d << endl;
    delete aptr1;
    aptr1 = NULL;
}

void Test2() {
    A* aptr2 = new B();
    B* bptr2 = static_cast<B*>(aptr2); // 上行转换
    cout << bptr2->d << endl;
    delete aptr2;
}

int main () {
   Test2();
   return 0;
    // delete bptr2;
}