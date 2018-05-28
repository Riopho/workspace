#ifndef BEHAVIAC_BASE_STATICASSERT_H_
#define BEHAVIAC_BASE_STATICASSERT_H_

namespace behaviac
{

    namespace Private
    {
        template <bool> struct STATIC_ASSERT_FAILURE;
        template <> struct STATIC_ASSERT_FAILURE<true>
        {
            enum { value = 1 };
        };

        template<int x> struct static_assert_test {};
    }//namespae Private

}//namespace behaviac

#define BEHAVIAC_STATIC_ASSERT(x) \
    typedef behaviac::Private::static_assert_test<\
    sizeof(behaviac::Private::STATIC_ASSERT_FAILURE< (bool)( (x) ) >)>\
    _static_assert_typedef_


//#define BEHAVIAC_STATIC_ASSERT(expr)	typedef char BEHAVIAC_JOIN_TOKENS(CC_, __LINE__) [(expr) ? 1 : -1]


#endif//BEHAVIAC_BASE_STATICASSERT_H_
