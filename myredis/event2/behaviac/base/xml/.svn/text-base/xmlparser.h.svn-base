#ifndef _XML_PARSER_H
#define _XML_PARSER_H

#include "behaviac/base/xml/ixml.h"

/************************************************************************/
/* XmlParser class, Parse xml and return root xml node if success.      */
/************************************************************************/
class BEHAVIAC_API XmlParser
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(XmlParser);

    //! Parse xml file. Suffix is used to reference different binary load.
    XmlNodeRef parse(const char* fileName, const char* rootNodeName = 0, const char* suffix = 0);
    XmlNodeRef parse(IFile* file, const char* rootNodeName = 0, const char* suffix = 0, bool handleError = true);
#if BEHAVIAC_ENABLE_BINARYNODE
    XmlNodeRef convertToReadOnly(XmlConstNodeRef node);
#endif//#if BEHAVIAC_ENABLE_BINARYNODE
    //! Parse xml from memory buffer.
    XmlNodeRef parseBuffer(const char* buffer, const char* rootNodeName = 0);
    XmlNodeRef parseBuffer(char* buffer, int size, const char* rootNodeName = 0);

#if BEHAVIAC_ENABLE_BINARYNODE
    XmlNodeRef loadReadOnlyBuffer(const char* buffer, int size, const char* rootNodeName = 0);
#endif//#if BEHAVIAC_ENABLE_BINARYNODE
    const char* getErrorString() const
    {
        return m_errorString.c_str();
    }
private:
    behaviac::string m_errorString;
};

#endif //_XML_PARSER_H
