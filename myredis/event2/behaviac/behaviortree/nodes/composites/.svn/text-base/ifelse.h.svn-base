#ifndef BEHAVIAC_BEHAVIORTREE_IFELSE_H_
#define BEHAVIAC_BEHAVIORTREE_IFELSE_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"


namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup IfElse
	* @{ */

	/**
	this node has three children: 'condition' branch, 'if' branch, 'else' branch. first, it executes 
	conditon, until it returns success or failure. if it returns success, it then executes 'if' branch,
	else if it returns failure, it then executes 'else' branch.
	*/
    class BEHAVIAC_API IfElse : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(IfElse, BehaviorNode);

        IfElse();
        virtual ~IfElse();
        virtual void load(int version, const char* agentType, const properties_t& properties);
	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

	private:
		virtual BehaviorTask* createTask() const;

    };
	
    class BEHAVIAC_API IfElseTask : public CompositeTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(IfElseTask, CompositeTask);
        IfElseTask() : CompositeTask()
        {}

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

#endif//BEHAVIAC_BEHAVIORTREE_IFELSE_H_