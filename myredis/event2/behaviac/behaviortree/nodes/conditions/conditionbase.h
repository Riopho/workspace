#ifndef BEHAVIAC_BEHAVIORTREE_CONDITIONBASE_H_
#define BEHAVIAC_BEHAVIORTREE_CONDITIONBASE_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup ConditionBase
	* @{ */
    class BEHAVIAC_API ConditionBase : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(ConditionBase, BehaviorNode);

        ConditionBase();
        virtual ~ConditionBase();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
    };

    // ============================================================================
    class BEHAVIAC_API ConditionBaseTask : public LeafTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(ConditionBaseTask, LeafTask);

		ConditionBaseTask();
		virtual ~ConditionBaseTask();
    protected:
		virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
    private:
		virtual bool isContinueTicking() const;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_CONDITIONBASE_H_
