#ifndef BEHAVIAC_BEHAVIORTREE_WAIT_H_
#define BEHAVIAC_BEHAVIORTREE_WAIT_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup Wait
	* @{ */

	/**
	Wait for the specified milliseconds. always return Running until time over.
	*/	
    class BEHAVIAC_API Wait : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(Wait, BehaviorNode);

		Wait();
		virtual ~Wait();
        virtual void load(int version, const char* agentType, const properties_t& properties);

		virtual float GetTime(Agent* pAgent) const;

	private:
		virtual BehaviorTask* createTask() const;

    protected:
		bool		m_ignoreTimeScale;
		Property*	m_time_var;

		friend class WaitTask;
    };	

    class BEHAVIAC_API WaitTask : public LeafTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitTask, LeafTask);

        WaitTask();

    protected:
		virtual ~WaitTask();

		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

		bool GetIgnoreTimeScale() const;
		float	GetTime(Agent* pAgent) const;

        float	m_start;
		float	m_time;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_WAIT_H_