#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Begin ....\n");
    pid_t pid = fork();
    if(pid < 0){
        perror("fork err");
        exit(1);
    }
    else if(pid == 0){
        //子进程
        printf("I am a child,pid = %d,ppid = %d\n",getpid(),getppid());
        while(1){
            printf("I am a child\n");
            sleep(1);
        }
        sleep(1);
    }
    else if(pid > 0){
        printf("childpid = %d,self = %d,ppid = %d\n",pid,getpid(),getppid());
        while(1){
            sleep(1);
        }
        
    }
    printf("End ....q\n");
    return 0 ;
}