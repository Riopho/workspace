#ifndef _CORE_FILEMANAGER_H_
#define _CORE_FILEMANAGER_H_

#include "behaviac/base/base.h"
#include "behaviac/base/core/container/string_t.h"
#include "behaviac/base/core/thread/mutex.h"
#include "behaviac/base/file/filesystem.h"

class IFile;
class CPathID;

/**
CFileManager is used to access files.

CFileManager is used internally as a singleton. 
you can override CFileManager to provide your file manager.
*/
class BEHAVIAC_API CFileManager
{
private:
	static CFileManager*	ms_pInstance;
	static bool				ms_bCreatedByMe;
	static void _SetInstance(CFileManager* pInstance);
	static CFileManager* _GetInstance();

public:
	static CFileManager* GetInstance()
	{
		CFileManager* pRandomGenerator = CFileManager::_GetInstance();

		return pRandomGenerator;
	}

	static void Cleanup();
public:
	virtual IFile* FileOpen(const char* fileName, CFileSystem::EOpenAccess iOpenAccess = CFileSystem::EOpenAccess_Read);

	virtual void FileClose(IFile* file);
	virtual bool FileExists(const char* fileName);

	virtual uint64_t FileGetSize(const char* fileName);
	virtual behaviac::wstring GetCurrentWorkingDirectory();

	bool PathIsRelative(const behaviac::string& path);
	void FormatPath(const char* fileNameToConvert, char* fileNameOut) const;
	const char* MakeRelativePath(const char* szFullPath, const char* szRootPath);

#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)
	void SetAssetManager(AAssetManager* mgr)
	{
		this->m_mgr = mgr;
	}
	AAssetManager* GetAssetManager()
	{
		return this->m_mgr;
	}
#endif//#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)	
protected:
	BEHAVIAC_DECLARE_MEMORY_OPERATORS(CFileManager);

	CFileManager();
	virtual ~CFileManager();

#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)
	AAssetManager* m_mgr;
#endif//#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)	

};

#endif // #ifndef _CORE_FILEMANAGER_H_
