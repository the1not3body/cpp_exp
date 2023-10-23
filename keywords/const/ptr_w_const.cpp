#include <iostream>

using namespace std;

int main() {
    int* p = new int(10);
    // int const* q = p;
    // const int*q = p;
    // *q = 20;
    int* const r = p;
    *r = 20;
    cout << *p << endl;
    const int* const s = p;
    // *s = 30;
    cout << *p << endl;
    int const* const t = p;
    // const int* p = new int(10);
    // int const* q = new int(10);
    // int* const r = new int(10);
    // const int* const s = new int(10);
    // int const* const t = new int(10);

    // cout << *p << endl;
    // cout << *q << endl;
    // cout << *r << endl;
    // cout << *s << endl;
    return 0;
}