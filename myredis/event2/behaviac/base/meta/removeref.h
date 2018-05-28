#ifndef _BEHAVIAC_BASE_META_REMOVEREF_H__INCLUDED
#define _BEHAVIAC_BASE_META_REMOVEREF_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        template< typename T >
        struct RemoveRef
        {
            typedef T Result;
        };

        template< typename T >
        struct RemoveRef< T& >
        {
            typedef T Result;
        };
    }
}

#endif
