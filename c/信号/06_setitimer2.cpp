#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

//
void catch_sig(int num){
    printf("cat %dsig\n",num);
}
main(int argc, char const *argv[])
{
    signal(SIGALRM,catch_sig);
    //第一次等待五秒，之后每隔三秒
    struct itimerval myit = {{3,0},{5,0}};
    setitimer(ITIMER_REAL,&myit,NULL);
    while(1){
        printf("ha\n");
        sleep(1);
    }

    return 0;
}

