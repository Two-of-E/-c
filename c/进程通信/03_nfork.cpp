//循环创建子进程，并且依次退出

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{

    int n = 5;
    int i = 0;
    pid_t pid = 0;
    for(i = 0; i<5; i++){
        pid = fork();
        if(pid == 0){
            //子进程
            printf("I am child ,pid=%d,ppid=%d\n",getpid(),getppid());
            break;//子进程退出循环，避免子进程再生成孙进程
        }
        else if(pid > 0){
            printf("I am father,pid=%d,ppid=%d\n",getpid(),getppid());
        }
    }
    //控制的结束
    sleep(i+1);
    if(i<5){
        printf("I am child%d ,will exit,pid=%d,ppid=%d\n",i,getpid(),getppid());
    }
    else{
        printf("I am father ,will out,pid=%d,ppid=%d\n",getpid(),getppid());
    }
    // while(1){
    //     sleep(1);
    // }
    return 0;
}

