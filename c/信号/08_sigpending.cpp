#include <stdio.h>
#include <unistd.h>
#include <signal.h>

main(int argc, char const *argv[])
{
    sigset_t pend,sigproc;
    //设置阻塞信号，等待按键产生信号
    sigemptyset(&sigproc);//先清空
    sigaddset(&sigproc,SIGINT);
    //sigaddset(&sigproc,SIGQUIT);
    //设置阻塞信号集
    sigprocmask(SIG_BLOCK,&sigproc,NULL);
    while(1){
            sigpending(&pend);
    int i = 1;
    for(i = 1;i<32;i++){
        if(sigismember(&pend,i) == 1){
            printf("1");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
    sleep(1);

    }
    //循环取未决信号集

    return 0;
}



