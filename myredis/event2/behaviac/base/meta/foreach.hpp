






#ifndef _BEHAVIAC_BASE_META_FOREACH_HPP__INCLUDED
#define _BEHAVIAC_BASE_META_FOREACH_HPP__INCLUDED

#include "behaviac/base/meta/issame.h"

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< bool >
            struct ForEachImpl
            {
                template< typename T, typename Tail, typename Functor, template< typename > class Wrapper >
                static Functor Execute(Functor functor)
                {
                    typedef typename Wrapper< T >::Type CurrentType;
                    functor(CurrentType());
                    typedef typename Tail::Head NextType;
                    typedef typename Tail::Tail NextTail;
                    return Details::ForEachImpl< IsSame< NextTail, Null >::Result >::template Execute< NextType, NextTail, Functor, Wrapper >(functor);
                }
            };

            template<>
            struct ForEachImpl< true >
            {
                template< typename T, typename Tail, typename Functor, template< typename > class Wrapper >
                static Functor Execute(Functor functor)
                {
                    typedef typename Wrapper< T >::Type CurrentType;
                    functor(CurrentType());
                    return functor;
                }
            };
        }
        template< typename CollectionType, template< typename > class Wrapper, typename Functor >
        Functor ForEach(Functor functor)
        {
            typedef typename CollectionType::Type SequenceType;
            typedef typename SequenceType::Head HeadType;
            typedef typename SequenceType::Tail TailType;
            return Details::ForEachImpl< IsSame< TailType, Null >::Result >::template Execute< HeadType, TailType, Functor, Wrapper >(functor);
        }
    }
}

#endif
