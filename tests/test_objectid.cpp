#include <gtest/gtest.h>
#include "crypto/objectid.h"

TEST(ObjectIdTest, ConstructorTest) {
    seal::ObjectId obj;

    EXPECT_EQ(obj, seal::ObjectId::ZeroID);
}
