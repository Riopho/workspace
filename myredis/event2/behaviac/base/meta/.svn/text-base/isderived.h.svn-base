#ifndef _BEHAVIAC_BASE_META_ISDERIVED_H__INCLUDED
#define _BEHAVIAC_BASE_META_ISDERIVED_H__INCLUDED

namespace behaviac
{
    namespace Meta
	{
		namespace Private
		{
			template <typename BASE, typename DERIVED>
			struct TypeResolver
			{
				template <typename TYPE>
				static Yes ResolvedType(DERIVED const volatile *, TYPE);
				static No  ResolvedType(BASE const volatile *, int);
			};

			template<typename BASE, typename DERIVED>
			struct IsDerivedInternal
			{
				struct TypeCaster
				{
					operator BASE const volatile *() const;
					operator DERIVED const volatile *();
				};
	            
				static const bool Result = (sizeof(TypeResolver<BASE,DERIVED>::ResolvedType(TypeCaster(), 0)) == sizeof(Yes));
			};
		}


		/// Lets you determine if a type derives from another one at compile time.
		/*! IsDerived<A, B>::Result will be true if type B inherits from type A.
		 */
		template<typename BASE, typename DERIVED>
		struct IsDerived : public BooleanType<Private::IsDerivedInternal<BASE, DERIVED>::Result> 
		{
		};
	}//namespace Meta
}//namespace behaviac

#endif//_BEHAVIAC_BASE_META_ISDERIVED_H__INCLUDED
