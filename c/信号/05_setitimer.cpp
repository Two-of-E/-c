#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
main(int argc, char const *argv[])
{
    struct itimerval myit={{0,0},{3,0}};//定义三秒

    setitimer(ITIMER_REAL,&myit,NULL);
    while(1){
        printf("ha\n");
        sleep(1);
    }
    return 0;
}
