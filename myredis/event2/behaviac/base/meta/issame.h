#ifndef _BEHAVIAC_BASE_META_ISSAME_H__INCLUDED
#define _BEHAVIAC_BASE_META_ISSAME_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {

        // Compare two type, Answer is true if they are the same
        //
        // IsSame< int32_t, int32_t >::Answer == true
        // IsSame< int32_t, float >::Answer == false
        //

        template< typename First, typename Second >
        struct IsSame
        {
            enum
            {
                Result = 0
            };
        };

        template< typename First >
        struct IsSame< First, First >
        {
            enum
            {
                Result = 1
            };
        };

    }
}

#endif
