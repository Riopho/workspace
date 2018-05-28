#ifndef _BASE_CRC_H_
#define _BASE_CRC_H_

#include "behaviac/base/core/config.h"

namespace CRC32
{
    BEHAVIAC_API  uint32_t CalcCRC(const char* str);
	BEHAVIAC_API  uint32_t CalcCRCNoCase(const char* str);
}

#endif // #ifndef _BASE_CRC_H_
