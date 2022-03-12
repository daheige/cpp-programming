# cpp-programming
    c++编程学习
    参考的书籍《c++程序设计第4版》《c++高级编程第3版本》

# c++选择的版本
    c++11或c++17

# c++编译运行步骤
    4个步骤：预处理--->编译--->汇编--->链接（形成可执行文件）

    预处理：
    g++ -o hello.ii -E hello.cpp

    编译：将预处理文件转化为汇编文件
    g++ -o hello.s -S hello.ii

    汇编：形成目标文件
    g++ -o hello.o -c hello.s

    链接： 把函数库导入进来，生成可执行文件
    g++ -o helloworld hello.o

    执行：
    % ./helloworld
    hello,world
    a,b,c
    1
    12
    1.23

    汇总起来就是一个命令 -o 的参数是目标可执行文件的名字
    g++ -o helloworld hello.cpp

# gcc 指定c++使用的版本

    vim ~/.bashrc 添加如下内容，别名设置
    alias gc11="gcc -lstdc++ -std=c++11"
    alias gc17="gcc -lstdc++ -std=c++17"
    alias g11="g++ -std=c++11"
    alias g17="g++ -std=c++17"
    使它生效运行如下命令
    source ~/.bashrc

# 编译c++程序

    g11 -o hello.out hello.cpp

# 运行

    ./hello.out

# c++跨平台

    同一份代码可以在不同的操作系统上成功编译并运行
    本质上源代码可以在不同的os上进行编译形成二进制文件，每个系统生成出来的二进制文件，并可以运行
