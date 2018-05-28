#ifndef _BEHAVIAC_BASE_META_REFTYPE_H__INCLUDED
#define _BEHAVIAC_BASE_META_REFTYPE_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        template< typename T >
        struct RefType
        {
            typedef T& Result;
        };

        template< typename T >
        struct RefType< T& >
        {
            typedef T& Result;
        };

        template< typename T >
        struct RefType< const T& >
        {
            typedef const T& Result;
        };

    }
}

#endif//_BEHAVIAC_BASE_META_REFTYPE_H__INCLUDED
