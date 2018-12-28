#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if(pid == 0){
        printf("I am child,pid =%d,ppid=%d\n",getpid(),getppid());
        sleep(2);
        printf("I am child,I will die\n");

    }
    else if(pid>0){
        while(1){
        printf("I am father,very happy,pid = %d\n",getpid());
        sleep(1);


    }
    }
    /* code */
    return 0;
}


