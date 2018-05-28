#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORFRAMES_H_
#define BEHAVIAC_BEHAVIORTREE_DECORATORFRAMES_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup DecoratorFrames
	* @{ */

	/**
	It returns Running result until it reaches the frame count specified, no matter which
	value its child return. Or return the child's value.
	*/
    class BEHAVIAC_API DecoratorFrames : public DecoratorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFrames, DecoratorNode);

        DecoratorFrames();
		virtual ~DecoratorFrames();

        virtual void load(int version, const char* agentType, const properties_t& properties);
    
		virtual int GetFrames(Agent* pAgent) const;

	private:
		virtual BehaviorTask* createTask() const;

	protected:
		Property*	m_frames_var;

		friend class DecoratorFramesTask;
    };

    class BEHAVIAC_API DecoratorFramesTask : public DecoratorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFramesTask, DecoratorTask);

        DecoratorFramesTask();

    protected:
		virtual ~DecoratorFramesTask();

		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual bool onenter(Agent* pAgent);
        virtual EBTStatus decorate(EBTStatus status);
    
		int GetFrames(Agent* pAgent) const;

	private:
        int	m_start;
		int	m_frames;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORFRAMES_H_