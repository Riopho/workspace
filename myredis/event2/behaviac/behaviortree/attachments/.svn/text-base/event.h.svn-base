#ifndef BEHAVIAC_BEHAVIORTREE_EVENT_H_
#define BEHAVIAC_BEHAVIORTREE_EVENT_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/property/property.h"

namespace behaviac
{
    class BEHAVIAC_API Event : public ConditionBase
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(Event, ConditionBase);

        Event();
        virtual ~Event();
        virtual void load(int version, const char* agentType, const properties_t& properties);

	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

	private:
		virtual BehaviorTask* createTask() const;

	protected:
		CMethodBase*				m_event;

		behaviac::string			m_referencedBehaviorPath;

		TriggerMode					m_triggerMode;
		//an event can be configured to stop being checked if triggered
		bool						m_bTriggeredOnce;

		friend class EventetTask;
    };	
	
    class BEHAVIAC_API EventetTask : public AttachmentTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(EventetTask, AttachmentTask);

        EventetTask();
        virtual ~EventetTask();

		bool TriggeredOnce() const;
		TriggerMode GetTriggerMode() const;

		const char* GetEventName() const;
    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

		virtual bool NeedRestart() const;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_EVENT_H_