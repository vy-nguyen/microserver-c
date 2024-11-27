#pragma once

#include <soci/soci.h>
#include <crypto/objectid.h>
#include <db/model-generic.h>

namespace org::openapitools::server::model {
    class TagAttr;
}

namespace seal {

class tag_attr_t : public DbModel<org::openapitools::server::model::TagAttr>
{
  public:
    std::string tagUuidKey;
    int         tagRank;
    int         tagScore;
    int         upVoteCount;
    int         downVoteCount;
    int         sharedCount;
    int         readCount;
    int         showCount;
    int         commentCount;
    int         followCount;
    int         bookMarkCount;
    int         blockedCount;

    tag_attr_t() : DbModel(), tagUuidKey(ObjectId::KeyLength, 0) {}
    tag_attr_t(const org::openapitools::server::model::TagAttr& dto);
    tag_attr_t(const tag_attr_t &cpy);

    void zero();
    std::string to_string() const;

    virtual void to_dto(org::openapitools::server::model::TagAttr& out) const override;
    
    inline void set_key(const char *const key) {
        tagUuidKey.replace(0, ObjectId::KeyLength, key);
    }
    
    inline void set_key(const std::string& key) {
        auto len = std::min((int)key.size(), ObjectId::KeyLength);
        tagUuidKey.replace(0, len, key.c_str(), len);
    }

    virtual nlohmann::json to_json_obj() const override {
        return nlohmann::json{
            {"tagUuidKey", tagUuidKey},
            {"tagRank", tagRank},
            {"tagScore", tagScore},
            {"upVoteCount", upVoteCount},
            {"downVoteCount", downVoteCount},
            {"sharedCount", sharedCount},
            {"readCount", readCount},
            {"showCount", showCount},
            {"commentCount", commentCount},
            {"followCount", followCount},
            {"bookMarkCount", bookMarkCount},
            {"blockedCount", blockedCount},
        };
    }
};

class Connector;

class tagattr_ops : public DbModelOps<tag_attr_t, org::openapitools::server::model::TagAttr> {
  public:
    tagattr_ops(int limit = 1024) : DbModelOps(limit) {}

    std::shared_ptr<tag_attr_t>
    find(const std::shared_ptr<Connector> conn, const std::string& id) const override {
        return find_intern(conn, id, "tagUuidKey");
    }

    bool
    insert(const std::shared_ptr<Connector> conn, const tag_attr_t& data) const override
    {
        auto stm = get_insert_stm(conn);
        stm->exchange(soci::use(data.tagUuidKey, "tagUuidKey"));
        stm->exchange(soci::use(data.tagRank, "tagRank"));
        stm->exchange(soci::use(data.tagScore, "tagScore"));
        stm->exchange(soci::use(data.upVoteCount, "upVoteCount"));
        stm->exchange(soci::use(data.downVoteCount, "downVoteCount"));
        stm->exchange(soci::use(data.sharedCount, "sharedCount"));
        stm->exchange(soci::use(data.readCount, "readCount"));
        stm->exchange(soci::use(data.showCount, "showCount"));
        stm->exchange(soci::use(data.commentCount, "commentCount"));
        stm->exchange(soci::use(data.followCount, "followCount"));
        stm->exchange(soci::use(data.bookMarkCount, "bookMarkCount"));
        stm->exchange(soci::use(data.blockedCount, "blockedCount"));
        exec_stm(stm);
        return true;
    }

    std::shared_ptr<tag_attr_t>
    update_field(const std::shared_ptr<Connector> conn,
           const std::string& id, const int_field_val_t& field) const;

    std::vector<std::shared_ptr<tag_attr_t>>
    update_field(const std::shared_ptr<Connector> conn,
           const std::string& id, const std::vector<const int_field_val_t>& fields) const;

  protected:
    std::shared_ptr<soci::statement>
        get_find_stm(const std::shared_ptr<Connector>) const override;

    std::shared_ptr<soci::statement>
        get_find_keys_stm(std::shared_ptr<Connector>) const override;

    std::shared_ptr<soci::statement>
        get_insert_stm(const std::shared_ptr<Connector>) const override;

    std::shared_ptr<soci::statement>
        get_update_stm(const std::shared_ptr<Connector>) const override;

