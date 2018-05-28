






#ifndef _BEHAVIAC_BASE_META_ADDPOINTER_H__INCLUDED
#define _BEHAVIAC_BASE_META_ADDPOINTER_H__INCLUDED

namespace behaviac
{
    namespace Meta
    {
        template< typename T >
        struct AddPointer
        {
            typedef T* Result;
        };
    }
}

#endif
