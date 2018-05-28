#ifndef _BEHAVIAC_BASE_CONSOLE_H_
#define _BEHAVIAC_BASE_CONSOLE_H_
#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_CONSOLE
#include "behaviac/base/core/singleton.h"
#include "behaviac/base/core/string/stringid.h"
#include "behaviac/base/core/fastdelegates/fastdelegate.h"
#include "behaviac/base/core/thread/mutex.h"

#include "behaviac/base/string/stringutils.h"

#include <string>
#include <map>
#include <vector>
#include <list>

#include <deque>


struct ConsoleBind;
class CXConsole;
class CXConsoleVariable;
class CStringID;
class CInputAxisValue;
class IConsoleCommandHandler;
class CConsoleGenericFilter;

#ifndef _DEBUG
#   define CONSOLE_TRIM_DEVELOPER_ELEMENTS
#endif // #ifndef _DEBUG

// Bitset used for console groups:
enum EConsoleGroup
{
    // Groups:
    ECGROUP_DEFAULT             = 1 << 0,
    ECGROUP_SINGLE              = 1 << 1,
    ECGROUP_MULTI               = 1 << 2,
    ECGROUP_MAX                 = 1 << 3,       // Used as the starting point of other derived enums (if any) (ie: enum X { XFIRST = ECGROUP_MAX << 0, XSECOND = ECGROUP_MAX << 1, ... }; ).

    // Various common combinations:
    ECGROUP_NONE                = 0,
    ECGROUP_ALL                 = 0xFFFFFFFF
};

// Base class for all console elements:
class BEHAVIAC_API CConsoleElement
{
public:
    CConsoleElement(const behaviac::string& name, const behaviac::wstring& help, uint32_t group, bool developerOnly) : m_name(name), m_help(help), m_group(group)
    {
        SetDeveloperOnly(developerOnly);
    }

    virtual ~CConsoleElement()
    {
    }

    const behaviac::string&    GetName() const
    {
        return m_name;
    }
    void                SetName(const behaviac::string& name)
    {
        m_name = name;
    }

    const behaviac::wstring&   GetHelp() const;
    void                SetHelp(const behaviac::wstring& help)
    {
        m_help = help;
    }

    void    SetGroup(uint32_t group)
    {
        m_group = group;
    }
    uint32_t   GetGroup() const
    {
        return m_group;
    }

    void    SetDeveloperOnly(bool developerOnly)
    {
#ifndef _DEBUG
        // :NOTE: This is used to trap console elements that should not be in the final release candidate (we should enable ASSERT once in the final to test these cases)!
        BEHAVIAC_ASSERT(developerOnly != true, "A console element that should not be part of the final release candidate is still registered");
#endif // #ifndef _DEBUG
        m_developerOnly = developerOnly;
    }

    bool  IsDeveloperOnly() const
    {
        return m_developerOnly;
    }

    inline bool operator==(const CConsoleElement& r)const
    {
        return m_name == r.m_name;
    }
    inline bool operator!=(const CConsoleElement& r)const
    {
        return m_name != r.m_name;
    }
    inline bool operator<(const CConsoleElement& r)const
    {
        return behaviac::StringUtils::tolower(m_name) < StringUtils::tolower(r.m_name);
    }

protected:
    behaviac::string m_name;
    behaviac::wstring m_help;
    uint32_t m_group;
    bool m_developerOnly;
};

enum EConsoleVarType
{
    CVAR_INT	=   1,
    CVAR_FLOAT	=	2,
    CVAR_STRING	=	3
};

// if this flag is set during registering a console variable, and the variable exists,
// then the variable will store its value in memory given by src
#define CVF_CHANGE_SOURCE (1u<<16)

#define VF_SERVER_ONCE  0x00000001
#define VF_CHEAT        0x00000002
#define VF_USERINFO     0x00000004
#define VF_MODIFIED     0x00000008
#define VF_SERVER       0x00000010
#define VF_NONOTIFY     0x00000020
#define VF_NOCHANGELEV  0x00000040
#define VF_REQUIRE_NET_SYNC  0x00000080
#define VF_DUMPTODISK		0x00000100

struct ICVarDumpSink
{
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(ICVarDumpSink)
    virtual ~ICVarDumpSink() {}
    virtual void OnElementFound(CXConsoleVariable* pCVar) = 0;
};

/*! Interface to the engine console.

	The engine console allow to manipulate the internal engine parameters
	and to invoke commands.
	This interface allow external modules to integrate their functionalities
	into the console as commands or variables.

*/

