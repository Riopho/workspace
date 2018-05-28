#ifndef BEHAVIAC_BEHAVIORTREE_REFERENCENODE_H_
#define BEHAVIAC_BEHAVIORTREE_REFERENCENODE_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup ReferencedBehavior
	* @{ */
    class BEHAVIAC_API ReferencedBehavior : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior, BehaviorNode);

        ReferencedBehavior();
        virtual ~ReferencedBehavior();
        virtual void load(int version, const char* agentType, const properties_t& properties);

	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

	private:
		virtual BehaviorTask* createTask() const;

	protected:
		behaviac::string	m_referencedBehaviorPath;

		friend class ReferencedBehaviorTask;
    };

    class BEHAVIAC_API ReferencedBehaviorTask : public SingeChildTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehaviorTask, SingeChildTask);

		ReferencedBehaviorTask();
		~ReferencedBehaviorTask();

		virtual void Init(const BehaviorNode* node);

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);

        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

		virtual bool isContinueTicking() const
		{
			return true;
		}
	};
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_REFERENCENODE_H_