#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
    //如果成功就不返回,也就是不在输出后面的代码
    //execlp("lsxx","ls","-l",NULL);
    //用excelp成功调用其他文件
    //第二个参数是调用代码的参数
    execlp("./nfork.out","",NULL);
    perror("exec err");
    printf("hi\n");
    return 0;



}






