# 《UNIX环境高级编程》第三版学习笔记笔记

## 环境配置：
- wget http://www.apuebook.com/src.3e.tar.gz
- tar -zxvf src.3e.tar
- cd apue.3e/
- make
- sudo cp ./include/apue.h /usr/include/
- sudo cp ./lib/libapue.a /usr/local/lib/


## 笔记目录：
- 01 UNIX 基础知识
	- 1.2 UNIX 体系结构
	- 1.4 文件和目录
	- 1.5 输入和输出
	- 1.6 程序和进程
	- 1.7 出错处理
	- 1.8 用户标识
	- 1.9 信号
	- 习题
- 02 UNIX 标准及实现
	- 2.2 UNIX 标准化
	- 2.3 UNIX 系统实现
	- 2.5 限制
	- 2.6 选项
	- 2.8 基本系统数据类型
- 03 文件 I/O
	- 3.1 引言
	- 3.2 文件描述符
	- 3.3 函数 `open` 和 `openat`
	- 3.4 函数 `creat`
	- 3.5 `close`
	- 3.6 函数 `lseek`
	- 3.7 函数 `read`
	- 3.8 函数 `write`
	- 3.9 I/O 的效率
	- 3.10 文件共享
	- 3.11 原子操作
	- 3.12 函数 `dup` 和 `dup2`
	- 3.13 函数 `sync`、`fsync` 和 `fdatasync`
	- 3.14 函数 `fcntl`
	- 3.15 函数 `ioctl`
	- 3.16 `/dev/fd`
	- 习题

