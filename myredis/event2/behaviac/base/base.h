#ifndef BEHAVIAC_BASE_H_
#define BEHAVIAC_BASE_H_

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/compiler.h"
#include "behaviac/base/core/assert_t.h"

#include "behaviac/base/core/memory/memory.h"

#include "behaviac/base/core/string/stringid.h"
#include "behaviac/base/core/logging/log.h"

#include "behaviac/base/core/container/string_t.h"
#include "behaviac/base/core/container/vector_t.h"
#include "behaviac/base/core/container/map_t.h"

#include "behaviac/base/core/version.h"

#include <functional>
#include <algorithm>

namespace behaviac
{
	/**
	return version behaviac::string
	*/
	BEHAVIAC_API const char* VersionString();

	/**
	it returns false if the dll's version is not compatible with 'versionString'
	@param versionString
	to use the default one, don't change it unless you know what you are doing.
	*/
	BEHAVIAC_API bool Start(const char* versionString = BEHAVIAC_VERSION_STRING);
	BEHAVIAC_API void Stop();

	BEHAVIAC_API void SetMainThread();
	BEHAVIAC_API bool IsMainThread();

	typedef void (*BreakpointPromptHandler_fn)(const char* breakPointDesc);
	BEHAVIAC_API void SetBreakpointPromptHandler(BreakpointPromptHandler_fn fn);

	BEHAVIAC_API BreakpointPromptHandler_fn GetBreakpointPromptHandler();

}//namespace behaviac

#define ASSERT_MAIN_THREAD()  BEHAVIAC_ASSERT(behaviac::IsMainThread(), "called not in the main thread")

#endif // BEHAVIAC_BASE_H_
