#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

main(int argc, char const *argv[])
{
    printf("I will die!\n");
    //sleep函数属于unist库
    sleep(2);


    //kill(getpid(),sig)自杀
    //raise(SIGKILL);

    //直接放弃
    abort();
    return 0;
}


