#ifndef _ENGINESERVICES_SCRIPTSERIALISATION_H_
#define _ENGINESERVICES_SCRIPTSERIALISATION_H_

#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/core/singleton.h"
#include <map>

class BEHAVIAC_API CScriptObjectHierarchicalValidator
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CScriptObjectHierarchicalValidator);

public:
    typedef bool (*kindOf_function)(int tag);

    void RegisterTag(int tag, kindOf_function method)
    {
        m_tags[tag] = method;
    }

    bool ValidateTag(int child, int parent)
    {
        return (m_tags[child])(parent);
    }

protected:
    CScriptObjectHierarchicalValidator();
    ~CScriptObjectHierarchicalValidator();
    BEHAVIAC_DELCARE_SINGLETON(CScriptObjectHierarchicalValidator);

private:
    behaviac::map<int, kindOf_function> m_tags;
};

// helper class
class CScriptSerialisation
{
public:
    static void Init();
    static void Shutdown();

protected:
private:

};

int BEHAVIAC_API LuaCreateTag(const char* name);
void BEHAVIAC_API LuaRegisterFunction(const char* parent, const char* name, int (*func)(struct lua_State*));
void BEHAVIAC_API LuaCopyTag(int tagSrc, int tagDest);
int BEHAVIAC_API LuaGetTag(lua_State* L, int idx);

template<class ObjectType>
static void LuaRegisterClass()
{
    ObjectType::SetScriptTag(LuaCreateTag(ObjectType::GetClassTypeName()));
    CScriptObjectHierarchicalValidator::GetInstance()->RegisterTag(ObjectType::GetScriptTag(), ObjectType::IsAScriptKindOf);
    ObjectType::CopyScriptProperties(ObjectType::GetScriptTag());
}
#endif//#if BEHAVIAC_ENABLE_LUA


#endif // #ifndef _ENGINESERVICES_SCRIPTSERIALISATION_H_
