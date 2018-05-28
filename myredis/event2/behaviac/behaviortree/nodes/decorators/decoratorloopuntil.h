#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORRUNUNTIL_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORRUNUNTIL_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcount.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorLoopUntil
	* @{ */

	/**
	DecoratorLoopUntil can be set two conditions, loop count 'C' and a return value 'R'.
	if current update count less equal than 'C' and child return value not equal to 'R',
	it returns Running. Or returns child value.
	*/
	class BEHAVIAC_API DecoratorLoopUntil: public DecoratorCount
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoopUntil, DecoratorCount);

		DecoratorLoopUntil();
		virtual ~DecoratorLoopUntil();

		virtual void load(int version, const char* agentType, const properties_t& properties);

	private:
		virtual BehaviorTask* createTask() const;

	protected:
		bool m_until;

		friend class DecoratorLoopUntilTask;
	};

	///Returns BT_RUNNING until the child returns BT_SUCCESS. if the child returns BT_FAILURE, it still returns BT_RUNNING
	/**
	however, if m_until is false, the checking condition is inverted.
	i.e. it Returns BT_RUNNING until the child returns BT_FAILURE. if the child returns BT_SUCCESS, it still returns BT_RUNNING
	*/
	class BEHAVIAC_API DecoratorLoopUntilTask: public DecoratorCountTask
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoopUntilTask, DecoratorCountTask);

        DecoratorLoopUntilTask() : DecoratorCountTask()
        {
        }

    protected:
		virtual bool NeedRestart() const;
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus decorate(EBTStatus status);
	};
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORRUNUNTIL_H_