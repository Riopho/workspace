#ifndef _BEHAVIAC_REAL_BASETYPE_SEQUENCE_H__INCLUDED
#define _BEHAVIAC_REAL_BASETYPE_SEQUENCE_H__INCLUDED

#include "behaviac/base/meta/meta.h"

namespace behaviac
{
    namespace Meta
    {

        // Type Sequence
        //
        // Provide the current type alias( Head ) and the remaining Type Sequence alias ( Tail )
        //

        template< typename HeadType, typename TailType >
        struct Sequence
        {
            typedef Sequence< HeadType, TailType > Type;
            typedef HeadType Head;
            typedef TailType Tail;
        };
    }
}

#endif
