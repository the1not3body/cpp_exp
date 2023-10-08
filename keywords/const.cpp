#include <iostream>
using namespace std;


const char * const p = "hello"; // p is a const pointer to a const char

// Path: effectiveCPP\const.cpp

void foo() {
    const int count = 0;
    const int *p = &count;
    const int &q = count;
    cout << "count : " <<  &count << endl;
    cout << "p : " << &p << endl;
    cout << "q : " << &q << endl;
}


class MyClass {
public:
    virtual ~MyClass() {}
    // const int num;
    // static int data;  // 静态成员变量，属于类本身，不是类的实例  
    MyClass();
    // MyClass(int i ) : num(i) {};
    
    // void printNum() {
    //     // num = 1;
    //     cout << num << endl;
    //     cout << data << endl;
    // }
    // static void printData() {
    //     cout << "Data: " << data << endl;
    //     // cout << "num: " << num << endl; 报错
    // }

    void f1();
    void f2() const;
    void f3() {
        f1();
        f2();
    }
    void f4 () const {
        // f1();
        f2();
    }
    virtual void f5() const {};
};

class subClass : public MyClass {
public:
    subClass() ;
    virtual ~subClass();
    virtual void f5() const override {
        cout << "h" << endl;
    };
};


// int MyClass::data = 10;

int main() {
    // foo();
    // MyClass p(3);
    MyClass* p = new subClass();
    p->f5();
    // p->printNum();
    return 0;
}