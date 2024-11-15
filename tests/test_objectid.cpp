#include <gtest/gtest.h>
#include "seal/config.h"
#include "crypto/objectid.h"
#include "db/connector.h"
#include "db/model/tag_attr.h"

using namespace seal;

void objid_ctor(const std::string &hex)
{
    auto o1 = ObjectId(hex);

    if (hex.rfind(std::string("0x"), 0) == 0 ||
        hex.rfind(std::string("0X"), 0) == 0) {
        EXPECT_EQ(hex.substr(2), o1.to_string());
    } else {
        EXPECT_EQ(hex, o1.to_string());
    }

    auto o2 = ObjectId(o1);
    EXPECT_EQ(o1, o2);

    ObjectId o3 = o1;
    EXPECT_EQ(o3, o2);

    std::string value = o2.to_string();
    auto o4 = ObjectId(value.c_str());
    EXPECT_EQ(o4, o1);

    auto o5 = ObjectId(std::move(o1));
    EXPECT_EQ(o5, o2);
}

void objidptr_ctor(const std::string &hex)
{
    auto o1 = ObjectId(hex);
    auto o2 = ObjectIdPtr(o1);

    EXPECT_TRUE(o2 == o1);

    auto o3 = ObjectIdPtr(std::move(o2));
    EXPECT_TRUE(o3 == o1);
    EXPECT_TRUE(o2.isEmpty());

    o2 = o1;
    EXPECT_TRUE(o2 == o3);

    auto o4 = ObjectIdPtr(o2.copy());
    EXPECT_TRUE(o4 == o2);

    auto buf = o4.move();
    auto oo1 = ObjectId(buf);
    auto oo2 = ObjectIdPtr(std::move(buf));
    EXPECT_TRUE(oo2 == oo1);
    EXPECT_TRUE(oo1 == oo2);
}

TEST(ObjectIdTest, ConstructorTest)
{
    seal::ObjectId obj;

    EXPECT_EQ(obj, seal::ObjectId::ZeroID);
    objid_ctor(std::string("0d57542aafc1f62d86e2071da30686e4c324e4f0"));
    objid_ctor(std::string("0x0d57542aafc1f62d86e2071da30686e4c324e4f0"));
    objid_ctor(std::string("0X0d57542aafc1f62d86e2071da30686e4c324e4f0"));

    objidptr_ctor(std::string("0d57542aafc1f62d86e2071da30686e4c324e4f0"));
}

void testHash()
{
    const unsigned char str[] = "This is a string to sha-1";
    auto id = ObjectIdPtr::compute_sha1(str, std::strlen((const char *)str));
    auto idCheck = ObjectId(std::string("8a8ba95b575ad18414fc3e386c53d8e969e30ee6"));

    EXPECT_TRUE(id == idCheck);
}

TEST(ObjectIdTest, HashTest) {
    testHash();
}

void connectorScope(std::shared_ptr<ConnectorPool> pool, int loop)
{
    auto connector = pool->get();
    auto session = connector->session();

    EXPECT_TRUE(connector->is_valid());
    EXPECT_TRUE(session != nullptr);
    EXPECT_TRUE(session.use_count() > 0);

    if (loop > 0) {
        connectorScope(pool, loop - 1);
    }
}

void testInsert(std::shared_ptr<ConnectorPool> pool) 
{
    auto data = std::make_shared<tag_attr_t>();

    data->set_key("abcdef");
    data->tagRank       = 123;
    data->tagScore      = 13;
    data->upVoteCount   = 10;
    data->downVoteCount = 2;
    data->sharedCount   = 1;
    data->readCount     = 1000;
    data->showCount     = 2032;
    data->commentCount  = 0;
    data->followCount   = 0;
    data->bookMarkCount = 1;
    data->blockedCount  = 0;

    auto op = tagattr_ops();
    auto ret = op.insert(pool->get(), *data);
    EXPECT_TRUE(ret != false);
}

void testFind(std::shared_ptr<ConnectorPool> pool)
{
    auto ops = tagattr_ops();
    auto tag = tag_attr_t();
    tag.set_key(std::string("abcdef"));

    auto result = ops.find(pool->get(), tag.tagUuidKey);

    EXPECT_TRUE(result != nullptr);
    std::cout << result->to_string() << std::endl;
}

TEST(DBConnector, Scope)
{
    auto pool = std::make_shared<ConnectorPool>(db::MySql);
    pool->dbHost(Config::dbHost)
        .dbName(Config::dbName)
        .userName(Config::dbUser)
        .userPassKey(Config::EnvDBPassKey);

    for (auto i = 0; i < 100; i++) {
        for (auto j = 0; j < (i * 2); j++) {
            connectorScope(pool, j);
        }
    }
    // auto ops = TagAttrOps();
    // ops.delete_table(pool->get());

    testInsert(pool);
    testFind(pool);
}
