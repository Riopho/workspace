#ifndef _ENGINESERVICES_CONSOLEGENERICFILTER_H_
#define _ENGINESERVICES_CONSOLEGENERICFILTER_H_
#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_CONSOLE
#include "behaviac/base/console/genericfilter.h"
#include "behaviac/base/console/consolehelper.h"

class BEHAVIAC_API CConsoleGenericFilter
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CConsoleGenericFilter);
public:
    CConsoleGenericFilter(CGenericFilter* filter, const char* prefix);

private:
    void SetGlobalPriority(uint32_t filterPriority);
    void SetGroupPriority(CNoCaseStringID filterGroup, uint32_t filterPriority);

    CGenericFilter* m_filter;
    CConsoleCommandList m_commandList;
};
#endif//#if BEHAVIAC_ENABLE_CONSOLE
#endif // #ifndef _ENGINESERVICES_CONSOLEGENERICFILTER_H_
