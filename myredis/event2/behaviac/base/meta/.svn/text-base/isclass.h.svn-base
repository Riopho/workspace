






#ifndef _BEHAVIAC_BASE_TRAITS_ISCLASS_H__INCLUDED
#define _BEHAVIAC_BASE_TRAITS_ISCLASS_H__INCLUDED

#include "behaviac/base/meta/meta.h"

namespace behaviac
{
    namespace Meta
    {

        // Result is true if the provided Type is a class
        //
        // class MyClass{};
        //
        // IsClass< MyClass >::Result == true
        // IsClass< int >::Result == false
        //

        template< typename Type >
        struct IsClass
        {
        private:

            template< typename AnswerYes >
            static Yes Tester(void(AnswerYes::*)(void));

            template< typename AnswerNo >
            static No Tester(...);

        public:

            enum
            {
                Result = sizeof(Tester<Type>(0)) == sizeof(Yes)
            };
        };
    }
}

#endif
