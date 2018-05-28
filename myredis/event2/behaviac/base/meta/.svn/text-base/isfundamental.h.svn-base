#ifndef _BEHAVIAC_BASE_TRAITS_ISFUNDAMENTAL_H__INCLUDED
#define _BEHAVIAC_BASE_TRAITS_ISFUNDAMENTAL_H__INCLUDED


namespace behaviac
{
    namespace Meta
    {

        // Answer is true only if the provided Type is a fundamental Type
        //
        // IsFundamental< int32_t >::Answer == true
        // IsFundamental< MyClass >::Answer == false
        //

        template< typename Type >
        struct IsFundamental
        {
            enum
            {
                Result = 0
            };
        };

#define BEHAVIAC_IS_FUNDAMENTAL( Type )     \
    template<>                          \
    struct IsFundamental< Type >        \
    {                                   \
        enum                            \
        {                               \
            Result = 1                  \
        };                              \
    };

        BEHAVIAC_IS_FUNDAMENTAL(uint8_t)
        BEHAVIAC_IS_FUNDAMENTAL(uint16_t)
        BEHAVIAC_IS_FUNDAMENTAL(uint32_t)


        BEHAVIAC_IS_FUNDAMENTAL(int8_t)
        BEHAVIAC_IS_FUNDAMENTAL(int16_t)
        //int32_t is actually a typedef of int
        //BEHAVIAC_IS_FUNDAMENTAL(int32_t)

        BEHAVIAC_IS_FUNDAMENTAL(signed long)
        BEHAVIAC_IS_FUNDAMENTAL(unsigned long)

        BEHAVIAC_IS_FUNDAMENTAL(int)

        BEHAVIAC_IS_FUNDAMENTAL(char)
		BEHAVIAC_IS_FUNDAMENTAL(bool)

#if !BEHAVIAC_COMPILER_GCC_LINUX
        BEHAVIAC_IS_FUNDAMENTAL(int64_t)
        BEHAVIAC_IS_FUNDAMENTAL(uint64_t)
#else
		BEHAVIAC_IS_FUNDAMENTAL(long long)
		BEHAVIAC_IS_FUNDAMENTAL(unsigned long long)
#endif//BEHAVIAC_COMPILER_GCC_LINUX

        BEHAVIAC_IS_FUNDAMENTAL(float)
        BEHAVIAC_IS_FUNDAMENTAL(double)

        BEHAVIAC_IS_FUNDAMENTAL(void)

    }
}

#endif
