#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORFAILUREUNTIL_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORFAILUREUNTIL_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcount.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorFailureUntil
	* @{ */

	/**
	UntilFailureUntil node always return Failure until it reaches a specified number of count.	
	when reach time exceed the count specified return Success. If the specified number of count 
	is -1, then always return failed.
	*/
    class BEHAVIAC_API DecoratorFailureUntil : public DecoratorCount
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFailureUntil, DecoratorCount);

        DecoratorFailureUntil();
        virtual ~DecoratorFailureUntil();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

	///Returns BT_FAILURE for the specified number of iterations, then returns BT_SUCCESS after that
	class BEHAVIAC_API DecoratorFailureUntilTask : public DecoratorCountTask
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFailureUntilTask, DecoratorCountTask);

        DecoratorFailureUntilTask() : DecoratorCountTask()
        {
        }

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus decorate(EBTStatus status);

		virtual bool NeedRestart() const;
	};
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORFAILUREUNTIL_H_