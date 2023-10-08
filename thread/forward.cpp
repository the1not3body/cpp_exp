#include <iostream>
#include <utility>

void some_function(int& val) {
    std::cout << "lvalue ref: " << val << '\n';
}

template <typename T>
void forward_example(T&& val) {
    some_function(std::forward<T>(val)); // 使用std::forward完美转发val
}



int main() {
    int x = 42;
    forward_example(x); // 传递一个左值
    // forward_example(100); // 传递一个右值
    return 0;
}
