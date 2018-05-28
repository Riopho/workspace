#ifndef _BEHAVIAC_BASE_META_REMOVEPTR_H__INCLUDED
#define _BEHAVIAC_BASE_META_REMOVEPTR_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        template< typename T >
        struct RemovePtr
        {
            typedef T Result;
        };

        template< typename T >
        struct RemovePtr< T* >
        {
            typedef T Result;
        };

        template <typename T>
        struct RemovePtr<T* const>
        {
            typedef T Result;
        };

        template <typename T>
        struct RemovePtr<T* volatile>
        {
            typedef T Result;
        };

        template <typename T>
        struct RemovePtr<T* const volatile>
        {
            typedef T Result;
        };
    }
}

#endif
