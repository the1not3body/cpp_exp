#include <iostream>
using namespace std;

int main() {
    int a[10] = {11, 1, 2, 3, 4, 5, 6, 7, 8,9};
    int (*p)[10] = &a;
    cout << (*p)[0] << endl;
    cout << (*p)[1] << endl;
    cout <<  p[1] << endl;
    cout << p << endl;
    return 0;
}