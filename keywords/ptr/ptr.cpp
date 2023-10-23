#include <iostream>
using namespace std;

void testPtr(int* p)
{
    cout << &p << " " <<  p << endl;
    int a = 1;
    p = &a;
    cout << &p << " " <<  p << endl;
}

int main(void)
{
    int *p = NULL;
    cout << &p << " " << p << endl;
    testPtr(p);
    cout << &p << " " << p << endl;

    return 0;
}