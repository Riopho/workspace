






#ifndef _BEHAVIAC_BASE_META_PUSHFRONT_H__INCLUDED
#define _BEHAVIAC_BASE_META_PUSHFRONT_H__INCLUDED

#include "behaviac/base/meta/collection.h"

namespace behaviac
{
    namespace Meta
    {
        template< typename T, typename CollectionType >
        struct PushFront
        {
            typedef Collection< Sequence< T, typename CollectionType::Type > > Result;
        };

        template< typename CollectionType >
        struct PushFront< Null, CollectionType >
        {
            typedef CollectionType Result;
        };
    }
}

#endif
