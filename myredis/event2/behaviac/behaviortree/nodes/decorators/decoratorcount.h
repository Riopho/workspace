#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORCOUNT_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORCOUNT_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{	
	class BEHAVIAC_API DecoratorCount : public DecoratorNode
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCount, DecoratorNode);

		DecoratorCount();
		virtual ~DecoratorCount();

		virtual void load(int version, const char* agentType, const properties_t& properties);

		virtual int GetCount(Agent* pAgent) const;

	protected:
		Property*	m_count_var;

		friend class DecoratorCountTask;
	};

	class BEHAVIAC_API DecoratorCountTask : public DecoratorTask
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountTask, DecoratorTask);

        DecoratorCountTask();

    protected:
		virtual ~DecoratorCountTask();

		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);

		int GetCount(Agent* pAgent) const;

	protected:
		int			m_n;
	};
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORCOUNT_H_