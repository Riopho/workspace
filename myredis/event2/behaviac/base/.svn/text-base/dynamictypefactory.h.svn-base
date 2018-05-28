#ifndef _ENGINESERVICES_DYNAMICTYPEFACTORY_H_
#define _ENGINESERVICES_DYNAMICTYPEFACTORY_H_


#include "behaviac/base/core/singleton.h"
#include "behaviac/base/core/factory.h"
#include "behaviac/base/dynamictype.h"

class BEHAVIAC_API CDynamicTypeFactory
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CDynamicTypeFactory);

private:
    CDynamicTypeFactory();
    ~CDynamicTypeFactory();

    CFactory<CDynamicType> m_factory;

    BEHAVIAC_DELCARE_SINGLETON(CDynamicTypeFactory);

public:
    bool Register(const CStringID& typeID, CFactory<CDynamicType>::InstantiateFunctionPointer instantiate);
    bool UnRegister(const CStringID& typeID);

    // templated version assuming the parameters are accessible
    // by the static methods GetClassTypeId and CreateObject
    template<class T>
    bool Register()
    {
        return Register(T::GetClassTypeId(), &T::CreateObject);
    }

    template<class T>
    bool UnRegister()
    {
        return m_factory.UnRegister(T::GetClassTypeId());
    }

    // visitor function
    template<typename VISITOR>
    void Visit(VISITOR& visitor)
    {
        m_factory.Visit(visitor);
    }

    CDynamicType* Create(const CStringID& typeID);
};

#endif // #ifndef _ENGINESERVICES_DYNAMICTYPEFACTORY_H_
