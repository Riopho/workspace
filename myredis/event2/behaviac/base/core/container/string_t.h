#ifndef _BASE_STRING_H_
#define _BASE_STRING_H_

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"

#include <string>
#include <algorithm>
#include "behaviac/base/core/memory/stl_allocator.h"

namespace behaviac
{
	//typedef std::string string;
	//typedef std::wstring wstring;

	//template<class _Elem>
	//class basic_string_t : public std::basic_string<_Elem, std::char_traits<_Elem>, std::allocator<_Elem> >
	//{

	//};

	//typedef basic_string_t<char, std::char_traits<char>, std::allocator<char> > string;
	//typedef basic_string_t<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstring;
	typedef std::basic_string<char, std::char_traits<char>, behaviac::stl_allocator<char> > string;
	typedef std::basic_string<wchar_t, std::char_traits<wchar_t>, behaviac::stl_allocator<wchar_t> > wstring;
}

inline behaviac::string make_lower(const behaviac::string& src)
{
	behaviac::string dst = src;
	std::transform(dst.begin(), dst.end(), dst.begin(), ::tolower);

	return dst;
}

inline behaviac::string make_upper(const behaviac::string& src)
{
	behaviac::string dst = src;
	std::transform(dst.begin(), dst.end(), dst.begin(), ::toupper);

	return dst;
}

#endif //#ifndef _BASE_STRING_H_
