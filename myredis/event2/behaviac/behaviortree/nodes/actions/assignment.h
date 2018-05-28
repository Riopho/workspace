#ifndef BEHAVIAC_BEHAVIORTREE_GETTER_H_
#define BEHAVIAC_BEHAVIORTREE_GETTER_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/agent/agent.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup Assignment
	* @{ */

	///Assignment
	/**
	Assign a right value to left par or agent property. a right value can be a par or agent property.
	*/
    class BEHAVIAC_API Assignment : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment, BehaviorNode);

		Assignment();
		virtual ~Assignment();
        virtual void load(int version, const char* agentType, const properties_t& properties);

    protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus) 
        { 
            BEHAVIAC_UNUSED_VAR(pAgent); 
            BEHAVIAC_UNUSED_VAR(childStatus); 

            return BT_FAILURE; 
        }

	private:
		virtual BehaviorTask* createTask() const;

    protected:
        Property*			m_opl;
        Property*			m_opr;
		CMethodBase*		m_opr_m;

		friend class AssignmentTask;
    };	

    class BEHAVIAC_API AssignmentTask : public LeafTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(AssignmentTask, LeafTask);

		AssignmentTask();
		virtual ~AssignmentTask();

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual bool isContinueTicking() const;

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_GETTER_H_