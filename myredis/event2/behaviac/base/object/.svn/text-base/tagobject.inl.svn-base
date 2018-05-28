#ifndef _BEHAVIAC_BASE_OBJECT_TAGOBJECT_MACROS_H_
#define _BEHAVIAC_BASE_OBJECT_TAGOBJECT_MACROS_H_

#include "behaviac/base/object/member.h"

template<class ValueType>
ValueType CTagObject::GetMember(const CStringID& nameId)
{
    const CTagObjectDescriptor& descriptor = GetDescriptor();
	CTagObjectDescriptor::MembersMap_t::const_iterator it = descriptor.ms_members.membersMap.find(nameId);
	if (it != descriptor.ms_members.membersMap.end())
    {
        const CMemberBase* member = it->second;

        BEHAVIAC_ASSERT(member->GetID() == nameId);

        int typeId = GetClassTypeNumberId<ValueType>();
		return *((ValueType*)member->Get(this, typeId));
    }

    BEHAVIAC_ASSERT(0, "CTagObject::GetMember, cannot find the parameter %s", nameId.LogStr().c_str());
    return ValueType();
}

template<class ValueType>
void CTagObject::SetMember(const CStringID& nameId, const ValueType& value)
{
    const CTagObjectDescriptor& descriptor = GetDescriptor();

	CTagObjectDescriptor::MembersMap_t::const_iterator it = descriptor.ms_members.membersMap.find(nameId);
	if (it != descriptor.ms_members.membersMap.end())
	{
		CMemberBase* member = it->second;

		BEHAVIAC_ASSERT(member->GetID() == nameId);
		int typeId = GetClassTypeNumberId<ValueType>();
		member->Set(this, (void*)&value, typeId);
		return;
	}

    BEHAVIAC_ASSERT(0, "CTagObject::SetMember, cannot find the parameter %s", nameId.LogStr().c_str());
}

#endif // #ifndef _BEHAVIAC_BASE_OBJECT_TAGOBJECT_MACROS_H_
