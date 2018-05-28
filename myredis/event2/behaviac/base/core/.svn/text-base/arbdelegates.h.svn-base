#ifndef _BEHAVIAC_BASE_ARBDELEGATES_H_
#define _BEHAVIAC_BASE_ARBDELEGATES_H_
// Namespace
namespace behaviac
{

#define TARB_PARAM_A_0
#define TARB_PARAM_B_0
#define TARB_PARAM_C_0
#define TARB_PARAM_D_0
#define TARB_PARAM_E_0
#define TARB_PARAM_F_0
#define TARB_PARAM_G_0
#define TARB_PARAM_H_0
#define TARB_PARAM_I_0

#define TARB_PARAM_A_1      typename T_P1,
#define TARB_PARAM_B_1      T_P1
#define TARB_PARAM_C_1      , T_P1
#define TARB_PARAM_D_1      T_P1,
#define TARB_PARAM_E_1      T_ARB p1
#define TARB_PARAM_F_1      , T_ARB p1
#define TARB_PARAM_G_1      , p1
#define TARB_PARAM_H_1      p1
#define TARB_PARAM_I_1      , T_ARB

#define TARB_PARAM_A_2      typename T_P1, typename T_P2,
#define TARB_PARAM_B_2      T_P1, T_P2
#define TARB_PARAM_C_2      , T_P1, T_P2
#define TARB_PARAM_D_2      T_P1, T_P2,
#define TARB_PARAM_E_2      T_ARB p1, T_ARB p2
#define TARB_PARAM_F_2      , T_ARB p1, T_ARB p2
#define TARB_PARAM_G_2      , p1, p2
#define TARB_PARAM_H_2      p1, p2
#define TARB_PARAM_I_2      , T_ARB, T_ARB

#define TARB_PARAM_A_3      typename T_P1, typename T_P2, typename T_P3,
#define TARB_PARAM_B_3      T_P1, T_P2, T_P3
#define TARB_PARAM_C_3      , T_P1, T_P2, T_P3
#define TARB_PARAM_D_3      T_P1, T_P2, T_P3,
#define TARB_PARAM_E_3      T_ARB p1, T_ARB p2, T_ARB p3
#define TARB_PARAM_F_3      , T_ARB p1, T_ARB p2, T_ARB p3
#define TARB_PARAM_G_3      , p1, p2, p3
#define TARB_PARAM_H_3      p1, p2, p3
#define TARB_PARAM_I_3      , T_ARB, T_ARB, T_ARB

#define TARB_PARAM_A_4      typename T_P1, typename T_P2, typename T_P3, typename T_P4,
#define TARB_PARAM_B_4      T_P1, T_P2, T_P3, T_P4
#define TARB_PARAM_C_4      , T_P1, T_P2, T_P3, T_P4
#define TARB_PARAM_D_4      T_P1, T_P2, T_P3, T_P4,
#define TARB_PARAM_E_4      T_ARB p1, T_ARB p2, T_ARB p3, T_ARB p4
#define TARB_PARAM_F_4      , T_ARB p1, T_ARB p2, T_ARB p3, T_ARB p4
#define TARB_PARAM_G_4      , p1, p2, p3, p4
#define TARB_PARAM_H_4      p1, p2, p3, p4
#define TARB_PARAM_I_4      , T_ARB, T_ARB, T_ARB, T_ARB

#define TARB_PARAM_A_5      typename T_P1, typename T_P2, typename T_P3, typename T_P4, typename T_P5,
#define TARB_PARAM_B_5      T_P1, T_P2, T_P3, T_P4, T_P5
#define TARB_PARAM_C_5      , T_P1, T_P2, T_P3, T_P4, T_P5
#define TARB_PARAM_D_5      T_P1, T_P2, T_P3, T_P4, T_P5,
#define TARB_PARAM_E_5      T_ARB p1, T_ARB p2, T_ARB p3, T_ARB p4, T_ARB p5
#define TARB_PARAM_F_5      , T_ARB p1, T_ARB p2, T_ARB p3, T_ARB p4, T_ARB p5
#define TARB_PARAM_G_5      , p1, p2, p3, p4, p5
#define TARB_PARAM_H_5      p1, p2, p3, p4, p5
#define TARB_PARAM_I_5      , T_ARB, T_ARB, T_ARB, T_ARB, T_ARB

#define TARB_PARAM_A_6      typename T_P1, typename T_P2, typename T_P3, typename T_P4, typename T_P5, typename T_P6,
#define TARB_PARAM_B_6      T_P1, T_P2, T_P3, T_P4, T_P5, T_P6
#define TARB_PARAM_C_6      , T_P1, T_P2, T_P3, T_P4, T_P5, T_P6
#define TARB_PARAM_D_6      T_P1, T_P2, T_P3, T_P4, T_P5, T_P6,
#define TARB_PARAM_E_6      T_ARB p1, T_ARB p2, T_ARB p3, T_ARB p4, T_ARB p5, T_ARB p6
#define TARB_PARAM_F_6      , T_ARB p1, T_ARB p2, T_ARB p3, T_ARB p4, T_ARB p5, T_ARB p6
#define TARB_PARAM_G_6      , p1, p2, p3, p4, p5, p6
#define TARB_PARAM_H_6      p1, p2, p3, p4, p5, p6
#define TARB_PARAM_I_6      , T_ARB, T_ARB, T_ARB, T_ARB, T_ARB, T_ARB

