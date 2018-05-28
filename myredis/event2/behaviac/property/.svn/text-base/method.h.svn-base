#ifndef BEHAVIAC_METHOD_H_
#define BEHAVIAC_METHOD_H_

#include "behaviac/base/core/delegatetask.h"
#include "behaviac/base/dynamictype.h"
#include "behaviac/base/core/factory.h"

#include "behaviac/behaviortree/behaviortree.h"

#include <string>
#include <map>

namespace behaviac
{
    class BEHAVIAC_API Method : public CDynamicType
    {
    public:
        BEHAVIAC_DECLARE_MEMORY_OPERATORS(Method);
        BEHAVIAC_DECLARE_ROOT_DYNAMIC_TYPE(Method, CDynamicType);

        Method() : m_task(0)
        {
        }

        virtual ~Method()
        {
            BEHAVIAC_DELETE(m_task);
        }

        void run();

        virtual void load(const char* params) = 0;
        virtual void bind(Agent* pAgent) = 0;
        virtual EBTStatus Result() = 0;

        template<typename TAGENT, typename T>
        static bool Register()
        {
            const CStringID& agentClassName = TAGENT::GetClassTypeId();
            Factory(agentClassName).Register<T>();

			return true;
        }

        template<typename TAGENT, typename T>
        static void UnRegister()
        {
            const CStringID& agentClassName = TAGENT::GetClassTypeId();
            Factory(agentClassName).UnRegister<T>();
        }

        static Method* Create(const char* agentClassName, const char* methodClassName);
        //////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////
        template <class R, class C>
        behaviac::AsyncValue<R> bind(C* pthis, R(C::* function_to_bind)())
        {
            typedef behaviac::DelegateTask0<R> DT;
            DT* fn = BEHAVIAC_NEW DT(DT::Delegate(pthis, function_to_bind));
            this->m_task = fn;
            return fn->getResult();
        }

        //template <class C>
        //void bind(C* pthis, void (C::* function_to_bind)())
        //{
        //    typedef behaviac::DelegateTask0<void> DT;
        //    DT* fn = BEHAVIAC_NEW DT(DT::Delegate(pthis, function_to_bind));
        //    this->m_task = fn;
        //}

        template <class R, class P, class C>
        behaviac::AsyncValue<R>  bind(C* pthis, P param, R(C::* function_to_bind)(P param))
        {
            typedef behaviac::DelegateTask1<P, R> DT;
            DT* fn = BEHAVIAC_NEW DT(param, DT::Delegate(pthis, function_to_bind));
            this->m_task = fn;
            return fn->getResult();
        }

        template <class R, class P, class P1, class C>
        behaviac::AsyncValue<R> bind(C* pthis, P param, P1 param1, R(C::* function_to_bind)(P param, P1 param1))
        {
            typedef behaviac::DelegateTask2<P, P1, R> DT;
            DT* fn = BEHAVIAC_NEW DT(param, param1, DT::Delegate(pthis, function_to_bind));
            this->m_task = fn;
            return fn->getResult();
        }

        template <class R, class P, class P1, class P2, class C>
        behaviac::AsyncValue<R>  bind(C* pthis, P param, P1 param1, P2 param2, R(C::* function_to_bind)(P param, P1 param1, P2 param2))
        {
            typedef behaviac::DelegateTask3<P, P1, P2, R> DT;
            DT* fn = BEHAVIAC_NEW DT(param, param1, param2, DT::Delegate(pthis, function_to_bind));
            this->m_task = fn;
            return fn->getResult();
        }

        //////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////
    private:
        behaviac::Task* m_task;
    private:
        typedef behaviac::map<const CStringID, CFactory<Method>*> MethodFactory_t;
        static MethodFactory_t ms_factories;
        static CFactory<Method>& Factory(const CStringID& agentClassName);
    };

    template<class R>
    class TMethod : public Method
    {
    public:
        BEHAVIAC_DECLARE_TEMPLATE_DYNAMIC_TYPE1(TMethod, R, Method)
        TMethod() : Method()
        {
        }
    protected:
        behaviac::AsyncValue<R> m_result;

    };


    template<>
    class TMethod<void> : public Method
    {
    public:
        BEHAVIAC_DECLARE_TEMPLATE_DYNAMIC_TYPE1(TMethod, void, Method)
        TMethod() : Method()
        {
        }
    protected:
    };

}

#endif//BEHAVIAC_METHOD_H_
