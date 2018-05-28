#ifndef _BEHAVIAC_BASE_CONFIG_H_
#define _BEHAVIAC_BASE_CONFIG_H_

#include "behaviac/base/core/singleton.h"
#include "behaviac/base/core/string/stringid.h"

#include "behaviac/base/xml/ixml.h"

#include <map>
#include <string>


class BEHAVIAC_API CConfig
{
public:
    BEHAVIAC_DELCARE_SINGLETON(CConfig);
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CConfig);
    CConfig();
    ~CConfig();
public:
    static const char*  Get(const char* section, const char* key);
    static void         Set(const char* section, const char* key, const char* value);

    static bool         Exists(const char* section, const char* key);
    static bool         SectionExists(const char* section);

    // overrideIfPresent : true=replace destination value with source value, false=keep destination value
    void MergeSections(const char* sourceSectionName, const char* destinationSectionName, bool overrideIfPresent);

    bool LoadConfig(const char* configfile);

    static const behaviac::map< CStringID, behaviac::string >& GetSection(const char* section);
    static XmlConstNodeRef                   GetSectionXmlInfo(const char* section);

private:
    typedef behaviac::map< CStringID, behaviac::string > TSectionXmlInfoMap;
    typedef behaviac::map< CStringID, TSectionXmlInfoMap > TSectionsXmlInfoMap;
    TSectionsXmlInfoMap m_settings;
    behaviac::map< CStringID, XmlConstNodeRef > m_settingsXmlInfo;
};

#endif // #ifndef _BEHAVIAC_BASE_CONFIG_H_
