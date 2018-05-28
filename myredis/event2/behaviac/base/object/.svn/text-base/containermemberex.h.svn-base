#ifndef _ENGINESERVICES_CONTAINERMEMBEREX_H_
#define _ENGINESERVICES_CONTAINERMEMBEREX_H_

#include "behaviac/base/object/containermember.h"
#include "behaviac/base/object/containertypehandlerex.h"


/////////////////////////////////////////////////////////
//////////     EXTENDED CONTAINER MEMBER     ////////////
/////////////////////////////////////////////////////////

#define REGISTER_CONTAINER_MEMBER_EX(containerName, elementName, valueName, memberName, propertyFlags, containerProvider, containedTypeHandler, UiDescriptor) \
    { \
        DECLARE_UIWRAPPER(UiDescriptor); \
        CMemberBase* property_ = CContainerMemberFactory< GenericContainerHandler, containerProvider, containedTypeHandler, propertyFlags, true >::Create( \
                                &objectType::memberName, objectType::GetClassTypeName(), containerName, elementName, valueName, "", localWrapper); \
        CTagObjectDescriptor::PushBackMember(ms_members, property_); \
    }

#define REGISTER_CONTAINER_MEMBER_NOCHILD(containerName, elementName, valueName, memberName, propertyFlags, containerProvider, containedTypeHandler, UiDescriptor) \
    { \
        DECLARE_UIWRAPPER(UiDescriptor); \
        CMemberBase* property_ = CContainerMemberFactory< GenericContainerHandler, containerProvider, containedTypeHandler, propertyFlags, false >::Create( \
                                &objectType::memberName, objectType::GetClassTypeName(), containerName, elementName, valueName, "", localWrapper); \
        CTagObjectDescriptor::PushBackMember(ms_members, property_); \
    }

#define REGISTER_CONTAINER_MEMBER_BYID(containerName, elementName, valueName, idName, memberName, propertyFlags, createChildNode, containerProvider, containedTypeHandler, UiDescriptor) \
    { \
        DECLARE_UIWRAPPER(UiDescriptor); \
        CMemberBase* property_ = CContainerMemberFactory< ByIDContainerHandler, containerProvider, containedTypeHandler, propertyFlags, createChildNode >::Create( \
                                &objectType::memberName, objectType::GetClassTypeName(), containerName, elementName, valueName, idName, localWrapper); \
        CTagObjectDescriptor::PushBackMember(ms_members, property_); \
    }

#define REGISTER_CONTAINER_MEMBER_USETAGASID(containerName, valueName, memberName, propertyFlags, createChildNode, containerProvider, containedTypeHandler, UiDescriptor) \
    { \
        DECLARE_UIWRAPPER(UiDescriptor); \
        CMemberBase* property_ = CContainerMemberFactory< UseTagAsIDContainerHandler, containerProvider, containedTypeHandler, propertyFlags, createChildNode>::Create( \
                                &objectType::memberName, objectType::GetClassTypeName(), containerName, "", valueName, "", localWrapper); \
        CTagObjectDescriptor::PushBackMember(ms_members, property_); \
    }

#define REGISTER_CONTAINER_MEMBER_CUSTOM_CONTAINERHANDLER(containerName, elementName, valueName, memberName, propertyFlags, createChildNode, containerHandler, containerProvider, containedTypeHandler, UiDescriptor) \
    { \
        DECLARE_UIWRAPPER(UiDescriptor); \
        CMemberBase* property_ = CContainerMemberFactory< containerHandler, containerProvider, containedTypeHandler, propertyFlags, createChildNode>::Create( \
                                &objectType::memberName, objectType::GetClassTypeName(), containerName, elementName, valueName, "", localWrapper); \
        CTagObjectDescriptor::PushBackMember(ms_members, property_); \
    }


#endif // #ifndef _ENGINESERVICES_CONTAINERMEMBEREX_H_
