#include <crypto/objectid.h>

namespace seal {

ObjectId ObjectId::ZeroID = ObjectId();

void compute_sha1(const unsigned char *const buf, size_t len, ObjectId &hash)
{
}

void compute_sha1(const std::string &buf, ObjectId &hash) {
    compute_sha1((unsigned char *)buf.c_str(), buf.size(), hash);
}

}
