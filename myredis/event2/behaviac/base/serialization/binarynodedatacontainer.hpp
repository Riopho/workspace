#ifndef _CORE_BINARYNODE_HPP_
#define _CORE_BINARYNODE_HPP_

#include "behaviac/base/serialization/binarynodedatacontainer.h"

#if BEHAVIAC_ENABLE_BINARYNODE

////////////////////////////////////////////////////////////////////////////////
// SChunk
////////////////////////////////////////////////////////////////////////////////
template <typename TContainedType>
struct CBinaryNodeDataContainer<TContainedType>::SChunk
{
    SChunk(const TContainedType& data) : m_data(data), m_nextChunk(NULL) {}

    TContainedType m_data;
    SChunk* m_nextChunk;
};


////////////////////////////////////////////////////////////////////////////////
// CBinaryNodeDataContainer::const_iterator
////////////////////////////////////////////////////////////////////////////////
template <typename TContainedType>
CBinaryNodeDataContainer<TContainedType>::const_iterator::const_iterator(SChunk* chunk)
    : m_chunk(chunk)
{
}

template <typename TContainedType>
bool CBinaryNodeDataContainer<TContainedType>::const_iterator::operator!=(const const_iterator& iter) const
{
    return !(*this == iter);
}

template <typename TContainedType>
bool CBinaryNodeDataContainer<TContainedType>::const_iterator::operator==(const const_iterator& iter) const
{
    return (m_chunk == iter.m_chunk);
}


template <typename TContainedType>
const TContainedType& CBinaryNodeDataContainer<TContainedType>::const_iterator::operator*() const
{
    BEHAVIAC_ASSERT(m_chunk);
    return m_chunk->m_data;
}

template <typename TContainedType>
const TContainedType* CBinaryNodeDataContainer<TContainedType>::const_iterator::operator->() const
{
    BEHAVIAC_ASSERT(m_chunk);
    return &m_chunk->m_data;
}


////////////////////////////////////////////////////////////////////////////////
// CBinaryNodeDataContainer::iterator
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// CBinaryNodeDataContainer
////////////////////////////////////////////////////////////////////////////////
template <typename TContainedType>
CBinaryNodeDataContainer<TContainedType>::CBinaryNodeDataContainer()
    : m_rootChunk(NULL)
{
}

template <typename TContainedType>
CBinaryNodeDataContainer<TContainedType>::~CBinaryNodeDataContainer()
{
    // Make sure it's been cleared! We can't do it here because we don't have the allocator...
    BEHAVIAC_ASSERT(!m_rootChunk);
}

template <typename TContainedType>
void CBinaryNodeDataContainer<TContainedType>::clear(CBinaryNodeBaseAllocator* allocator)
{
    while (m_rootChunk)
    {
        SChunk* toDelete = m_rootChunk;
        m_rootChunk = m_rootChunk->m_nextChunk;
        toDelete->~SChunk();
        allocator->Free(toDelete);
    }
}

template <typename TContainedType>
int32_t CBinaryNodeDataContainer<TContainedType>::size() const
{
    int32_t totalSize = 0;
    SChunk* chunk = m_rootChunk;

    while (chunk)
    {
        ++totalSize;
        chunk = chunk->m_nextChunk;
    }

    return totalSize;
}

template <typename TContainedType>
int32_t CBinaryNodeDataContainer<TContainedType>::GetMemUsage() const
{
    int32_t memUsage = 0;
    SChunk* chunk = m_rootChunk;

    while (chunk)
    {
        memUsage += sizeof(SChunk);
        chunk = chunk->m_nextChunk;
    }

    return memUsage;
}

template <typename TContainedType>
TContainedType& CBinaryNodeDataContainer<TContainedType>::push_back(CBinaryNodeBaseAllocator* allocator, const TContainedType& element)
{
    SChunk* newChunk = (SChunk*)allocator->Alloc(sizeof(SChunk));
    new(newChunk) SChunk(element);

    if (m_rootChunk)
    {
        SChunk* lastChunk = m_rootChunk;

        while (lastChunk->m_nextChunk)
        {
            lastChunk = lastChunk->m_nextChunk;
        }

        lastChunk->m_nextChunk = newChunk;
    }
    else
    {
        m_rootChunk = newChunk;
    }

    return newChunk->m_data;
}

template <typename TContainedType>
const TContainedType& CBinaryNodeDataContainer<TContainedType>::operator[](int32_t index) const
{
    BEHAVIAC_ASSERT(m_rootChunk);
    int32_t currentChunkIndex = 0;
    SChunk* currentChunk = m_rootChunk;

    while (currentChunkIndex < index)
    {
        currentChunk = currentChunk->m_nextChunk;
        ++currentChunkIndex;
        BEHAVIAC_ASSERT(currentChunk); // means index is greater than size
    }

    return currentChunk->m_data;
}

template <typename TContainedType>
TContainedType& CBinaryNodeDataContainer<TContainedType>::operator[](int32_t index)
{
    BEHAVIAC_ASSERT(m_rootChunk);
    int32_t currentChunkIndex = 0;
    SChunk* currentChunk = m_rootChunk;

    while (currentChunkIndex < index)
    {
        currentChunk = currentChunk->m_nextChunk;
        ++currentChunkIndex;
        BEHAVIAC_ASSERT(currentChunk); // means index is greater than size
    }

    return currentChunk->m_data;
}


//template <typename TContainedType>
//CBinaryNodeDataContainer<TContainedType>::iterator CBinaryNodeDataContainer<TContainedType>::Erase(CBinaryNodeBaseAllocator* allocator, const Iterator& iter)
//{
//    BEHAVIAC_ASSERT(m_rootChunk);
//    BEHAVIAC_ASSERT(iter->m_chunk);
//    BEHAVIAC_ASSERT(iter->m_index < iter->m_chunk->m_size);
//
//    TODO;
//}
#endif//#if BEHAVIAC_ENABLE_BINARYNODE

#endif //_CORE_BINARYNODE_HPP_
