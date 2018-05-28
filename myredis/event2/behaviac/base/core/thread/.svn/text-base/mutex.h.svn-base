#ifndef BEHAVIAC_BASE_THREAD_MUTEX_H_
#define BEHAVIAC_BASE_THREAD_MUTEX_H_
#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"

namespace behaviac
{

    /// used for large wait times.
    class BEHAVIAC_API Mutex
    {
    public:
        Mutex();
        ~Mutex();

        ///Lock the section following the lock.
        void Lock();

        /// Unlock the section following the lock.
        /*! NOTE: It is a programming error to unlock a blocking lock
        twice in a row (i.e. to unlock an already unlocked blocking lock) and may
        result in a crash
        */
        void Unlock();

        ///Try to lock the section following the lock.
        /*! \return true if lock was locked successfully, false otherwise
        */
        bool TryLock();

    private:
        struct MutexImpl;
        struct MutexImpl* _impl;

        static const int kMutexShadowSize = 40;

        uint8_t        m_Shadow[kMutexShadowSize];
    };


	class BEHAVIAC_API ScopedLock
	{
		Mutex& m_mutex_;
		ScopedLock& operator=(ScopedLock& cs);
	public:
		ScopedLock(Mutex& cs) : m_mutex_(cs)
		{
			m_mutex_.Lock();
		}

		~ScopedLock()
		{
			m_mutex_.Unlock();
		}
	};

}//namespace behaviac

#endif //BEHAVIAC_BASE_THREAD_MUTEX_H_
