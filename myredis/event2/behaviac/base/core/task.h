#ifndef BEHAVIAC_TASK_H_
#define BEHAVIAC_TASK_H_

#include "behaviac/base/core/logging/log.h"
#include "behaviac/base/core/fastdelegates/fastdelegate.h"

namespace behaviac
{
    /**
     * The base class for all tasks.
     */
    class Task
    {
    public:
        Task()
        {}

        virtual ~Task() {};
        virtual void run() = 0;
        virtual bool isSync() const
        {
            return false;
        }
    };
}//namespace behaviac

#endif // BEHAVIAC_TASK_H_
