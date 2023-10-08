#include <stdio.h>
#include <arpa/inet.h>

int main() {

    //printf("a = %d, b = %d\n", sizeof(unsigned short), sizeof(unsigned short int)); // a = 2, b = 2
    // htons 转换端口（short类型，占2个字节）
    unsigned short a = 0x1234;//主机字节序（小端模式）
    printf("a : %x\n", a);
    unsigned short b = htons(a);//转换成网络字节序（大端模式）
    printf("b : %x\n", b);

    printf("=======================\n");

    // htonl 转换IP（int类型，占4个字节）
    char buf[4] = {100, 80, 1, 100};
    int num = *(int *)buf;
    printf("num = %d\n", num);
    int sum = htonl(num);
    unsigned char *p = (unsigned char *)&sum;

    printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));

    printf("=======================\n");

    // ntohl
    unsigned char buf1[4] = {1, 1, 80, 100};
    int num1 = *(int *)buf1;
    int sum1 = ntohl(num1);
    unsigned char *p1 = (unsigned char *)&sum1;
    printf("%d %d %d %d\n", *p1, *(p1+1), *(p1+2), *(p1+3));
    
     // ntohs


    return 0;
}