    std::shared_ptr<soci::statement>
        get_create_stm(const std::shared_ptr<Connector>) const override;

    std::shared_ptr<soci::statement>
        get_delete_stm(const std::shared_ptr<Connector>) const override;

    static constexpr auto find_fmt =
        "SELECT * from TagAttr WHERE tagUuidKey = :tagUuidKey";

    static constexpr auto find_set_fmt = 
        "SELECT * from TagAttr WHERE tagUuidKey IN (:keyIds) LIMIT :limit OFFSET :offset";

    static constexpr auto insert_fmt =
        "INSERT INTO TagAttr (tagUuidKey, tagRank, "
        "  tagScore, upVoteCount, downVoteCount, sharedCount, readCount, showCount, "
        "  commentCount, followCount, bookMarkCount, blockedCount) VALUES ("
        "  :tagUuidKey, :tagRank, :tagScore, :upVoteCount, :downVoteCount, :sharedCount, "
        "  :readCount, :showCount, :commentCount, :followCount, :bookMarkCount, :blockedCount)"
        "ON DUPLICATE KEY UPDATE "
        "  tagRank = VALUES(tagRank),"
        "  tagScore = VALUES(tagScore),"
        "  upVoteCount = VALUES(upVoteCount),"
        "  downVoteCount = VALUES(downVoteCount),"
        "  sharedCount = VALUES(sharedCount),"
        "  readCount = VALUES(readCount),"
        "  showCount = VALUES(showCount),"
        "  commentCount = VALUES(commentCount),"
        "  followCount = VALUES(followCount),"
        "  bookMarkCount = VALUES(bookMarkCount),"
        "  blockedCount = VALUES(blockedCount)"
        ;

    static constexpr auto update_fmt =
        "UPDATE TagAttr SET :counter = :counter + :inc_count WHERE tagUuid = :tagUuid";

    static constexpr auto update_mult_fmt =
        "UPDATE TagAttr SET %s WHERE tagUuid = :tagUuid";

    static constexpr auto deltab_fmt =
        "DELETE FROM TagAttr";

    static constexpr auto create_fmt =
        "CREATE TABLE TagAttr ("
        "  tagUuidKey VARCHAR(20) PRIMARY KEY,"
        "  tagRank INT,"
        "  tagScore INT,"
        "  upVoteCount INT,"
        "  downVoteCount INT,"
        "  sharedCount INT,"
        "  readCount INT,"
        "  showCount INT,"
        "  commentCount INT,"
        "  followCount INT,"
        "  bookMarkCount INT,"
        "  blockedCount INT"
        ")";
};

}

namespace soci {
    template <>
    struct type_conversion<seal::tag_attr_t> {
        typedef values base_type;

        static void from_base(const values& v, indicator /* ind */, seal::tag_attr_t& t) {
            auto buf = v.get<std::string>("tagUuidKey");
            std::swap(buf, t.tagUuidKey);

            t.tagRank       = v.get<int>("tagRank");
            t.tagScore      = v.get<int>("tagScore");
            t.upVoteCount   = v.get<int>("upVoteCount");
            t.downVoteCount = v.get<int>("downVoteCount");
            t.sharedCount   = v.get<int>("sharedCount");
            t.readCount     = v.get<int>("readCount");
            t.showCount     = v.get<int>("showCount");
            t.commentCount  = v.get<int>("commentCount");
            t.followCount   = v.get<int>("followCount");
            t.bookMarkCount = v.get<int>("bookMarkCount");
            t.blockedCount  = v.get<int>("blockedCount");

            // t.name = v.get<std::string>("name");
        }

        static void to_base(const seal::tag_attr_t& t, values& v, indicator& /* ind */) {
            v.set("tagUuidKey", t.tagUuidKey);
            v.set("tagRank", t.tagRank);
            v.set("tagScore", t.tagScore);
            v.set("upVoteCount", t.upVoteCount);
            v.set("downVoteCount", t.downVoteCount);
            v.set("sharedCount", t.sharedCount);
            v.set("readCount", t.readCount);
            v.set("showCount", t.showCount);
            v.set("commentCount", t.commentCount);
            v.set("followCount", t.followCount);
            v.set("bookMarkCount", t.bookMarkCount);
            v.set("blockedCount", t.blockedCount);
        }
    };
}
