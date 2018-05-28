#ifndef _CORE_FORMATSTRINGMEMBER_H_
#define _CORE_FORMATSTRINGMEMBER_H_

#include "behaviac/base/file/formatstring.h"

template< typename CONTAINER, void (CONTAINER::*fct)(const char*) >
class CFormatStringMember
{
public:
    // never has a generic implementation, always a specialized implementation
    inline CONTAINER& GetContainer();

    inline void operator()(const char* format)
    {
        CONTAINER& cont = GetContainer();
        (cont.*fct)(format);
    }

#define DECLARE_TYPENAME( num ) typename T##num
#define DECLARE_PARAM( num ) const T##num p##num
#define USE_PARAM( num ) p##num
#define DEFINE_FORMATSTRING( num ) \
    template< REPEAT( DECLARE_TYPENAME, num ) > \
    inline void operator()( const char* format, REPEAT( DECLARE_PARAM, num ) ) \
    { \
        CONTAINER& cont = GetContainer(); \
        (cont.*fct)( FormatString( format, REPEAT( USE_PARAM, num ) ) ); \
    }

    DEFINE_FORMATSTRING(1)
    DEFINE_FORMATSTRING(2)
    DEFINE_FORMATSTRING(3)
    DEFINE_FORMATSTRING(4)
    DEFINE_FORMATSTRING(5)
    DEFINE_FORMATSTRING(6)
    DEFINE_FORMATSTRING(7)
    DEFINE_FORMATSTRING(8)
    DEFINE_FORMATSTRING(9)
    DEFINE_FORMATSTRING(10)
    DEFINE_FORMATSTRING(11)
    DEFINE_FORMATSTRING(12)
    DEFINE_FORMATSTRING(13)
    DEFINE_FORMATSTRING(14)
    DEFINE_FORMATSTRING(15)

#undef DEFINE_FORMATSTRING
#undef USE_PARAM
#undef DECLARE_PARAM
#undef DECLARE_TYPENAME
};

#define DECLARE_FORMATSTRINGMEMBER( cls, fct, name ) \
    CFormatStringMember< cls, &cls::fct > name

// non-null fake pointer removes warning on GCC
#define FORMATSTRINGMEMBER_OFFSETOF(s,m) ( ( (size_t)&reinterpret_cast< const volatile char& >( reinterpret_cast< s* >( 16 )->m ) ) - 16 )

#define IMPLEMENT_FORMATSTRINGMEMBER( cls, fct, name ) \
    template< > \
    inline cls& CFormatStringMember< cls, &cls::fct >::GetContainer() \
    { \
        return *reinterpret_cast< cls* >( reinterpret_cast< uint8_t* >( this ) - FORMATSTRINGMEMBER_OFFSETOF( cls, name ) ); \
    }

#endif // _CORE_FORMATSTRINGMEMBER_H_
