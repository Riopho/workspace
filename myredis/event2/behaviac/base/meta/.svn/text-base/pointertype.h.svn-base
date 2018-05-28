#ifndef _BEHAVIAC_BASE_META_POINTERTYPE_H__INCLUDED
#define _BEHAVIAC_BASE_META_POINTERTYPE_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        template< typename T >
        struct PointerType
        {
            typedef T* Result;
        };

        template< typename T >
        struct PointerType< T& >
        {
            typedef T* Result;
        };

        template< typename T >
        struct PointerType< const T& >
        {
            typedef const T* Result;
        };

        //template< typename T >
        //struct PointerType< T* >
        //{
        //    typedef T* Result;
        //};

        //template< typename T >
        //struct PointerType< const T* >
        //{
        //    typedef const T* Result;
        //};

    }
}

#endif//_BEHAVIAC_BASE_META_POINTERTYPE_H__INCLUDED
