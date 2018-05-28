#ifndef _ENGINESERVICES_SCRIPTREFERENCE_H_
#define _ENGINESERVICES_SCRIPTREFERENCE_H_

#include "behaviac/base/base.h"
#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/smartptr.h"

struct lua_State;

class CScriptReference;
typedef CSmartPtr<CScriptReference> CScriptReferenceRef;

// Just a int wrapper to differentiate when marshalling.
struct ScriptReferenceId
{
    ScriptReferenceId() : m_reference(0) {}
    ScriptReferenceId(int val)
    {
        *this = val;
    }

    int operator =(int val)
    {
        m_reference = val;
        return val;
    }

    operator int() const
    {
        return m_reference;
    }

    int m_reference;
};

class BEHAVIAC_API CScriptReference : public CRefCounted
{
public:
    CScriptReference() : m_reference(0) {}
    CScriptReference(lua_State* lua_state, int index);

    ~CScriptReference();

    ScriptReferenceId operator =(ScriptReferenceId val)
    {
        m_reference = val;
        return	val;
    }
    bool operator ==(const CScriptReference& r)
    {
        return (r.m_reference == m_reference);
    }

    operator int () const
    {
        return m_reference;
    }

protected:
private:
    ScriptReferenceId m_reference;
};

#endif//#if BEHAVIAC_ENABLE_LUA

#endif // #ifndef _ENGINESERVICES_SCRIPTREFERENCE_H_
