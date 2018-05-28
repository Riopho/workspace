#ifndef BEHAVIAC_TYPETRAITS_H_
#define BEHAVIAC_TYPETRAITS_H_

/*-----------------------------------------------------------------------------
* Macros to abstract the presence of certain compiler intrinsic type traits
-----------------------------------------------------------------------------*/
#if _MSC_VER >= 1400
#define HAS_USER_DESTRUCTOR(T) __has_user_destructor(T)
#define HAS_TRIVIAL_DESTRUCTOR(T) __has_trivial_destructor(T)
#define IS_POD(T) __is_pod(T)
#define IS_ENUM(T) __is_enum(T)
#else
#define HAS_USER_DESTRUCTOR(T) (true)
#define HAS_TRIVIAL_DESTRUCTOR(T) (true)
#define IS_POD(T) (false)
#define IS_ENUM(T) (false)
#endif


/*-----------------------------------------------------------------------------
Type traits similar to TR1 (uses intrinsics supported by VC8)
Should be updated/revisited/discarded when compiler support for tr1 catches up.
-----------------------------------------------------------------------------*/

namespace behaviac
{

	/**
	* TIsFloatType
	*/
	template<typename T> struct TIsFloatType
	{
		enum { Value = false };
	};

	template<> struct TIsFloatType<float>
	{
		enum { Value = true };
	};
	template<> struct TIsFloatType<double>
	{
		enum { Value = true };
	};
	template<> struct TIsFloatType<long double>
	{
		enum { Value = true };
	};

	/**
	* TIsIntegralType
	*/
	template<typename T> struct TIsIntegralType
	{
		enum { Value = false };
	};

	template<> struct TIsIntegralType<unsigned char>
	{
		enum { Value = true };
	};
	template<> struct TIsIntegralType<unsigned short>
	{
		enum { Value = true };
	};
	template<> struct TIsIntegralType<unsigned int>
	{
		enum { Value = true };
	};
	template<> struct TIsIntegralType<unsigned long>
	{
		enum { Value = true };
	};

	template<> struct TIsIntegralType<signed char>
	{
		enum { Value = true };
	};
	template<> struct TIsIntegralType<signed short>
	{
		enum { Value = true };
	};
	template<> struct TIsIntegralType<signed int>
	{
		enum { Value = true };
	};
	template<> struct TIsIntegralType<signed long>
	{
		enum { Value = true };
	};

	template<> struct TIsIntegralType<bool>
	{
		enum { Value = true };
	};
	template<> struct TIsIntegralType<char>
	{
		enum { Value = true };
	};

	// compilers we support define wchar_t as a native type
#if !_MSC_VER || defined(_NATIVE_WCHAR_T_DEFINED)
	template<> struct TIsIntegralType<wchar_t>
	{
		enum { Value = true };
	};
#endif

	// C99, but all compilers we use support it
	template<> struct TIsIntegralType<unsigned long long>
	{
		enum { Value = true };
	};
	template<> struct TIsIntegralType<signed long long>
	{
		enum { Value = true };
	};

	/**
	* TIsArithmeticType
	*/
	template<typename T> struct TIsArithmeticType
	{
		enum { Value = TIsIntegralType<T>::Value || TIsFloatType<T>::Value } ;
	};

	/**
	* TIsPointerType
	*/
	template<typename T> struct TIsPointerType
	{
		enum { Value = false };
	};
	template<typename T> struct TIsPointerType<T*>
	{
		enum { Value = true };
	};
	template<typename T> struct TIsPointerType<const T*>
	{
		enum { Value = true };
	};
	template<typename T> struct TIsPointerType<const T* const>
	{
		enum { Value = true };
	};
	template<typename T> struct TIsPointerType<T* volatile>
	{
		enum { Value = true };
	};
	template<typename T> struct TIsPointerType<T* const volatile>
	{
		enum { Value = true };
	};

	/**
	* TIsVoidType
	*/
	template<typename T> struct TIsVoidType
	{
		enum { Value = false };
	};
	template<> struct TIsVoidType<void>
	{
		enum { Value = true };
	};
	template<> struct TIsVoidType<void const>
	{
		enum { Value = true };
	};
	template<> struct TIsVoidType<void volatile>
	{
		enum { Value = true };
	};
	template<> struct TIsVoidType<void const volatile>
	{
		enum { Value = true };
	};

	template<typename T> struct TIsPODType
	{
		enum { Value = IS_POD(T) || IS_ENUM(T) || TIsArithmeticType<T>::Value || TIsPointerType<T>::Value };
	};

	template<typename T>
	struct TIsFundamentalType
	{
		enum { Value = TIsArithmeticType<T>::Value || TIsVoidType<T>::Value };
	};

	template<typename T> struct THasDestructor
	{
		enum { value = ((!HAS_TRIVIAL_DESTRUCTOR(T) && !TIsPODType<T>::Value) || HAS_USER_DESTRUCTOR(T)) };
	};

}

#endif//BEHAVIAC_TYPETRAITS_H_

