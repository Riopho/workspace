#ifndef BEHAVIAC_BEHAVIORTREE_SELECTORSTOCHASTIC_H_
#define BEHAVIAC_BEHAVIORTREE_SELECTORSTOCHASTIC_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/behaviortree/nodes/composites/compositestochastic.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup SelectorStochastic
	* @{ */

	/**
	the Selector runs the children from the first sequentially until the child which returns success.
	for SelectorStochastic, the children are not sequentially selected, instead it is selected stochasticly.

	for example: the children might be [0, 1, 2, 3, 4]
	Selector always select the child by the order of 0, 1, 2, 3, 4
	while SelectorStochastic, sometime, it is [4, 2, 0, 1, 3], sometime, it is [2, 3, 0, 4, 1], etc.
	*/
    class BEHAVIAC_API SelectorStochastic : public CompositeStochastic
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorStochastic, CompositeStochastic);

        SelectorStochastic();
        virtual ~SelectorStochastic();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;

    };

    class BEHAVIAC_API SelectorStochasticTask : public CompositeStochasticTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorStochasticTask, CompositeStochasticTask);
        SelectorStochasticTask() : CompositeStochasticTask()
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

#endif//BEHAVIAC_BEHAVIORTREE_SELECTORSTOCHASTIC_H_