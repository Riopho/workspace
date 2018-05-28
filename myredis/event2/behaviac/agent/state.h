#ifndef _BEHAVIAC_STATE_H_
#define _BEHAVIAC_STATE_H_

#include "behaviac/base/base.h"
#include "behaviac/property/properties.h"

namespace behaviac
{
	class Property;
	class World;
	class BehaviorTreeTask;

	/*! \addtogroup Agent
	* @{
	* \addtogroup State_t
	* @{ */

	/// The State_t class
	/*!
	I don't know what is this!
	*/

	class BEHAVIAC_API State_t
	{
	protected:
		Variables			m_vars;
		BehaviorTreeTask*	m_bt;

		friend class Agent;
		friend class Context;
	public:
		State_t();
		State_t(const State_t& c);
		virtual ~State_t();

		void Clear();

		bool SaveToFile(const char* fileName) const;
		bool LoadFromFile(const char* fileName);

		bool SaveToFile(IFile* file) const;
		virtual bool LoadFromFile(IFile* file);
	protected:
		State_t& operator=(const State_t& c);
	};

	/*! @} */
	/*! @} */

	typedef behaviac::map<const behaviac::string, State_t> States_t;
}


#endif//#ifndef _BEHAVIAC_STATE_H_
