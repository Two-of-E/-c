#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

main(int argc, char const *argv[])
{
    int i =0;
    pid_t pid3,pid;
    for(i = 0;i<5;i++){
        pid = fork();
        if(pid == 0){
            break;
        }
        if(i == 2){
            pid3 = pid;
        }
    }
    if(i<5){
        while(1){

            printf("I am child,pid = %d,ppid=%d\n",getpid(),getppid());
            sleep(3);
        }
    }
    else if(i ==5){
        printf("I am parent ,pid =%d,I will kill xiaosan pid3=%d\n",getpid(),pid3);
        sleep(5);
        kill(pid3,SIGKILL);
        while(1){
            sleep(1);
        }
    }
    return 0;
}
