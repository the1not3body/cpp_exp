#include <iostream>
#include <functional>
#include <utility>

void print_sum(int a, int b) {
    std::cout << a + b << std::endl;
}

template <typename Func, typename... Args>
void call_with_bound_arguments(Func func, Args&&... args) {
    auto bound_func = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);
    bound_func(); // 调用绑定的函数
}

int main() {
    int x = 10;
    int y = 20;

    call_with_bound_arguments(print_sum, x, y); // 输出 30，其中 x 和 y 是被绑定的参数

    return 0;
}
