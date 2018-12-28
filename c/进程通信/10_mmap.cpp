#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //创建并截断文件
    int fd = open("mem.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    //扩展文件,不能用大小为0的文件
    ftruncate(fd,8);
    //cpp强制类型转换解决，void函数返回地址的问题。
    //char *mem = (char*)mmap(NULL,8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    char *mem = (char*)mmap(NULL,8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    
    if(mem == MAP_FAILED){
        perror("mmap err");
        return -1;
    }
    strcpy(mem,"world\n");

    munmap(mem,8);
    close(fd);
    return 0;
}

