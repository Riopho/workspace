#ifndef _BEHAVIAC_BASE_TRAITS_ISENUM_H__INCLUDED
#define _BEHAVIAC_BASE_TRAITS_ISENUM_H__INCLUDED

#include "behaviac/base/meta/isclass.h"
#include "behaviac/base/meta/isfundamental.h"
#include "behaviac/base/meta/isfunction.h"
#include "behaviac/base/meta/iscompound.h"

namespace behaviac
{
    namespace Meta
    {

        // Result is true only if the provided type is an Enum
        //
        // enum MyEnum { Bleh };
        //
        // IsEnum< MyEnum >::Result == true
        // IsEnum< int >::Result == false
        //
        template< typename Type >
        struct IsEnum
        {
            enum
            {
                Result =    !IsFundamental< Type >::Result &&
                            !IsClass< Type >::Result &&
                            !IsFunction< Type >::Result &&
                            !IsCompound< Type >::Result
            };
        };
    }
}

#endif
