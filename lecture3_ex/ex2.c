#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pc;
    int count=0;
    pc=vfork();
    count++;
    if(pc==0){
        printf("This is the child process, pid=%d \n", getpid());
        printf("Count= %d\n", count);
        exit(1);//certain properties of a process can be determined only after the process has quit, child process need to be quited before entering the parent process
    }else if(pc<0){
        perror("Error: \n");
        exit(0);
    }else{
        printf("This is the parent process, pid=%d \n", getpid());
        printf("Count= %d\n", count);
        exit(1);//parent process quit before requited information
    }
    return 0;
}