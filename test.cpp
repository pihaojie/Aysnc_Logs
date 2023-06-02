#include "log_level/log1.h" 
#include <time.h>
void TestLog() 
{
    int cnt = 0;
    clock_t start,finish;
    start=clock();
    Log::Instance()->init(0,"./testlog1",".log",0);//同步日志
    for(int j = 0; j < 15000; j++ )
    {
        LOG_DEBUG("%s 111111111 %d ============= ", "Test", cnt++);
        LOG_INFO ("%s 111111111 %d ============= ", "Test", cnt++);
        LOG_WARN ("%s 111111111 %d ============= ", "Test", cnt++);
        LOG_ERROR("%s 111111111 %d ============= ", "Test", cnt++);
    }
    finish=clock();
    cout<<"同步时间为："<<finish-start<<endl;

    cnt = 0;
    start=clock();
    Log::Instance()->init(0,"./testlog2",".log",1000);//异步日志
    for(int j = 0; j < 15000; j++ )
    {
        LOG_DEBUG("%s 222222222 %d ============= ", "Test", cnt++);
        LOG_INFO ("%s 222222222 %d ============= ", "Test", cnt++);
        LOG_WARN ("%s 222222222 %d ============= ", "Test", cnt++);
        LOG_ERROR("%s 222222222 %d ============= ", "Test", cnt++);
    }
    finish=clock();
    cout<<"异步时间为："<<finish-start<<endl;
}
 
int main() 
{
    TestLog();
}