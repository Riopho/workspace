




#ifndef _BEHAVIAC_BASE_META_DETAILS_EXIST_HPP__INCLUDED
#define _BEHAVIAC_BASE_META_DETAILS_EXIST_HPP__INCLUDED

#include "behaviac/base/meta/collection.h"

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< typename LookingFor, typename HeadType, typename TailType >
            struct ExistImpl
            {
                enum
                {
                    Result = ExistImpl< LookingFor, typename TailType::Head, typename TailType::Tail >::Result
                };
            };

            template< typename LookingFor, typename TailType >
            struct ExistImpl< LookingFor, LookingFor, TailType >
            {
                enum
                {
                    Result = 1
                };
            };

            template< typename LookingFor, typename HeadType >
            struct ExistImpl< LookingFor, HeadType, Meta::Null >
            {
                enum
                {
                    Result = 0
                };
            };

            template< typename LookingFor >
            struct ExistImpl< LookingFor, LookingFor, Meta::Null >
            {
                enum
                {
                    Result = 1
                };
            };
        }

        template< typename LookingFor, typename VectorType >
        struct Exist
        {
            typedef typename VectorType::Type SequenceType;
            enum
            {
                Result = Details::ExistImpl< LookingFor, typename SequenceType::Head, typename SequenceType::Tail >::Result
            };
        };

        template< typename LookingFor >
        struct Exist< LookingFor, Meta::Null >
        {
            enum
            {
                Result = 0
            };
        };
    }
}

#endif
