#pragma once

#include <soci/soci.h>
#include <crypto/objectid.h>

namespace seal {

struct TagBase {
    ObjectId tag_uuid;
    int      tag_rank;
    int      tag_score;
};

struct TagAttr {
    TagBase  tag_header;
    int      up_vote;
    int      down_vote;
    int      shared_cnt;
    int      read_cnt;
    int      show_cnt;
    int      view_cnt;
    int      comment_cnt;
    int      follow_cnt;
};

}

namespace soci {
    template <>
    struct type_conversion<seal::TagAttr> {
        typedef values base_type;

        static void from_base(const values& v, indicator /* ind */, seal::TagAttr &t) {
            seal::TagBase &header = t.tag_header;
            auto buf = v.get<std::string>("tag_uuid");

            header.tag_uuid.assign(buf.c_str());
            header.tag_rank  = v.get<int>("tag_rank");
            header.tag_score = v.get<int>("tag_score");

            t.up_vote     = v.get<int>("up_vote");
            t.down_vote   = v.get<int>("down_vote");
            t.shared_cnt  = v.get<int>("shared_cnt");
            t.read_cnt    = v.get<int>("read_cnt");
            t.show_cnt    = v.get<int>("show_cnt");
            t.view_cnt    = v.get<int>("view_cnt");
            t.comment_cnt = v.get<int>("comment_cnt");
            t.follow_cnt  = v.get<int>("follow_cnt");

            // t.name = v.get<std::string>("name");
        }

        static void to_base(const seal::TagAttr &t, values& v, indicator& /* ind */) {
            const seal::TagBase &header = t.tag_header;

            v.set("tag_uuid", header.tag_uuid.raw());
            v.set("tag_rank", header.tag_rank);
            v.set("tag_score", header.tag_score);
            v.set("up_vote", t.up_vote);
            v.set("down_vote", t.down_vote);
            v.set("shared_cnt", t.shared_cnt);
            v.set("read_cnt", t.read_cnt);
            v.set("show_cnt", t.show_cnt);
            v.set("view_cnt", t.view_cnt);
            v.set("comment_cnt", t.comment_cnt);
            v.set("follow_cnt", t.follow_cnt);
        }
    };
}
