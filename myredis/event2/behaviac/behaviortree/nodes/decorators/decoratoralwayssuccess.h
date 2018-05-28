#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORALWAYSSUCCESS_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORALWAYSSUCCESS_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorAlwaysSuccess
	* @{ */

	/**
	No matter what child return. DecoratorAlwaysSuccess always return Success. it can only has one child node.
	*/
    class BEHAVIAC_API DecoratorAlwaysSuccess : public DecoratorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysSuccess, DecoratorNode);

        DecoratorAlwaysSuccess();
        virtual ~DecoratorAlwaysSuccess();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

	private:
		virtual BehaviorTask* createTask() const;

    };

    class BEHAVIAC_API DecoratorAlwaysSuccessTask : public DecoratorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysSuccessTask, DecoratorTask);

        DecoratorAlwaysSuccessTask() : DecoratorTask()
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

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORALWAYSSUCCESS_H_