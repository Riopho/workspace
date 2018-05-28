#ifndef _CORE_XML_BASE64_H_
#define _CORE_XML_BASE64_H_

#include "behaviac/base/base.h"

namespace XmlBase64
{
    void BEHAVIAC_API EncodeBuff(const int8_t* inBuff, int8_t*& outBuff, int32_t nbBytes);
    void BEHAVIAC_API DecodeBuff(const int8_t* inBuff, int8_t*& outBuff);
    int32_t BEHAVIAC_API GetEncodedBuffSize(int32_t nbBytes);
};

#endif//_CORE_XML_BASE64_H_
