#ifndef SCRIPTUTILS_H_
#define SCRIPTUTILS_H_

#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
struct lua_State;

class BEHAVIAC_API CScriptUtils
{
public:
	// Clones the table at 'idx' to the table at the top of the stack.
	static void CloneTable(lua_State* L, int idx, bool deep);
};

#endif//BEHAVIAC_ENABLE_LUA

#endif //SCRIPTUTILS_H_
