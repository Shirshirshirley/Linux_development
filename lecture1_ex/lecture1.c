-static:静态连接库文件， 讲所需库文件拷贝与源文件放在一起形成可执行文件，因此较大
eg： gcc -static hello.o -o hello

-Wall：生成所有警告信息
-w：不生成任何警告信息

-D：define macro；

GDB 调试：

-- compile 时使用 
        -g suffix
-- 启动GDB： 
        gdb file
-- 在main函数处设置断点：break main
        b main
-- 运行：
        run;
-- 继续逐条执行：
        next;（跳过函数，在函数外的下一条执行）；
        s；（会进入函数内继续执行）
-- 继续执行直到完成：
        continue；
-- 查看文件内容：
        list；
-- set break point：
    b （functionname）；
    b  （line number）；
    b （filename）：（line nunmber）；
    b （linenumber）if（condition）；