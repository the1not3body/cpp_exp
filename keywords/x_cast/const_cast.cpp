#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *  const b = &a;
    int* p = const_cast<int*>(b);
}
