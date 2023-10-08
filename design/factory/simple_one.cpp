#include <iostream>
using namespace std;

enum FruitType {orange, strawberry, cherry};

class Fruit {
public:
    virtual ~Fruit();
    virtual void Eat() = 0;
};

class Orange : public Fruit {
public:
    Orange(string name) : name(name) {};
    void Eat() { cout << "i am orange: "  << endl;}
private:
    string name;
};

class FruitFactory {
public:
    Fruit* CreateFruit(FruitType type) {
        switch (type) {
        case orange:
            return new Orange("");
            break;
        default:
            break;
        }
    }
};