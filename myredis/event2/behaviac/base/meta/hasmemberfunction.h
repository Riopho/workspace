#ifndef BEHAVIAC_ENGINE_SYSTEM_UTILITIES_META_HASMEMBERFUNCTION_H__INCLUDED
#define BEHAVIAC_ENGINE_SYSTEM_UTILITIES_META_HASMEMBERFUNCTION_H__INCLUDED

#include "behaviac/base/meta/meta.h"

namespace behaviac
{
    namespace Meta
    {


#define BEHAVIAC_DECLARE_BASE_MEMBER_FUNCTION( FuncName ) \
public:\
    struct _Stub_##FuncName;\
    void FuncName( _Stub_##FuncName & )


        template < class RetType, class ObjType, class Arg1 >
        Meta::Yes HasConstMemberFunction1(RetType(ObjType::*)(Arg1) const);

        template < class RetType, class ObjType, class Arg1 >
        Meta::No  HasConstMemberFunction1(...);

#define BEHAVIAC_HAS_CONST_MEMBER_FUNCTION_1_ARG( FuncName, RetType, ObjType, Arg1 )\
    (sizeof(behaviac::Meta::HasConstMemberFunction1<RetType, ObjType, Arg1>(&ObjType::FuncName)) == sizeof(Meta::Yes))


        template < class RetType, class ObjType, class Arg1, class Arg2 >
        Meta::Yes HasConstMemberFunction2(RetType(ObjType::*)(Arg1, Arg2) const);

        template < class RetType, class ObjType, class Arg1, class Arg2 >
        Meta::No  HasConstMemberFunction2(...);

#define BEHAVIAC_HAS_CONST_MEMBER_FUNCTION_2_ARGS( FuncName, RetType, ObjType, Arg1, Arg2 )\
    (sizeof(behaviac::Meta::HasConstMemberFunction2<RetType, ObjType, Arg1, Arg2>(&ObjType::FuncName)) == sizeof(Meta::Yes))


        template < class RetType, class ObjType, class Arg1, class Arg2, class Arg3 >
        Meta::Yes HasConstMemberFunction3(RetType(ObjType::*)(Arg1, Arg2, Arg3) const);

        template < class RetType, class ObjType, class Arg1, class Arg2, class Arg3 >
        Meta::No  HasConstMemberFunction3(...);

#define BEHAVIAC_HAS_CONST_MEMBER_FUNCTION_3_ARGS( FuncName, RetType, ObjType, Arg1, Arg2, Arg3 )\
    (sizeof(behaviac::Meta::HasConstMemberFunction3<RetType, ObjType, Arg1, Arg2, Arg3>(&ObjType::FuncName)) == sizeof(Meta::Yes))


        template < class RetType, class ObjType, class Arg1, class Arg2, class Arg3, class Arg4 >
        Meta::Yes HasConstMemberFunction4(RetType(ObjType::*)(Arg1, Arg2, Arg3, Arg4) const);

        template < class RetType, class ObjType, class Arg1, class Arg2, class Arg3, class Arg4 >
        Meta::No  HasConstMemberFunction4(...);

#define BEHAVIAC_HAS_CONST_MEMBER_FUNCTION_4_ARGS( FuncName, RetType, ObjType, Arg1, Arg2, Arg3, Arg4 )\
    (sizeof(behaviac::Meta::HasConstMemberFunction4<RetType, ObjType, Arg1, Arg2, Arg3, Arg4>(&ObjType::FuncName)) == sizeof(Meta::Yes))

}  //namespace Meta
}  //namespace behaviac

#endif
