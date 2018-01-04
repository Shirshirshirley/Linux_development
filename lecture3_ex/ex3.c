#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
//exec函数族会在一个进程中启动另外一个程序执行，并用它来取代原调用进程的数据段、代码段和堆栈段。
//在exec函数调用后，原调用进程的内容除了进程号之外，其他全部被新的进程替代了。
int main(){
    int data;
    data=execl("./a","a",NULL);
    if(data<0){
        perror("Error:");
    }else{
        printf("The currrent process is %d\n",getpid());
    }
    exit(1);
}