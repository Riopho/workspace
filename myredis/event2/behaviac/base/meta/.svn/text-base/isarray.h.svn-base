#ifndef _BEHAVIAC_BASE_META_ISARRAY_H__INCLUDED
#define _BEHAVIAC_BASE_META_ISARRAY_H__INCLUDED

#include "behaviac/base/meta/meta.h"

namespace behaviac
{
    namespace Meta
    {
        // Answer is true if the provided Type is an Array
        //
        // typedef int IntArray[10];
        //
        // IsPtr< IntArray >::Answer == true
        // IsPtr< int >::Answer == false
        //

        template< typename Type >
        struct IsArray
        {
            enum { Result = 0 };
        };

        template< typename Type, int32_t Count >
        struct IsArray< Type[Count] >
        {
            enum { Result = 1 };
        };

        template< typename Type >
        struct IsArray< Type[] >
        {
            enum { Result = 1 };
        };

    }
}

#endif//_BEHAVIAC_BASE_META_ISARRAY_H__INCLUDED
