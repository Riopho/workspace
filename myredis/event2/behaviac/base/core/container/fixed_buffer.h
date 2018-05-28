#ifndef _BEHAVIAC_BASE_CONTAINER_FIXEDBUFFER_H_
#define _BEHAVIAC_BASE_CONTAINER_FIXEDBUFFER_H_

#include "behaviac/base/core/assert_t.h"

/**
a buffer with kLength and each item is of type T.
no real memory alloc/free in usage
*/
template<typename T, int kLength>
class fixed_buffer
{
    int m_nextFree;
    int m_used;
    T m_buffer[kLength];

public:
    fixed_buffer() : m_nextFree(0), m_used(0)
    {
        BEHAVIAC_ASSERT(sizeof(T) >= sizeof(uint32_t));
        *(int*)&m_buffer[kLength - 1] = -1;

        for (int i = kLength - 2; i >= 0; --i)
        {
            *(int*)&m_buffer[i] = i + 1;
        }
    }

    int used() const
    {
        return m_used;
    }

    T* get()
    {
        if (m_nextFree != -1)
        {
            int freeIndex = m_nextFree;
            m_nextFree = *(int*)&m_buffer[m_nextFree];
            m_used++;
            return &m_buffer[freeIndex];
        }

        return 0;
    }

    void put(T* d)
    {
        int index = d - this->m_buffer;
        BEHAVIAC_ASSERT(index >= 0 && index < kLength);
        *(int*)d = m_nextFree;
        m_nextFree = index;
        BEHAVIAC_ASSERT(m_used <= kLength && m_used > 0);
        m_used--;
    }
};

#endif//_BEHAVIAC_BASE_CONTAINER_FIXEDBUFFER_H_
