#include <forward_list>
#include <iostream>
#include <db/connector.h>
#include <db/model/tag_attr.h>
#include <sstream>

namespace seal {

const std::string_view TagAttrOps::find_fmt = "SELECT * FROM TagAttr WHERE tagUuidKey = :tagUuidKey"; 
const std::string_view TagAttrOps::find_set_fmt = "";

const std::string_view TagAttrOps::insert_fmt = "INSERT INTO TagAttr (tagUuidKey, tagRank, "
    "tagScore, upVoteCount, downVoteCount, sharedCount, readCount, showCount, commentCount,  "
    "followCount, bookMarkCount, blockedCount) VALUES ("
    ":tagUuidKey, :tagRank, :tagScore, :upVoteCount, :downVoteCount, :sharedCount, :readCount, "
    ":showCount, :commentCount, :followCount, :bookMarkCount, :blockedCount)";

const std::string_view TagAttrOps::update_fmt = "";

std::shared_ptr<tag_attr_t>
TagAttrOps::find(const Connector &conn, const std::string &uuid) const
{
    std::string key(uuid);
    auto out = std::make_shared<tag_attr_t>();
    auto sql = conn.session();
    try {
        *sql << TagAttrOps::find_fmt, soci::into(*out), soci::use(key);

    } catch (const soci::soci_error &err) {
        std::cerr << "Failed to find " << err.what() << std::endl;
        return nullptr;
    }
    return out;
}

std::forward_list<tag_attr_t>
TagAttrOps::find(const Connector &conn, const std::vector<const char *> set, int page) const
{
    auto list = std::forward_list<tag_attr_t>();
    return list;
}

std::shared_ptr<tag_attr_t>
TagAttrOps::insert(const Connector &conn, std::shared_ptr<tag_attr_t> attr) const
{
    auto sql = conn.session();
    try {
        *sql << TagAttrOps::insert_fmt, soci::use(*attr);

    } catch (const soci::soci_error &err) {
        std::cerr << "Failed to insert " << err.what() << std::endl;
        return nullptr;
    }
    return attr;
}

std::string TagAttrOps::to_string(const tag_attr_t &attr) const
{
    std::ostringstream oss;

    oss << "[" << attr.tagUuidKey << "]"
        << "\n\trank.........." << attr.tagRank
        << "\n\tscore........." << attr.tagScore
        << "\n\tup_vote......." << attr.upVoteCount
        << "\n\tdown_vote....." << attr.downVoteCount
        << "\n\tshared_cnt...." << attr.sharedCount
        << "\n\tread_cnt......" << attr.readCount
        << "\n\tshow_cnt......" << attr.showCount
        << "\n\tcomment_cnt..." << attr.commentCount
        << "\n\tfollow_cnt...." << attr.followCount
        << "\n\tbookmark_cnt.." << attr.bookMarkCount
        << "\n\tblocked_cnt..." << attr.blockedCount << "\n";
    return oss.str();
}

}
