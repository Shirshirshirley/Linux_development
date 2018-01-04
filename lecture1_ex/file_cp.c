#include <stdio.h>
#include <fcntl.h>
//not technically required, but needed on some UNIX distributions

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFFER 1024

int main(){
//open the from file,the file discriptor
int from_fd;
from_fd=open("fromfile.txt", O_RDONLY);
//open the to_file, if it doesn't exist, create a new file
int to_fd;
to_fd=open("tofile.txt", O_WRONLY|O_CREAT,0755);
if(from_fd==-1||to_fd==-1){
    perror("Open file failed, please try again.");
    exit(1);
}
//read from the from_file, return the number of words read
int word_read;
int word_write=0;
char buff[BUFFER];
char ptr;//a pointer pointing to the buffer
//continuously read data from the from_file
while(word_read=read(from_fd,buff,BUFFER)){
    if(word_read==-1){
    perror("Failed to read from from_file.");
    exit(1);
    }else{
            ptr=buff;
            while(word_write=write(to_fd, ptr,BUFFER)){
                if(word_write==-1){
                    perror("Failed to write to to_file.");
                    exit(1);
                }else if(word_write==word_read){
                    break;
                }else if(word_write>0){ //this is when size_read!=size_write
                    ptr=ptr+word_write;
                    word_read=word_read-word_write;
                }
            }
        }
    }
//finish transferring the data; need to save the file and close them.
close(from_fd);
close(to_fd);
exit(0);
}

