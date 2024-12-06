
#pragma once

#include <cctype>
#include <string>
#include <memory>
#include <cstring>
#include <algorithm>
#include <openssl/sha.h>

namespace seal {

class ObjectIdPtr;

class ObjectId {
  public:
    static ObjectId  ZeroID;
    static const std::size_t KeyLength;
    friend class ObjectIdPtr;
    typedef std::shared_ptr<ObjectId> ObjectId_ptr;

    ObjectId() {
        std::memset(m_data, 0, sizeof(m_data));
    }

    ~ObjectId() = default;

    ObjectId(const unsigned char *const data) {
        std::copy(data, data + sizeof(m_data), m_data);
    }

    ObjectId(bool raw, const std::string& data) {
        auto cstr = data.c_str();
        auto len = data.length();
        auto zlen = 0;

        if (len >= SHA_DIGEST_LENGTH) {
            len = SHA_DIGEST_LENGTH;
        } else {
            zlen = SHA_DIGEST_LENGTH - len;
        }
        std::copy(cstr, cstr + len, m_data); 
        if (zlen > 0) {
            std::memset(m_data + len, 0, zlen);
        }
    }

    ObjectId(const std::string& hex) {
        const char *str = hex.c_str();
        if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
            str += 2;
        }
        size_t limit = std::min(2 * sizeof(m_data), std::strlen(str));

        for (size_t i = 0; i < limit; i += 2) {
            auto index = (i >> 1);
            if (!std::isxdigit(str[i]) && !std::isxdigit(str[i + 1])) {
                m_data[index] = '\0';
                continue;
            }
            sscanf(str + i, "%2hhx", m_data + index);
        }
    }

    ObjectId(const ObjectId& other) {
        std::copy(other.m_data, other.m_data + sizeof(m_data), m_data);
    }

    // Move semantics
    //
    ObjectId(const ObjectId&& other) noexcept {
        std::copy(other.m_data, other.m_data + sizeof(m_data), m_data);
    }

    ObjectId& operator =(const ObjectId&& other) {
        if (this != &other) {
            std::copy(other.m_data, other.m_data + sizeof(m_data), m_data);
        }
        return *this;
    }

    // Operators
    //
    ObjectId& operator =(const ObjectId& other) {
        if (this != &other) {
            std::copy(other.m_data, other.m_data + sizeof(m_data), m_data);
        }
        return *this;
    }

    bool operator ==(const ObjectId& other) const {
        if (this != &other) {
            return std::memcmp(m_data, other.m_data, sizeof(m_data)) == 0;
        }
        return true;
    }

    bool operator ==(const ObjectIdPtr& other) const;

    ObjectId& assign(const char *const buf) {
        std::copy(buf, buf + sizeof(m_data), m_data);
        return *this;
    }

    const unsigned char *const get_raw() const {
        return m_data;
    }

    std::string raw() const {
        return std::string(reinterpret_cast<const char *>(m_data), SHA_DIGEST_LENGTH);
    }

    std::string to_string() const {
        constexpr auto size = (SHA_DIGEST_LENGTH * 2);
        char hex[size + 1];

        hex[size] = '\0';
        for (size_t i = 0; i < sizeof(m_data); i++) {
            std::sprintf(hex + (i << 1), "%02x", m_data[i]);
        }
        return std::string(hex);
    }

    friend void compute_sha1(const unsigned char* const buf, int len, ObjectId& hash);

    static inline void sha1(const std::string& buf, ObjectId& hash) {
        compute_sha1((unsigned char *)buf.c_str(), buf.size(), hash);
    }

  private:
    unsigned char m_data[SHA_DIGEST_LENGTH];
};

class ObjectIdPtr {
  public:
    typedef std::shared_ptr<ObjectIdPtr> ObjectIdPtr_ptr;

    ObjectIdPtr() : m_data(nullptr) {}
    ~ObjectIdPtr() {
        delete[] m_data;
    }

    explicit ObjectIdPtr(ObjectId& other) {
        m_data = new unsigned char [SHA_DIGEST_LENGTH];
        std::copy(other.m_data, other.m_data + SHA_DIGEST_LENGTH, m_data);
    }

    explicit ObjectIdPtr(unsigned char* data) {
        m_data = data;
    }

    explicit ObjectIdPtr(const std::string& raw) {
        m_data = new unsigned char [SHA_DIGEST_LENGTH];
        auto data = raw.c_str();
        auto len = raw.length();
        auto zlen = 0;

        if (len >= SHA_DIGEST_LENGTH) {
            len = SHA_DIGEST_LENGTH;
        } else {
            zlen = SHA_DIGEST_LENGTH - len;
        }
        std::copy(data, data + len, m_data);
        if (zlen >= 0) {
            std::memset(m_data + len, 0, zlen);
        }
    }

    // Move semantic
    //
    ObjectIdPtr(ObjectIdPtr&& other) noexcept {
        m_data = other.m_data;
        other.m_data = nullptr;
    }

    unsigned char *const move() {
        auto ret = m_data;
        m_data = nullptr;
        return ret;
    }

    // Copy the buffer out.  The caller owns the returned buffer.
    //
    unsigned char *const copy() const {
        if (m_data != nullptr) {
            auto out = new unsigned char [SHA_DIGEST_LENGTH];
            std::copy(m_data, m_data + SHA_DIGEST_LENGTH, out);
            return out;
        }
        return nullptr;
    }

    const unsigned char *const get_raw() const {
        return m_data;
    }

    std::string raw() const {
        return std::string(reinterpret_cast<const char *>(m_data), SHA_DIGEST_LENGTH);
    }

    // Operators
    //
    bool operator ==(const ObjectIdPtr& other) const {
        if (this != &other) {
            if (m_data != nullptr && other.m_data != nullptr) {
                return std::memcmp(m_data, other.m_data, SHA_DIGEST_LENGTH) == 0;
            }
            return false;
        }
        return true;
    }

    bool operator ==(const ObjectId& other) const {
        if (m_data != nullptr) {
            return std::memcmp(m_data, other.m_data, SHA_DIGEST_LENGTH) == 0;
        }
        return false;
    }

    ObjectIdPtr& operator =(const ObjectId& other) {
        if (m_data != nullptr) {
            delete[] m_data;
        }
        m_data = new unsigned char[SHA_DIGEST_LENGTH];
        std::copy(other.m_data, other.m_data + SHA_DIGEST_LENGTH, m_data);
        return *this;
    }

    std::string to_string() const {
        if (m_data != nullptr) {
            return ObjectId(m_data).to_string();
        }
        return std::string("");
    }

    bool isEmpty() {
        return m_data == nullptr;
    }

    static ObjectIdPtr compute_sha1(const unsigned char *const buf, int len);
    static ObjectIdPtr sha1(const std::string& buf);

    // Disallow copy.
    ObjectIdPtr(const ObjectIdPtr&) = delete;
    ObjectIdPtr& operator =(const ObjectIdPtr&) = delete;

  private:
    unsigned char *m_data;
};

}
