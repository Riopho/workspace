






#ifndef _BEHAVIAC_REAL_BASETYPE_COUNT_H__INCLUDED
#define _BEHAVIAC_REAL_BASETYPE_COUNT_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< typename LookingFor, typename SequenceHead, typename SequenceTail >
            struct CountImpl;

        }  //namespace Details

        template< typename LookingFor, typename VectorType >
        struct Count
        {
            typedef typename VectorType::Type SequenceType;
            enum
            {
                Result = Details::CountImpl< LookingFor, typename SequenceType::Head, typename SequenceType::Tail >::Result
            };
        };
    }
}

#include "behaviac/base/meta/count.hpp"

#endif
