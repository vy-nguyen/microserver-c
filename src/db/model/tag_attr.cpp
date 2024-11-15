#include <memory.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <memory>
#include <sstream>
#include <db/connector.h>
#include <db/model/tag_attr.h>
#include <model/TagAttr.h>

namespace seal {

thread_local std::shared_ptr<soci::statement> _find_stm;
thread_local std::shared_ptr<soci::statement> _find_set_stm;
thread_local std::shared_ptr<soci::statement> _insert_stm;
thread_local std::shared_ptr<soci::statement> _update_stm;
thread_local std::shared_ptr<soci::statement> _create_stm;
thread_local std::shared_ptr<soci::statement> _deltab_stm;

std::shared_ptr<soci::statement>
tagattr_ops::get_find_stm(const std::shared_ptr<Connector> conn) const 
{
    if (_find_stm == nullptr) {
        _find_stm = std::make_shared<soci::statement>(
                conn->session()->prepare << tagattr_ops::find_fmt);
    }
    return _find_stm;
}

std::shared_ptr<soci::statement>
tagattr_ops::get_find_keys_stm(std::shared_ptr<Connector> conn) const
{
    if (_find_set_stm == nullptr) {
        _find_set_stm = std::make_shared<soci::statement>(
                conn->session()->prepare << tagattr_ops::find_set_fmt);
    }
    return _find_set_stm;
}

std::shared_ptr<soci::statement>
tagattr_ops::get_insert_stm(const std::shared_ptr<Connector> conn) const
{
    if (_insert_stm == nullptr) {
        _insert_stm = std::make_shared<soci::statement>(
                conn->session()->prepare << tagattr_ops::insert_fmt);
    }
    return _insert_stm;
}

std::shared_ptr<soci::statement>
tagattr_ops::get_update_stm(const std::shared_ptr<Connector> conn) const
{
    if (_update_stm == nullptr) {
        _update_stm = std::make_shared<soci::statement>(
                conn->session()->prepare << tagattr_ops::update_fmt);
    }
    return _update_stm;
}

std::shared_ptr<soci::statement>
tagattr_ops::get_create_stm(const std::shared_ptr<Connector> conn) const
{
    if (_create_stm == nullptr) {
        _create_stm = std::make_shared<soci::statement>(
                conn->session()->prepare << tagattr_ops::create_fmt);
    }
    return _create_stm;
}

std::shared_ptr<soci::statement>
tagattr_ops::get_delete_stm(const std::shared_ptr<Connector> conn) const
{
    if (_deltab_stm == nullptr) {
        _deltab_stm = std::make_shared<soci::statement>(
                conn->session()->prepare << tagattr_ops::deltab_fmt);
    }
    return _deltab_stm;
}


/**
 * tagattr_ops::find
 * -----------------
 *
std::shared_ptr<tag_attr_t>
tagattr_ops::find(const std::shared_ptr<Connector> conn, const std::string& uuid) const
{
    auto out = std::make_shared<tag_attr_t>();
    auto sql = conn->session();

    if (find_stm == nullptr) {
        find_stm = std::make_shared<soci::statement>(sql->prepare << tagattr_ops::find_fmt);
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
 */

/**
 * tagattr_ops::find
 * -----------------
 *
std::forward_list<std::shared_ptr<tag_attr_t>>
tagattr_ops::find(const std::shared_ptr<Connector> conn,
        const std::vector<std::string>& keys, int page) const
{
    auto list = std::forward_list<std::shared_ptr<tag_attr_t>>();
    return list;
}
 */

/**
 * tagattr_ops::update_field
 * -------------------------
 *
 */
std::shared_ptr<tag_attr_t>
tagattr_ops::update_field(const std::shared_ptr<Connector> conn,
        const std::string& id, const int_field_val_t& field) const
{
    return nullptr;
}

/**
 * tagattr_ops::update_field
 * -------------------------
 *
 */
std::vector<std::shared_ptr<tag_attr_t>>
tagattr_ops::update_field(const std::shared_ptr<Connector> conn,
        const std::string& id, const std::vector<const int_field_val_t>& fields) const
{
    std::vector<std::shared_ptr<tag_attr_t>> out;

    return out;
}

tag_attr_t::tag_attr_t(const tag_attr_t &cpy)
{
    tagUuidKey = cpy.tagUuidKey;
    tagRank = cpy.tagRank;
    tagScore = cpy.tagScore;
    upVoteCount = cpy.upVoteCount;
    downVoteCount = cpy.downVoteCount;
    sharedCount = cpy.sharedCount;
    readCount = cpy.readCount;
    showCount = cpy.showCount;
    commentCount = cpy.commentCount;
    followCount = cpy.followCount;
    bookMarkCount = cpy.bookMarkCount;
    blockedCount = cpy.blockedCount;
}

tag_attr_t::tag_attr_t(const org::openapitools::server::model::TagAttr& dto)
{
    tagUuidKey = dto.getTagUuidKey();
    tagRank = dto.getTagRank();
    tagScore = dto.getTagScore();
    upVoteCount = dto.getUpVoteCount();
    downVoteCount = dto.getDownVoteCount();
    sharedCount = dto.getSharedCount();
    readCount = dto.getReadCount();
    showCount = dto.getShowCount();
    commentCount = dto.getCommentCount();
    followCount = dto.getFollowCount();
    bookMarkCount = dto.getBookMarkCount();
    blockedCount = dto.getBlockedCount();
}

/**
 * tag_attr_t::to_dto
 * ------------------
 *
 */
void tag_attr_t::to_dto(org::openapitools::server::model::TagAttr& out) const
{
    out.setTagUuidKey(tagUuidKey);
    out.setTagRank(tagRank);
    out.setTagScore(tagScore);
    out.setUpVoteCount(upVoteCount);
    out.setDownVoteCount(downVoteCount);
    out.setSharedCount(sharedCount);
    out.setReadCount(readCount);
    out.setShowCount(showCount);
    out.setCommentCount(commentCount);
    out.setFollowCount(followCount);
    out.setBookMarkCount(bookMarkCount);
    out.setBlockedCount(blockedCount);
}

void tag_attr_t::zero()
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

std::string tag_attr_t::to_string() const
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
