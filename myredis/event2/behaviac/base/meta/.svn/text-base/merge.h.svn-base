






#ifndef _BEHAVIAC_REAL_BASETYPE_MERGE_H__INCLUDED
#define _BEHAVIAC_REAL_BASETYPE_MERGE_H__INCLUDED

#include "behaviac/base/meta/collection.h"

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< typename SequenceType, typename Type >
            struct MergeImpl;

        }  //namespace Details

        template< typename LeftVector, typename RightVector >
        struct Merge;


        // Collection merging utility. Merge two collection into one
        //
        //
        //

        template< typename LeftVector, typename RightVector >
        struct Merge
        {
            // Newly merged type
            typedef Collection< typename Details::MergeImpl< typename LeftVector::Type, typename RightVector::Type >::Result > Result;
        };

        template< typename LeftVector >
        struct Merge< LeftVector, Null >
        {
            typedef LeftVector Result;
        };

        template< typename RightVector >
        struct Merge< Null, RightVector >
        {
            typedef RightVector Result;
        };
    }
}

#include "behaviac/base/meta/merge.hpp"

#endif
