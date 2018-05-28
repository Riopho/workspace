#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORLOG_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORLOG_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"


namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorLog
	* @{ */

	/**
	Output message specified when it updates.
	*/
    class BEHAVIAC_API DecoratorLog : public DecoratorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLog, DecoratorNode);

        DecoratorLog();
        virtual ~DecoratorLog();
        virtual void load(int version, const char* agentType, const properties_t& properties);

	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

	private:
		virtual BehaviorTask* createTask() const;

	protected:
		behaviac::string m_message;

		friend class DecoratorLogTask;
    };

    class BEHAVIAC_API DecoratorLogTask : public DecoratorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLogTask, DecoratorTask);

        DecoratorLogTask() : DecoratorTask()
        {
        }

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus decorate(EBTStatus status);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORLOG_H_