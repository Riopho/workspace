






#ifndef _BEHAVIAC_REAL_BASETYPE_IF_H__INCLUDED
#define _BEHAVIAC_REAL_BASETYPE_IF_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        template< bool, typename Then, typename Else >
        struct IfThenElse
        {
            typedef Then Result;
        };

        template< typename Then, typename Else >
        struct IfThenElse< false, Then, Else >
        {
            typedef Else Result;
        };

    }
}

#endif
