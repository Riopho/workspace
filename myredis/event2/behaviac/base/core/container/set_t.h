#ifndef _BASE_SET_H_
#define _BASE_SET_H_

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"

#include <set>
#include "behaviac/base/core/memory/stl_allocator.h"

namespace behaviac
{
	template<class _Kty,
	class _Pr = std::less<_Kty>,
	class _Alloc = behaviac::stl_allocator<_Kty> >
	class set_t : public std::set<_Kty, _Pr, _Alloc>
	{

	};
}//namespace behaviac

#endif //#ifndef _BASE_SET_H_
