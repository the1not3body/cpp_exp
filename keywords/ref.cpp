#include <iostream>
using namespace std;

void testREFF(int& p) {
	p = 20; // 等价于 *p = 20;
}

int main()
{
	int a = 10;
	int& b = a;

    cout << &b << " " << b << endl;
	testREFF(b);
	cout << b << endl;//12

    return 0;
}