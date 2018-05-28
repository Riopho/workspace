#ifndef _BEHAVIAC_BASE_SOCKETCONNECT_H_
#define _BEHAVIAC_BASE_SOCKETCONNECT_H_

#include "behaviac/base/base.h"
#include "behaviac/base/core/container/string_t.h"

#include "behaviac/base/core/staticassert.h"
#include "behaviac/base/core/thread/wrapper.h"
#include "behaviac/base/core/socket/socketconnect_base.h"

namespace behaviac
{
	namespace Socket
	{
		/**
		@param bBlocking
		if true, block the execution and wait for the connection from the designer
		if false, wait for the connection from the designer but doesn't block the game
		*/
		BEHAVIAC_API bool SetupConnection(bool bBlocking, unsigned short port = 60636);
		BEHAVIAC_API void ShutdownConnection();

		BEHAVIAC_API void SendText(const char* text);
		BEHAVIAC_API void SendWorkspace(const char* text);

		/**
		return true if it successfully reads data
		return false if there is no text read
		*/
		BEHAVIAC_API bool ReadText(behaviac::string& text);

		/**
		flush messsages
		*/
		BEHAVIAC_API void Flush();
	}
}//namespace behaviac

#endif//#if _BEHAVIAC_BASE_SOCKETCONNECT_H_

