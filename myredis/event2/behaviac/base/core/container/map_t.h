#ifndef _BASE_MAP_H_
#define _BASE_MAP_H_

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"

#include <map>
#include "behaviac/base/core/memory/stl_allocator.h"

namespace behaviac
{
	template<class _Kty, class _Ty,	
	class _Pr = std::less<_Kty>,	
	class _Alloc = behaviac::stl_allocator<std::pair<const _Kty, _Ty> > >
	class map : public std::map<_Kty, _Ty, _Pr, _Alloc>
	{

	};
}//namespace behaviac

#endif //#ifndef _BASE_MAP_H_
