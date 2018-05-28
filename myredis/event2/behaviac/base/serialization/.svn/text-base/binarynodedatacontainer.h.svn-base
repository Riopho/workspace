#ifndef _CORE_BINARYNODEDATACONTAINER_H_
#define _CORE_BINARYNODEDATACONTAINER_H_

#if BEHAVIAC_ENABLE_BINARYNODE
class CBinaryNodeBaseAllocator;


template <typename TContainedType>
class CBinaryNodeDataContainer
{
private:
    struct SChunk;

public:
    CBinaryNodeDataContainer();
    ~CBinaryNodeDataContainer();

    struct const_iterator
    {
        const_iterator() {}
        const_iterator(SChunk* chunk);

        bool operator!=(const const_iterator& iter) const;
        bool operator==(const const_iterator& iter) const;

        const_iterator& operator++() // pre-increment
        {
            BEHAVIAC_ASSERT(m_chunk);
            m_chunk = m_chunk->m_nextChunk;
            return *this;
        }

        const TContainedType& operator*() const;
        const TContainedType* operator->() const;

    protected:
        SChunk* m_chunk;
    };

    struct iterator : public const_iterator
    {
        iterator() : const_iterator() {}
        iterator(SChunk* chunk) : const_iterator(chunk) {}

        iterator& operator++() // pre-increment
        {
            BEHAVIAC_ASSERT(m_chunk);
            m_chunk = m_chunk->m_nextChunk;
            return *this;
        }

        TContainedType& operator*() const
        {
            BEHAVIAC_ASSERT(m_chunk);
            return m_chunk->m_data;
        }

        TContainedType* operator->() const
        {
            BEHAVIAC_ASSERT(m_chunk);
            return &m_chunk->m_data;
        }

    protected:
        using const_iterator::m_chunk;
    };

    void clear(CBinaryNodeBaseAllocator* allocator);
    int32_t size() const;
    int32_t GetMemUsage() const;

    TContainedType& push_back(CBinaryNodeBaseAllocator* allocator, const TContainedType& element);

    const TContainedType& operator[](int32_t index) const;
    TContainedType& operator[](int32_t index);

    const_iterator begin() const
    {
        return const_iterator(m_rootChunk);
    }

    iterator begin()
    {
        return iterator(m_rootChunk);
    }

    const_iterator end() const
    {
        return const_iterator(NULL);
    }
    iterator end()
    {
        return iterator(NULL);
    }

    // Not implemented
    //iterator Erase(CBinaryNodeBaseAllocator* allocator, const iterator& iter);

private:
    SChunk* m_rootChunk;
};
#endif//#if BEHAVIAC_ENABLE_BINARYNODE

#endif //_CORE_BINARYNODEDATACONTAINER_H_
