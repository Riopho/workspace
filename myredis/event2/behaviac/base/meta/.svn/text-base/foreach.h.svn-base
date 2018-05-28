






#ifndef _BEHAVIAC_BASE_META_FOREACH_H__INCLUDED
#define _BEHAVIAC_BASE_META_FOREACH_H__INCLUDED

#include "behaviac/base/meta/meta.h"
#include "behaviac/base/meta/foreach.hpp"

namespace behaviac
{
    namespace Meta
    {
        template< typename CollectionType, template< typename > class Wrapper, typename Functor >
        Functor ForEach(Functor functor);

        template< typename CollectionType, typename Functor >
        Functor ForEach(Functor functor)
        {
            return ForEach< CollectionType, Identity, Functor >(functor);
        }
    }
}

#endif
