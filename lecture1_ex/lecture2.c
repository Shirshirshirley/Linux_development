 
 
 文件编程

 method：
    1.Linux系统调用
        创建：
            int creat(const char* filename, mode_t mode)//filename：要创建的文件名，包含路径，缺失为当前路径
                                                        //mode:文件属性 s_irusr可读/s_iwusr可写 etc...
                                                        //可执行=1， 可写=2，可读=4， 权限和=sum各权限；
            creat(filename,0755);
            //第一个数字：文件所有者， 第二个数字：所有者所在的组；第三个数字：其他用户；
        描述：
        所有打开的文件都对应一个文件描述符（本质是一个非负数）；
        打开：
            int open(char* pathname,int flag, mode_t mode) //只读，只写，读写，追加方式，创建（所指定文件不存在时，则创建），非阻塞
        读：
            int read(int fd, const void*buf, size_t length)
                //读取length个字节到buf所指向的缓冲区。 返回值为实际读取的字节数。
        写：
            int write(int fd, const void *buf, size_t, length)
                //
        定位：
            int lseek(int fd, offset_t offset, int whence)
            //将文件读写指针相对whence移动offset个字节，操作成功时， 返回文件指针相对于文件头的位置。
            //whence可以使用一下值：
            /* seek_set: 相对文件头， 
                seek_cur:相对于当前位置
                seek_end:相对于文件末尾*/
            ？？如何利用lseek来计算文件长度：
                lseek(fd, 0, SEEK_END) return值应该为末尾相对于文件头的偏移。
        访问判断：
            int access(const char* pathname. int mode)
            //判断文件的访问权限。
            eg： if(access("/etc/passwd",R_OK)==0)

comprehensive example:




    2.C语言库函数

时间编程