#ifndef BEHAVIAC_BEHAVIORTREE_SELECTORLOOP_H_
#define BEHAVIAC_BEHAVIORTREE_SELECTORLOOP_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup SelectorLoop
	* @{ */

	/**
	Behavives similarly to SelectorTask, i.e. executing chidren until the first successful one. 
	however, in the following ticks, it constantly monitors the higher priority nodes.if any 
	one's precondtion node returns success, it picks it and execute it, and before executing,
	it first cleans up the original executing one. all its children are WithPreconditionTask 
	or its derivatives.
	*/
    class BEHAVIAC_API SelectorLoop : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorLoop, BehaviorNode);

        SelectorLoop();
        virtual ~SelectorLoop();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
	private:
		virtual BehaviorTask* createTask() const;
	//protected:
	//	Nodes*		m_preconditions;
	//	Nodes*		m_actions;
    };
   
    class BEHAVIAC_API SelectorLoopTask : public CompositeTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorLoopTask, CompositeTask);
        SelectorLoopTask();
		virtual ~SelectorLoopTask();

		virtual void Init(const BehaviorNode* node);
		virtual void addChild(BehaviorTask* pBehavior);
    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
	private:
		virtual bool isContinueTicking() const
		{
			return true;
		}
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_SELECTORLOOP_H_