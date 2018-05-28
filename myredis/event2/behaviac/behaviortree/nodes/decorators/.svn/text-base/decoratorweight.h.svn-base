#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORWEIGHT_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORWEIGHT_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorWeight
	* @{ */

	/**
	Specified the weight value of SelectorProbability child node.
	*/
    class BEHAVIAC_API DecoratorWeight : public DecoratorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight, DecoratorNode);

		DecoratorWeight();
		virtual ~DecoratorWeight();
		virtual void load(int version, const char* agentType, const properties_t& properties);

		virtual int GetWeight(behaviac::Agent* pAgent) const;

	private:
		virtual BehaviorTask* createTask() const;

	protected:
		Property*	m_weight_var;

		friend class DecoratorWeightTask;
    };

    class BEHAVIAC_API DecoratorWeightTask : public DecoratorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeightTask, DecoratorTask);

        DecoratorWeightTask() : DecoratorTask()
        {
        }

		int GetWeight(Agent* pAgent) const;

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus decorate(EBTStatus status);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORWEIGHT_H_