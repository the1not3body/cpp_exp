#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/uio.h> //readv
#include <vector> //readv
#include <atomic>
#include <assert.h>

int main() {
    struct iovec iov[3]; // 创建一个包含3个iovec结构的数组

    // 初始化三个缓冲区
    char buf1[] = "Hello, ";
    char buf2[] = "world!";
    char buf3[20]; // 用于接收数据的缓冲区

    // 设置iovec结构中的数据
    iov[0].iov_base = buf1;
    iov[0].iov_len = strlen(buf1);
    iov[1].iov_base = buf2;
    iov[1].iov_len = strlen(buf2);
    iov[2].iov_base = buf3;
    iov[2].iov_len = sizeof(buf3);

    // 使用writev将数据写入文件描述符1（标准输出）
    ssize_t bytes_written = writev(1, iov, 3);
    if (bytes_written == -1) {
        perror("writev");
        return 1;
    }

    // 使用readv从文件描述符0（标准输入）读取数据到buf3
    ssize_t bytes_read = readv(0, iov, 3);
    if (bytes_read == -1) {
        perror("readv");
        return 1;
    }

    // 输出从标准输入读取的数据
    std::cout << "Read " << bytes_read << " bytes: " << buf3 << std::endl;

    return 0;
}
