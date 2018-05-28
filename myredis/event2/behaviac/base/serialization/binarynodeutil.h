#ifndef _CORE_BINARYNODEUTIL_H_
#define _CORE_BINARYNODEUTIL_H_

#if BEHAVIAC_ENABLE_BINARYNODE
#define BINARYNODE_CURRENT_VERSION  2
// NOTE: Version number of 2 was chosen so that it will definitely differ from what
// the original code wrote at that offset in the file (0x00010000).

#define DEBUGSTRING_BUFFER_SIZE 512

namespace
{
#if BEHAVIAC_COMPILER_APPLE    
//
#else
    bool WriteEscapeCode(IFile* file, int32_t escapeValue)
    {
        bool result = true;
        uint32_t bytesWritten = file->Write(int32_t(0xFE));
        result &= (bytesWritten == sizeof(int8_t));
        int32_t value = escapeValue;
        SwapByte(value);
        bytesWritten = file->Write(value);
        result &= (bytesWritten == sizeof(value));
        return result;
    }

    bool WritePackedSize(IFile* file, int32_t size)
    {
        bool result = true;
        uint32_t bytesWritten;

        if (size < 0xFE)
        {
            bytesWritten = file->Write((int8_t)size);
            result &= (bytesWritten == sizeof(int8_t));
        }
        else
        {
            bytesWritten = file->Write(int32_t(0xFF));
            result &= (bytesWritten == sizeof(int8_t));
            int32_t value = size;
            SwapByte(value);
            bytesWritten = file->Write(value);
            result &= (bytesWritten == sizeof(value));
        }

        return result;
    }

    bool ReadPackedSize(IFile* file, int32_t& size, bool& gotEscapeCode)
    {
        bool result = true;
        int32_t bytesRead;
        int32_t packedSize;
        bytesRead = file->Read(packedSize);
        result &= (bytesRead == sizeof(packedSize));

        if (packedSize >= 0xFE)
        {
            gotEscapeCode = (packedSize == 0xFE);
            bytesRead = file->Read(size);
            result &= (bytesRead == sizeof(size));
            SwapByte(size);
        }
        else
        {
            gotEscapeCode = false;
            size = packedSize;
        }

        return result;
    }

    bool WriteStringID(IFile* file, const CStringID& stringID, bool debugStrings)
    {
        bool result = true;
        int32_t bytesWritten;
        // Always write the IDType first
        CStringID::IDType id = stringID.GetUniqueID();
        SwapByte(id);
        bytesWritten = file->Write(id);
        result &= (bytesWritten == sizeof(id));
        // Then if required and possible, write the debug behaviac::string
#if STRINGID_USESTRINGCONTENT

        if (debugStrings)
        {
            const char* id = stringID.c_str();
            int32_t idSize = strlen(id);
            int32_t value = idSize;
            SwapByte(value);
            bytesWritten = file->Write(value);
            result &= (bytesWritten == sizeof(value));
            bytesWritten = file->Write(id, idSize);
            result &= (bytesWritten == idSize);
        }

#endif //STRINGID_USESTRINGCONTENT
        return result;
    }

    bool ReadSerializationID(IFile* file, CSerializationID& serializationID, bool debugStrings)
    {
        bool result = true;
        int32_t bytesRead;
        CStringID::IDType tagID;
        bytesRead = file->Read(tagID);
        result &= (bytesRead == sizeof(tagID));
        SwapByte(tagID);

        if (debugStrings)
        {
            int32_t tagSize;
            bytesRead = file->Read(tagSize);
            result &= (bytesRead == sizeof(tagSize));
            SwapByte(tagSize);

            if (tagSize < DEBUGSTRING_BUFFER_SIZE)
            {
                char tempBuffer[DEBUGSTRING_BUFFER_SIZE];
                bytesRead = file->Read(tempBuffer, tagSize);
                result &= (bytesRead == tagSize);
                tempBuffer[tagSize] = '\0';
                serializationID = CStringID(tempBuffer);
            }
            else
            {
                BEHAVIAC_LOGWARNING("Attribute name is too long, debug behaviac::string will be missing");
                file->Seek(tagSize, CFileSystem::ESeekMoveMode_Cur);
                serializationID = CStringID(tagID);
            }
        }
        else
        {
            serializationID = CStringID(tagID);
        }

        return result;
    }
#endif//#if !BEHAVIAC_COMPILER_APPLE 
    template <typename T>
    void ValidateBufferSize(int32_t size)
    {
        if (size != sizeof(T))
        {
            BEHAVIAC_ASSERT(0, "Invalid buffer size!");
        }
    }

    template <typename T>
    void ValidateVectorBufferSize(int32_t size, const behaviac::vector<T>& value)
    {
        // Calculate the expected buffer size
        int32_t bufferSize = value.size() * sizeof(T);
        bufferSize += sizeof(typename behaviac::vector<T>::size_type); // to store the size

        if (size != bufferSize)
        {
            BEHAVIAC_ASSERT(0, "Invalid buffer size!");
        }
    }
      
}

//#define ENABLE_BUFFER_SIZE_VALIDATION

#if defined(ENABLE_BUFFER_SIZE_VALIDATION) || defined(BEHAVIAC_ENABLE_ASSERTS)
	#define VALIDATE_BUFFER_SIZE(bufferSize, type) ValidateBufferSize<type>(bufferSize)
	#define VALIDATE_VECTOR_BUFFER_SIZE(bufferSize, value) ValidateVectorBufferSize(bufferSize, value)
#else // defined(ENABLE_BUFFER_SIZE_VALIDATION) || defined(BEHAVIAC_ENABLE_ASSERTS)
	#define VALIDATE_BUFFER_SIZE(bufferSize, type)
	#define VALIDATE_VECTOR_BUFFER_SIZE(bufferSize, value)
#endif // defined(ENABLE_BUFFER_SIZE_VALIDATION) || defined(BEHAVIAC_ENABLE_ASSERTS)


class CBinaryNodeSaveContext
{
    typedef behaviac::map<SMD5Digest, int32_t> Digest2ValueMap;

    Digest2ValueMap		m_digest2Value;

    bool LookupValue(SMD5Digest const& digest, int32_t& value)
    {
        Digest2ValueMap::const_iterator it = m_digest2Value.find(digest);

        if (it == m_digest2Value.end())
        {
            return false;
        }

        value = it->second;
        return true;
    }

public:
    int32_t m_currentNodeID;

    int32_t m_numUniqueNodes;
    int32_t m_numChildLinks;

    bool m_saveAsGraph;

    void Reset()
    {
        m_currentNodeID = m_numUniqueNodes = m_numChildLinks = 0;
        m_saveAsGraph = false;
    }

    CBinaryNodeSaveContext()
    {
        Reset();
    }

    bool LookupNodeID(SMD5Digest const& nodeDigest, int32_t& nodeID)
    {
        return LookupValue(nodeDigest, nodeID);
    }

    void InsertNodeID(SMD5Digest const& nodeDigest, int32_t nodeID)
    {
        m_digest2Value[nodeDigest] = nodeID;
    }

    bool LookupAttrPosition(SMD5Digest const& attrDigest, int32_t& attrPosition)
    {
        return LookupValue(attrDigest, attrPosition);
    }

    void InsertAttrPosition(SMD5Digest const& attrDigest, int32_t attrPosition)
    {
        m_digest2Value[attrDigest] = attrPosition;
    }
};
#endif//#if BEHAVIAC_ENABLE_BINARYNODE

#endif //_CORE_BINARYNODEUTIL_H_