enum ScrollDir
{
    sdDOWN,
    sdUP,
    sdNONE
};

struct SXConsoleCommand : public CConsoleElement
{
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(SXConsoleCommand);

    SXConsoleCommand(const behaviac::string& name, const behaviac::wstring& help, uint32_t group, bool developerOnly) : CConsoleElement(name, help, group, developerOnly) {};

    behaviac::string sCommand;

    typedef fastdelegate::FastDelegate1<const behaviac::vector<behaviac::string>&, bool> C_Command;

    C_Command   m_cFunc;
};

//typedef behaviac::vector<behaviac::wstring> ConsoleBuffer;
typedef std::deque<behaviac::wstring> ConsoleBuffer;
typedef ConsoleBuffer::const_iterator ConsoleBufferConstRItor;

typedef behaviac::map<behaviac::string, SXConsoleCommand> ConsoleCommandsMap;
typedef ConsoleCommandsMap::iterator ConsoleCommandsMapItor;

struct string_nocase_lt
{
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(string_nocase_lt)
    bool operator()(const behaviac::string& s1, const behaviac::string& s2) const
    {
        return string_icmp(s1.c_str(), s2.c_str()) < 0;
    }
};

typedef behaviac::map<behaviac::string, CXConsoleVariable*, string_nocase_lt> ConsoleVariablesMap;
typedef ConsoleVariablesMap::iterator ConsoleVariablesMapItor;

class BEHAVIAC_API IConsoleOutputObserver
{
public:
    virtual ~IConsoleOutputObserver() {};

    // Called each time a new output is sent to the console (PrintLine, PrintWarning, PrintError, etc...):
    virtual void OnOutput(const behaviac::wstring& output) = 0;
};

class BEHAVIAC_API IConsoleImpl
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(IConsoleImpl);

public:
    virtual void UpdateConsole(float deltaTime) = 0;
    virtual void InitializeConsole() = 0;
    virtual void ShutdownConsole() = 0;
    virtual void ShowConsole(bool show) = 0;
    virtual bool UseInputActionMap() = 0;
    virtual const behaviac::wstring& LocalizeString(const behaviac::wstring& s) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
class BEHAVIAC_API CXConsole
{
public:
    BEHAVIAC_DELCARE_SINGLETON(CXConsole);
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CXConsole);

