#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void catch_sig(int num){
    printf("begin call ,catch %d sig\n",num);
    sleep(5);//模拟捕获函数执行时间较长
    printf("end call ,catch %dsig\n ",num);
}
main(int argc, char const *argv[])
{
    struct sigaction act;
    act.sa_flags = 0;
    act.sa_handler = catch_sig;

    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask,SIGQUIT);//临时屏蔽ctrl+\信号

    //注册捕捉
    sigaction(SIGINT,&act,NULL);
    while(1){
        printf("who can kill me?\n");
        sleep(1);
    }
    return 0;
}




