#include <iostream>
extern int tom;
static int dick = 30;
int harry = 300;

void remote_access() {
     using namespace std;
    cout << "In remote_access() : " << endl;
    cout  << "&tom = " << &tom << ", " << "&dick = " << &dick << ", ";
    cout << "&harry = " << &harry << endl;
}
