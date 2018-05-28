






#ifndef _BEHAVIAC_BASE_META_REMOVECONST_H__INCLUDED
#define _BEHAVIAC_BASE_META_REMOVECONST_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        template< typename T >
        struct RemoveConst
        {
            typedef T Result;
        };

        template< typename T >
        struct RemoveConst< const T >
        {
            typedef T Result;
        };

        template< typename T >
        struct RemoveConst< const T* >
        {
            typedef T* Result;
        };

        template< typename T >
        struct RemoveConst< const T& >
        {
            typedef T& Result;
        };


        template <typename T>
        struct RemoveConst<volatile T>
        {
            typedef volatile typename RemoveConst<T>::Result Result;
        };

        template <typename T>
        struct RemoveConst<volatile const T>
        {
            typedef volatile typename RemoveConst<T>::Result Result;
        };

        template <typename T>
        struct RemoveConst<T&>
        {
            typedef typename RemoveConst<T>::Result& Result;
        };

        template <typename T>
        struct RemoveConst<T*>
        {
            typedef typename RemoveConst<T>::Result* Result;
        };

        template <typename T>
        struct RemoveConst<T* const>
        {
            typedef typename RemoveConst<T>::Result* Result;
        };

        template <typename T>
        struct RemoveConst<T* volatile const>
        {
            typedef typename RemoveConst<T>::Result* volatile Result;
        };

    }
}

#endif
