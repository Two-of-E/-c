#include <unistd.h>
#include <stdio.h>

main(int argc, char const *argv[])
{
    int i = 0;
    alarm(1);
    while(1){
        printf("%d\n",i++);
    }
    return 0;
}



