#ifndef BEHAVIAC_BEHAVIORTREE_WAITFRAMES_H_
#define BEHAVIAC_BEHAVIORTREE_WAITFRAMES_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup WaitFrames
	* @{ */

	/**
	Wait for the specified frames. always return Running until exceeds count.
	*/
    class BEHAVIAC_API WaitFrames : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitFrames, BehaviorNode);

		WaitFrames();
		virtual ~WaitFrames();
        virtual void load(int version, const char* agentType, const properties_t& properties);

		virtual int GetFrames(Agent* pAgent) const;

	private:
		virtual BehaviorTask* createTask() const;

    protected:
		Property*		m_frames_var;
		CMethodBase*	m_frames_method;

		friend class WaitFramesTask;
    };	

    class BEHAVIAC_API WaitFramesTask : public LeafTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitFramesTask, LeafTask);

        WaitFramesTask();

    protected:
		virtual ~WaitFramesTask();

		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

		int GetFrames(Agent* pAgent) const;

    private:
        int		m_start;
		int		m_frames;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_WAITFRAMES_H_