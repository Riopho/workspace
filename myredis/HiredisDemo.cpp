#include <iostream>
using namespace std;

#include "hiredis.h"
#include "stdio.h"


//void commonSet(redisContext* conn,redisReply* reply,string& key,string& value)
//{
  //  reply = (redisReply*)redisCommand(conn,"Set %s %s",key,value);
   // cout << "Set:" << key << reply->str << endl;
    //freeReplyObject(reply);
//}


int main()
{
    cout << "Hello hiredis" << endl;

    redisContext *conn = NULL;
    redisReply *reply = NULL;
    
    conn = redisConnect("127.0.0.1",6379);
    if(conn == NULL || conn->err){
        if(conn){
            cout << "connection error: " << conn->err << endl;
            redisFree(conn);
        }else{
            cout << "Connection error: cant't allocate redis context" << endl;    
        }
        return 1;
    }


    reply = (redisReply*)redisCommand(conn,"PING");
    cout << "ping:" << reply->str << endl;
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(conn,"set %s %s","name","danni");
    cout << "Set name:" << reply->str << endl;
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(conn,"GET name");
    cout << "Get name:" << reply->str << endl;
    freeReplyObject(reply);

    string s1 = "age";
    string s2 = "23";
//    commonSet(&coon,&reply,&s1,&s2);

    redisFree(conn);
    return 0;
}

