#include <crypto/objectid.h>

namespace seal {

ObjectId ObjectId::ZeroID     = ObjectId();
const int ObjectId::KeyLength = SHA_DIGEST_LENGTH;

bool ObjectId::operator ==(const ObjectIdPtr &other) const {
    return other == *this;
}

void compute_sha1(const unsigned char *const buf, int len, ObjectId &hash) {
    SHA1(buf, len, hash.m_data);
}

ObjectIdPtr ObjectIdPtr::compute_sha1(const unsigned char *const buf, int len) {
    unsigned char *ptr = new unsigned char [SHA_DIGEST_LENGTH];
    SHA1(buf, len, ptr);
    return ObjectIdPtr(ptr);
}

ObjectIdPtr ObjectIdPtr::sha1(const std::string &buf) {
    return compute_sha1((const unsigned char *const)buf.c_str(), buf.size());
}

}
