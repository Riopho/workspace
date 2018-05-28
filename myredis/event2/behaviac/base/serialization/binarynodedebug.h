#ifndef _CORE_BINARYNODEDEBUG_H_
#define _CORE_BINARYNODEDEBUG_H_

#include "behaviac/base/serialization/binarynode.h"

#if BEHAVIAC_ENABLE_BINARYNODE

class BEHAVIAC_API CBinaryNodeDebug : public CBinaryNode
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CBinaryNodeDebug);

    CBinaryNodeDebug(const CSerializationID& tag);
    virtual ~CBinaryNodeDebug();

    virtual CBinaryNodeDebug* newChild(const CSerializationID& childID);
    virtual void addChild(const CSerializationID& keyID, const ISerializableNode* child);
    virtual void removeChild(ISerializableNode* child);
    virtual bool SaveToFile(const char* fileName) const;
protected:

    XmlNodeRef  m_xml;
};
#endif//#if BEHAVIAC_ENABLE_BINARYNODE

#endif //_CORE_BINARYNODE_H_
