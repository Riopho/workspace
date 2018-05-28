#ifndef _BEHAVIAC_EXT_TYPES_H_
#define _BEHAVIAC_EXT_TYPES_H_

//inlcude the following headers in your type extension files
#include "behaviac/base/dynamictype.h"
#include "behaviac/base/object/typehandler.h"
#include "behaviac/base/string/valuefromstring.h"
#include "behaviac/base/string/valuetostring.h"

#include "behaviac/base/meta/meta.h"
#include "behaviac/base/meta/isenum.h"

#include "behaviac/base/core/types.h"
#include "behaviac/base/dynamictype.h"

#include "behaviac/base/object/tagobject.h"
#include "behaviac/agent/agent.h"
#include "behaviac/base/object/member.h"
#include "behaviac/base/object/uitype.h"
#include "behaviac/property/method.h"
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//we declare a type "Float2" to simulate a type defined in a thirdparty lib
namespace TestNS
{
	struct Float2
	{
		float x;
		float y;
	};
}

#undef M_SPECIALIZE_TYPE_HANDLER_COMPOUND

#define M_SPECIALIZE_TYPE_HANDLER_COMPOUND()             \
	M_SPECIALIZE_TYPE_HANDLER(TestNS::Float2);				

M_SPECIALIZE_TYPE_HANDLER_COMPOUND()	

//
struct myFloat2
{
    float x;
    float y;

    DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL(myFloat2);

    myFloat2()
	{}

	myFloat2(const TestNS::Float2& v) : x(v.x), y(v.y)
	{
	}
};

template <>
inline CTagObjectDescriptor& GetObjectDescriptor<TestNS::Float2>()					     
{																		 
	return myFloat2::GetObjectDescriptor();								     
}																		 

template <>
inline void RegisterProperties<TestNS::Float2>()                                         
{                                                                         
	myFloat2::RegisterProperties();
}

//add the following to a cpp
//BEGIN_PROPERTIES_DESCRIPTION(myFloat2)
//	CLASS_DISPLAYNAME(L"")
//	CLASS_DESC(L"")
//
//	REGISTER_PROPERTY(x);
//	REGISTER_PROPERTY(y);
//END_PROPERTIES_DESCRIPTION()

namespace behaviac
{
// ValueToString & ValueFromString
namespace StringUtils
{
	namespace Private
	{
		template<>
        inline behaviac::string ToString(const TestNS::Float2& val)
        {
            //myFloat2::ToString is defined by DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL(myFloat2)
			myFloat2 temp(val);
			return temp.ToString();
        }
        
		template<>
		inline bool FromString(const char* str, TestNS::Float2& val)
		{
            myFloat2 temp;

            //myFloat2::FromString is defined by DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL(myFloat2)
            if (temp.FromString(str))
			{
				val.x = temp.x;
				val.y = temp.y;
                return true;
			}
            return false;
		}
	}
}
}

// SwapByteTempl helpers
template< typename SWAPPER >
inline void SwapByteTempl(TestNS::Float2& v)
{
    SwapByteTempl< SWAPPER >(v.x);
    SwapByteTempl< SWAPPER >(v.y);
}


//operators
namespace behaviac
{
	namespace Details
    {
		//------------------------------------------------------------------------
        template<>
		inline bool Equal(const TestNS::Float2& lhs, const TestNS::Float2& rhs)
        {
            return behaviac::IsEqualWithEpsilon(lhs.x, rhs.x) && behaviac::IsEqualWithEpsilon(lhs.y, rhs.y);
        }
	}
}


#endif//_BEHAVIAC_EXT_TYPES_H_
