#ifndef BEHAVIAC_SPSCQUEUE_H_
#define BEHAVIAC_SPSCQUEUE_H_

namespace behaviac
{

    template<typename T, uint32_t TSize>
    struct SPSCQueue
    {
    public:
        SPSCQueue() :
            m_pushIndex(0),
            m_popIndex(0)
        {
        }

        uint32_t Size() const
        {
            const uint32_t popIndex = Load_Acquire(m_popIndex);
            const uint32_t pushIndex = Load_Acquire(m_pushIndex);
            return pushIndex - popIndex;
        }
        bool IsFull() const
        {
            const uint32_t c = Size();
            return c == TSize;
        }

        void Push(const T& t)
        {
            uint32_t pushIndex = Load_Relaxed(m_pushIndex) ;
            const uint32_t index = (pushIndex & (TSize - 1));
            m_buffer[index] = t;
            Store_Release(m_pushIndex, pushIndex + 1);
        }

        // NULL if queue is empty.
        T* Peek()
        {
            const uint32_t popIndex = Load_Relaxed(m_popIndex);
            const uint32_t pushIndex = Load_Acquire(m_pushIndex);

            if (pushIndex <= popIndex)
            {
                return NULL;
            }

            const uint32_t index = popIndex & (TSize - 1);
            return &m_buffer[index];
        }
        void Pop() // use in conjuction with Peek()
        {
            const uint32_t popIndex = Load_Relaxed(m_popIndex);
            Store_Release(m_popIndex, popIndex + 1);
        }

    private:
        SPSCQueue(const SPSCQueue&);
        SPSCQueue& operator=(const SPSCQueue&);

        static const int kCacheLineSize = 32;
        typedef uint8_t	PadBuffer[kCacheLineSize - 4];

        uint32_t		m_pushIndex;
        PadBuffer		m_padding0;
        uint32_t		m_popIndex;
        PadBuffer		m_padding1;
        T				m_buffer[TSize];
    };

} // behaviac

#endif//BEHAVIAC_SPSCQUEUE_H_
