#ifndef BEHAVIAC_DELEGATETASK_H_
#define BEHAVIAC_DELEGATETASK_H_

#include "behaviac/base/core/fastdelegates/fastdelegate.h"
#include "behaviac/base/core/thread/asyncvalue.h"
#include "behaviac/base/core/task.h"

namespace behaviac
{
    /**
     * Task that calls a function that doesn't take any parameters
     */
    template<typename RetType> class DelegateTask0 : public Task
    {
    public:
        typedef fastdelegate::FastDelegate0<RetType> Delegate;
        typedef behaviac::AsyncValue<RetType> Result;
    protected:
        Delegate    mDelegate;
        Result      mResult;
    public:
        DelegateTask0(Delegate fn): mDelegate(fn) {}
        Result getResult()
        {
            return mResult;
        }
        virtual void run()
        {
            mResult = mDelegate();
        }
    };

    /**
     * Task that calls a function without a return value or parameters
     */
    template<> class DelegateTask0<void> : public Task
    {
    public:
        typedef fastdelegate::FastDelegate0<void> Delegate;
        typedef behaviac::AsyncValue<void> Result;
    protected:
        Delegate	mDelegate;
        Result      mResult;
    public:
        DelegateTask0(Delegate fn): mDelegate(fn) { }
        Result getResult()
        {
            return mResult;
        }
        virtual void run()
        {
            mDelegate();
        }
    };

    /**
     * Task that calls a function with 1 parameter
     */
    template<typename Param1, typename RetType>
    class DelegateTask1 : public Task
    {
    public:
        typedef fastdelegate::FastDelegate1<Param1, RetType> Delegate;
        typedef behaviac::AsyncValue<RetType> Result;
    protected:
        Delegate    mDelegate;
        Param1      mParam1;
        Result      mResult;
    public:
        DelegateTask1(Param1 p1, Delegate fn): mDelegate(fn), mParam1(p1) { }
        Result getResult()
        {
            return mResult;
        }
        virtual void run()
        {
            mResult = mDelegate(mParam1);
        }
    };

    /**
     * Task that calls a function with 1 parameter and without a return value
     */
    template<typename Param1>
    class DelegateTask1<Param1, void> : public Task
    {
    public:
        typedef fastdelegate::FastDelegate1<Param1, void> Delegate;
        typedef behaviac::AsyncValue<void> Result;
    protected:
        Delegate    mDelegate;
        Param1      mParam1;
        Result      mResult;
    public:
        DelegateTask1(Param1 p1, Delegate fn): mDelegate(fn), mParam1(p1) { }
        Result getResult()
        {
            return mResult;
        }
        virtual void run()
        {
            mDelegate(mParam1);
        }
    };

    /**
     * Task that calls a function with 2 parameters
     */
    template<typename Param1, typename Param2, typename RetType>
    class DelegateTask2 : public Task
    {
    public:
        typedef fastdelegate::FastDelegate2<Param1, Param2, RetType> Delegate;
        typedef behaviac::AsyncValue<RetType> Result;
    protected:
        Delegate    mDelegate;
        Param1      mParam1;
        Param2      mParam2;
        Result      mResult;
    public:
        DelegateTask2(Param1 p1, Param2 p2, Delegate fn): mDelegate(fn),
            mParam1(p1), mParam2(p2) { }
        Result getResult()
        {
            return mResult;
        }
        virtual void run()
        {
            mResult = mDelegate(mParam1, mParam2);
        }
    };

    /**
     * Task that calls a function with 2 parameters and without a return value
     */
    template<typename Param1, typename Param2>
    class DelegateTask2<Param1, Param2, void> : public Task
    {
    public:
        typedef fastdelegate::FastDelegate2<Param1, Param2, void> Delegate;
        typedef behaviac::AsyncValue<void> Result;
    protected:
        Delegate    mDelegate;
        Param1      mParam1;
        Param2      mParam2;
        Result      mResult;
    public:
        DelegateTask2(Param1 p1, Param2 p2, Delegate fn): mDelegate(fn),
            mParam1(p1), mParam2(p2) { }
        Result getResult()
        {
            return mResult;
        }
        virtual void run()
        {
            mDelegate(mParam1, mParam2);
        }
    };

    /**
     * Task that calls a function with 3 parameters
     */
    template < typename Param1, typename Param2, typename Param3,
             typename RetType >
    class DelegateTask3 : public Task
    {
    public:
        typedef fastdelegate::FastDelegate3 < Param1, Param2, Param3,
                RetType > Delegate;
        typedef behaviac::AsyncValue<RetType> Result;
    protected:
        Delegate    mDelegate;
        Param1      mParam1;
        Param2      mParam2;
        Param3      mParam3;
        Result      mResult;
    public:
        DelegateTask3(Param1 p1, Param2 p2, Param3 p3, Delegate fn):
            mDelegate(fn), mParam1(p1), mParam2(p2), mParam3(p3) { }
        Result getResult()
        {
            return mResult;
        }
        virtual void run()
        {
            mResult = mDelegate(mParam1, mParam2, mParam3);
        }
    };

    /**
     * Task that calls a function with 3 parameters and without a return value
     */
    template<typename Param1, typename Param2, typename Param3>
    class DelegateTask3<Param1, Param2, Param3, void> : public Task
    {
    public:
        typedef fastdelegate::FastDelegate3<Param1, Param2, Param3, void> Delegate;
        typedef behaviac::AsyncValue<void> Result;
    protected:
        Delegate    mDelegate;
        Param1      mParam1;
        Param2      mParam2;
        Param3      mParam3;
        Result      mResult;
    public:
        DelegateTask3(Param1 p1, Param2 p2, Param3 p3, Delegate fn):
            mDelegate(fn), mParam1(p1), mParam2(p2), mParam3(p3) { }
        Result getResult()
        {
            return mResult;
        }
        virtual void run()
        {
            mDelegate(mParam1, mParam2, mParam3);
        }
    };
}//namespace behaviac

#endif // BEHAVIAC_DELEGATETASK_H_
