#ifndef _ENGINESERVICES_SCRIPTREGISTRY_H_
#define _ENGINESERVICES_SCRIPTREGISTRY_H_

#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
#include <vector>


class BEHAVIAC_API CScriptRegistry
{
public:
    void LoadScriptRegistry(const char* registryFilename);

    template<typename T>
    void Visit(T& visitor);

private:
    bool RegisterScript(XmlNodeRef&);


private:
    struct SBucketScript
    {
        SBucketScript(const CStringID& typeID, const CStringID& baseTypeID, const char* luaFile)
            : m_type(typeID)
            , m_baseType(baseTypeID)
            , m_luaFile(luaFile)
            , m_loaded(false)
        {
        }
        bool operator==(const SBucketScript& rhs)const
        {
            return m_type == rhs.m_type;
        }

        CStringID		m_type;
        CStringID		m_baseType;
        const char*		m_luaFile;
        bool			m_loaded;
    };

    typedef behaviac::vector< SBucketScript > ContainerScript;
    typedef ContainerScript::iterator CreatorItScript;

    ContainerScript m_registry;
};


template<typename T>
void CScriptRegistry::Visit(T& visitor)
{
    CreatorItScript it(m_registry.begin());
    CreatorItScript itEnd(m_registry.end());

    while (it != itEnd)
    {
        visitor.Visit(it->m_baseType, it->m_type);
        ++it;
    }
}
#endif//#if BEHAVIAC_ENABLE_LUA

#endif // #ifndef _ENGINESERVICES_SCRIPTREGISTRY_H_
