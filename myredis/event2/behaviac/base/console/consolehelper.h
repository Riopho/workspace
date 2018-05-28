#ifndef _ENGINESERVICES_CONSOLEHELPER_H_
#define _ENGINESERVICES_CONSOLEHELPER_H_
#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_CONSOLE
#include "behaviac/base/core/fastdelegates/fastdelegate.h"
#include "behaviac/base/console/console.h"

#define BEHAVIAC_CONSOLE_COMMAND_GET_PARAM( num ) \
    P##num param##num; \
    if( !GetParam( param##num, args[num-1].c_str() ) ) \
    { \
        CONSOLE_DEVELOPER_ONLY_PRINT_LINE("invalid parameter (%d) value", num ); \
        return; \
    } \
    else if( m_range && !m_range##num.IsInRange( param##num ) ) \
    { \
        CONSOLE_DEVELOPER_ONLY_PRINT_LINE("parameter (%d) is out of range", num ); \
        return; \
    }

class BEHAVIAC_API CConsoleCommandList
{
private:
    struct SConsoleCommandBase
    {
        BEHAVIAC_DECLARE_MEMORY_OPERATORS(SConsoleCommandBase);
        SConsoleCommandBase(const char* name) : m_name(name), m_nbParams(0), m_range(false)
        {
            m_name.make_lower();
        }

        behaviac::string m_name;
        uint8_t m_nbParams;
        bool m_range;

        virtual void Execute(behaviac::vector<behaviac::string>& args) = 0;

    protected:
        bool GetParam(bool& val, const char* str)
        {
            if (str && str[1] == '\0' && (str[0] == '0' || str[0] == '1'))
            {
                val = str[0] == '1';
                return true;
            }

            return false;
        }
        bool GetParam(uint32_t& val, const char* str)
        {
            if (!strncmp(str, "0x", 2))
            {
                return sscanf(str + 2, "%08x", &val) == 1;
            }
            else
            {
                return sscanf(str, "%u", &val) == 1;
            }
        }
        bool GetParam(int32_t& val, const char* str)
        {
            if (!strncmp(str, "0x", 2))
            {
                return sscanf(str + 2, "%08x", &val) == 1;
            }
            else
            {
                return sscanf(str, "%d", &val) == 1;
            }
        }
        bool GetParam(behaviac::Float32& val, const char* str)
        {
            return sscanf(str, "%f", &val) == 1;
        }
        bool GetParam(behaviac::string& val, const char* str)
        {
            val = str;
            return true;
        }
        bool GetParam(CStringID& val, const char* str)
        {
            val.SetContent(str);
            return true;
        }
        bool GetParam(CNoCaseStringID& val, const char* str)
        {
            val.SetContent(str);
            return true;
        }
    };

    template< class T > struct SConsoleCommandParamBase
    {
        T m_min;
        T m_max;

        void Set(T min, T max)
        {
            m_min = min;
            m_max = max;
        }
        bool IsInRange(T val)
        {
            return val >= m_min && val <= m_max;
        }
    };

    struct SConsoleCommand0 : public SConsoleCommandBase
    {
        SConsoleCommand0(const char* name) : SConsoleCommandBase(name) {}
        fastdelegate::FastDelegate0<void> m_callback;

        virtual void Execute(behaviac::vector<behaviac::string>& args)
        {
            m_callback();
        }
    };

    template< class P1 > struct SConsoleCommand1 : public SConsoleCommandBase
    {
        SConsoleCommand1(const char* name) : SConsoleCommandBase(name) {}
        SConsoleCommandParamBase<P1> m_range1;
        fastdelegate::FastDelegate1<P1, void> m_callback;

        virtual void Execute(behaviac::vector<behaviac::string>& args)
        {
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(1);
            m_callback(param1);
        }
    };

    template< class P1, class P2 > struct SConsoleCommand2 : public SConsoleCommandBase
    {
        SConsoleCommand2(const char* name) : SConsoleCommandBase(name) {}
        SConsoleCommandParamBase<P1> m_range1;
        SConsoleCommandParamBase<P2> m_range2;
        fastdelegate::FastDelegate2<P1, P2, void> m_callback;

        virtual void Execute(behaviac::vector<behaviac::string>& args)
        {
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(1);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(2);
            m_callback(param1, param2);
        }
    };

    template< class P1, class P2, class P3 > struct SConsoleCommand3 : public SConsoleCommandBase
    {
        SConsoleCommand3(const char* name) : SConsoleCommandBase(name) {}
        SConsoleCommandParamBase<P1> m_range1;
        SConsoleCommandParamBase<P2> m_range2;
        SConsoleCommandParamBase<P3> m_range3;
        fastdelegate::FastDelegate3<P1, P2, P3, void> m_callback;

        virtual void Execute(behaviac::vector<behaviac::string>& args)
        {
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(1);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(2);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(3);
            m_callback(param1, param2, param3);
        }
    };

    template< class P1, class P2, class P3, class P4 > struct SConsoleCommand4 : public SConsoleCommandBase
    {
        SConsoleCommand4(const char* name) : SConsoleCommandBase(name) {}
        SConsoleCommandParamBase<P1> m_range1;
        SConsoleCommandParamBase<P2> m_range2;
        SConsoleCommandParamBase<P3> m_range3;
        SConsoleCommandParamBase<P4> m_range4;
        fastdelegate::FastDelegate4<P1, P2, P3, P4, void> m_callback;

        virtual void Execute(behaviac::vector<behaviac::string>& args)
        {
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(1);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(2);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(3);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(4);
            m_callback(param1, param2, param3, param4);
        }
    };

    template< class P1, class P2, class P3, class P4, class P5 > struct SConsoleCommand5 : public SConsoleCommandBase
    {
        SConsoleCommand5(const char* name) : SConsoleCommandBase(name) {}
        SConsoleCommandParamBase<P1> m_range1;
        SConsoleCommandParamBase<P2> m_range2;
        SConsoleCommandParamBase<P3> m_range3;
        SConsoleCommandParamBase<P4> m_range4;
        SConsoleCommandParamBase<P5> m_range5;
        fastdelegate::FastDelegate5<P1, P2, P3, P4, P5, void> m_callback;

        virtual void Execute(behaviac::vector<behaviac::string>& args)
        {
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(1);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(2);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(3);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(4);
            BEHAVIAC_CONSOLE_COMMAND_GET_PARAM(5);
            m_callback(param1, param2, param3, param4, param5);
        }
    };

public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CConsoleCommandList);
    CConsoleCommandList(const char* prefix);
    ~CConsoleCommandList();

    void AddCommand(const char* name, fastdelegate::FastDelegate0< void > cb)
    {
        behaviac::string newCommandName = m_prefix + name;
        CXConsole::GetInstance()->AddCommand(newCommandName.c_str(), SXConsoleCommand::C_Command(this, &CConsoleCommandList::ConsoleCommandCB), "");
		typedef SConsoleCommand0 CommandType;
        CommandType* newCommand = BEHAVIAC_NEW CommandType(name);
        newCommand->m_callback = cb;
        m_commands.push_back(newCommand);
    }

    template < typename P1 > void* AddCommand(const char* name, fastdelegate::FastDelegate1<P1, void> cb)
    {
        behaviac::string newCommandName = m_prefix + name;
        CXConsole::GetInstance()->AddCommand(newCommandName.c_str(), SXConsoleCommand::C_Command(this, &CConsoleCommandList::ConsoleCommandCB), "");
		typedef SConsoleCommand1<P1> CommandType;
        CommandType* newCommand = BEHAVIAC_NEW CommandType(name);
        newCommand->m_nbParams = 1;
        newCommand->m_callback = cb;
        m_commands.push_back(newCommand);
        return newCommand;
    }
    template < typename P1 > void AddCommandWithRange(const char* name, fastdelegate::FastDelegate1<P1, void> cb, P1 min, P1 max)
    {
        SConsoleCommand1<P1>* newCommand = (SConsoleCommand1<P1>*) AddCommand(name, cb);
        newCommand->m_range = true;
        newCommand->m_range1.Set(min, max);
    }

    template < typename P1, typename P2 > void* AddCommand(const char* name, fastdelegate::FastDelegate2<P1, P2, void> cb)
    {
        behaviac::string newCommandName = m_prefix + name;
        CXConsole::GetInstance()->AddCommand(newCommandName.c_str(), SXConsoleCommand::C_Command(this, &CConsoleCommandList::ConsoleCommandCB), "");
		typedef SConsoleCommand2<P1, P2> CommandType;
        CommandType* newCommand = BEHAVIAC_NEW CommandType(name);
        newCommand->m_nbParams = 2;
        newCommand->m_callback = cb;
        m_commands.push_back(newCommand);
        return newCommand;
    }
    template < typename P1, typename P2 > void AddCommandWithRange(const char* name, fastdelegate::FastDelegate2<P1, P2, void> cb, P1 min1, P1 max1, P2 min2, P2 max2)
    {
        SConsoleCommand2<P1, P2>* newCommand = (SConsoleCommand2<P1, P2>*) AddCommand(name, cb);
        newCommand->m_range = true;
        newCommand->m_range1.Set(min1, max1);
        newCommand->m_range2.Set(min2, max2);
    }

    template < typename P1, typename P2, typename P3 > void* AddCommand(const char* name, fastdelegate::FastDelegate3<P1, P2, P3, void> cb)
    {
        behaviac::string newCommandName = m_prefix + name;
        CXConsole::GetInstance()->AddCommand(newCommandName.c_str(), SXConsoleCommand::C_Command(this, &CConsoleCommandList::ConsoleCommandCB), "");
		typedef SConsoleCommand3<P1, P2, P3> CommandType;
        CommandType* newCommand = BEHAVIAC_NEW CommandType(name);
        newCommand->m_nbParams = 3;
        newCommand->m_callback = cb;
        m_commands.push_back(newCommand);
        return newCommand;
    }
    template < typename P1, typename P2, typename P3 > void AddCommandWithRange(const char* name, fastdelegate::FastDelegate3<P1, P2, P3, void> cb, P1 min1, P1 max1, P2 min2, P2 max2, P3 min3, P3 max3)
    {
        SConsoleCommand3<P1, P2, P3>* newCommand = (SConsoleCommand3<P1, P2, P3>*) AddCommand(name, cb);
        newCommand->m_range = true;
        newCommand->m_range1.Set(min1, max1);
        newCommand->m_range2.Set(min2, max2);
        newCommand->m_range3.Set(min3, max3);
    }

    template < typename P1, typename P2, typename P3, typename P4 > void* AddCommand(const char* name, fastdelegate::FastDelegate4<P1, P2, P3, P4, void> cb)
    {
        behaviac::string newCommandName = m_prefix + name;
        CXConsole::GetInstance()->AddCommand(newCommandName.c_str(), SXConsoleCommand::C_Command(this, &CConsoleCommandList::ConsoleCommandCB), "");
		typedef SConsoleCommand4<P1, P2, P3, P4> CommandType;
        CommandType* newCommand = BEHAVIAC_NEW CommandType(name);
        newCommand->m_nbParams = 4;
        newCommand->m_callback = cb;
        m_commands.push_back(newCommand);
        return newCommand;
    }
    template < typename P1, typename P2, typename P3, typename P4 > void AddCommandWithRange(const char* name, fastdelegate::FastDelegate4<P1, P2, P3, P4, void> cb, P1 min1, P1 max1, P2 min2, P2 max2, P3 min3, P3 max3, P4 min4, P4 max4)
    {
        SConsoleCommand4<P1, P2, P3, P4>* newCommand = (SConsoleCommand4<P1, P2, P3, P4>*) AddCommand(name, cb);
        newCommand->m_range = true;
        newCommand->m_range1.Set(min1, max1);
        newCommand->m_range2.Set(min2, max2);
        newCommand->m_range3.Set(min3, max3);
        newCommand->m_range4.Set(min4, max4);
    }

    template < typename P1, typename P2, typename P3, typename P4, typename P5 > void* AddCommand(const char* name, fastdelegate::FastDelegate5<P1, P2, P3, P4, P5, void> cb)
    {
        behaviac::string newCommandName = m_prefix + name;
        CXConsole::GetInstance()->AddCommand(newCommandName.c_str(), SXConsoleCommand::C_Command(this, &CConsoleCommandList::ConsoleCommandCB), "");
		typedef SConsoleCommand5<P1, P2, P3, P4, P5> CommandType;
        CommandType* newCommand = BEHAVIAC_NEW CommandType(name);
        newCommand->m_nbParams = 5;
        newCommand->m_callback = cb;
        m_commands.push_back(newCommand);
        return newCommand;
    }
    template < typename P1, typename P2, typename P3, typename P4, typename P5 > void AddCommandWithRange(const char* name, fastdelegate::FastDelegate5<P1, P2, P3, P4, P5, void> cb, P1 min1, P1 max1, P2 min2, P2 max2, P3 min3, P3 max3, P4 min4, P4 max4, P5 min5, P5 max5)
    {
        SConsoleCommand5<P1, P2, P3, P4, P5>* newCommand = (SConsoleCommand5<P1, P2, P3, P4, P5>*) AddCommand(name, cb);
        newCommand->m_range = true;
        newCommand->m_range1.Set(min1, max1);
        newCommand->m_range2.Set(min2, max2);
        newCommand->m_range3.Set(min3, max3);
        newCommand->m_range4.Set(min4, max4);
        newCommand->m_range5.Set(min5, max5);
    }

private:
    bool ConsoleCommandCB(const behaviac::vector<behaviac::string>& commandTokens);

    behaviac::string m_prefix;
    behaviac::vector<SConsoleCommandBase*> m_commands;
};

template<> struct CConsoleCommandList::SConsoleCommandParamBase<behaviac::string>
{
    bool IsInRange(behaviac::string val)
    {
        return true;
    }
};
#endif//#if BEHAVIAC_ENABLE_CONSOLE
#endif // #ifndef _ENGINESERVICES_CONSOLEHELPER_H_
