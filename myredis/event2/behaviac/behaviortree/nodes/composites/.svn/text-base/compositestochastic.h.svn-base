#ifndef BEHAVIAC_BEHAVIORTREE_COMPOSITESTOCHASTIC_H_
#define BEHAVIAC_BEHAVIORTREE_COMPOSITESTOCHASTIC_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup CompositeStochastic
	* @{ */

	/**
	Base class of Stochastic Nodes
	*/
    class BEHAVIAC_API CompositeStochastic : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(CompositeStochastic, BehaviorNode);

        CompositeStochastic();
        virtual ~CompositeStochastic();
        virtual void load(int version, const char* agentType, const properties_t& properties);

	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

		CMethodBase*				m_method;

		friend class CompositeStochasticTask;
    };	

    class BEHAVIAC_API CompositeStochasticTask : public CompositeTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(CompositeStochasticTask, CompositeTask);
        CompositeStochasticTask();
		virtual ~CompositeStochasticTask();

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus) = 0;

	private:
		void random_child(Agent* pAgent);
	protected:
		behaviac::vector<uint32_t>		m_set;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_COMPOSITESTOCHASTIC_H_