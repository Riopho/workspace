






#ifndef _BEHAVIAC_BASE_META_SIZE_H__INCLUDED
#define _BEHAVIAC_BASE_META_SIZE_H__INCLUDED

#include "behaviac/base/meta/collection.h"
#include "behaviac/base/meta/size.hpp"

namespace behaviac
{
    namespace Meta
    {
        template< typename CollectionType >
        struct Size
        {
            typedef typename CollectionType::Type SequenceType;

            enum
            {
                Result = Details::SizeImpl< typename SequenceType::Head, typename SequenceType::Tail >::Result
            };
        };

        template<>
        struct Size< Meta::Null >
        {
            enum
            {
                Result = 0
            };
        };

        template<>
        struct Size< Meta::Collection<> >
        {
            enum
            {
                Result = 0
            };
        };
    }
}

#endif
