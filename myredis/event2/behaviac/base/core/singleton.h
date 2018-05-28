#ifndef _BEHAVIAC_BASE_CORE_SINGLETON_H_
#define _BEHAVIAC_BASE_CORE_SINGLETON_H_

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"

#include "behaviac/base/core/memory/memory.h"

/*
class CSequenceManager
{
	BEHAVIAC_DELCARE_SINGLETON(CSequenceManager);
	//...
};

in cpp:
BEHAVIAC_IMPLEMNT_SINGLETON(CSequenceManager);
*/

#define BEHAVIAC_DELCARE_SINGLETON(T)										\
	protected:																\
		static T* ms_singleton;												\
		static T* GetInstance_();											\
		static void SetInstance_(T*);										\
		T(const T&);														\
		const T& operator=(const T&);										\
	public:																	\
		static inline T* GetInstance()										\
		{																	\
			if (!GetInstance_())											\
			{																\
				CreateInstance();											\
			}																\
																			\
			return GetInstance_();											\
		}																	\
																			\
		static T* CreateInstance()											\
		{																	\
			if (!GetInstance_())											\
			{																\
				T* p = BEHAVIAC_NEW T;										\
				SetInstance_(p);											\
			}																\
																			\
			return GetInstance_();											\
		}																	\
																			\
		static void DestroyInstance()										\
		{																	\
			T* p = GetInstance_();											\
			if (p)															\
			{																\
				BEHAVIAC_DELETE(p);											\
				SetInstance_(0);											\
			}																\
		}																	


#define BEHAVIAC_IMPLEMNT_SINGLETON(T)				\
	T* T::ms_singleton = 0;							\
	T* T::GetInstance_()							\
	{												\
		return ms_singleton;						\
	}												\
	void T::SetInstance_(T* p)						\
	{												\
		ms_singleton = p;							\
	}


#endif//_BEHAVIAC_BASE_CORE_SINGLETON_H_
