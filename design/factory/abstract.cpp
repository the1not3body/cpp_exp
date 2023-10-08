#include <iostream>
using namespace std;

enum FruitType {orange, strawberry, cherry};


class Orange {
public:
    void Eat() { cout << "i am orange: "  << endl;}
};

class Strawberry{
public:
    void Eat() { cout << "i am strawberry: "  << endl;}
};

class FruitFactory {
public:
    virtual Strawberry* CreateStrawberry() = 0;
    virtual Orange* CreateOrange() = 0;
};

class GoodFarmerFactory : public FruitFactory {
public:
    Strawberry* CreateStrawberry() {
        return new Strawberry();
    }
    Orange* CreateOrange() {
        return new Orange();
    }
};

class DoleFactory : public FruitFactory {
public:
    Strawberry* CreateStrawberry() {
        return new Strawberry();
    }
    Orange* CreateOrange() {
        return new Orange();
    }
};

int main() {
    GoodFarmerFactory fac1;
    Orange* optr = fac1.CreateOrange();
    optr->Eat();

    delete optr;
    return 0;
}