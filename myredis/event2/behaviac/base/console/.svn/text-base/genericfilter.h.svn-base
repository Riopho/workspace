#ifndef _CORE_GENERICFILTER_H_
#define _CORE_GENERICFILTER_H_
#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_CONSOLE
#include "behaviac/base/core/string/stringid.h"

#include "behaviac/base/base.h"

#include <map>
#include <set>
#include <string>


class BEHAVIAC_API CGenericFilter
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CGenericFilter);
public:

    CGenericFilter(const char* name);
    ~CGenericFilter();

    enum TPriorityEnum
    {
        Prio_High     =   1,
        Prio_Normal   =   2,
        Prio_Low      =   3
    };

    bool IsFiltered(CNoCaseStringID filterGroup, TPriorityEnum filterPriority);

    void SetEnable(bool filterEnable);
    void SetGroupException(CNoCaseStringID filterGroup, bool filterException);
    void ClearGroupExceptions();

    void SetGlobalPriority(TPriorityEnum filterPriority);
    void SetGroupPriority(CNoCaseStringID filterGroup, TPriorityEnum filterPriority);
    void ClearGroupPriorities();

    void PrintMode();
    void PrintPriorities();

private:
    behaviac::string m_name;
    bool m_enable;
    behaviac::set_t<CNoCaseStringID> m_groupException;
    TPriorityEnum m_globalPriority;
    behaviac::map<CNoCaseStringID, TPriorityEnum> m_groupPriority;
};
#endif//#if BEHAVIAC_ENABLE_CONSOLE

#endif // #ifndef _CORE_GENERICFILTER_H_
