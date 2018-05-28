#ifndef BEHAVIAC_BEHAVIORTREE_CONDITIONS_OR_H_
#define BEHAVIAC_BEHAVIORTREE_CONDITIONS_OR_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/composites/selector.h"
#include "behaviac/behaviortree/nodes/conditions/conditionbase.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup Or
	* @{ */

	/**
	Boolean arithmetical operation ||
	*/
    class BEHAVIAC_API Or : public ConditionBase
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(Or, ConditionBase);

        Or();
        virtual ~Or();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

    class BEHAVIAC_API OrTask : public SelectorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(OrTask, SelectorTask);

        OrTask() : SelectorTask()
        {
        }

        virtual ~OrTask()
        {
        }

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_CONDITIONS_OR_H_