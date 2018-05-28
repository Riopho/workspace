






#ifndef _BEHAVIAC_REAL_BASETYPE_COLLECTION_H__INCLUDED
#define _BEHAVIAC_REAL_BASETYPE_COLLECTION_H__INCLUDED

#include "behaviac/base/meta/meta.h"
#include "behaviac/base/meta/sequence.h"
#include "behaviac/base/meta/boost/enum_shifted_params.hpp"

namespace behaviac
{
    namespace Meta
    {
#define BEHAVIAC_TYPE_COLLECTION_MAX_SIZE 13

        //
        // 'Comment your class/struct details here'
        //

        template< BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(BEHAVIAC_TYPE_COLLECTION_MAX_SIZE, typename Type, Null) >
        struct Collection
        {
            typedef typename Collection< BOOST_PP_ENUM_SHIFTED_PARAMS(BEHAVIAC_TYPE_COLLECTION_MAX_SIZE, Type) >::Type Tail;

            typedef Sequence< Type0, Tail > Type;
        };

        template< typename HeadType, typename TailType >
        struct Collection< Sequence< HeadType, TailType > >
        {
            typedef Sequence< HeadType, TailType > Type;
        };

        template<>
        struct Collection<>
        {
            typedef Null Type;
        };
    }
}

#endif
