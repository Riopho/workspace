






#ifndef _BEHAVIAC_BASE_META_SIZE_HPP__INCLUDED
#define _BEHAVIAC_BASE_META_SIZE_HPP__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< typename Head, typename Tail >
            struct SizeImpl
            {
                enum
                {
                    Result = 1 + SizeImpl< typename Tail::Head, typename Tail::Tail >::Result
                };
            };

            template< typename Head >
            struct SizeImpl< Head, Meta::Null >
            {
                enum
                {
                    Result = 1
                };
            };
        }
    }
}

#endif
