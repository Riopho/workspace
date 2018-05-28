#ifndef _CORE_EXTENSIONCONFIG_H_
#define _CORE_EXTENSIONCONFIG_H_

#include "behaviac/base/core/singleton.h"
#include "behaviac/base/core/string/stringid.h"
#include "behaviac/base/core/rapidxml/rapidxml.hpp"

#include "behaviac/base/base.h"
#include "behaviac/base/xml/ixml.h"

#include <vector>
#include <string>

class BEHAVIAC_API CExtensionConfig
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CExtensionConfig);

public:
    struct SConfigInfo
    {
        CStringID						m_classID;
        behaviac::string					m_className; // used when creating .dep files, for example
        behaviac::vector<behaviac::string>	m_sourceExt;
        behaviac::string					m_targetExt;
        behaviac::vector<behaviac::string>	m_compileDependencies;

        void LoadFromXML(XmlNodeRef&);
    };

    // will be const will return const* in the future
    const SConfigInfo* GetInfoFromSource(const char* target);
    const SConfigInfo* GetInfoFromTarget(const char* source);
    const SConfigInfo* GetInfoFromDependency(const char* file);
    const SConfigInfo* GetInfoFromClassID(CStringID classID);

protected:
    CExtensionConfig();
    ~CExtensionConfig();

    void LoadFromXML(const char*);
    void LoadFromXML(XmlNodeRef&);

    behaviac::vector<SConfigInfo> m_resInfos;

    BEHAVIAC_DELCARE_SINGLETON(CExtensionConfig);
};

#endif // #ifndef _CORE_EXTENSIONCONFIG_H_
