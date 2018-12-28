#include <stdio.h>
#include <unistd.h>

main(int argc, char const *argv[])
{
    int ret = 0;
    ret = alarm(6);
    printf("ret = %d\n",ret);
    while(1){
        printf("da wo a \n");
        sleep(1);
    }
    return 0;
}
