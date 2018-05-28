#ifndef BEHAVIAC_BASE_CORE_CONFIG_H_
#define BEHAVIAC_BASE_CORE_CONFIG_H_

#include "behaviac/base/core/staticassert.h"
#include "behaviac/base/core/compiler.h"

#include "behaviac/base/core/types.h"

#if defined(_MSC_VER) && _MSC_VER < 1600 /* MSVC2010 */
#include "msc_stdint.h"
#else
#include <stdint.h>
#endif


#if BEHAVIAC_COMPILER_MSVC
	//warning C4275: non dll-interface class 'stdext::exception' used as base for dll-interface class 'std::bad_cast'
	#pragma warning(disable : 4275)

	//warning C4530: C++ exception handler used, but unwind semantics are not enabled. Specify /EHsc
	#pragma warning(disable : 4530)

	//warning C4251: 'behaviac::VariableRegistry::m_proxyHolders' : class 'behaviac::vector<T>' needs to have dll-interface to be used
	//by clients of class 'behaviac::VariableRegistry'
	#pragma warning(disable : 4251)

	//unreferenced formal parameter
	#pragma warning(disable : 4100)

	#pragma warning(disable : 4505) // unreferenced local function has been removed
	
	#pragma warning(disable : 4127) // conditional expression is constant

	//warning C4702: unreachable code
	#pragma warning(disable : 4702)

#endif//BEHAVIAC_COMPILER_MSVC


//please don't use the following macros in the public header files unless you know what you are doing.
//otherwise, it might be causing uncompatible layout for types

#define BEHAVIAC_ENABLE_LUA				0
#define BEHAVIAC_ENABLE_CONSOLE			0
#define BEHAVIAC_ENABLE_NETWORKD		0
#define BEHAVIAC_ENABLE_BINARYNODE		0


#if (defined(_DEBUG) || defined(DEBUG) || defined(BEHAVIAC_CFG_PROFILE))
	//developement version
#else
	#ifndef BEHAVIAC_RELEASE
		#define BEHAVIAC_RELEASE	1
	#endif//BEHAVIAC_RELEASE
#endif//

#if !defined(BEHAVIAC_RELEASE)
	#define BEHAVIAC_ENABLE_HOTRELOAD	1
	#define BEHAVIAC_ENABLE_PROFILING	0
#endif//BEHAVIAC_RELEASE

#endif//BEHAVIAC_BASE_CORE_CONFIG_H_
