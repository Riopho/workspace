
#ifndef _ENGINESERVICES_SCRIPTMARSHALTYPE_H_
#define _ENGINESERVICES_SCRIPTMARSHALTYPE_H_

#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/dynamictype.h"

struct lua_State;

class CScriptMarshalDynamicObjectHolder
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CScriptMarshalDynamicObjectHolder);

public:
    virtual ~CScriptMarshalDynamicObjectHolder() {};

    template <class T> bool GetData(T*& data)
    {
        CDynamicType* rawData;

        if (!GetDataRaw(rawData))
        {
            return false;
        }

        data = T::DynamicCast(rawData);
        return data != NULL;
    }
    virtual bool GetDataRaw(CDynamicType*& data) = 0;

    virtual bool SetData(CDynamicType* data) = 0;

    virtual bool Validate(CDynamicType* data) = 0;
};

template <class T>
class CScriptMarshalBasicHolder : public CScriptMarshalDynamicObjectHolder
{
public:
    virtual bool GetDataRaw(CDynamicType*& data)
    {
        data = pointer;
        return true;
    }

    virtual bool SetData(CDynamicType* data)
    {
        T* tmpData = T::DynamicCast(data);

        if (tmpData == NULL)
        {
            return false;
        }

        pointer = tmpData;
        return true;
    }

    virtual bool Validate(CDynamicType* data)
    {
        return data == pointer;
    }

    T* pointer;

    static bool IsGarbageCollected()
    {
        return false;
    }
};

// Basic holder - simply store the pointer directly to the userdata.
template <class StorageType> struct ScriptMarshalObjectHolder
{
    template <class T> bool GetData(T*& data)
    {
        data = static_cast<T*>(pointer);
        return true;
    }
    template <class T> bool SetData(T* data)
    {
        pointer = data;
        return true;
    }
    template <class T> bool Validate(T* data)
    {
        return pointer == data;
    }
    StorageType* pointer;

    static bool IsGarbageCollected()
    {
        return false;
    }
};

// Type registration is made of:
// - A static script table, which is a lua_ref to the metatable of the userdata representing an instance of that type.
// - An object holder, which determines how the object will be marshalled to the scripting environment.
#define SCRIPTMARSHAL_DECLARE_OBJECT_HOLDER(holderClass) typedef holderClass ObjectHolder;
#define SCRIPTMARSHAL_DECLARE_OBJECT_TABLE(type) \
    static int GetScriptTable() { return ms_scriptTable; }\
    static void SetScriptTable(int table) { if (ms_scriptTable != -1) return; ms_scriptTable = table; }\
    static int ms_scriptTable;
#define SCRIPTMARSHAL_IMPLEMENT_OBJECT_TABLE(type) int type::ms_scriptTable = -1;


// This macro is used to declare a type with a custom object holder.
#define SCRIPTMARSHAL_DECLARE_TYPE_HOLDER(type, holderClass) SCRIPTMARSHAL_DECLARE_OBJECT_TABLE(type) SCRIPTMARSHAL_DECLARE_OBJECT_HOLDER(holderClass);
// This macro is used to declare a type with a default object holder.
#define SCRIPTMARSHAL_DECLARE_TYPE(type) SCRIPTMARSHAL_DECLARE_TYPE_HOLDER(type, CScriptMarshalBasicHolder<type>)
// This macro is used to implement a type (static variable instantiation).
#define SCRIPTMARSHAL_IMPLEMENT_TYPE(type) SCRIPTMARSHAL_IMPLEMENT_OBJECT_TABLE(type)


class IScriptMarshalTableSave
{
public:
    virtual void SaveScriptTable(lua_State* L) {} // Empty implementation, we're not actually forced to serialize anything.
};

#endif//#if BEHAVIAC_ENABLE_LUA


#endif
