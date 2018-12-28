#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if(pid == 0){
        printf("I am child,will die\n");
        sleep(2);
        return 120;
    }
    else if(pid > 0){
        int status;

        printf("I am parent,wait for child die!\n");
        pid_t wpid = wait(&status);

        printf("wait ok,wpid=%d,pid=%d\n",wpid,pid);
        if(WIFEXITED(status)){
            printf("child exit with %d\n",WEXITSTATUS(status));
        }
        
        else if (WIFSIGNALED(status)){
            printf("child killed by %d\n",WTERMSIG(status));
        }
        {
            /* code */
        }
        
        while(1){
            sleep(1);
        }
    }

    /* code */
    return 0;
}








