同步/异步线程池

运行方式：
1：CMakeLists.txt在主目录下已写好，运行的Makefile在build文件夹下，可执行文件为Log_level,若更改文件，可以在build目录下使用make命令重新生成可执行文件。
2：在主目录下，使用g++ test.cpp log_level/log1.cpp buffer/buffer.cpp -o log -lpthread生成可执行文件

文件说明：
1：test.cpp,对日志系统进行测试，分异步和同步测试，并分别记录运行的时间，队列大小为0的时候是同步日志，大于0为异步日志，异步测试时的队列大小设为1024(可更改)
2：log.cpp,日志初始化、写入等相关操作的文件
3：blockqueue.h,队列的文件，异步时所用到的，将任务放于队列中
4：buffer.cpp,建立的缓冲区

运行流程：
1：使用单例模式（局部静态变量方法）获取实例Log::Instance()。
2：通过实例调用Log::Instance()->init()函数完成初始化，若设置阻塞队列大小大于0则选择异步日志，等于0则选择同步日志，更新isAysnc变量。
3：通过实例调用write()函数写日志，首先根据当前时刻创建日志（前缀为时间，后缀为".log"，并更新日期today和当前行数lineCount。
4：在write()函数内部，通过isAsync变量判断写日志的方法：如果是异步，工作线程将要写的内容放进阻塞队列中，由写线程在阻塞队列中取出数据，然后写入日志；如果是同步，直接写入日志文件中。

分级情况：
1：Debug，调试代码时的输出，在系统实际运行时，一般不使用。
2：Warn，这种警告与调试时终端的warning类似，同样是调试代码时使用。
3：Info，报告系统当前的状态，当前执行的流程或接收的信息等。
4：Erro，输出系统的错误信息

分文件情况：
1：按天分，日志写入前会判断当前today是否为创建日志的时间，若为创建日志时间，则写入日志，否则按当前时间创建新的log文件，更新创建时间和行数。
2：按行分，日志写入前会判断行数是否超过最大行限制，若超过，则在当前日志的末尾加lineCount / MAX_LOG_LINES为后缀创建新的log文件。