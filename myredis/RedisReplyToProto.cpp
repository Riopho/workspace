#include "BaseLog.h"

#include "RedisReplyToProto.h"

#define PROTO_INTEGER_TYPE(cpp_type) \
        (cpp_type == FieldDescriptor::CPPTYPE_INT32  \
                || cpp_type == FieldDescriptor::CPPTYPE_UINT32 \
                || cpp_type == FieldDescriptor::CPPTYPE_INT64 \
                || cpp_type == FieldDescriptor::CPPTYPE_UINT64)

int CRedisReplyToProto::ReplyToProto(redisReply * reply, ::google::protobuf::Message * pMessage)
{
    CHECK_IF_NULL_RET(reply, -1);
    CHECK_IF_NULL_RET(pMessage, -1);

    if (REDIS_REPLY_STRING != reply->type && REDIS_REPLY_ARRAY != reply->type && REDIS_REPLY_INTEGER != reply->type && REDIS_REPLY_NIL != reply->type)
    {
        LOG_ERR("reply type invalid. Type: %d, MessageName: %s", reply->type, pMessage->GetTypeName().c_str());
        return -1;
    }

    const ::google::protobuf::Reflection * pReflection = pMessage->GetReflection();
    CHECK_IF_NULL_RET(pReflection, -1);

    const ::google::protobuf::Descriptor * pDescriptor = pMessage->GetDescriptor();
    CHECK_IF_NULL_RET(pDescriptor, -1);

    const int iFieldCount = pDescriptor->field_count();
    for (int i = 0; i < iFieldCount; ++ i)
    {
        const google::protobuf::FieldDescriptor * pField = pDescriptor->field(i);
        CHECK_IF_NULL_RET(pField, -1);

        LOG_DBG("[Field] tag: %d, name: %s, CppType: %s", pField->number(), pField->name().c_str(), pField->cpp_type_name());
        const google::protobuf::FieldDescriptor::Label label = pField->label();
        if (label == google::protobuf::FieldDescriptor::LABEL_OPTIONAL)
        {
            LOG_ERR("don't use optional label. MessageName: %s, FieldName: %s", pMessage->GetTypeName().c_str(), pField->name().c_str());
            return -1;
        }

        const google::protobuf::FieldDescriptor::CppType cpp_type = pField->cpp_type();

        if (REDIS_REPLY_INTEGER == reply->type || REDIS_REPLY_STRING == reply->type || REDIS_REPLY_NIL == reply->type)
        {
            if (!ReplyTypeCheck(reply, pField))
            {
                LOG_ERR("reply and proto type not equal. reply.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                        , reply->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                return -1;
            }
            // message 只有一个元素，直接返回 
            return ReplyMessageOneField(reply, pReflection, pMessage, pField);
        }
        else if (REDIS_REPLY_ARRAY == reply->type)
        {
            // 返回的元素不足，返回失败 
            if (reply->elements <= i || NULL == reply->element[i])
            {
                LOG_ERR("reply array elements less message field number. field.name: %s.%s"
                        , pMessage->GetTypeName().c_str(), pField->name().c_str());
                return -1;
            }
            redisReply * element = reply->element[i];
            if (!ReplyTypeCheck(element, pField))
            {
                LOG_ERR("reply.element and proto type not equal. reply.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                        , element->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                return -1;
            }
            if (label == FieldDescriptor::LABEL_REQUIRED)
            {
                // message 有多个字段 
                if (PROTO_INTEGER_TYPE(cpp_type) || cpp_type == FieldDescriptor::CPPTYPE_STRING)
                {
                    if (0 != ReplyMessageOneField(element, pReflection, pMessage, pField))
                    {
                        return -1;
                    }
                }
                else if (cpp_type == FieldDescriptor::CPPTYPE_MESSAGE)
                {
                    // message
                    if (0 != ReplyToProto(element, pReflection->MutableMessage(pMessage, pField)))
                    {
                        LOG_ERR("reply.element array(message) set proto failed. element.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                                , element->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                        return -1;
                    }
                }
            }
            else if (label == FieldDescriptor::LABEL_REPEATED)
            {
                if (0 != ReplySetRepeated(element, pReflection, pMessage, pField))
                {
                    LOG_ERR("reply.element array(repeated) set proto failed. element.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                            , element->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                    return -1;
                }
            }
        }
        else
        {
            LOG_ERR("reply set proto unknown reply.type. reply.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                    , reply->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
            return -1;
        }
    }

    return 0;
}

// int CRedisReplyToProto::TestReplyToProto(::google::protobuf::Message * pMessage)
int CRedisReplyToProto::TestReplyToProto(const ::google::protobuf::Descriptor * pDescriptor)
{
    CHECK_IF_NULL_RET(pDescriptor, -1);

    // google::protobuf::Descriptor * pDescriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(pMessage->GetTypeName());
    // CHECK_IF_NULL_RET(pDescriptor, -1);

    const int iFieldCount = pDescriptor->field_count();
    for (int i = 0; i < iFieldCount; ++ i)
    {
        const google::protobuf::FieldDescriptor * pField = pDescriptor->field(i);
        CHECK_IF_NULL_RET(pField, -1);
        LOG_DBG("[Field] tag: %d, name: %s, CppType: %s", pField->number(), pField->name().c_str(), pField->cpp_type_name());
        const google::protobuf::FieldDescriptor::Label label = pField->label();
        if (label == google::protobuf::FieldDescriptor::LABEL_OPTIONAL)
        {
            LOG_ERR("don't use optional label");
        }

        if (pField->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
        {
            TestReplyToProto(pField->message_type());
        }
    }

    return 0;
}

int CRedisReplyToProto::ReplySetInteger(const Reflection * pReflection, Message * pMessage, const FieldDescriptor * pField, int64_t integer)
{
    CHECK_IF_NULL_RET(pReflection, -1);
    CHECK_IF_NULL_RET(pMessage, -1);
    CHECK_IF_NULL_RET(pField, -1);

    const FieldDescriptor::CppType cpp_type = pField->cpp_type();
    switch (cpp_type)
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
            pReflection->SetInt32(pMessage, pField, integer);
            break;

        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
            pReflection->SetUInt32(pMessage, pField, integer);
            break;

        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
            pReflection->SetInt64(pMessage, pField, integer);
            break;

        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
            pReflection->SetUInt64(pMessage, pField, integer);
            break;

        default:
            LOG_ERR("undefine type. MessageName: %s, CppType: %d (%s)", pMessage->GetTypeName().c_str(), cpp_type, pField->cpp_type_name());
            return -1;
    }

    return 0;
}

int CRedisReplyToProto::ReplyRepeatedAddInteger(const Reflection * pReflection, Message * pMessage, const FieldDescriptor * pField, int64_t integer)
{
    CHECK_IF_NULL_RET(pReflection, -1);
    CHECK_IF_NULL_RET(pMessage, -1);
    CHECK_IF_NULL_RET(pField, -1);

    const FieldDescriptor::CppType cpp_type = pField->cpp_type();
    switch (cpp_type)
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
            pReflection->AddInt32(pMessage, pField, integer);
            break;

        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
            pReflection->AddUInt32(pMessage, pField, integer);
            break;

        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
            pReflection->AddInt64(pMessage, pField, integer);
            break;

        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
            pReflection->AddUInt64(pMessage, pField, integer);
            break;

        default:
            LOG_ERR("undefine type. MessageName: %s, CppType: %d (%s)", pMessage->GetTypeName().c_str(), cpp_type, pField->cpp_type_name());
            return -1;
    }

    return 0;
}
bool CRedisReplyToProto::ReplyTypeCheck(redisReply * reply, const FieldDescriptor * pField)
{
    CHECK_IF_NULL_RET(reply, 0);
    CHECK_IF_NULL_RET(pField, 0);

    const google::protobuf::FieldDescriptor::CppType cpp_type = pField->cpp_type();

    if (REDIS_REPLY_INTEGER == reply->type)
    {
        return PROTO_INTEGER_TYPE(cpp_type);
    }

    if (REDIS_REPLY_STRING == reply->type || REDIS_REPLY_NIL == reply->type)
    {
        return (PROTO_INTEGER_TYPE(cpp_type) || cpp_type == FieldDescriptor::CPPTYPE_STRING);
    }

    if (REDIS_REPLY_ARRAY == reply->type)
    {
        return (cpp_type == FieldDescriptor::CPPTYPE_MESSAGE || pField->label() == FieldDescriptor::LABEL_REPEATED);
    }

    return true;
}

int CRedisReplyToProto::ReplyMessageOneField(redisReply * reply, const Reflection * pReflection, Message * pMessage, const FieldDescriptor * pField)
{
    if (NULL == reply || NULL == pReflection || NULL == pMessage || NULL == pField)
    {
        return -1;
    }

    const google::protobuf::FieldDescriptor::CppType cpp_type = pField->cpp_type();
    if (REDIS_REPLY_INTEGER == reply->type)
    {
        if (0 != ReplySetInteger(pReflection, pMessage, pField, reply->integer))
        {
            LOG_ERR("reply set proto integer failed. reply.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                    , reply->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
            return -1;
        }
    }
    else if (REDIS_REPLY_STRING == reply->type || REDIS_REPLY_NIL == reply->type)
    {
        if (cpp_type == FieldDescriptor::CPPTYPE_STRING)
        {
            const std::string str = (REDIS_REPLY_STRING == reply->type)? std::string(reply->str, reply->len): "";
            pReflection->SetString(pMessage, pField, str);
        }
        else if (PROTO_INTEGER_TYPE(cpp_type))
        {
            const std::string str = (REDIS_REPLY_STRING == reply->type)? std::string(reply->str, reply->len): "0";
            if (0 != ReplySetInteger(pReflection, pMessage, pField, strtoll(str.c_str(), NULL, 10)))
            {
                LOG_ERR("reply set proto integer failed. reply.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                        , reply->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                return -1;
            }
        }
        else 
        {
            LOG_ERR("reply string set proto failed. reply.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                    , reply->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
            return -1;
        }
    }

    return 0;
}

int CRedisReplyToProto::ReplySetRepeated(redisReply * reply, const Reflection * pReflection, Message * pMessage, const FieldDescriptor * pField)
{
    if (NULL == reply || NULL == pReflection || NULL == pMessage || NULL == pField)
    {
        return -1;
    }

    if (REDIS_REPLY_ARRAY != reply->type)
    {
        LOG_ERR("proto is repeated label, but redis not array. field.name: %s.%s", pMessage->GetTypeName().c_str(), pField->name().c_str());
        return -1;
    }

    const google::protobuf::FieldDescriptor::CppType cpp_type = pField->cpp_type();

    for (int k = 0; k < reply->elements; ++ k)
    {
        redisReply * element = reply->element[k];
        CHECK_IF_NULL_RET(element, -1);

        if (!ReplyTypeCheck(element, pField))
        {
            LOG_ERR("reply.element and proto type not equal. element.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                    , element->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
            return -1;
        }

        if (REDIS_REPLY_INTEGER == element->type)
        {
            if (0 != ReplyRepeatedAddInteger(pReflection, pMessage, pField, element->integer))
            {
                LOG_ERR("reply.element set proto integer failed. element.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                        , element->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                return -1;
            }
        }
        else if (REDIS_REPLY_STRING == element->type || REDIS_REPLY_NIL == element->type)
        {
            if (cpp_type == FieldDescriptor::CPPTYPE_STRING)
            {
                const std::string str = (REDIS_REPLY_STRING == element->type)? std::string(element->str, element->len): "";
                pReflection->AddString(pMessage, pField, str);
            }
            else if (PROTO_INTEGER_TYPE(cpp_type))
            {
                const std::string str = (REDIS_REPLY_STRING == element->type)? std::string(element->str, element->len): "0";
                ReplyRepeatedAddInteger(pReflection, pMessage, pField, strtoll(str.c_str(), NULL, 10));
            }
            else 
            {
                LOG_ERR("reply.element string set proto failed. element.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                        , element->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                return -1;
            }
        }
        else if (REDIS_REPLY_ARRAY == element->type)
        {
            if (cpp_type != FieldDescriptor::CPPTYPE_MESSAGE)
            {
                LOG_ERR("unknown repeated type. field.cpp_type: %d(%s), field.name: %s.%s"
                        , cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                return -1;
            }

            // repeated 里只会嵌套基本字段和message, 这里如果 reply 还是 array 则一定是 message
            if (0 != ReplyToProto(element, pReflection->AddMessage(pMessage, pField)))
            {
                LOG_ERR("reply.element array set proto failed. element.type: %d, field.cpp_type: %d(%s), field.name: %s.%s"
                        , element->type, cpp_type, pField->cpp_type_name(), pMessage->GetTypeName().c_str(), pField->name().c_str());
                return -1;
            }
        }
    }

    return 0;
}

