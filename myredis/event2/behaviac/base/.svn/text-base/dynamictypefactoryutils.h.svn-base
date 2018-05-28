#ifndef _ENGINESERVICES_DYNAMICTYPEFACTORYUTILS_H_
#define _ENGINESERVICES_DYNAMICTYPEFACTORYUTILS_H_

#include "behaviac/base/dynamictypefactory.h"

namespace DynTypeFactoryUtils
{
    //---------------------------------------------------------------------------------------
    // Name: DynTypeFactoryUtils::CreateObjectOfKind()
    // Desc: Uses the dynamic type factory to create an object that should be a kind
    // of T, and returns it as type T*.
    // If the newly created object is not an object of type T, NULL is returned.
    //---------------------------------------------------------------------------------------
    template<class T> T* CreateObjectOfKind(const CStringID& typeID)
    {
        CDynamicType* dynType = CDynamicTypeFactory::GetInstance()->Create(typeID);

        if (dynType != NULL)
        {
            T* newObj = T::DynamicCast(dynType);
            BEHAVIAC_ASSERT(newObj != NULL, "%s is not a type of %s. Creation failed!", typeID.LogStr().c_str(), T::GetClassTypeId().LogStr().c_str());

            if (newObj == NULL)
            {
                // The object was created but is not of the right type.
                BEHAVIAC_DELETE(dynType);
            }

            return newObj;
        }

        return NULL;
    }
};

#endif
