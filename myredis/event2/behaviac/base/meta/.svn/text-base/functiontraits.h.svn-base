






#ifndef _BEHAVIAC_BASE_META_FUNCTIONTRAITS_H__INCLUDED
#define _BEHAVIAC_BASE_META_FUNCTIONTRAITS_H__INCLUDED

#include "behaviac/base/meta/functiontraits.hpp"
#include "behaviac/base/meta/addpointer.h"

namespace behaviac
{
    namespace Meta
    {

        // Provide the param count and each param type of function signature
        //
        //
        //

        template< typename Function >
        struct FunctionTraits : public Details::FunctionTraits< typename AddPointer< Function >::Result >
        {
            typedef Function Signature;
        };
    }
}

#endif
