//编写应用程序， 创建一可读可写的文件

#include <stdio.h>
#include <stdlib.h>
int main(){
FILE* stream;
stream=fopen("Driver.txt", "w+");
int word_write;
int word_read;
char buffer[80]="Zicun has been driving for a long period of time! \n";
word_write=fwrite(buffer, 4, 10,stream);
fclose(stream);
exit(0);
}