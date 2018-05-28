#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORCOUNTLIMIT_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORCOUNTLIMIT_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcount.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorCountLimit
	* @{ */

	/**
	DecoratorCountLimit can be set a integer Count limit value. DecoratorCountLimit node tick its child until
	inner count less equal than count limit value. Whether node increase inner count depend on 
	the return value of its child when it updates. if DecorateChildEnds flag is true, node increase count
	only when its child node return value is Success or Failure. The inner count will never reset until
	attachment on the node evaluate true.
	*/
    class BEHAVIAC_API DecoratorCountLimit : public DecoratorCount
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit, DecoratorCount);

        DecoratorCountLimit();
        virtual ~DecoratorCountLimit();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

	private:
		virtual BehaviorTask* createTask() const;

    };

	///enter and tick the child for the specified number of iterations, then it will not enter and tick the child after that
	class BEHAVIAC_API DecoratorCountLimitTask : public DecoratorCountTask
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimitTask, DecoratorCountTask);

        DecoratorCountLimitTask();

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual bool CheckPredicates(Agent* pAgent);
        virtual bool onenter(Agent* pAgent);
        virtual EBTStatus decorate(EBTStatus status);
	private:
		bool m_bInited;
	};
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORCOUNTLIMIT_H_