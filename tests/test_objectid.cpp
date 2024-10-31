#include <gtest/gtest.h>
#include "crypto/objectid.h"

using namespace seal;

void objid_ctor(const std::string &hex) {
    ObjectId o1 = ObjectId(hex);

    if (hex.rfind(std::string("0x"), 0) == 0 ||
        hex.rfind(std::string("0X"), 0) == 0) {
        EXPECT_EQ(hex.substr(2), o1.to_string());
    } else {
        EXPECT_EQ(hex, o1.to_string());
    }

    ObjectId o2 = ObjectId(o1);
    EXPECT_EQ(o1, o2);

    ObjectId o3 = o1;
    EXPECT_EQ(o3, o2);

    std::string value = o2.to_string();
    ObjectId o4 = ObjectId(value.c_str());
    EXPECT_EQ(o4, o1);

    ObjectId o5 = ObjectId(std::move(o1));
    EXPECT_EQ(o5, o2);

    // ObjectId o6 = o1;
    // EXPECT_EQ(o6, o2);
}

TEST(ObjectIdTest, ConstructorTest) {
    seal::ObjectId obj;

    EXPECT_EQ(obj, seal::ObjectId::ZeroID);
    objid_ctor(std::string("0d57542aafc1f62d86e2071da30686e4c324e4f0"));
    objid_ctor(std::string("0x0d57542aafc1f62d86e2071da30686e4c324e4f0"));
    objid_ctor(std::string("0X0d57542aafc1f62d86e2071da30686e4c324e4f0"));
}
