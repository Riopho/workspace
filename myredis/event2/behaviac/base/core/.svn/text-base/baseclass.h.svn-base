#ifndef BEHAVIAC_BASE_BASECLASS_H_
#define BEHAVIAC_BASE_BASECLASS_H_

namespace behaviac
{

    /// BaseClass is the class from which all TAG objects derivate
    class BEHAVIAC_API BaseClass
    {
    public:
        BaseClass() {}

    private:

    };

    /// All cloneable object must inherit from this class. It allows to duplicate inherited object when we only know it's base class.
    class BEHAVIAC_API Cloneable : public BaseClass
    {
    public:
        virtual ~Cloneable() {}

        virtual Cloneable* Clone() const = 0;
        virtual void Destroy() = 0;
    };

    /// Macro that will assure the copy constructor isn't used
    /*! Example :
    	\code
    	class MyClass
    	{
    		CLASS_COPY_NOT_ALLOWED(MyClass)

    		public:
    			MyClass();
    	};
    	\endcode
    */
#define CLASS_COPY_NOT_ALLOWED(ClassName)                   \
private:                                                \
    ClassName (const ClassName &);                      \
    const ClassName & operator=(const ClassName &)

}//end of ns

#endif // #ifndef BEHAVIAC_BASE_BASECLASS_H_
