#ifndef BEHAVIAC_BASE_NONCOPYABLE_H_
#define BEHAVIAC_BASE_NONCOPYABLE_H_

#include "behaviac/base/core/config.h"

namespace behaviac
{
    /**
     * Derive from this to stop a class from being able to be
     * copied, either via copy constructor or assignment.
     */
    class BEHAVIAC_API NonCopyable
    {
    protected:
        NonCopyable(void) { }
        ~NonCopyable(void) { }
    private:
        NonCopyable(const NonCopyable&);
        NonCopyable& operator=(const NonCopyable&);
    };
}//namespace behaviac

#endif // BEHAVIAC_BASE_NONCOPYABLE_H_
