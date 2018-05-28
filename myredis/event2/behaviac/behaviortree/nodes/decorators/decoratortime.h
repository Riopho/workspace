#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORTIME_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORTIME_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorTime
	* @{ */

	/**
	It returns Running result until it reaches the time limit specified, no matter which
	value its child return. Or return the child's value.
	*/
    class BEHAVIAC_API DecoratorTime : public DecoratorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorTime, DecoratorNode);

		DecoratorTime();
		virtual ~DecoratorTime();
        virtual void load(int version, const char* agentType, const properties_t& properties);
    
		virtual int GetTime(Agent* pAgent) const;

	private:
		virtual BehaviorTask* createTask() const;

	protected:
		Property*	m_time_var;

		friend class DecoratorTimeTask;
    };

    class BEHAVIAC_API DecoratorTimeTask : public DecoratorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorTimeTask, DecoratorTask);

        DecoratorTimeTask();

    protected:
		virtual ~DecoratorTimeTask();

		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);
		
		virtual bool onenter(Agent* pAgent);
        virtual EBTStatus decorate(EBTStatus status);
    
		int GetTime(Agent* pAgent) const;
	private:
        int	m_start;
		int	m_time;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORTIME_H_