public:
    CXConsole();
    ~CXConsole();

    void Init();

    //! Create a new console variable
    CXConsoleVariable* CreateVariable(const char* sName, const char* sValue, int nFlags, const behaviac::string& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);
    CXConsoleVariable* CreateVariable(const char* sName, const char* sValue, int nFlags, const behaviac::wstring& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);

    int Register(const char* name, int*   src, int defaultvalue, int flags, const behaviac::string& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);
    int Register(const char* name, int*   src, int defaultvalue, int flags, const behaviac::wstring& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);

    float Register(const char* name, float* src, float defaultvalue, int flags, const behaviac::string& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);
    float Register(const char* name, float* src, float defaultvalue, int flags, const behaviac::wstring& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);

    void UnregisterVariable(const char* sVarName, bool bDelete = false);

    // console commands mapped to script functions
    void AddCommand(const behaviac::string& sName, const char* sScriptFunc, const behaviac::string& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);
    void AddCommand(const behaviac::string& sName, const char* sScriptFunc, const behaviac::wstring& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);
    // ... to C functions
    void AddCommand(const behaviac::string& sName, SXConsoleCommand::C_Command, const behaviac::string& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);
    void AddCommand(const behaviac::string& sName, SXConsoleCommand::C_Command, const behaviac::wstring& help, uint32_t group = ECGROUP_DEFAULT, bool developerOnly = true);

    void RemoveCommand(const behaviac::string& sName);

    CXConsoleVariable* GetCVar(const char* name);

    void RefreshVariable(const behaviac::string& sVarName);

    void PrintLine(bool developerOnly, const char* s, ...);
    void PrintLine(bool developerOnly, const wchar_t* s, ...);

    void PrintWarning(bool developerOnly, const char* warning, ...);
    void PrintWarning(bool developerOnly, const wchar_t* warning, ...);

    void PrintError(bool developerOnly, const char* error, ...);
    void PrintError(bool developerOnly, const wchar_t* error, ...);

    virtual void Update(float deltaTime);

    void Lock();
    void Unlock();
    bool IsLocked();

    virtual void ShowConsole(bool show);
    void ExecuteString(const behaviac::string& command);
    void ExecuteString(const behaviac::wstring& command);

    void Exit(const char* command, ...);

    void ExecuteCommandsFromSetting();

    void GetCommandAndArgs(const char* behaviac::string, behaviac::string& command, behaviac::vector<behaviac::string>& args);
    void GetCommandAndArgs(const behaviac::vector<behaviac::string>& commandTokens, behaviac::string& command, behaviac::vector<behaviac::string>& args);
    bool HasArg(const behaviac::string& commandstring, const behaviac::string& arg);
    bool HasArg(const behaviac::vector<behaviac::string>& commandTokens, const behaviac::string& arg);

    bool IsActive()
    {
        return m_bConsoleActive;
    }

    void    SetGroupFilter(uint32_t groupFilter)
    {
        m_groupFilter = groupFilter;
    }
    uint32_t   GetGroupFilter() const
    {
        return m_groupFilter;
    }

    void    SetShowDeveloperConsoleElements(bool value)
    {
        m_showDeveloperConsoleElements = value;
    }
    bool  IsShowDeveloperConsoleElements() const
    {
        return m_showDeveloperConsoleElements;
    }

    int		GetNumVars();
    void	GetVars(const char** pszArray, int numItems, bool sorted = true);
    const char*	AutoComplete(const char* substr);
    const char*	AutoCompletePrev(const char* substr);

    void    RunBatch(const behaviac::string& batchFileName);

    int     GetNumValidCommandElements();
    void    GetValidCommandElements(behaviac::vector<CConsoleElement*>& commandElementArray, bool sortedByName = true);

    bool    ValidateConsoleElementGroup(const CConsoleElement& consoleElement) const;

    virtual const behaviac::wstring& LocalizeString(const behaviac::wstring& s);

    IConsoleImpl*   GetConsoleImpl()
    {
        return m_consoleImpl;
    }
    void            SetConsoleImpl(IConsoleImpl* consoleImpl);

    const ConsoleBuffer& GetConsoleBuffer() const
    {
        return m_dqConsoleBuffer;
    }
    const ConsoleBuffer& GetHistory() const
    {
        return m_dqHistory;
    }

    void ClearConsoleBuffer();

    void AddCommandToHistory(const behaviac::wstring& str);

    // IConsoleOutputObserver's are notified each time a new output is sent to the console (PrintLine, PrintWarning, PrintError, etc...):
    void RegisterOutputObserver(IConsoleOutputObserver* outputObserver);
    void UnregisterOutputObserver(IConsoleOutputObserver* outputObserver);

    //////////////////////////////////////////////////////////////////////////
    // External Console Command Handler:

    // :!!NOTE!!: Only use these functions in the EXTREME (!) case where you need to pass commands to an external console system and that these
    // :!!NOTE!!: commands are not known by the game at runtime and must not contain altered names (ie. PunkBuster). In any other case, you should avoid
    // :!!NOTE!!: to use this kind of callback since some commands could slip in the final product. Also, help and some features are not available
    // :!!NOTE!!: for these commands (tab, search, etc.)! Without important limitations (ie. PunkBuster), there's always a way of doing what you want
    // :!!NOTE!!: with objects derived from "CConsoleElement"!
    //! Register an handler for all commands starting with the specified prefix.
    //! Commands will be intercepted completely by the handler.
    //! @param prefix Command prefix.
    //! @param handler Object receiving an event when a prefixed command is entered in the console.
    void    RegisterExternalConsolePrefixedCommandHandler(const behaviac::string& prefix, IConsoleCommandHandler* handler);

    //! Unregister an handler for all commands starting with the specified prefix.
    //! @param prefix Command prefix.
    void    UnRegisterExternalConsolePrefixedCommandHandler(const behaviac::string& prefix);
    //////////////////////////////////////////////////////////////////////////

