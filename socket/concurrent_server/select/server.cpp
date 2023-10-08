#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

int main() {

    // 创建socket
    int lfd = socket(PF_INET, SOCK_STREAM, 0);//返回监听文件描述符
    struct sockaddr_in saddr;
    saddr.sin_port = htons(9999);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;

    // 绑定
    bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));

    // 监听
    listen(lfd, 8);

    // 创建一个fd_set的集合，存放的是需要检测的文件描述符
    fd_set rdset, tmp;
    FD_ZERO(&rdset);//先全部清零
    FD_SET(lfd, &rdset);//把监听文件描述符对应的标志位置一
    int maxfd = lfd;//最大文件描述符的值设置为lfd的值

    while(1) {

        tmp = rdset;
        //把fdset赋给一个临时集合，因为有可能要修改其内部的值

        // 调用select系统函数，让内核帮检测哪些文件描述符有数据
        int ret = select(maxfd + 1, &tmp, NULL, NULL, NULL);
        if(ret == -1) {
            perror("select");
            exit(-1);
        } else if(ret == 0) {
            //表示检测的集合中没有文件描述符发生变化
            continue;
        } else if(ret > 0) {
            //说明检测到了有文件描述符的对应的缓冲区的数据发生了改变
            //先判断lfd是否发生变化
            if(FD_ISSET(lfd, &tmp)) {//表示有新的客户端连接进来了
                struct sockaddr_in cliaddr;
               	int len = sizeof(cliaddr);
   				int cfd = accept(lfd, (struct sockaddr *)&cliaddr, (socklen_t*)&len);//返回用于通信的文件描述符

                // 将新的文件描述符加入到集合中
                FD_SET(cfd, &rdset);

                // 更新最大的文件描述符
                maxfd = maxfd > cfd ? maxfd : cfd;
            }
			//遍历除监听文件描述符之外的其他文件描述符，即用来和客户端通信的fd
            for(int i = lfd + 1; i <= maxfd; i++) {
                if(FD_ISSET(i, &tmp)) {
                    // 说明这个文件描述符对应的客户端发来了数据
                    char buf[1024] = {0};
                    int len = read(i, buf, sizeof(buf));
                    
                    if(len == -1) {
                        perror("read");
                        exit(-1);
                    } else if(len == 0) {
                        printf("client closed...\n");
                        close(i);
                        FD_CLR(i, &rdset);
                        //客户端关闭后，记得把它对应的标志位也清零
                    } else if(len > 0) {
                        printf("read buf = %s\n", buf);
                        usleep(1000);
                        write(i, buf, strlen(buf) + 1);//写数据
                        sleep(1);
                    }
                }
            }

        }

    }
    close(lfd);
    return 0;
}
