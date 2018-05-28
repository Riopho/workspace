






#ifndef _BEHAVIAC_REAL_BASETYPE_DETAILS_MERGE_HPP__INCLUDED
#define _BEHAVIAC_REAL_BASETYPE_DETAILS_MERGE_HPP__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< typename Type >
            struct MergeImpl< Null, Type >
            {
                typedef typename Collection< Type >::Type Result;
            };

            template< typename HeadType, typename TailType >
            struct MergeImpl< Null, Sequence< HeadType, TailType > >
            {
                typedef Sequence< HeadType, TailType > Result;
            };

            template< typename HeadType, typename TailType, typename Type >
            struct MergeImpl< Sequence< HeadType, TailType >, Type >
            {
                typedef Sequence< HeadType, typename MergeImpl< TailType, Type >::Result > Result;
            };
        }
    }
}

#endif