protected:
    void Release();
    void SetStatus(bool bActive)
    {
        m_bConsoleActive = bActive;
    }

    bool GetStatus();

    int		GetNumCmds();
    void	GetCmds(const char** pszArray, int numItems, bool sorted = true);

    void AddLine(behaviac::wstring& str);
    void ExecuteCommand(SXConsoleCommand& cmd, behaviac::string& str);
    void DisplayHelp(const behaviac::wstring& help, const char* name);
    bool HandlePrefixedCommand(const behaviac::string& command);

    behaviac::string GetBatchFileFullPath(const behaviac::string& batchFileName) const;

    ConsoleBuffer m_dqConsoleBuffer;
    ConsoleBuffer m_dqHistory;

    ConsoleCommandsMap	m_mapCommands;
    ConsoleVariablesMap m_mapVariables;

    uint32_t m_groupFilter;
    bool m_showDeveloperConsoleElements;

    bool m_bConsoleActive;

    typedef behaviac::vector< std::pair<behaviac::string, IConsoleCommandHandler*> > ConsoleCmdHandlerList;
    typedef ConsoleCmdHandlerList::iterator ConsoleCmdHandlerListIt;
    typedef ConsoleCmdHandlerList::const_iterator ConsoleCmdHandlerListConstIt;
    ConsoleCmdHandlerList m_consoleCmdHandlerList;

    IConsoleImpl* m_consoleImpl;

    behaviac::vector<IConsoleOutputObserver*> m_outputObservers;

    behaviac::Mutex m_critSection;
    uint32_t m_lockCount;
};

#define CONSOLE_ALL_PRINT_LINE(...) CXConsole::GetInstance()->PrintLine(false, __VA_ARGS__)
#define CONSOLE_ALL_PRINT_WARNING(...) CXConsole::GetInstance()->PrintWarning(false, __VA_ARGS__)
#define CONSOLE_ALL_PRINT_ERROR(...) CXConsole::GetInstance()->PrintError(false, __VA_ARGS__)

#ifndef CONSOLE_TRIM_DEVELOPER_ELEMENTS
#   define CONSOLE_DEVELOPER_ONLY_PRINT_LINE(...) CXConsole::GetInstance()->PrintLine(true, __VA_ARGS__)
#   define CONSOLE_DEVELOPER_ONLY_PRINT_WARNING(...) CXConsole::GetInstance()->PrintWarning(true, __VA_ARGS__)
#   define CONSOLE_DEVELOPER_ONLY_PRINT_ERROR(...) CXConsole::GetInstance()->PrintError(true, __VA_ARGS__)
#else
#   define CONSOLE_DEVELOPER_ONLY_PRINT_LINE(...)
#   define CONSOLE_DEVELOPER_ONLY_PRINT_WARNING(...)
#   define CONSOLE_DEVELOPER_ONLY_PRINT_ERROR(...)
#endif

//////////////////////////////////////////////////////////////////////////
//! IConsoleCommandHandler
//
class BEHAVIAC_API IConsoleCommandHandler
{
public:
    virtual void OnConsoleCommand(const behaviac::string& command) {};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//! this interface is the 1:1 "C++ representation"
//! of a console variable.
//! NOTE: a console variable is accessible in C++ trough
//! this interface

// #@P? Console variables are not useful to the Xbox player. They MUST NOT make it to the final version.
// The whole console things should die for the Xbox release version.
//
typedef fastdelegate::FastDelegate1<CXConsoleVariable*, void>  CXConsoleVariableCCB;
class BEHAVIAC_API CXConsoleVariable : public CConsoleElement
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CXConsoleVariable)

    CXConsoleVariable(const char* sName, int nFlags, EConsoleVarType nType, const behaviac::wstring& help, uint32_t group, bool developerOnly);
    CXConsoleVariable(const char* sName, void* pVar, int nFlags, EConsoleVarType nType, const behaviac::wstring& help, uint32_t group, bool developerOnly);
    virtual ~CXConsoleVariable();

    void		ClearFlags(int flags);
    int			GetFlags()const;

    int			GetIVal()const;
    void		Set(int i);

    void		Set(float f);
    float		GetFVal()const;

    void		Set(const char* s);
    const char* GetString()const;

    EConsoleVarType GetType()const;

    void		Release();
    void		Refresh();
    void		SetSrc(void* pSrc);

    // Set update callback
    inline void SetCommitCallback(const CXConsoleVariableCCB& cb)
    {
        BEHAVIAC_ASSERT(!m_commitCB && "A callback was already assigned to cvar %s", GetName().c_str());
        m_commitCB = cb;
    }

    inline void RemoveCommitCallback()
    {
        m_commitCB = CXConsoleVariableCCB();
    }

    bool IsDirty(void)
    {
        return m_Dirty;
    };
    void SetDirty(bool b)
    {
        m_Dirty = b;
    };

    enum { NameSize = 256 };

protected:
    // Called to acknowledge value change
    virtual void OnCommit(void);

