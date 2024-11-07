#include <memory.h>
#include <forward_list>
#include <iostream>
#include <db/connector.h>
#include <db/model/tag_attr.h>
#include <memory>
#include <sstream>

namespace seal {

thread_local std::shared_ptr<soci::statement> find_stm;

std::shared_ptr<tag_attr_t>
TagAttrOps::find(const std::shared_ptr<Connector> conn, const std::string &uuid) const
{
    auto out = std::make_shared<tag_attr_t>();
    auto sql = conn->session();

    if (find_stm == nullptr) {
        find_stm = std::make_shared<soci::statement>(sql->prepare << TagAttrOps::find_fmt);
    }
    try {
        find_stm->exchange(soci::use(uuid, "tagUuidKey"));
        find_stm->exchange(soci::into(*out));
        find_stm->define_and_bind();
        find_stm->execute(true);
        find_stm->bind_clean_up();

        if (!find_stm->got_data()) {
            return nullptr;
        }
    } catch (const soci::soci_error &err) {
        std::cerr << "Failed to find " << err.what() << std::endl;
        return nullptr;
    }
    return out;
}

std::forward_list<tag_attr_t>
TagAttrOps::find(const std::shared_ptr<Connector> conn,
        const std::vector<const std::string> &keys, int page) const
{
    auto list = std::forward_list<tag_attr_t>();
    return list;
}

std::shared_ptr<tag_attr_t>
TagAttrOps::insert(const std::shared_ptr<Connector> conn,
        std::shared_ptr<tag_attr_t> attr) const
{
    auto sql = conn->session();
    try {
        *sql << TagAttrOps::insert_fmt, soci::use(*attr);

    } catch (const soci::soci_error &err) {
        std::cerr << "Failed to insert " << err.what() << std::endl;
        return nullptr;
    }
    return attr;
}

std::shared_ptr<tag_attr_t>
TagAttrOps::update(const std::shared_ptr<Connector> conn,
        const std::string &id, const field_val_t &field) const
{
    return nullptr;
}

std::vector<std::shared_ptr<tag_attr_t>>
TagAttrOps::update(const std::shared_ptr<Connector> conn,
        const std::string &id, const std::vector<const field_val_t> &fields) const
{
    std::vector<std::shared_ptr<tag_attr_t>> out;

    return out;
}

void
TagAttrOps::delete_table(const std::shared_ptr<Connector> conn) const
{
    auto sql = conn->session();
    try {
        *sql << TagAttrOps::deltab_fmt;

    } catch (const soci::soci_error &err) {
        std::cerr << "Failed to insert " << err.what() << std::endl;
    }
}

void
TagAttrOps::create_table(const std::shared_ptr<Connector> conn) const
{
    auto sql = conn->session();
    try {
        *sql << TagAttrOps::create_fmt;

    } catch (const soci::soci_error &err) {
        std::cerr << "Failed to create table " << err.what() << std::endl;
    }
}

void TagAttr::zero()
{
    tagRank = 0;
    tagScore = 0;
    upVoteCount = 0;
    downVoteCount = 0;
    sharedCount = 0;
    readCount = 0;
    commentCount = 0;
    followCount = 0;
    bookMarkCount = 0;
    blockedCount = 0;
}

std::string TagAttr::to_string() const
{
    std::ostringstream oss;

    oss << "[" << tagUuidKey << "]"
        << "\n\trank.........." << tagRank
        << "\n\tscore........." << tagScore
        << "\n\tup_vote......." << upVoteCount
        << "\n\tdown_vote....." << downVoteCount
        << "\n\tshared_cnt...." << sharedCount
        << "\n\tread_cnt......" << readCount
        << "\n\tshow_cnt......" << showCount
        << "\n\tcomment_cnt..." << commentCount
        << "\n\tfollow_cnt...." << followCount
        << "\n\tbookmark_cnt.." << bookMarkCount
        << "\n\tblocked_cnt..." << blockedCount << "\n";
    return oss.str();
}

}
