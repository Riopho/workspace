#ifndef _CORE_MD5_H_
#define _CORE_MD5_H_

#include "behaviac/base/base.h"


// Implemented directly from RFC-1321:  http://www.ietf.org/rfc/rfc1321.txt

//--------------------------------------------------------------------------

struct BEHAVIAC_API SMD5Digest
{
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(SMD5Digest);

public:
    uint8_t    m_digest[16];

protected:
    int cmp(SMD5Digest const& rhs) const
    {
        return memcmp(const_cast<uint8_t*>(m_digest),
                      const_cast<uint8_t*>(rhs.m_digest), sizeof(m_digest));
    }

public:
    bool operator ==(SMD5Digest const& rhs) const
    {
        return cmp(rhs) == 0;
    }
    bool operator !=(SMD5Digest const& rhs) const
    {
        return cmp(rhs) != 0;
    }
    bool operator < (SMD5Digest const& rhs) const
    {
        return cmp(rhs) < 0;
    }
    bool operator <=(SMD5Digest const& rhs) const
    {
        return cmp(rhs) <= 0;
    }
    bool operator > (SMD5Digest const& rhs) const
    {
        return cmp(rhs) > 0;
    }
    bool operator >=(SMD5Digest const& rhs) const
    {
        return cmp(rhs) >= 0;
    }
};

//--------------------------------------------------------------------------

class BEHAVIAC_API CMD5Hash
{
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CMD5Hash);

public:
    CMD5Hash() { }

    void Start();
    void append(const uint8_t* data, uint32_t size);
    void Finish(SMD5Digest& digest);

    void append(SMD5Digest& digest)
    {
        append(digest.m_digest, sizeof(digest.m_digest));
    }

private:
    void ProcessBlock();

    union
    {
        uint8_t b[64];
        uint32_t w[16];
    }	m_buf;
    union
    {
        uint8_t b[16];
        uint32_t w[4];
    }	m_abcd;
    uint32_t									m_msgLength[2];

};

//--------------------------------------------------------------------------

#endif // #ifndef _CORE_MD5_H_
