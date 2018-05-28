#ifndef BEHAVIAC_BEHAVIORTREE_SEQUENCESTOCHASTIC_H_
#define BEHAVIAC_BEHAVIORTREE_SEQUENCESTOCHASTIC_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/composites/compositestochastic.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup SequenceStochastic
	* @{ */

	///Execute behaviors in a random order
	/**
	SequenceStochastic tick each of their children in a random order. If a child returns Failure,
	so does the Sequence. If it returns Success, the Sequence will move on to the next child in line
	and return Running.If a child returns Running, so does the Sequence and that same child will be
	ticked again next time the Sequence is ticked.Once the Sequence reaches the end of its child list,
	it returns Success and resets its child index �C meaning the first child in the line will be ticked
	on the next tick of the Sequence.
	*/
    class BEHAVIAC_API SequenceStochastic : public CompositeStochastic
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(SequenceStochastic, CompositeStochastic);
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(SequenceStochastic);

        SequenceStochastic();
        virtual ~SequenceStochastic();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

    class BEHAVIAC_API SequenceStochasticTask : public CompositeStochasticTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(SequenceStochasticTask, CompositeStochasticTask);
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(SequenceStochasticTask);

        SequenceStochasticTask() : CompositeStochasticTask()
        {}

		virtual void addChild(BehaviorTask* pBehavior);
    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_SEQUENCESTOCHASTIC_H_