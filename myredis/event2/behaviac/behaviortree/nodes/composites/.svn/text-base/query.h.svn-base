#ifndef BEHAVIAC_BEHAVIORTREE_QUERY_H_
#define BEHAVIAC_BEHAVIORTREE_QUERY_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup Query
	* @{ */

	/**
	Sub trees are queried
	*/
    class BEHAVIAC_API Query : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query, BehaviorNode);

		Query();
		virtual ~Query();
		virtual void load(int version, const char* agentType, const properties_t& properties);

	private:
		virtual BehaviorTask* createTask() const;

    protected:
		behaviac::string			m_domain;

        struct Descriptor_t
        {
            Property*	Attribute;
            Property*	Reference;
            float		Weight;

			Descriptor_t() : Attribute(0), Reference(0), Weight(0.0f)
			{}

			Descriptor_t(const Descriptor_t& copy) : Attribute(copy.Attribute->clone()), Reference(copy.Reference->clone()), Weight(copy.Weight)
			{}

			~Descriptor_t()
			{
				BEHAVIAC_DELETE(Attribute);
				BEHAVIAC_DELETE(Reference);
			}

			DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL(Query::Descriptor_t);
        };

		typedef behaviac::vector<Descriptor_t> Descriptors_t;

		Descriptors_t				m_descriptors;

		struct PropertyFinder_t
		{
			PropertyFinder_t& operator=(const PropertyFinder_t&);
			const Descriptor_t& tofind;

			PropertyFinder_t(const Descriptor_t& q) : tofind(q)
			{}

			bool operator()(const BehaviorTree::Descriptor_t& other);
		};

		static const Property* FindProperty(const Descriptor_t& q, const BehaviorTree::Descriptors_t& c);

		const Descriptors_t& GetDescriptors() const;
		void SetDescriptors(const char* descriptors);

		float ComputeSimilarity(const Descriptors_t& q, const BehaviorTree::Descriptors_t& c) const;

		friend class QueryTask;
    };

    class BEHAVIAC_API QueryTask : public SingeChildTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(QueryTask, SingeChildTask);

		QueryTask();
		virtual void Init(const BehaviorNode* node);

    protected:
		virtual ~QueryTask();

		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual bool isContinueTicking() const
		{
			return true;
		}

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

    private:
		virtual bool CheckPredicates(Agent* pAgent);
		bool ReQuery(Agent* pAgent);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_QUERY_H_
