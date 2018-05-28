#include <iostream>
using namespace std;

extern "C"
{
    #include "string.h"
    #include "stdio.h"
    #include "stdlib.h"
    #include "signal.h"
    #include "hiredis.h" 
    #include "libevent.h"
    #include "async.h"
}

//连接回调函数
void ConnCallBack(const redisAsyncContext *conn,int state)
{
    if(state != REDIS_OK)
    {
        cout << "Connect fail:" << conn->err << endl;
        return;
    }
    
    cout << "Connected success" << endl;
}


//断开连接回调函数
void DisConnCallBack(const redisAsyncContext *conn,int state)
{
    if(state != REDIS_OK)
    {
        cout << "Disconnect fail:" << conn->err << endl;
        return;
    }
    cout << "Disconnect success." << endl;
}


//Get的回调函数
void CallBackFunc(redisAsyncContext *conn,void *r,void *privdata)
{
    redisReply* reply = (redisReply*)r ;
    if(reply == NULL)
    {
        return;
    }
    cout  << "param: " << (char *)privdata << " = " << reply->integer << endl;
    redisAsyncDisconnect(conn);
}


//argc:参数的个数，*argv[]/**argv：指针数组，第一个元素是程序名称
int main(int argc,char *argv[])
{   
    signal(SIGPIPE,SIG_IGN);
    struct event_base *base = event_base_new();     //新建一个libevent事件处理实例

    
    //创建异步连接
    redisAsyncContext *conn = redisAsyncConnect("127.0.0.1",6801);

    if(conn->err){
        cout << "Connection error:" << conn->err << endl;
        return 1;
    }   

    redisLibeventAttach(conn,base);                 //将连接添加到libevent事件处理

    //注册连接回调函数
    redisAsyncSetConnectCallback(conn,ConnCallBack);
    
    //注册链接断开回调函数
    redisAsyncSetDisconnectCallback(conn,DisConnCallBack);

    //发送set命令  （conn,回调函数，privdata参数,format....）
    redisAsyncCommand(conn,NULL,NULL,"SET name 1111");
    
    //发送get命令
    char param[] = "name";
    redisAsyncCommand(conn,CallBackFunc,param,"GET name");
    //redisAsyncCommand(conn,CallBackFunc,(char *)"ping","ping);
    //redisAsyncCommand(conn,CallBackFunc,(char *)"name","GET name");
        
    //开始libevent循环，在此之前redis是不会进行连接的。
    event_base_dispatch(base);

    return 0;
}

