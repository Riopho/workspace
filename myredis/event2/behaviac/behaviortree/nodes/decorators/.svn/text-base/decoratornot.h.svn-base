#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORNOT_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORNOT_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorNot
	* @{ */

	/**
	Not Node inverts the return value of child. But keeping the Running value unchanged.
	*/
    class BEHAVIAC_API DecoratorNot : public DecoratorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot, DecoratorNode);

        DecoratorNot();
        virtual ~DecoratorNot();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

    class BEHAVIAC_API DecoratorNotTask : public DecoratorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNotTask, DecoratorTask);

        DecoratorNotTask() : DecoratorTask()
        {
        }

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus decorate(EBTStatus status);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORNOT_H_