    // Delegate function body
#define TARB_BODY( n )                                                                                  \
public:                                                                                                 \
    template < typename T_RET, TARB_PARAM_A_##n typename T_CLASS >                                      \
    TArbDelegate( T_CLASS *x_pC, T_RET(T_CLASS::*x_pF)( TARB_PARAM_B_##n ) )                        \
    {   _Register< T_RET TARB_PARAM_C_##n >( x_pC, x_pF ); }                                            \
    template < typename T_RET, TARB_PARAM_A_##n typename T_CLASS >                                      \
    void Register( T_CLASS *x_pC, T_RET(T_CLASS::*x_pF)( TARB_PARAM_B_##n ) )                       \
    {   _Register< T_RET TARB_PARAM_C_##n >( x_pC, x_pF ); }                                            \
    T_ARB operator ()( TARB_PARAM_E_##n )                                                               \
    {   typedef T_ARB (*t_Thunk)( void*, void* TARB_PARAM_I_##n );                                      \
        return ((t_Thunk)m_pThunk)( m_pClass, m_pFunction TARB_PARAM_G_##n ); }                         \
private:                                                                                                \
    template < typename T_RET, TARB_PARAM_A_##n typename T_CLASS, typename T_FUNCTION >                 \
    void _Register( T_CLASS *x_pC, T_FUNCTION x_pF )                                                \
    {   m_uParams = n;                                                                                  \
        m_pClass = x_pC;                                                                                \
        m_pFunction = *(void**)&x_pF;                                                                   \
        typedef T_ARB (*t_Thunk)( void*, void* TARB_PARAM_I_##n );                                      \
        m_pThunk = (t_Thunk)&SThunk_##n< T_RET >::Thunk< T_RET, TARB_PARAM_D_##n T_CLASS, T_FUNCTION >; \
    }                                                                                                   \
    template< typename T_RET > struct SThunk_##n                                                        \
    {   template < typename T_RET, TARB_PARAM_A_##n typename T_CLASS, typename T_FUNCTION >             \
        static T_ARB Thunk( void* x_pC, void* x_pF TARB_PARAM_F_##n )                               \
        {   return ( ( (T_CLASS*)x_pC )->*( *( (T_FUNCTION*)&x_pF ) ) )( TARB_PARAM_H_##n ); }          \
    };                                                                                                  \
    template <> struct SThunk_##n< void >                                                               \
    {   template < typename T_RET, TARB_PARAM_A_##n typename T_CLASS, typename T_FUNCTION >             \
        static T_ARB Thunk( void* x_pC, void* x_pF TARB_PARAM_F_##n )                               \
        {   ( ( (T_CLASS*)x_pC )->*( *( (T_FUNCTION*)&x_pF ) ) )( TARB_PARAM_H_##n ); return 0; }       \
    };


    /// Delegates template that invokes functions using an arbitration class
    /**

    Example:

    \code

    #include <stdio.h>
    #include <tchar.h>
    #include <string.h>

    // _variant_t
    #include <comutil.h>
    #pragma comment ( lib, "comsuppw.lib" )

    #include "arbdelegates.h"

    // Turn off Microsoft's promotional material
    #pragma warning ( disable : 4996 )

    // Define our custom delegates class
    typedef adel::TArbDelegate< _variant_t > CDelegate;

    // Class containing functions we will call
    class CMyClass
    {
    public:
    int Add2( int a, int b ) { return a + b; }
    float Add3( float a, float b, float c ) { return a + b + c; }
    void Trace( _variant_t msg ) { adTRACE0( (_bstr_t )msg ); }
    _variant_t GetString() { return _T( "Some String\n\n" ); }
    };

    // Test the delegates
    void test_delegates()
    {
    CMyClass mc;

    // Call CMyClass::Add1()
    CDelegate d;
    d.Register( &mc, &CMyClass::Add2 );
    int x = d( 2, 3 );

    // Call CMyClass::Add2()
    CDelegate d2( &mc, &CMyClass::Add3 );
    float y = d2( 1.5, 2.5, 3.5 );

    // Call CMyClass::Trace
    CDelegate d3( &mc, &CMyClass::Trace );
    d3( _T( "\nHello World!\n\n" ) );

    // Call CMyClass::GetString
    CDelegate d4( &mc, &CMyClass::GetString );
    adTRACE0( (_bstr_t)d4() );

    return;
    }

    \endcode

    */
    template < typename T_ARB >
    class TArbDelegate
    {
    public:

        /// Constructor
        TArbDelegate()
        {
            m_uParams = 0;
            m_pClass = m_pFunction = m_pThunk = 0;
        }

        /// Copy constructor
        TArbDelegate(TArbDelegate& x_rD)
        {
            m_uParams = x_rD.m_uParams;
            m_pClass = x_rD.m_pClass;
            m_pFunction = x_rD.m_pFunction;
            m_pThunk = x_rD.m_pThunk;
        }

        /// Copy constructor
        TArbDelegate& operator = (TArbDelegate& x_rD)
        {
            m_uParams = x_rD.m_uParams;
            m_pClass = x_rD.m_pClass;
            m_pFunction = x_rD.m_pFunction;
            m_pThunk = x_rD.m_pThunk;
            return *this;
        }

        // For each possible number of parameters
        TARB_BODY(0);
        TARB_BODY(1);
        TARB_BODY(2);
        TARB_BODY(3);
        TARB_BODY(4);
        TARB_BODY(5);
        TARB_BODY(6);

    public:

        /// Returns the number of parameters the function has
        unsigned int GetNumParams()
        {
            return m_uParams;
        }

        /// Returns non-zero if the delegate appears to be set
        unsigned int IsValid()
        {
            return 0 != m_pThunk;
        }

    protected:

        /// Class pointer
        void*                   m_pClass;

        /// Function pointer
        void*                   m_pFunction;

        /// Thunk
        void*                   m_pThunk;

        /// Number of params
        unsigned int            m_uParams;
    };


}; // end namespace


#endif//_BEHAVIAC_BASE_ARBDELEGATES_H_
