#ifndef BEHAVIAC_BEHAVIORTREE_CONDITIONS_FALSE_H_
#define BEHAVIAC_BEHAVIORTREE_CONDITIONS_FALSE_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/conditions/conditionbase.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup False
	* @{ */

	/**
	True is a leaf node that always return Failure.
	*/
    class BEHAVIAC_API False : public ConditionBase
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(False, ConditionBase);

        False();
        virtual ~False();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

    class BEHAVIAC_API FalseTask : public ConditionBaseTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(FalseTask, ConditionBaseTask);

        FalseTask() : ConditionBaseTask()
        {
        }

        virtual ~FalseTask()
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

#endif//BEHAVIAC_BEHAVIORTREE_CONDITIONS_FALSE_H_