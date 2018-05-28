#ifndef __READONLY_XML_HEADER__
#define __READONLY_XML_HEADER__

#include "behaviac/base/xml/ixml.h"

#if BEHAVIAC_ENABLE_BINARYNODE
#include <string>

#define INVALID_READONLY_STRING -1
#define INVALID_READONLY_ID -1

class IFile;

class CReadOnlyString
{
public:
    CReadOnlyString(const char* str = NULL)
        : m_offset(INVALID_READONLY_STRING)
        , m_string(str) {}

    friend bool operator<(CReadOnlyString const& a, CReadOnlyString const& b)
    {
        return strcmp(a.m_string, b.m_string) < 0;
    }

    int32_t   m_offset;
    const char* m_string;
};

class CReadOnlyXmlContext
{
public:
    void    clear();
    behaviac::set_t<CReadOnlyString>		m_stringSet;
    behaviac::vector<char>				m_dictionary;
    int32_t							m_numNodes;
    int32_t							m_numAttrs;
};

class CReadOnlyXml
{
public:
    CReadOnlyXml() : m_dict(NULL), m_refCount(0) {}

    char*   m_dict;
    int8_t    m_version;
    int32_t   m_dictSize;
    int32_t   m_numNodes;
    int32_t   m_numAttrs;

    //! Ref count itself, its zeroed on node creation.
    mutable int m_refCount; // mutable as ref-counting as nothing to do with data access
};

class CReadOnlyAttribute
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CReadOnlyAttribute)
    CReadOnlyAttribute()
        : m_type(0)
        , m_key(INVALID_READONLY_STRING)
        , m_offsetValue(INVALID_READONLY_STRING) {}

    int32_t   m_type  : 8;
    int32_t   m_key   : 24;

    union
    {
        int32_t   m_offsetValue;
        int32_t   m_intValue;
        float   m_floatValue;
    };
};

/**
 ******************************************************************************
 * CReadOnlyXmlNode class
 * Never use CReadOnlyXmlNode directly instead use reference counted XmlNodeRef.
 ******************************************************************************
 */
class CReadOnlyXmlNode : public IXmlNode
{
public:
    static const char   ms_readOnlyXmlFlag;
    static XmlNodeRef   CreateReadOnlyXmlNode(XmlConstNodeRef fromnode);
    static void         DestroyReadOnlyXmlNode(CReadOnlyXmlNode* node);
    static int32_t        AddReadOnlyString(const char*);
    static bool       WritePackedSize(IFile* file, int32_t value);

    template <class TValueType>
    static void ReadValue(const int8_t*& buffer, TValueType& value)
    {
        value = *(TValueType*)buffer;
        buffer += sizeof(TValueType);
        SwapByte(value);
    }

    static void ReadPackedSize(const int8_t*& buffer, int32_t& size, bool& gotEscapeCode);
    static CReadOnlyXmlNode* LoadNodesFromBuffer(const int8_t* buffer, int32_t size);
    static void SaveToFile(IFile* file, const CReadOnlyXmlNode* node);

    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CReadOnlyXmlNode)

    //! Constructor.
    CReadOnlyXmlNode();

    void InitNode(XmlConstNodeRef fromnode);

    //! Get XML node tag.
    const char* getTag() const
    {
        return &m_xml->m_dict[m_tag];
    };
    void	setTag(const char* tag);

    //! Return true if given tag equal to node tag.
    bool isTag(const char* tag) const
    {
        return string_icmp(tag, &m_xml->m_dict[m_tag]) == 0;
    }

    //! Returns content of this node.
    const char* getContent() const
    {
        return &m_xml->m_dict[m_content];
    };

    //! Replaces content of this node
    void setContent(const char* str);

    //! Replaces content of this node, in this implementation 'newContent' is left alone (data is copied)
    void transferContent(behaviac::string& newContent);

    // inherited.

    //////////////////////////////////////////////////////////////////////////
    //! Reference counting.
    void AddRef() const;
    //! When ref count reach zero XML node dies.
    void Release() const;

    bool    saveToFile(const char* fileName) const;
    bool    saveToFile(IFile* file) const;
    void    saveNodeToFile(IFile* file) const;
    void    LoadFromBuffer(const int8_t*& buffer, int8_t*& nodeBuf, CReadOnlyXml* xml);

