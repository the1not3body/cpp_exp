#include <iostream>
#include <functional>

void print_sum(int a, int b) {
    std::cout << a + b << std::endl;
}

int main() {
    auto add_five = std::bind(print_sum, std::placeholders::_1, std::placeholders::_2);
    add_five(10, 6); // 输出 15，其中 10 是第一个参数
    return 0;
}
