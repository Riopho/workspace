






#ifndef _BEHAVIAC_BASE_META_REMOVEALL_H__INCLUDED
#define _BEHAVIAC_BASE_META_REMOVEALL_H__INCLUDED

#include "behaviac/base/meta/removeconst.h"
#include "behaviac/base/meta/removeptr.h"
#include "behaviac/base/meta/removeref.h"
#include "behaviac/base/meta/ifthenelse.h"
#include "behaviac/base/meta/iscompound.h"

namespace behaviac
{
    namespace Meta
    {
        template< typename T >
        struct RemoveAll
        {
            typedef typename RemoveConst< T >::Result TempResult;
            typedef typename IfThenElse <    IsRef< TempResult >::Result,
                    typename RemoveRef< TempResult >::Result,
                    typename RemovePtr< TempResult >::Result >::Result Result;
        };
    }
}

#endif
