#ifndef _CORE_READONLYBINARYNODE_H_
#define _CORE_READONLYBINARYNODE_H_

#include "behaviac/base/serialization/serializablenode.h"

#if BEHAVIAC_ENABLE_BINARYNODE

class CReadOnlyBinaryNode_Fake;


////////////////////////////////////////////////////////////////////////////////
// CReadOnlyBinaryNode
// This class is a "one alloc" representation of a hierarchy. It can be loaded
// from a buffer and read, but it cannot be modified.
class BEHAVIAC_API CReadOnlyBinaryNode : public ISerializableNode
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CReadOnlyBinaryNode);

    CReadOnlyBinaryNode();
    virtual ~CReadOnlyBinaryNode();

    ////////////////////////////////////////////////////////////////////////////
    // ISerializableNode interface
    virtual SerializableNodeRef clone() const;

    virtual int32_t getChildCount() const;
    virtual ISerializableNode* getChild(int32_t childIndex);
    virtual const ISerializableNode* getChild(int32_t childIndex) const;

    virtual ISerializableNode* findChild(const CSerializationID& childID);
    virtual const ISerializableNode* findChild(const CSerializationID& childID) const;

    virtual ISerializableNode* newChild(const CSerializationID& childID);

    virtual void removeChild(ISerializableNode* child);

    virtual bool isTag(const CSerializationID& tagID) const;
    virtual CSerializationID getTag() const;

    virtual int32_t getAttributesCount() const;

    virtual bool SaveToFile(const char* fileName) const;
    virtual bool LoadFromFile(const char* fileName);

    virtual bool SaveToFile(IFile* file) const;
    virtual bool LoadFromFile(IFile* file);

    virtual int32_t GetMemUsage() const;

    // We take ownership of the buffer from here
    bool LoadFromBuffer(int8_t* buffer, int32_t bufferSize, bool keepBuffer = true);

private:
    static void BuildFakeNode(CReadOnlyBinaryNode_Fake*& fakeNode, int8_t*& sourceBuffer, bool debugStrings, behaviac::vector< CReadOnlyBinaryNode_Fake* >& nodeLookup);
    void BuildFakeNode(int8_t* buffer, int32_t numUniqueNodes, int32_t numChildLinks, bool debugStrings);

    static void ComputeDataSizeForClone(const CReadOnlyBinaryNode_Fake* sourceFakeNode, int32_t& newDataSize, int32_t& numTotalNodes, bool debugStrings);
    static void CloneFakeNode(const CReadOnlyBinaryNode_Fake* sourceFakeNode, CReadOnlyBinaryNode_Fake*& destFakeNode, int8_t*& destBuffer, bool debugStrings);

    CReadOnlyBinaryNode_Fake* m_fakeNode;
    int8_t* m_dataBuffer;

    // whoa don't use these! use clone() instead
    CReadOnlyBinaryNode(const CReadOnlyBinaryNode&);
    CReadOnlyBinaryNode& operator=(const CReadOnlyBinaryNode&);

    friend class CReadOnlyBinaryNode_Fake;
};
#endif//#if BEHAVIAC_ENABLE_BINARYNODE

#endif //_CORE_READONLYBINARYNODE_H_
