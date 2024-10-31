
#pragma once

#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <openssl/sha.h>

namespace seal {

class ObjectId {
  public:
    static ObjectId ZeroID;

    ObjectId() {
        std::memset(m_data, 0, sizeof(m_data));
    }

    ~ObjectId() = default;

    ObjectId(const unsigned char *const data) {
        std::copy(data, data + sizeof(m_data), m_data);
    }

    ObjectId(const std::string &hex) {
        const char *str = hex.c_str();
        size_t limit = std::min(2 * sizeof(m_data), hex.size());

        for (size_t i = 0; i < limit; i += 2) {
            if (!std::isxdigit(str[i]) && !std::isxdigit(str[i + 1])) {
                continue;
            }
            sscanf(str + i, "%2hhx", m_data + (i >> 1));
        }
    }

    ObjectId(const ObjectId &other) {
        std::copy(other.m_data, other.m_data + sizeof(m_data), m_data);
    }

    // Move semantics
    //
    ObjectId(const ObjectId &&other) noexcept {
        std::copy(other.m_data, other.m_data + sizeof(m_data), m_data);
    }

    ObjectId &operator =(const ObjectId &&other) {
        if (this != &other) {
            std::copy(other.m_data, other.m_data + sizeof(m_data), m_data);
        }
        return *this;
    }

    // Operators
    //
    ObjectId &operator =(const ObjectId &other) {
        if (this != &other) {
            std::copy(other.m_data, other.m_data + sizeof(m_data), m_data);
        }
        return *this;
    }

    bool operator ==(const ObjectId &other) const {
        if (this != &other) {
            return std::memcmp(m_data, other.m_data, sizeof(m_data));
        }
        return true;
    }

    std::string to_string() const {
        constexpr auto size = (SHA_DIGEST_LENGTH * 2);
        char hex[size + 1];

        hex[size] = '\0';
        for (size_t i = 0; i < sizeof(m_data); i++) {
            std::sprintf(hex + (i << 2), "%02x", m_data[i]);
        }
        return std::string(hex);
    }

    static void compute_sha1(const unsigned char *const buf, size_t len, ObjectId &hash);
    static void compute_sha1(const std::string &buf, ObjectId &hash);

  private:
    unsigned char m_data[SHA_DIGEST_LENGTH];
};

}
