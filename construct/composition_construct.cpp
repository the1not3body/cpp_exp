#include <iostream>

using namespace std;

class B {
public:    
    B() {
        cout << "B created..." << endl;
    }

    virtual ~B() {
        cout << "B destoried..." << endl;
    }
};

class A {
public:
    B BInst;
    A() {
        cout << "A created..." << endl;
    }

    virtual ~A() {
        cout << "A destoried..." << endl;
    }
};



class C : public A {
public:

    C() {
        cout << "C created..." << endl;
    }

    virtual ~C() {
        cout << "C destoried..." << endl;
    }
};

int main() {
    A *ptr = new C();
    delete ptr;
}