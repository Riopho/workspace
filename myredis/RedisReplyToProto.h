/*******************************************************************************
 * Author :          X.Q Chen
 * Email :           465276914@qq.com
 * Last modified :   2018-02-24 18:07
 * Filename :        RedisReplyToProto.h
 * Description :     
 * *****************************************************************************/
#ifndef _REDIS_REPLY_TO_PROTO_H_
#define _REDIS_REPLY_TO_PROTO_H_

#include "hiredis.h"

#include "google/protobuf/descriptor.h"
#include "google/protobuf/message.h"

using namespace google::protobuf;

class CRedisReplyToProto
{
    public :
        // @NOTE 还不能支持一个数字的返回值，返回值
        static int ReplyToProto(redisReply * reply, Message * pMessage);
        
        // static int TestReplyToProto(::google::protobuf::Message * pMessage);
        static int TestReplyToProto(const Descriptor * pDescriptor);

    private :
        static int ReplyMessageOneField(redisReply * reply, const Reflection * pReflection, Message * pMessage, const FieldDescriptor * pField);

        static int ReplySetInteger(const Reflection * pReflection, Message * pMessage, const FieldDescriptor * pField, int64_t integer);

        static int ReplySetRepeated(redisReply * reply, const Reflection * pReflection, Message * pMessage, const FieldDescriptor * pField);

        static int ReplyRepeatedAddInteger(const Reflection * pReflection, Message * pMessage, const FieldDescriptor * pField, int64_t integer);

        static bool ReplyTypeCheck(redisReply * reply, const FieldDescriptor * pField);
};

#endif

