/**
* Simple API
* A simple API to demonstrate OpenAPI to C++ stub generation.
*
* The version of the OpenAPI document: 1.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#include "TagAttr.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

TagAttr::TagAttr()
{
    m_TagUuidKey = "";
    m_TagRank = 0;
    m_TagRankIsSet = false;
    m_TagScore = 0;
    m_TagScoreIsSet = false;
    m_UpVoteCount = 0;
    m_UpVoteCountIsSet = false;
    m_DownVoteCount = 0;
    m_DownVoteCountIsSet = false;
    m_SharedCount = 0;
    m_SharedCountIsSet = false;
    m_ReadCount = 0;
    m_ReadCountIsSet = false;
    m_ShowCount = 0;
    m_ShowCountIsSet = false;
    m_CommentCount = 0;
    m_CommentCountIsSet = false;
    m_FollowCount = 0;
    m_FollowCountIsSet = false;
    m_BookMarkCount = 0;
    m_BookMarkCountIsSet = false;
    m_BlockedCount = 0;
    m_BlockedCountIsSet = false;
    
}

void TagAttr::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool TagAttr::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool TagAttr::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "TagAttr" : pathPrefix;

                                                    
    return success;
}

bool TagAttr::operator==(const TagAttr& rhs) const
{
    return
    
    
    (getTagUuidKey() == rhs.getTagUuidKey())
     &&
    
    
    ((!tagRankIsSet() && !rhs.tagRankIsSet()) || (tagRankIsSet() && rhs.tagRankIsSet() && getTagRank() == rhs.getTagRank())) &&
    
    
    ((!tagScoreIsSet() && !rhs.tagScoreIsSet()) || (tagScoreIsSet() && rhs.tagScoreIsSet() && getTagScore() == rhs.getTagScore())) &&
    
    
    ((!upVoteCountIsSet() && !rhs.upVoteCountIsSet()) || (upVoteCountIsSet() && rhs.upVoteCountIsSet() && getUpVoteCount() == rhs.getUpVoteCount())) &&
    
    
    ((!downVoteCountIsSet() && !rhs.downVoteCountIsSet()) || (downVoteCountIsSet() && rhs.downVoteCountIsSet() && getDownVoteCount() == rhs.getDownVoteCount())) &&
    
    
    ((!sharedCountIsSet() && !rhs.sharedCountIsSet()) || (sharedCountIsSet() && rhs.sharedCountIsSet() && getSharedCount() == rhs.getSharedCount())) &&
    
    
    ((!readCountIsSet() && !rhs.readCountIsSet()) || (readCountIsSet() && rhs.readCountIsSet() && getReadCount() == rhs.getReadCount())) &&
    
    
    ((!showCountIsSet() && !rhs.showCountIsSet()) || (showCountIsSet() && rhs.showCountIsSet() && getShowCount() == rhs.getShowCount())) &&
    
    
    ((!commentCountIsSet() && !rhs.commentCountIsSet()) || (commentCountIsSet() && rhs.commentCountIsSet() && getCommentCount() == rhs.getCommentCount())) &&
    
    
    ((!followCountIsSet() && !rhs.followCountIsSet()) || (followCountIsSet() && rhs.followCountIsSet() && getFollowCount() == rhs.getFollowCount())) &&
    
    
    ((!bookMarkCountIsSet() && !rhs.bookMarkCountIsSet()) || (bookMarkCountIsSet() && rhs.bookMarkCountIsSet() && getBookMarkCount() == rhs.getBookMarkCount())) &&
    
    
    ((!blockedCountIsSet() && !rhs.blockedCountIsSet()) || (blockedCountIsSet() && rhs.blockedCountIsSet() && getBlockedCount() == rhs.getBlockedCount()))
    
    ;
}

bool TagAttr::operator!=(const TagAttr& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TagAttr& o)
{
    j = nlohmann::json::object();
    j["tagUuidKey"] = o.m_TagUuidKey;
    if(o.tagRankIsSet())
        j["tagRank"] = o.m_TagRank;
    if(o.tagScoreIsSet())
        j["tagScore"] = o.m_TagScore;
    if(o.upVoteCountIsSet())
        j["upVoteCount"] = o.m_UpVoteCount;
    if(o.downVoteCountIsSet())
        j["downVoteCount"] = o.m_DownVoteCount;
    if(o.sharedCountIsSet())
        j["sharedCount"] = o.m_SharedCount;
    if(o.readCountIsSet())
        j["readCount"] = o.m_ReadCount;
    if(o.showCountIsSet())
        j["showCount"] = o.m_ShowCount;
    if(o.commentCountIsSet())
        j["commentCount"] = o.m_CommentCount;
    if(o.followCountIsSet())
        j["followCount"] = o.m_FollowCount;
    if(o.bookMarkCountIsSet())
        j["bookMarkCount"] = o.m_BookMarkCount;
    if(o.blockedCountIsSet())
        j["blockedCount"] = o.m_BlockedCount;
    
}

void from_json(const nlohmann::json& j, TagAttr& o)
{
    j.at("tagUuidKey").get_to(o.m_TagUuidKey);
    if(j.find("tagRank") != j.end())
    {
        j.at("tagRank").get_to(o.m_TagRank);
        o.m_TagRankIsSet = true;
    } 
    if(j.find("tagScore") != j.end())
    {
        j.at("tagScore").get_to(o.m_TagScore);
        o.m_TagScoreIsSet = true;
    } 
    if(j.find("upVoteCount") != j.end())
    {
        j.at("upVoteCount").get_to(o.m_UpVoteCount);
        o.m_UpVoteCountIsSet = true;
    } 
    if(j.find("downVoteCount") != j.end())
    {
        j.at("downVoteCount").get_to(o.m_DownVoteCount);
        o.m_DownVoteCountIsSet = true;
    } 
    if(j.find("sharedCount") != j.end())
    {
        j.at("sharedCount").get_to(o.m_SharedCount);
        o.m_SharedCountIsSet = true;
    } 
    if(j.find("readCount") != j.end())
    {
        j.at("readCount").get_to(o.m_ReadCount);
        o.m_ReadCountIsSet = true;
    } 
    if(j.find("showCount") != j.end())
    {
        j.at("showCount").get_to(o.m_ShowCount);
        o.m_ShowCountIsSet = true;
    } 
    if(j.find("commentCount") != j.end())
    {
        j.at("commentCount").get_to(o.m_CommentCount);
        o.m_CommentCountIsSet = true;
    } 
    if(j.find("followCount") != j.end())
    {
        j.at("followCount").get_to(o.m_FollowCount);
        o.m_FollowCountIsSet = true;
    } 
    if(j.find("bookMarkCount") != j.end())
    {
        j.at("bookMarkCount").get_to(o.m_BookMarkCount);
        o.m_BookMarkCountIsSet = true;
    } 
    if(j.find("blockedCount") != j.end())
    {
        j.at("blockedCount").get_to(o.m_BlockedCount);
        o.m_BlockedCountIsSet = true;
    } 
    
}

std::string TagAttr::getTagUuidKey() const
{
    return m_TagUuidKey;
}
void TagAttr::setTagUuidKey(std::string const& value)
{
    m_TagUuidKey = value;
}
int32_t TagAttr::getTagRank() const
{
    return m_TagRank;
}
void TagAttr::setTagRank(int32_t const value)
{
    m_TagRank = value;
    m_TagRankIsSet = true;
}
bool TagAttr::tagRankIsSet() const
{
    return m_TagRankIsSet;
}
void TagAttr::unsetTagRank()
{
    m_TagRankIsSet = false;
}
int32_t TagAttr::getTagScore() const
{
    return m_TagScore;
}
void TagAttr::setTagScore(int32_t const value)
{
    m_TagScore = value;
    m_TagScoreIsSet = true;
}
bool TagAttr::tagScoreIsSet() const
{
    return m_TagScoreIsSet;
}
void TagAttr::unsetTagScore()
{
    m_TagScoreIsSet = false;
}
int32_t TagAttr::getUpVoteCount() const
{
    return m_UpVoteCount;
}
void TagAttr::setUpVoteCount(int32_t const value)
{
    m_UpVoteCount = value;
    m_UpVoteCountIsSet = true;
}
bool TagAttr::upVoteCountIsSet() const
{
    return m_UpVoteCountIsSet;
}
void TagAttr::unsetUpVoteCount()
{
    m_UpVoteCountIsSet = false;
}
int32_t TagAttr::getDownVoteCount() const
{
    return m_DownVoteCount;
}
void TagAttr::setDownVoteCount(int32_t const value)
{
    m_DownVoteCount = value;
    m_DownVoteCountIsSet = true;
}
bool TagAttr::downVoteCountIsSet() const
{
    return m_DownVoteCountIsSet;
}
void TagAttr::unsetDownVoteCount()
{
    m_DownVoteCountIsSet = false;
}
int32_t TagAttr::getSharedCount() const
{
    return m_SharedCount;
}
void TagAttr::setSharedCount(int32_t const value)
{
    m_SharedCount = value;
    m_SharedCountIsSet = true;
}
bool TagAttr::sharedCountIsSet() const
{
    return m_SharedCountIsSet;
}
void TagAttr::unsetSharedCount()
{
    m_SharedCountIsSet = false;
}
int32_t TagAttr::getReadCount() const
{
    return m_ReadCount;
}
void TagAttr::setReadCount(int32_t const value)
{
    m_ReadCount = value;
    m_ReadCountIsSet = true;
}
bool TagAttr::readCountIsSet() const
{
    return m_ReadCountIsSet;
}
void TagAttr::unsetReadCount()
{
    m_ReadCountIsSet = false;
}
int32_t TagAttr::getShowCount() const
{
    return m_ShowCount;
}
void TagAttr::setShowCount(int32_t const value)
{
    m_ShowCount = value;
    m_ShowCountIsSet = true;
}
bool TagAttr::showCountIsSet() const
{
    return m_ShowCountIsSet;
}
void TagAttr::unsetShowCount()
{
    m_ShowCountIsSet = false;
}
int32_t TagAttr::getCommentCount() const
{
    return m_CommentCount;
}
void TagAttr::setCommentCount(int32_t const value)
{
    m_CommentCount = value;
    m_CommentCountIsSet = true;
}
bool TagAttr::commentCountIsSet() const
{
    return m_CommentCountIsSet;
}
void TagAttr::unsetCommentCount()
{
    m_CommentCountIsSet = false;
}
int32_t TagAttr::getFollowCount() const
{
    return m_FollowCount;
}
void TagAttr::setFollowCount(int32_t const value)
{
    m_FollowCount = value;
    m_FollowCountIsSet = true;
}
bool TagAttr::followCountIsSet() const
{
    return m_FollowCountIsSet;
}
void TagAttr::unsetFollowCount()
{
    m_FollowCountIsSet = false;
}
int32_t TagAttr::getBookMarkCount() const
{
    return m_BookMarkCount;
}
void TagAttr::setBookMarkCount(int32_t const value)
{
    m_BookMarkCount = value;
    m_BookMarkCountIsSet = true;
}
bool TagAttr::bookMarkCountIsSet() const
{
    return m_BookMarkCountIsSet;
}
void TagAttr::unsetBookMarkCount()
{
    m_BookMarkCountIsSet = false;
}
int32_t TagAttr::getBlockedCount() const
{
    return m_BlockedCount;
}
void TagAttr::setBlockedCount(int32_t const value)
{
    m_BlockedCount = value;
    m_BlockedCountIsSet = true;
}
bool TagAttr::blockedCountIsSet() const
{
    return m_BlockedCountIsSet;
}
void TagAttr::unsetBlockedCount()
{
    m_BlockedCountIsSet = false;
}


} // namespace org::openapitools::server::model