private:
    void    setAttrInternal(const char* key, const char* value);
    int32_t   findAttr(const char* key) const;
    const char* getAttrValue(int32_t attrId) const
    {
        return &m_xml->m_dict[m_attributes[attrId].m_offsetValue];
    }

    XmlNodeRef newChild(const char*);
    CReadOnlyXmlNode* newChild();

    // shouldn't be called
private:
    //! Get XML Node attributes.
    virtual void copyAttributes(XmlConstNodeRef fromNode);

    //! Get the number of attribute
    virtual int	getAttrCount() const
    {
        return m_attrCount;
    }
    //! Get an attribute value with his index
    virtual const char* getAttr(int index) const;
    //! Get an attribute value with his index
    virtual const char* getAttrTag(int index) const;

    //! Get XML Node attribute for specified key.
    const char* getAttr(const char* key) const;
    //! Check if attributes with specified key exist.
    bool haveAttr(const char* key) const;

    //! Adds new child node.
    void addChild(XmlNodeRef node);

    //! Remove child node.
    void removeChild(XmlNodeRef node);

    //! Remove all child nodes.
    void removeAllChilds();

    //! Swap child nodes
    void swapChilds(int child1, int child2);

    //! Get number of child XML nodes.
    int	getChildCount() const
    {
        return (int)m_childCount;
    };
    int	getChildCount(const char* tag) const;

    //! Get XML Node child nodes.
    XmlNodeRef getChild(int i)
    {
        return &m_childs[i];
    }
    XmlConstNodeRef getChild(int i) const
    {
        return &m_childs[i];
    }

    //! Find node with specified tag.
    XmlNodeRef findChild(const char* tag);
    XmlConstNodeRef findChild(const char* tag) const;

    //! Find node with specified tag. Create the new one if not found.
    XmlNodeRef findChildSafe(const char* tag);
    //! Find node with specified tag. Return the Invalid node if not found.
    XmlConstNodeRef findChildSafe(const char* tag) const;

    XmlNodeRef	clone() const;

#ifdef _DEBUG
    //! Returns line number for XML tag.
    int getLine() const
    {
        return 0;
    };
    //! Set line number in xml.
    void setLine(int line) 
    { 
        BEHAVIAC_UNUSED_VAR(line);
    };
#endif //_DEBUG

    //! Returns XML of this node and sub nodes.
    void getXML(behaviac::string& xml, int level = 0) const;
	void getXML(behaviac::wstring& xml, int level = 0) const;

    void ReserveAttr(int nCount);

    //! Set new XML Node attribute.
    virtual void setAttrText(const char* key, const char* value)
    {
		BEHAVIAC_UNUSED_VAR(key);
        BEHAVIAC_UNUSED_VAR(value);
        BEHAVIAC_ASSERT(!"Cannot modify ReadOnlyXml node");
    }

	virtual void setAttrText(const char* key, const wchar_t* value)
	{
		BEHAVIAC_UNUSED_VAR(key);
        BEHAVIAC_UNUSED_VAR(value);
        BEHAVIAC_ASSERT(!"Cannot modify ReadOnlyXml node");
    }

    //! Delete attrbute.
    void delAttr(const char* key);
    //! Remove all node attributes.
    void removeAllAttributes();

    const XmlConstNodeRef& getInvalidNode() const
    {
        return m_invalidNode;
    }

private:
    static const XmlConstNodeRef m_invalidNode;

    int32_t m_childCount;
    CReadOnlyXmlNode* m_childs;

    //! Xml node attributes.
    int32_t m_attrCount;
    CReadOnlyAttribute* m_attributes;

    //! Content of XML node.
    int32_t m_content;

    //! behaviac of XML node.
    int32_t m_tag;

    CReadOnlyXml* m_xml;
};



/**
 ******************************************************************************
 * CReadOnlyXmlNode class
 * Never use CXmlNode directly instead use reference counted XmlNodeRef.
 ******************************************************************************
 */
#endif//#if BEHAVIAC_ENABLE_BINARYNODE


#endif // __READONLY_XML_HEADER__
