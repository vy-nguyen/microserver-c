#pragma once

#include <forward_list>
#include <soci/soci.h>
#include <crypto/objectid.h>

namespace seal {

typedef struct TagAttr {
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
} tag_attr_t;

class Connector;

class TagAttrOps {
  public:
    TagAttrOps(int limit = 1024) : limit(limit) {}

    std::shared_ptr<tag_attr_t>
    find(const Connector &conn, const std::string &id) const;

    std::forward_list<tag_attr_t>
    find(const Connector &conn, const std::vector<const char *>set, int page) const;

    std::shared_ptr<tag_attr_t>
    insert(const Connector &conn, const std::shared_ptr<tag_attr_t> attr) const;

    std::shared_ptr<tag_attr_t>
    update(const Connector &conn,
           const std::string &id, const char *const field, int val) const;

    std::string to_string(const tag_attr_t &attr) const;

  private:
    static const std::string_view find_fmt;
    static const std::string_view find_set_fmt;
    static const std::string_view insert_fmt;
    static const std::string_view update_fmt;

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
