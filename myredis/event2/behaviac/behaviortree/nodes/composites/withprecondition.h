#ifndef BEHAVIAC_BEHAVIORTREE_WITHPRECONDITION_H_
#define BEHAVIAC_BEHAVIORTREE_WITHPRECONDITION_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/composites/sequence.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup SelectorStochastic
	* @{ */

	/**
	WithPrecondition is the precondition of SelectorLoop child. must be used in conjunction with SelectorLoop.
	WithPrecondition can return SUCCESS or FAILURE. child would execute when it returns SUCCESS, or not.
	*/
    class BEHAVIAC_API WithPrecondition : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(WithPrecondition, BehaviorNode);

        WithPrecondition();
        virtual ~WithPrecondition();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };
	
    class BEHAVIAC_API WithPreconditionTask : public SequenceTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(WithPreconditionTask, SequenceTask);
        WithPreconditionTask() : SequenceTask()
        {}
		virtual void addChild(BehaviorTask* pBehavior);
    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
    private:
		BehaviorTask* PreconditionNode();
		BehaviorTask* Action();

		friend class SelectorLoopTask;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_WITHPRECONDITION_H_