#ifndef _ENGINESERVICES_SERIALIZATIONEVENT_H_
#define _ENGINESERVICES_SERIALIZATIONEVENT_H_

#include "behaviac/base/object/tagobject.h"

/////////////////////////////////////////////////////////
///////////////     CONTAINED MEMBER      ///////////////
/////////////////////////////////////////////////////////

#define REGISTER_SERIALIZATION_EVENT(functionToCall, PropertyFlags2)                                             \
    {                                                                                                               \
		CMemberBase* property = CSerializationEventFactory<PropertyFlags2>::Create(&objectType::functionToCall, objectType::GetClassTypeName());     \
        CTagObjectDescriptor::PushBackMember(ms_members, property);                                                                             \
    }

template<class ObjectType2, uint32_t PropertyFlags2>
class CSerializationEvent : public CMemberBase
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CSerializationEvent);

    CSerializationEvent(void (ObjectType2::*Function)(), const char* className)
        : CMemberBase("SerializationEvent", className),
          m_function(Function) {}

	CSerializationEvent(const CSerializationEvent& copy) : CMemberBase(copy), m_function(copy.m_function)
	{}

	virtual CMemberBase* clone() const
	{
		CMemberBase* p = BEHAVIAC_NEW CSerializationEvent(*this);

		return p;
	}

    virtual void Load(CTagObject* parent, const ISerializableNode* node)
    {
        BEHAVIAC_UNUSED_VAR(parent);
        BEHAVIAC_UNUSED_VAR(node);

        if ((PropertyFlags2 & EPersistenceType_Description_Load))
        {
            (((ObjectType2*)parent)->*m_function)();
        }
    }

    virtual void Save(const CTagObject* parent, ISerializableNode* node)
    {
        BEHAVIAC_UNUSED_VAR(parent);
        BEHAVIAC_UNUSED_VAR(node);

        if ((PropertyFlags2 & EPersistenceType_Description_Save))
        {
            (((ObjectType2*)parent)->*m_function)();
        }
    }

    virtual void LoadState(CTagObject* parent, const ISerializableNode* node)
    {
        BEHAVIAC_UNUSED_VAR(parent);
        BEHAVIAC_UNUSED_VAR(node);

        if ((PropertyFlags2 & EPersistenceType_State_Load))
        {
            (((ObjectType2*)parent)->*m_function)();
        }
    }

    virtual void SaveState(const CTagObject* parent, ISerializableNode* node)
    {
        BEHAVIAC_UNUSED_VAR(parent);
        BEHAVIAC_UNUSED_VAR(node);

        if ((PropertyFlags2 & EPersistenceType_State_Save))
        {
            (((ObjectType2*)parent)->*m_function)();
        }
    }

    virtual void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
    {
        BEHAVIAC_UNUSED_VAR(parent);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(types);
    }

    virtual void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
    {
        BEHAVIAC_UNUSED_VAR(parent);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(types);
    }

    void (ObjectType2::*m_function)();
};

template<uint32_t PropertyFlags22>
struct CSerializationEventFactory
{
    template<class ObjectType22>
    static CMemberBase* Create(void (ObjectType22::*Function)(), const char* className)
    {
		typedef CSerializationEvent<ObjectType22, PropertyFlags22> EventType;
        return BEHAVIAC_NEW EventType(Function, className);
    }
};

#endif // #ifndef _ENGINESERVICES_SERIALIZATIONEVENT_H_
