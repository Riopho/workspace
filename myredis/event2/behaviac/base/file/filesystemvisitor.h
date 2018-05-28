#ifndef _CORE_FILESYSTEMVISITOR_H_
#define _CORE_FILESYSTEMVISITOR_H_

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"
#include "behaviac/base/core/container/string_t.h"
#include "behaviac/base/core/container/vector_t.h"
#include "behaviac/base/core/container/list_t.h"
#include "behaviac/base/core/container/map_t.h"
#include "behaviac/base/core/container/set_t.h"

class IFileSystemVisitor
{
protected:
    inline ~IFileSystemVisitor()
    {
    }

public:
    // full path DOESN'T end with separator
    virtual bool EnterDirectory(const char* fullDirPath, const char* dirName) = 0;
    virtual bool VisitFile(const char* fullFilePath, const char* fileName) = 0;
    // full path DOESN'T end with separator
    virtual bool VisitDirectory(const char* fullDirPath, const char* dirName) = 0;
    virtual void ExitDirectory() = 0;
};

class CVectorFileSystemVisitor : public IFileSystemVisitor
{
public:
    CVectorFileSystemVisitor(behaviac::vector< behaviac::string >& vec, bool storeFullPath, uint32_t maximumSize, bool keepCase);

public:
    virtual bool EnterDirectory(const char* fullDirPath, const char* dirName);
    virtual bool VisitFile(const char* fullFilePath, const char* fileName);
    virtual bool VisitDirectory(const char* fullDirPath, const char* dirName);
    virtual void ExitDirectory();

private:
    CVectorFileSystemVisitor(const CVectorFileSystemVisitor& copy);
    CVectorFileSystemVisitor& operator=(const CVectorFileSystemVisitor& copy);

    behaviac::vector< behaviac::string >&   m_vec;
    bool                    m_storeFullPath;
    uint32_t                  m_maximumSize;
    bool                    m_keepCase;
};

class CCounterFileSystemVisitor : public IFileSystemVisitor
{
public:
    CCounterFileSystemVisitor(uint32_t maximumSize);

public:
    uint32_t GetCount() const
    {
        return m_count;
    }

    virtual bool EnterDirectory(const char* fullDirPath, const char* dirName);
    virtual bool VisitFile(const char* fullFilePath, const char* fileName);
    virtual bool VisitDirectory(const char* fullDirPath, const char* dirName);
    virtual void ExitDirectory();

private:
    uint32_t m_maximumSize;
    uint32_t m_count;
};

#endif // _CORE_FILESYSTEMVISITOR_H_
