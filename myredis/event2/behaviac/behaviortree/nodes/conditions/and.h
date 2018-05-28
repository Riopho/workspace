#ifndef BEHAVIAC_BEHAVIORTREE_CONDITIONS_AND_H_
#define BEHAVIAC_BEHAVIORTREE_CONDITIONS_AND_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/composites/sequence.h"
#include "behaviac/behaviortree/nodes/conditions/conditionbase.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup And
	* @{ */

	/**
	Boolean arithmetical operation &&
	*/
    class BEHAVIAC_API And : public ConditionBase
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(And, ConditionBase);

        And();
        virtual ~And();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

    class BEHAVIAC_API AndTask : public SequenceTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(AndTask, SequenceTask);

        AndTask() : SequenceTask()
        {
        }

        virtual ~AndTask()
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

#endif//BEHAVIAC_BEHAVIORTREE_CONDITIONS_AND_H_