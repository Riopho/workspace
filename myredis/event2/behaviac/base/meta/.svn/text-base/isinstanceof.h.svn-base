






#ifndef _BEHAVIAC_BASE_TRAITS_ISINSTANCEOF_H__INCLUDED
#define _BEHAVIAC_BASE_TRAITS_ISINSTANCEOF_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< typename BaseType, typename DerivedType >
            struct IsInstanceOfImpl;
        }


        // Answer is true if DerivedType derived from BaseType or is the same than
        // BaseType
        //
        // class A {};
        // class B : public A {};
        // class C {};
        //
        // IsIntanceOf< A, B >::Answer == true
        // IsInstanceOf< A, A >::Answer == true
        // IsInstanceOf< A, C >::Answer == false
        //

        template< typename BaseType, typename DerivedType >
        struct IsInstanceOf
        {
            enum
            {
                Result = Details::IsInstanceOfImpl< const BaseType*, const DerivedType* >::Result
            };
        };
    }
}

#include "behaviac/base/meta/isinstanceof.hpp"

#endif
