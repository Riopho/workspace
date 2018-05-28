#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORSUCCESSUNTIL_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORSUCCESSUNTIL_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcount.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorSuccessUntil
	* @{ */

	/**
	UntilFailureUntil node always return Success until it reaches a specified number of count.
	when reach time exceed the count specified return Failure. If the specified number of count
	is -1, then always return Success.
	*/
    class BEHAVIAC_API DecoratorSuccessUntil : public DecoratorCount
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorSuccessUntil, DecoratorCount);

        DecoratorSuccessUntil();
        virtual ~DecoratorSuccessUntil();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

	///Returns BT_SUCCESS for the specified number of iterations, then returns BT_FAILURE after that
	class BEHAVIAC_API DecoratorSuccessUntilTask : public DecoratorCountTask
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorSuccessUntilTask, DecoratorCountTask);

        DecoratorSuccessUntilTask() : DecoratorCountTask()
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

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORSUCCESSUNTIL_H_