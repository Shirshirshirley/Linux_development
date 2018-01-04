//在父进程中创建一无名管道，并创建紫禁城来读该管道， 父进程来写该管
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char** argv){
    pid_t pc;
    //create a new pipe
    int pd[2];
    char buffer[512];
    if(pipe(pd)<0){
        perror("Error: \n");
    }else{
        pc=fork();
        //the child process read from pipe using pd[0];
        if(pc==0){// This is the child process
            printf("I am the  child process...\n");
            sleep(2);//wait for parent process to write first
            printf("Finish sleeping!\n");
            close(pd[1]);
            int data;
            printf("Start reading from parent process...\n");
            data=read(pd[0],buffer,100);
            if(data<0){
                perror("Error: \n");
            }
            else{
                printf("The content inside the child process pid= %d is %s", getpid(), buffer);
            }
            exit(0);
        }else{//this is the parent process writing to pipe
            close(pd[0]);
            int data1;
            printf("Start writing to child process...\n");
            data1=write(pd[1],argv[1], 100);
            exit(0);
        }

    }
    return 0;
}