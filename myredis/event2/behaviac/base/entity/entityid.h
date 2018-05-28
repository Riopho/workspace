#ifndef _ENGINESERVICES_ENTITYID_H_
#define _ENGINESERVICES_ENTITYID_H_

#include "behaviac/base/smartptr.h"
#include "behaviac/base/dynamictype.h"
#include "behaviac/base/core/string/stringid.h"

#define INVALID_ENTITY_ID EntityId()

class EntityId
{
public:
    // Type definitions.
    typedef uint64_t IdType;
    static const IdType InvalidEntityId = (uint64_t) - 1;

public:
    EntityId() : m_id(InvalidEntityId)
    {
    }

    explicit EntityId(IdType id) : m_id(id)
    {
    }

    bool IsValid() const
    {
        return (m_id != InvalidEntityId);
    }

    bool operator == (const EntityId& entityId) const
    {
        return m_id == entityId.m_id;
    }

    bool operator != (const EntityId& entityId) const
    {
        return m_id != entityId.m_id;
    }

    bool operator < (const EntityId& entityId) const
    {
        return m_id < entityId.m_id;
    }

    IdType GetUniqueID() const
    {
        return m_id;
    }

    bool IsDynamic() const
    {
        return (GetUniqueID() >> 63) == 1;
    }

private:
    EntityId(int id)
    {
        BEHAVIAC_UNUSED_VAR(id);
    }

    IdType m_id;
};

BEHAVIAC_OVERRIDE_TYPE_NAME(EntityId)

namespace stdext
{
    template<>
    inline size_t hash_value(const EntityId& keyval)
    {
        // hash _Keyval to size_t value one-to-one
        return ((size_t)keyval.GetUniqueID() ^ ((size_t)0xdeadbeef));
    }
}

#endif // #ifndef _ENGINESERVICES_ENTITYID_H_
