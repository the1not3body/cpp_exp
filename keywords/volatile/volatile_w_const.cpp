#include <iostream>
using namespace std;

void Test1() {
    volatile const int* a = new int(10);
    volatile int const*  b = new int(10);
    volatile int* const c = new int(10);
    volatile const int* const d = new int(10);
    volatile int const* const e = new int(10);

    const volatile int* f = new int(10);
    const int volatile* g = new int(10);
    const int* volatile h = new int(10);
}

void Test2() {
    const int local = 10;
    printf("修改前:\n");
	printf("修改前local本身的值 : %d \n", local);
	printf("修改前local的地址: %x \n", &local);
 
	int *ptr = (int*)&local;
	*ptr = 100;
	printf("修改后:\n");
	printf("修改后local本身的值: %d \n", local);
	printf("修改后local对应的内存空间中的值:: %d \n", *ptr);
	printf("修改后local的地址: %x \n", &local);
	printf("\n\n");
	printf("测试添加volatile修饰符:\n");
 
 
	/****** 添加volatile避免编译器的优化 ********/
	const volatile int local2 = 10;
	printf("修改前:\n");
	printf("修改前local2本身的值 : %d \n", local2);
	printf("修改前local的地址: %x \n", &local2);
 
	int *ptr2 = (int*)&local2;
	*ptr2 = 100;
	printf("修改后:\n");
	printf("修改后local2本身的值: %d \n", local2);
	printf("修改后local2对应的内存空间中的值:: %d \n", *ptr2);
	printf("修改后local2的地址: %x \n", &local2);
}

int main() {
    Test2();
    return 0;
}