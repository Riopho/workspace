#ifndef BEHAVIAC_BEHAVIORTREE_IMPULSE_H_
#define BEHAVIAC_BEHAVIORTREE_IMPULSE_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup WaitforSignal
	* @{ */

	/**
	Always return Running until the predicates of WaitforSignal node become true,
	or executing child node and return execution result.
	*/
    class BEHAVIAC_API WaitforSignal : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitforSignal, BehaviorNode);

        WaitforSignal();
        virtual ~WaitforSignal();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

	private:
		virtual BehaviorTask* createTask() const;

    };	

    class BEHAVIAC_API WaitforSignalTask : public SingeChildTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitforSignalTask, SingeChildTask);
        WaitforSignalTask() : SingeChildTask(), m_bTriggered(false)
        {}
	protected:
		virtual ~WaitforSignalTask();

		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual void Init(const BehaviorNode* node);
        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);

		virtual bool CheckPredicates(Agent* pAgent);

        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

		virtual bool isContinueTicking() const
		{
			//return !this->m_bTriggered;
			return true;
		}
	private:
		bool	m_bTriggered;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_IMPULSE_H_