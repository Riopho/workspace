#ifndef TEST_H
#define TEST_H

#include "behaviac/base/base.h"
#include "behaviac/base/core/container/string_t.h"

#include "behaviac/base/meta/collection.h"
#include "behaviac/base/meta/foreach.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

//#define ENABLE_MEMORYDUMP	0

namespace test
{
    typedef void (*Test)();

    class TestFailedException
    {
    public:
        TestFailedException(const std::string& message)
            : m_message(message)
        {
        }

        std::string m_message;
    };

    class TestSuite
    {
    private:
        typedef std::pair<std::string, Test> RegisteredTest;
        typedef std::vector<RegisteredTest> RegisteredTests;

    public:
        TestSuite()
            : m_verbose(false)
        {
        }

        void registerTest(const std::string& testName, Test test)
        {
            m_tests.push_back(RegisteredTest(testName, test));
        }

        void setVerbose(bool b)
        {
            m_verbose = b;
        }

		bool runAllTests()
        {
            bool allPassed = true;

            for (RegisteredTests::iterator test = m_tests.begin(); test != m_tests.end(); ++test)
            {
                if (m_verbose)
                {
                    std::cout << test->first << " " << std::flush;
                }
#if BEHAVIAC_COMPILER_MSVC
                try
                {
#endif//#if BEHAVIAC_COMPILER_MSVC                    
                    test->second();

                    if (m_verbose)
                    {
                        std::cout << "PASS" << std::endl << std::flush;
                    }
                    else
                    {
                        std::cout << "." << std::flush;
                    }
#if BEHAVIAC_COMPILER_MSVC                    
                }
                catch (TestFailedException e)
                {
                    allPassed = false;

                    if (!m_verbose)
                    {
                        std::cout << test->first << " ";
                    }

                    std::cout << "FAIL: " << e.m_message << std::endl << std::flush;
                }
#endif//#if BEHAVIAC_COMPILER_MSVC                
            }

            if (!m_verbose)
            {
                std::cout << std::endl << std::flush;
            }

            return allPassed;
        }

        static TestSuite& getInstance()
        {
            static TestSuite instance;
            return instance;
        }

    private:
        bool m_verbose;
        RegisteredTests m_tests;
    };

    class AutoTestRegister
    {
    public:
        AutoTestRegister(const std::string& name, Test test)
        {
            TestSuite::getInstance().registerTest(name, test);
        }
    };
}

#define TEST(SUITENAME, TESTNAME)                                           \
    void SUITENAME##_##TESTNAME();                                          \
    static test::AutoTestRegister autoTestRegister_##SUITENAME##_##TESTNAME(#SUITENAME "_" #TESTNAME, SUITENAME##_##TESTNAME); \
    void SUITENAME##_##TESTNAME()

#define SUITE(Name)                                                         \
    namespace Suite##Name {                                                 \
        namespace UnitTestSuite {                                           \
            inline char const* GetSuiteName () {                            \
                return #Name ;                                              \
            }                                                               \
        }                                                                   \
    }                                                                       \
    namespace Suite##Name


#define TEST_FIXTURE(SUITENAME, TESTNAME) \
    class SUITENAME##_##TESTNAME##Helper : public SUITENAME \
    { \
    public: \
        void test(); \
    }; \
    void SUITENAME##_##TESTNAME()                         \
    {\
        SUITENAME##_##TESTNAME##Helper testinstance; \
        testinstance.test(); \
    }\
    static test::AutoTestRegister autoTestRegister_##SUITENAME##_##TESTNAME(#SUITENAME "_" #TESTNAME, SUITENAME##_##TESTNAME); \
    void SUITENAME##_##TESTNAME##Helper::test()


#define TEST_COLLECTION( CollectionType, Type, TESTNAME )												\
    void _##TESTNAME();																					\
    static test::AutoTestRegister autoTestRegister_##TESTNAME(#TESTNAME, _##TESTNAME);					\
    struct TestFunctor_##TESTNAME																		\
    {                                                                                                   \
        TestFunctor_##TESTNAME()																		\
        {}                                                                                              \
        \
        template< typename Type >                                                                       \
        void operator()( Type );                                                                        \
    private:                                                                                            \
        \
        TestFunctor_##TESTNAME & operator=( const TestFunctor_##TESTNAME & );							\
    };                                                                                                  \
    void _##TESTNAME()																					\
    {																									\
        TestFunctor_##TESTNAME functor;																	\
        behaviac::Meta::ForEach< CollectionType >( functor );												\
    }																									\
    template< typename Type >                                                                           \
    void TestFunctor_##TESTNAME::operator()( Type )

#if BEHAVIAC_COMPILER_MSVC
#define CHECK(X)                                              \
    if (!(X))                                                 \
    {                                                         \
        std::ostringstream os;                                \
        os << #X << " ";                                      \
        os << __FILE__ << ":" << __LINE__;                    \
        throw test::TestFailedException(os.str());            \
    }

#define CHECK_EQUAL(E, A)                                     \
    if (!((E) == (A)))                                        \
    {                                                         \
        std::ostringstream os;                                \
        os << "(" << #E << " == " << #A << ") ";              \
        os << "E:" << (E) << " actual:" << (A) << " "; \
        os << __FILE__ << ":" << __LINE__;                    \
        throw test::TestFailedException(os.str());            \
    }

#else
#define CHECK(X)                                              \
    if (!(X))                                                 \
    {                                                         \
        std::ostringstream os;                                \
        os << #X << " ";                                      \
        os << __FILE__ << ":" << __LINE__;                    \
        BEHAVIAC_ASSERT(false);                               \
    }

#define CHECK_EQUAL(E, A)                                     \
    if (!((E) == (A)))                                        \
    {                                                         \
        std::ostringstream os;                                \
        os << "(" << #E << " == " << #A << ") ";              \
        os << __FILE__ << ":" << __LINE__;                    \
        BEHAVIAC_ASSERT(false);                               \
    }

#endif//#if BEHAVIAC_COMPILER_MSVC

#endif // TEST_H
