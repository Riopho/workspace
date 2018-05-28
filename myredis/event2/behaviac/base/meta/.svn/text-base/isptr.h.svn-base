#ifndef _BEHAVIAC_BASE_META_ISPTR_H__INCLUDED
#define _BEHAVIAC_BASE_META_ISPTR_H__INCLUDED

#include "behaviac/base/meta/meta.h"

namespace behaviac
{
    namespace Meta
    {
        // Answer is true if the provided Type is a pointer
        //
        // typedef int * IntPtr;
        //
        // IsPtr< IntPtr >::Answer == true
        // IsPtr< int >::Answer == false
        //

        template< typename Type >
        struct IsPtr
        {
            enum { Result = 0 };
        };

        template< typename Type >
        struct IsPtr< Type* >
        {
            enum { Result = 1 };
        };


        template< typename Type >
        struct IsPtr< const Type* >
        {
            enum { Result = 1 };
        };

		template< typename Type >
		struct IsPtr < Type*& >
		{
			enum { Result = 1 };
		};

		template< typename Type >
		struct IsPtr < const Type*& >
		{
			enum { Result = 1 };
		};

    }
}

#endif//_BEHAVIAC_BASE_META_ISPTR_H__INCLUDED
