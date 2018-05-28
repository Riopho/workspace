#ifndef _BEHAVIAC_BASE_TRAITS_ISSTRUCT_H__INCLUDED
#define _BEHAVIAC_BASE_TRAITS_ISSTRUCT_H__INCLUDED

#include "behaviac/base/meta/isclass.h"

namespace behaviac
{
    namespace Meta
    {
        // Result is true only if the provided type is a struct
        //
        // struct MyStruct { Bleh };
        //
        // IsStruct< MyStruct >::Result == true
        // IsStruct< int >::Result == false
        //
        template< typename T >
        static No CheckIfAbstract(T(*)[1]);

        template< typename T >
        static Yes CheckIfAbstract(...);

        template< typename T >
        struct IsStruct
        {
            enum
            {
                Result = IsClass< T >::Result &&
                         sizeof(CheckIfAbstract< T >(0)) == sizeof(No)
            };
        };
    }
}

#endif
