#pragma once

#include <forward_list>
#include <soci/soci.h>
#include <nlohmann/json.hpp>
#include <crypto/objectid.h>

namespace seal {

typedef struct FieldVal final {
    int              value;
    std::string_view field;
} field_val_t;

typedef struct TagAttr final {
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

    TagAttr() : tagUuidKey(ObjectId::KeyLength, 0) {}

    void zero();
    std::string to_string() const;

    inline void set_key(const char *const key) {
        tagUuidKey.replace(0, ObjectId::KeyLength, key);
    }
    
    inline void set_key(const std::string &key) {
        auto len = std::min((int)key.size(), ObjectId::KeyLength);
        tagUuidKey.replace(0, len, key.c_str(), len);
    }

    nlohmann::json to_json() const {
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
} tag_attr_t;

class Connector;

class TagAttrOps {
  public:
    TagAttrOps(int limit = 1024) : limit(limit) {}

    std::shared_ptr<tag_attr_t>
    find(const std::shared_ptr<Connector> conn, const std::string &id) const;

    std::forward_list<tag_attr_t>
    find(const std::shared_ptr<Connector> conn,
         const std::vector<const std::string> &keys, int page) const;

    std::shared_ptr<tag_attr_t>
    insert(const std::shared_ptr<Connector> conn,
           const std::shared_ptr<tag_attr_t> attr) const;

    std::shared_ptr<tag_attr_t>
    update(const std::shared_ptr<Connector> conn,
           const std::string &id, const field_val_t &field) const;

    std::vector<std::shared_ptr<tag_attr_t>>
    update(const std::shared_ptr<Connector> conn,
           const std::string &id, const std::vector<const field_val_t> &fields) const;

    void create_table(const std::shared_ptr<Connector> conn) const;
    void delete_table(const std::shared_ptr<Connector> conn) const;

  private:
    static constexpr auto find_fmt =
        "SELECT * from TagAttr WHERE tagUuidKey = :tagUuidKey";

    static constexpr auto find_set_fmt = 
        "SELECT * from TagAttr WHERE tagUuidKey IN (:keyIds)";

    static constexpr auto insert_fmt =
        "INSERT INTO TagAttr (tagUuidKey, tagRank, "
        "tagScore, upVoteCount, downVoteCount, sharedCount, readCount, showCount, "
        "commentCount, followCount, bookMarkCount, blockedCount) VALUES ("
        ":tagUuidKey, :tagRank, :tagScore, :upVoteCount, :downVoteCount, :sharedCount, "
        ":readCount, :showCount, :commentCount, :followCount, :bookMarkCount, :blockedCount)";

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

    int limit;
};

}

namespace soci {
    template <>
    struct type_conversion<seal::TagAttr> {
        typedef values base_type;

        static void from_base(const values& v, indicator /* ind */, seal::TagAttr &t) {
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

        static void to_base(const seal::TagAttr &t, values& v, indicator& /* ind */) {
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
