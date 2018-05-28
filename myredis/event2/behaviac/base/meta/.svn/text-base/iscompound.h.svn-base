#ifndef _BEHAVIAC_BASE_TRAITS_ISCOMPOUND_H__INCLUDED
#define _BEHAVIAC_BASE_TRAITS_ISCOMPOUND_H__INCLUDED

#include "behaviac/base/meta/isptr.h"
#include "behaviac/base/meta/isref.h"
#include "behaviac/base/meta/isarray.h"

namespace behaviac
{
    namespace Meta
    {
        // Answer is true if the provided Type is a pointer or a reference or an array
        //
        //
        //

        template< typename Type >
        struct IsCompound
        {
            enum
            {
                Result =    IsPtr< Type >::Result ||
                            IsRef< Type >::Result ||
                            IsArray< Type >::Result
            };
        };
    }
}

#endif
