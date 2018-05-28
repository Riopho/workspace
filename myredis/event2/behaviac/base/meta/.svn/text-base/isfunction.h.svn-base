






#ifndef _BEHAVIAC_BASE_TRAITS_ISFUNCTION_H__INCLUDED
#define _BEHAVIAC_BASE_TRAITS_ISFUNCTION_H__INCLUDED

#include "behaviac/base/meta/meta.h"

namespace behaviac
{
    namespace Meta
    {

        // Answer is true if the provided Type is a function
        //
        // void MyFunction();
        //
        // IsFunction< MyFunction >::Answer == true
        // IsFunction< MyClass >::Answer == false

        template< typename Type >
        struct IsFunction
        {
        private:

            template< typename AnswerYes >
            static Yes Tester(...);

            template< typename AnswerNo >
            static No Tester(AnswerNo(*)[1]);

        public:

            enum
            {
                Result = sizeof(Tester<Type>(0)) == sizeof(Yes)
            };
        };

        template< typename Type >
        struct IsFunction< Type& >
        {
            enum { Result = 0 };
        };

        template<>
        struct IsFunction< void >
        {
            enum { Result = 0 };
        };

        template<>
        struct IsFunction< void const >
        {
            enum { Result = 0 };
        };
    }
}

#endif
