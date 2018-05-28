#ifndef BEHAVIAC_PS_THREAD__INCLUDED
#define BEHAVIAC_PS_THREAD__INCLUDED

#include "behaviac/base/core/compiler.h"

#if BEHAVIAC_COMPILER_MSVC
	typedef unsigned int THREAD_ID_TYPE;
	#define __STDCALL __stdcall
#elif BEHAVIAC_COMPILER_APPLE || BEHAVIAC_COMPILER_ANDROID || BEHAVIAC_COMPILER_GCC_LINUX
	#include <sys/types.h>
	#include <pthread.h>
	typedef pthread_t* THREAD_ID_TYPE;
	#define __STDCALL
#else
	typedef __pthread_t* THREAD_ID_TYPE;
	#define __STDCALL
#endif//BEHAVIAC_COMPILER_MSVC

// Invalid thread Id definition
#define BEHAVIAC_INVALID_TID        0xFFFFFFFF


namespace behaviac
{
	BEHAVIAC_API THREAD_ID_TYPE GetTID();

	namespace thread
	{
		typedef void*		ThreadHandle;
		typedef unsigned int (__STDCALL ThreadFunction)(void* arg);

		BEHAVIAC_API bool IsThreadTerminated(behaviac::thread::ThreadHandle hThread);
		BEHAVIAC_API ThreadHandle CreateAndStartThread(thread::ThreadFunction* function, void* arg, size_t stackSize);
		BEHAVIAC_API void StopThread(ThreadHandle th);
	}//namespace thread
}//namespace behaviac

#endif //BEHAVIAC_PS_THREAD__INCLUDED
