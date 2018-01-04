#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pc;
    pc=fork();
    if(pc==0)
        printf("The child process has an ID of = %d \n", getpid());
    else if(pc<0)
        perror("Error: \n");
    else
        printf("The parent process has an ID of = %d \n", getpid());
    return 0;
}