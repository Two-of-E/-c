#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void catch_sig(int num){
    pid_t wpid;
    // wpid = waitpid(-1,NULL,WNOHANG);
    // if(wpid>0){
    //     printf("wait child %d ok \n",wpid);
    // }
    //一次尽可能多回收
    while((wpid = waitpid(-1,NULL,WNOHANG)) > 0){
        printf("wait child %d ok \n",wpid);
    }
}

main(int argc, char const *argv[])
{
    int i=0;
    pid_t pid;
    //在创建子进程之前屏蔽SIGCHLD信号
    sigset_t myset,oldset;
    sigemptyset(&myset);
    sigaddset(&myset,SIGCHLD);
    //保护现场，设置了SIGCHLD到阻塞信号集
    sigprocmask(SIG_BLOCK,&myset,&oldset);


    for(i =0;i<10 ;i++){
        pid = fork();
        if(pid == 0){
            break;
        }
    }
    if(i == 10){
        //parent
        sleep(2);
        struct sigaction act;
        act.sa_flags = 0;
        act.sa_handler = catch_sig;

        sigemptyset(&act.sa_mask);
        sigaction(SIGCHLD,&act,NULL);
        //解除屏蔽现场
        sigprocmask(SIG_SETMASK,&oldset,NULL);

        while(1){
            sleep(1);
        }


    }else if(i<10){
        printf("I am %d child,pid = %d\n",i,getpid());
        //sleep(1);
    }
    return 0;
}




