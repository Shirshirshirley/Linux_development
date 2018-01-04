//使用库函数，实现文件的copy的功能

#include <stdio.h>
#include <stdlib.h>


int copyfile(char* from_file, char* to_file){
    FILE* fd_read,*fd_write;
    int word_read, word_write;
    char buffer[1024];
    int size=2;
    int n=4;
    char* ptr=buffer;
    //open the from file to read
    fd_read=fopen(from_file, "r");
    if(fd_read==NULL){
        perror("Error: ");
        return -1;
    }
    //open the to file to write
    fd_write=fopen(to_file,"w+");
    if(fd_write==NULL){
        perror("Error: ");
        return -1;
    }
    while(word_read=fread(buffer, size, n, fd_read)){
        printf("The length of the word_read: %d \n", word_read);
        if(word_read==-1){
            perror("Error: ");
            return -1;
        }else if(word_read==EOF){
            printf("Finished!\n");
            return 0;
        }else if(word_read>0){
            while(word_write=fwrite(ptr,size,word_read,fd_write)){
                if(word_write==-1){
                    perror("Failed to write to the destination file.\n");
                }else if(word_write==word_read){
                    break;
                }else if(word_write>0){
                    ptr=ptr+word_write;
                    word_read=word_read-word_write;
                    printf("The remainning words count in buffer is :%d \n", word_read);
                    continue;
                }
            }
        }
    }
    fclose(fd_read);
    fclose(fd_write);
    return 0;
}

int main(int argc, char* argv[]){
    if(argc!=3){
        perror("Invalid inputs, please anykey to quit \n");
        getchar();
        exit(1);
    }
    char* from_file, *to_file;
    from_file=argv[1];
    to_file=argv[2];
    printf("from_file: %s and to_file %s\n", from_file, to_file);
    int return_val;
    return_val=copyfile(from_file, to_file);
    if(return_val==0){
        printf("Successfully copied!\n");
    }else{
        perror("Unsuccessful operation!\n");
    }
    return 0;
}
