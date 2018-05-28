#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORALWAYSRUNNING_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORALWAYSRUNNING_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorAlwaysRunning
	* @{ */

	/**
	No matter what child return. DecoratorAlwaysRunning always return Running. it can only has one child node.
	*/
    class BEHAVIAC_API DecoratorAlwaysRunning : public DecoratorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysRunning, DecoratorNode);

        DecoratorAlwaysRunning();
        virtual ~DecoratorAlwaysRunning();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

    class BEHAVIAC_API DecoratorAlwaysRunningTask : public DecoratorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysRunningTask, DecoratorTask);

        DecoratorAlwaysRunningTask() : DecoratorTask()
        {
        }

		virtual void addChild(BehaviorTask* pBehavior);
    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus decorate(EBTStatus status);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORALWAYSRUNNING_H_