#ifndef _ENGINESERVICES_UITYPEINTERFACE_H_
#define _ENGINESERVICES_UITYPEINTERFACE_H_

struct UiGenericType
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(UiGenericType);

public:
    virtual void SetMemberName(const char* memberName) 
    {
    	BEHAVIAC_UNUSED_VAR(memberName);
    }
    virtual void SaveDescription(XmlNodeRef& xmlNode) = 0;
	virtual ~UiGenericType()
	{
	}
};

#define UiDescriptorAllocate_DefaultUiInfo  ((UiGenericType*)NULL)

#define DefaultUiInfo DefaultUiInfo

#endif // #ifndef _ENGINESERVICES_UITYPEINTERFACE_H_