private:

    char* 			m_sValue;
    int* 			m_nValue;
    float* 			m_fValue;

    int				m_nFlags;
    EConsoleVarType	m_nType;

    CXConsoleVariableCCB m_commitCB;
    bool            m_Dirty;

    // indicates whether the principal value (m_sValue for behaviac::string-typed var; m_nValue for int-typed var; m_fValue for float-typed var)
    // needs to be deleted along with the duplicated values. If this is false, the principal value doesn't belong to this object and doesn't
    // need to be deallocated. The other two need to be deallocated ANYWAY
    bool			m_bAutoDelete;
};

//////////////////////////////////////////////////////////////////////////
// CTypedGlobalConsoleVariable<T>
//
// In Release, the CTypedGlobalConsoleVariable will simply be a constant T.
// But in other builds, it will be a static object registered in the console.
//
// Please use the GLOBAL_SMART_CONSOLE macro. Like this :
//
// GLOBAL_SMART_CONSOLE( T, SomeSetting, "g_somesetting", 0 )
//

class BEHAVIAC_API CGlobalConsoleVariable
{
    // construction
protected:
    CGlobalConsoleVariable(const char* name, const behaviac::string& help);

    // functions
public:
    virtual void Register(CXConsole& console) = 0;

    static CGlobalConsoleVariable* GetHead()
    {
        return m_head;
    }

    CGlobalConsoleVariable* GetPrevious() const
    {
        return m_previous;
    }
    CGlobalConsoleVariable* GetNext() const
    {
        return m_next;
    }

    // implementation functions
protected:
    // we have Init and Shutdown functions that need to be called from the derived class so that
    // we have the full vtable
    void Init();
    void Shutdown();

    void Unregister(CXConsole& console);

    // variables
protected:
    const char* m_name;
    behaviac::string    m_help;

private:
    static CGlobalConsoleVariable*  m_head;
    CGlobalConsoleVariable*         m_previous;
    CGlobalConsoleVariable*         m_next;
};

template< typename T >
class CTypedGlobalConsoleVariable : private CGlobalConsoleVariable
{
    // construction
public:
    CTypedGlobalConsoleVariable(const char* name, T defaultValue, const behaviac::string& help)
        : CGlobalConsoleVariable(name, help)
        , m_value(defaultValue)
    {
        Init();
    }

    ~CTypedGlobalConsoleVariable()
    {
        Shutdown();
    }

    // functions
public:
    // boolean operations
    operator bool() const
    {
        return m_value != 0;
    }

    bool operator!() const
    {
        return m_value == 0;
    }

    // T operations
    operator T() const
    {
        return m_value;
    }

    operator T& ()
    {
        return m_value;
    }

    // comparaison
    bool operator==(T rhs) const
    {
        return m_value == rhs;
    }

    bool operator!=(T rhs) const
    {
        return m_value != rhs;
    }

    // assignment
    T& operator=(T rhs)
    {
        m_value = rhs;
        return m_value;
    }

    // implementation functions
private:
    virtual void Register(CXConsole& console)
    {
        console.Register(m_name, &m_value, m_value, 0, m_help);
    }

    // variables
private:
    T           m_value;
};

#ifndef ENABLE_DEBUG_TOOLS
#define GLOBAL_SMART_CONSOLE( type, name, str, val, description ) static const type name = val
#define GLOBAL_SMART_CONSOLE_NONCONST( type, name, str, val, description ) static type name = val
#else
#define GLOBAL_SMART_CONSOLE( type, name, str, val, description ) static CTypedGlobalConsoleVariable< type > name( str, val, description )
#define GLOBAL_SMART_CONSOLE_NONCONST                             GLOBAL_SMART_CONSOLE
#endif

#ifndef _DEBUG
#define GLOBAL_SMART_CONSOLE_RETAIL( type, name, str, val, description )          static const type name = val
#define GLOBAL_SMART_CONSOLE_NONCONST_RETAIL( type, name, str, val, description ) static       type name = val
#else
#define GLOBAL_SMART_CONSOLE_RETAIL( type, name, str, val, description ) static CTypedGlobalConsoleVariable< type > name( str, val, description )
#define GLOBAL_SMART_CONSOLE_NONCONST_RETAIL GLOBAL_SMART_CONSOLE_RETAIL
#endif//#ifndef _DEBUG

// 'console' is unused and a left over from previous implementation
#define SMART_CONSOLE( type, name, console, str, val, description ) GLOBAL_SMART_CONSOLE( type, name, str, val, description )
#endif//#if BEHAVIAC_ENABLE_CONSOLE

#endif // #ifndef _BEHAVIAC_BASE_CONSOLE_H_
