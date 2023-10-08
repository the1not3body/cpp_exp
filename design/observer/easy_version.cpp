// cpp 委托构造

#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void update(Subject* sub, int value) = 0;
};

class Subject {
public:
    void attach(Observer* obs) {
        m_views.push_back(obs);
    }

    void set_val(int value) {
        m_value = value;
        notify();
    }

    void notify() {
        for (auto it : m_views) {
            it->update(this, m_value);
        }
    }
private:
    int m_value;
    vector<Observer*> m_views;
};