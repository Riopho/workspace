#ifndef _CORE_SWAPBYTEBASE_H_
#define _CORE_SWAPBYTEBASE_H_
#include "behaviac/base/base.h"
#include "behaviac/base/core/container/string_t.h"
#include "behaviac/base/core/container/vector_t.h"
#include "behaviac/base/core/container/list_t.h"
#include "behaviac/base/core/container/map_t.h"
#include "behaviac/base/core/container/set_t.h"

#include "behaviac/base/string/pathid.h"
#include "behaviac/base/core/string/stringid.h"

#include "swapbyte.h"

//////////////////////////////////////////////////////////////////////////
// SwapByteTempl helpers


template< typename SWAPPER >
inline void SwapByteTempl(const char*& s)
{
	BEHAVIAC_UNUSED_VAR(s);
}


template< typename SWAPPER >
inline void SwapByteTempl(behaviac::string& s)
{
	BEHAVIAC_UNUSED_VAR(s);
}

template<typename SWAPPER>
inline void SwapByteTempl(CStringID& value)
{
#if STRINGID_USESTRINGCONTENT
	const char* s = value.c_str();
	value.SetContent(s);
#else
	CStringID::IDType id  = value.GetUniqueID();
	SwapByte(id);

	value.SetUniqueID(id);
#endif//#if STRINGID_USESTRINGCONTENT
}


template<typename SWAPPER>
inline void SwapByteTempl(CPathID& value)
{
#if STRINGID_USESTRINGCONTENT
	const char* s = value.c_str();
	value.SetContent(s);
#else
	CPathID::IDType id  = value.GetUniqueID();
	SwapByte(id);

	value = CPathID(id);
#endif//#if STRINGID_USESTRINGCONTENT
}

//////////////////////////////////////////////////////////////////////////
template<typename SWAPPER, typename T>
inline void SwapByteTempl(behaviac::vector<T>& value)
{
    for (unsigned int i = 0; i < value.size(); ++i)
    {
        SwapByteTempl< SWAPPER >(value[i]);
    }
}

template<typename SWAPPER>
inline void SwapByteTempl(behaviac::vector<bool>& value)
{
	BEHAVIAC_UNUSED_VAR(value);
}


#endif // #ifndef _CORE_SWAPBYTEBASE_H_

