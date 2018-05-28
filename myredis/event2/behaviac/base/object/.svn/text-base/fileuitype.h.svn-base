#ifndef _ENGINESERVICES_FILEUITYPE_H_
#define _ENGINESERVICES_FILEUITYPE_H_

#include "behaviac/base/object/uitype.h"

struct UiFileType : public UiBasicType
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(UiFileType);

private:
    const char* m_fileFilter;
    const char* m_defaultFolder;
    const char* m_replaceExtension;
    bool m_removePath;

public:

    UiFileType() : m_fileFilter(NULL), m_defaultFolder(NULL), m_replaceExtension(NULL), m_removePath(false) {}
    UiFileType(const char* fileFilter, const char* defaultFolder = NULL, const char* replaceExtension = NULL, bool removePath = false, const char* description = NULL) : UiBasicType(Ui_None, description), m_fileFilter(fileFilter), m_defaultFolder(defaultFolder), m_replaceExtension(replaceExtension), m_removePath(removePath) {}

    virtual void SaveDescription(XmlNodeRef& xmlNode)
    {
        UiBasicType::SaveDescription(xmlNode);

        if (m_fileFilter)
        {
            xmlNode->setAttr("FileFilter", m_fileFilter);
        }

        if (m_defaultFolder)
        {
            xmlNode->setAttr("DefaultFolder", m_defaultFolder);
        }

        if (m_replaceExtension)
        {
            xmlNode->setAttr("ReplaceExtension", m_replaceExtension);
        }

        if (m_removePath)
        {
            xmlNode->setAttr("RemovePath", m_removePath);
        }
    }
};

#define UiDescriptorAllocate_UiFileType BEHAVIAC_NEW UiFileType

#endif // #ifndef _ENGINESERVICES_FILEUITYPE_H_
