






#ifndef _BEHAVIAC_BASE_META_DETAILS_ISINSTANCEOF_HPP__INCLUDED
#define _BEHAVIAC_BASE_META_DETAILS_ISINSTANCEOF_HPP__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< typename BaseType, typename DerivedType >
            struct IsInstanceOfImpl
            {
                static Yes Test(BaseType);
                static No Test(...);
                static DerivedType Make();

                enum
                {
                    Result = sizeof(Test(Make())) == sizeof(Yes)
                };
            };
        }
    }
}

#endif
