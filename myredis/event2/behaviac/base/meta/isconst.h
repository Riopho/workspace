






#ifndef _BEHAVIAC_BASE_META_ISCONST_H__INCLUDED
#define _BEHAVIAC_BASE_META_ISCONST_H__INCLUDED

#include "behaviac/base/meta/meta.h"

namespace behaviac
{
    namespace Meta
    {
        // Answer is true only if the provided Type is const
        //
        // typedef const int ConstInt
        //
        // IsConst< ConstInt >::Answer == true
        // IsConst< int >::Answer == false
        //

        template< typename T >
        struct IsConst
        {
            enum
            {
                Result = 0
            };
        };

        template< typename T >
        struct IsConst< const T >
        {
            enum { Result = 1 };
        };

        template< typename T >
        struct IsConst< const T& >
        {
            enum { Result = 1 };
        };

        template< typename T >
        struct IsConst< const T* >
        {
            enum { Result = 1 };
        };

    }
}

#endif
