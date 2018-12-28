#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

unsigned int myalarm(unsigned int seconds){
    //{周期性定时秒：微秒}，{下一次时间秒：微秒}
    struct itimerval oldit,myit = {{0,0},{0,0}};
    myit.it_value.tv_sec = seconds;

    setitimer(ITIMER_REAL,&myit,&oldit);
    printf("tv_sec = %ld,tv_mirsrc%ld\n",oldit.it_value.tv_sec,oldit.it_value.tv_usec);
    return oldit.it_value.tv_sec;
}
main(int argc, char const *argv[])
{
    int ret = 0;
    ret = myalarm(4);
    printf("ret = %d\n",ret);
    sleep(1);
    //返回剩余的时间
    ret = myalarm(4);
    printf("ret = %d\n",ret);
    while(1){
        printf("lai da wo\n");
        sleep(1);
    }
    /* code */
    return 0;
}

