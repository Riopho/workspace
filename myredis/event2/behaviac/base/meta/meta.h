



#ifndef _BEHAVIAC_BASE_META_META_H__INCLUDED
#define _BEHAVIAC_BASE_META_META_H__INCLUDED

#include "behaviac/base/base.h"
#include "behaviac/base/core/assert_t.h"
#include "behaviac/base/core/staticassert.h"

namespace behaviac
{
    // Meta programming and Traits tools

    namespace Meta
    {
        // Empty Class tag
        struct Empty
        {
            typedef Empty Type;
        };

        // Null Class behaviac
        struct Null
        {
            typedef Null Type;
        };

        template< typename T = Null >
        struct Identity
        {
            typedef T Type;
        };

        typedef uint8_t Yes;
        typedef struct
        {
            uint8_t padding[2];
        } No;

		struct TrueType
		{
			enum { Result = true };
		};

		struct FalseType
		{
			enum { Result = false };
		};

		template <bool val>
		struct BooleanType : public FalseType 
		{};

		template <>
		struct BooleanType<true> : public TrueType 
		{};


    }
}

#endif
