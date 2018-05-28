



#ifndef BEHAVIAC_ENGINE_SYSTEM_UTILITIES_META_ISABSTRACT_H__INCLUDED
#define BEHAVIAC_ENGINE_SYSTEM_UTILITIES_META_ISABSTRACT_H__INCLUDED

#include "behaviac/base/meta/isclass.h"
#include "behaviac/base/meta/ifthenelse.h"

namespace behaviac
{
    namespace Meta
    {
        template< typename T >
        static No CheckIfAbstract(T(*)[1]);

        template< typename T >
        static Yes CheckIfAbstract(...);

        template< typename T >
        struct IsAbstract
        {
            enum
            {
                Result = IsClass< T >::Result &&
                         sizeof(CheckIfAbstract< T >(0)) == sizeof(Yes)
            };
        };
    }
}

#endif
