#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    pid_t pc, pwait;
    int count=0;
    pc=fork();
    if(pc==0){
        printf("I am the child process, pid= %d", getpid());
        for(count=0; count<10; count++){
            printf("Data= %d", count);
        }
        exit(0);
    }else{
        printf("I am the parent process pid= %d", getpid());
        pwait= wait(NULL);
        printf("I waited process pid= %d", pwait);
        exit (0);
    }
    return 0;
}