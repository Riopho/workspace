






#ifndef _BEHAVIAC_BASE_META_ISREF_H__INCLUDED
#define _BEHAVIAC_BASE_META_ISREF_H__INCLUDED

#include "behaviac/base/meta/meta.h"

namespace behaviac
{
    namespace Meta
    {
        // Answer is true if the provided Type is a reference
        //
        // typedef int & IntRef;
        //
        // IsPtr< IntRef >::Answer == true
        // IsPtr< int >::Answer == false
        //

        template< typename Type >
        struct IsRef
        {
            enum { Result = 0 };
        };

        template< typename Type >
        struct IsRef< Type& >
        {
            enum { Result = 1 };
        };


        template< typename Type >
        struct IsRef< const Type& >
        {
            enum { Result = 1 };
        };
    }
}

#endif//_BEHAVIAC_BASE_META_ISREF_H__INCLUDED
