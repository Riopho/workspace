#ifndef _CORE_BINARYNODE_H_
#define _CORE_BINARYNODE_H_

#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_BINARYNODE
#include "behaviac/base/serialization/serializablenode.h"
#include "behaviac/base/file/filemanager.h"
#include "behaviac/base/file/file.h"
#include "behaviac/base/string/pathid.h"
#include "behaviac/base/md5.h"
#include "behaviac/base/serialization/binarynodeutil.h"

class CBinaryNodeSaveContext;
class CBinaryNodeLoadContext;
class CMD5Hash;
struct SMD5Digest;

class BEHAVIAC_API CBinaryNode : public ISerializableNode
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CBinaryNode);

    CBinaryNode(const CSerializationID& tag);
    CBinaryNode(const CBinaryNode& other);
    virtual ~CBinaryNode();

    CBinaryNode& operator=(const CBinaryNode& other);

    //////////////////////////////////////////////////////////////////////////
    // ISerializableNode interface
    virtual SerializableNodeRef clone() const;

    virtual int32_t getChildCount() const
    {
        return m_children.size();
    }
    virtual ISerializableNode* getChild(int32_t childIndex)
    {
        BEHAVIAC_ASSERT(childIndex < getChildCount());
        return m_children[childIndex];
    }
    virtual const ISerializableNode* getChild(int32_t childIndex) const
    {
        BEHAVIAC_ASSERT(childIndex < getChildCount());
        return m_children[childIndex];
    }

    virtual ISerializableNode* findChild(const CSerializationID& childID);
    virtual const ISerializableNode* findChild(const CSerializationID& childID) const;

    virtual CBinaryNode* newChild(const CSerializationID& childID);

    virtual void removeChild(ISerializableNode* child);

    virtual bool isTag(const CSerializationID& tagID) const
    {
        return m_tag == tagID;
    }
    virtual CSerializationID getTag() const
    {
        return m_tag;
    }

    virtual int32_t getAttributesCount() const;

    virtual const char* getAttrRaw(const CSerializationID& keyID, int typeId = 0, int length = 0) const;
    virtual void setAttrRaw(const CSerializationID& keyID, const char* valueStr, int typeId = 0, int length = 0);

    virtual void addChild(const CSerializationID& keyID, const ISerializableNode* child);

    virtual bool SaveToFile(const char* fileName) const;
    virtual bool LoadFromFile(const char* fileName);

    // This saves/loads an entire hierarchy, including magic and version numbers
    bool SaveToFile(IFile* file, bool removeDuplicates) const;
    virtual bool SaveToFile(IFile* file) const;
    virtual bool LoadFromFile(IFile* file);

    void LoadFromBuffer(int8_t* buffer, int32_t bufferSize);

    virtual int32_t GetMemUsage() const;

    static int32_t GetMagicNumber();
    static int16_t GetCurrentVersionNumber();
protected:
    typedef behaviac::vector<CBinaryNode*> NodesContainer;
    NodesContainer m_children;

private:
    template <typename T>
    void setAttrIntrinsic(const CSerializationID& keyID, INTRINSIC_PARAM(T) value);
    template <typename T>
    void setAttrSizeof(const CSerializationID& keyID, T value)
	{
		//SwapByte(value);
		GetAttribute(keyID)->SetContent((int8_t*)&value, sizeof(T));
	}

    template <typename T>
    bool getAttrSizeof(const CSerializationID& keyID, T& value) const
	{
		const CAttribute* attribute = GetAttribute(keyID);

		if (attribute)
		{
			int32_t bufferSize;
			int8_t* buffer = attribute->GetContent(bufferSize);
			VALIDATE_BUFFER_SIZE(bufferSize, sizeof(T));
			value = *(T*)buffer;
			//SwapByte(value);
			return true;
		}

		return false;
	}

    template <typename T>
    void setAttrVector(const CSerializationID& keyID, const behaviac::vector<T>& value);
    template <typename T>
    bool getAttrVector(const CSerializationID& keyID, behaviac::vector<T>& value) const;

    template <typename T>
    void setAttrCRC(const CSerializationID& keyID, const T& value);
    template <typename T>
    bool getAttrCRC(const CSerializationID& keyID, T& value) const;

    CSerializationID m_tag;

    class CAttribute
    {
    public:
        CAttribute(const CStringID& tag)
            : m_tag(tag),
              m_buffer(NULL),
              m_bufferSize(0)
        {}

        bool IsTag(const CStringID& tag) const
        {
            return m_tag == tag;
        }

        const CStringID& GetTag() const
        {
            return m_tag;
        }

        void SetContent(int8_t* buffer, int32_t bufferSize)
        {
            Delete();
            New(bufferSize);
            memcpy(GetBuffer(), buffer, bufferSize);
        }

        int8_t* GetContent(int32_t& bufferSize) const
        {
            bufferSize = m_bufferSize;
            return GetBuffer();
        }

        int8_t* GetNewBuffer(int32_t bufferSize)
        {
            Delete();
            New(bufferSize);
            return GetBuffer();
        }

        void ReleaseBuffer()
        {
            Delete();
        }

    private:
        void New(int32_t bufferSize)
        {
            //BEHAVIAC_LOGINFO("CBinaryNode::CAttribute::New size: %d\n", bufferSize);
            if (bufferSize > 4)
            {
                m_buffer = (int8_t*)BEHAVIAC_MALLOC_WITHTAG(bufferSize, "BinarySerialization");
            }

            m_bufferSize = bufferSize;
        }

        void Delete()
        {
            if (m_bufferSize > 4)
            {
                BEHAVIAC_FREE(m_buffer);
                m_buffer = NULL;
            }

            m_bufferSize = 0;
        }

        int8_t* GetBuffer() const
        {
            if (m_bufferSize > 4)
            {
                return m_buffer;
            }

            return (int8_t*)&m_buffer;
        }

        CStringID m_tag;
        int32_t m_bufferSize;
        int8_t* m_buffer;
    };

    typedef behaviac::vector<CAttribute> AttributesContainer;
    AttributesContainer m_attributes;

    CAttribute* GetAttribute(const CStringID& key);
    const CAttribute* GetAttribute(const CStringID& key) const;
    CAttribute* GetAttribute(const CSerializationID& key);
    const CAttribute* GetAttribute(const CSerializationID& key) const;

    // This saves/loads the current node's attributes and children
    bool SaveToFile(IFile* file, bool debugStrings, CBinaryNodeSaveContext& saveContext) const;
    bool LoadFromFile(IFile* file, bool debugStrings, CBinaryNodeLoadContext& loadContext);

    static void AppendStringIDToHash(CMD5Hash& hash, const CStringID& stringID);
    static void ComputeAttributeContentHash(CBinaryNodeSaveContext& saveContext, const CAttribute& attr, SMD5Digest& attrDigest);
    void ComputeHash(CBinaryNodeSaveContext& saveContext, SMD5Digest& digest) const;

    void PrepareToSaveHeirarchy(CBinaryNodeSaveContext& saveContext) const;

    CBinaryNode* clonePtr() const;

    void Cleanup();
    void CopyContentFrom(const CBinaryNode& other);

    int32_t GetNumNodesRecursive() const;

    struct CompareNodeTag;
    struct CompareAttrTag;
};
#endif//#if BEHAVIAC_ENABLE_BINARYNODE

#endif //_CORE_BINARYNODE_H_
