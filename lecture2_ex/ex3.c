//获取本地时间，以字符串方式显示出来

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    time_t data;
    data=time(NULL);// obtian calendar time, seconds count
    char *return_string=ctime(&data);
    printf("Current time = %s", return_string);

}