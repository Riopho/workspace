#ifndef _ENGINESERVICES_CONTAINERUITYPE_H_
#define _ENGINESERVICES_CONTAINERUITYPE_H_

#include "behaviac/base/object/uitype.h"

struct UiContainerType : public UiBasicType
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(UiContainerType);

private:
    bool m_resizable;
    const char* m_elementName;

public:

    UiContainerType() : m_resizable(false), m_elementName(NULL) {}
    UiContainerType(bool resizable, const char* description = NULL) : UiBasicType(Ui_None, description), m_resizable(resizable), m_elementName(NULL) {}

    virtual void SetMemberName(const char* memberName)
    {
        m_elementName = memberName;
    }
    virtual void SaveDescription(XmlNodeRef& xmlNode)
    {
        UiBasicType::SaveDescription(xmlNode);

        if (m_elementName)
        {
            xmlNode->setAttr("Container", m_elementName);
        }

        if (m_resizable)
        {
            xmlNode->setAttr("Resizable", true);
        }
    }
};

#define UiDescriptorAllocate_UiContainerType BEHAVIAC_NEW UiContainerType

#endif // #ifndef _ENGINESERVICES_CONTAINERUITYPE_H_
