#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORLOOP_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORLOOP_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcount.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorLoop
	* @{ */

	/**
	DecoratorLoop can be set a integer Count value. It increases inner count value when it updates.
	It always return Running until inner count less equal than integer Count value. Or returns the child
	value. It always return Running when the count limit equal to -1.
	*/
    class BEHAVIAC_API DecoratorLoop : public DecoratorCount
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop, DecoratorCount);

        DecoratorLoop();
        virtual ~DecoratorLoop();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

	///Returns BT_FAILURE for the specified number of iterations, then returns BT_SUCCESS after that
    class BEHAVIAC_API DecoratorLoopTask : public DecoratorCountTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoopTask, DecoratorCountTask);

		DecoratorLoopTask();
		virtual ~DecoratorLoopTask();

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus decorate(EBTStatus status);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORLOOP_H_