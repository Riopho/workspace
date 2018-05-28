#ifndef _BASE_VECTOR_H_
#define _BASE_VECTOR_H_

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"

#include <vector>
#include "behaviac/base/core/memory/stl_allocator.h"

namespace behaviac
{
	template<class _Ty,	class _Ax = behaviac::stl_allocator<_Ty> >
	class vector : public std::vector<_Ty, _Ax>
	{

	};
}//namespace behaviac


#endif //#ifndef _BASE_VECTOR_H_
