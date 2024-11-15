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
/*
 * TagAttr.h
 *
 * 
 */

#ifndef TagAttr_H_
#define TagAttr_H_


#include <string>
#include <nlohmann/json.hpp>

namespace org::openapitools::server::model
{

/// <summary>
/// 
/// </summary>
class  TagAttr
{
public:
    TagAttr();
    virtual ~TagAttr() = default;


    /// <summary>
    /// Validate the current data in the model. Throws a ValidationException on failure.
    /// </summary>
    void validate() const;

    /// <summary>
    /// Validate the current data in the model. Returns false on error and writes an error
    /// message into the given stringstream.
    /// </summary>
    bool validate(std::stringstream& msg) const;

    /// <summary>
    /// Helper overload for validate. Used when one model stores another model and calls it's validate.
    /// Not meant to be called outside that case.
    /// </summary>
    bool validate(std::stringstream& msg, const std::string& pathPrefix) const;

    bool operator==(const TagAttr& rhs) const;
    bool operator!=(const TagAttr& rhs) const;

    /////////////////////////////////////////////
    /// TagAttr members

    /// <summary>
    /// 
    /// </summary>
    std::string getTagUuidKey() const;
    void setTagUuidKey(std::string const& value);
    /// <summary>
    /// 
    /// </summary>
    int32_t getTagRank() const;
    void setTagRank(int32_t const value);
    bool tagRankIsSet() const;
    void unsetTagRank();
    /// <summary>
    /// 
    /// </summary>
    int32_t getTagScore() const;
    void setTagScore(int32_t const value);
    bool tagScoreIsSet() const;
    void unsetTagScore();
    /// <summary>
    /// 
    /// </summary>
    int32_t getUpVoteCount() const;
    void setUpVoteCount(int32_t const value);
    bool upVoteCountIsSet() const;
    void unsetUpVoteCount();
    /// <summary>
    /// 
    /// </summary>
    int32_t getDownVoteCount() const;
    void setDownVoteCount(int32_t const value);
    bool downVoteCountIsSet() const;
    void unsetDownVoteCount();
    /// <summary>
    /// 
    /// </summary>
    int32_t getSharedCount() const;
    void setSharedCount(int32_t const value);
    bool sharedCountIsSet() const;
    void unsetSharedCount();
    /// <summary>
    /// 
    /// </summary>
    int32_t getReadCount() const;
    void setReadCount(int32_t const value);
    bool readCountIsSet() const;
    void unsetReadCount();
    /// <summary>
    /// 
    /// </summary>
    int32_t getShowCount() const;
    void setShowCount(int32_t const value);
    bool showCountIsSet() const;
    void unsetShowCount();
    /// <summary>
    /// 
    /// </summary>
    int32_t getCommentCount() const;
    void setCommentCount(int32_t const value);
    bool commentCountIsSet() const;
    void unsetCommentCount();
    /// <summary>
    /// 
    /// </summary>
    int32_t getFollowCount() const;
    void setFollowCount(int32_t const value);
    bool followCountIsSet() const;
    void unsetFollowCount();
    /// <summary>
    /// 
    /// </summary>
    int32_t getBookMarkCount() const;
    void setBookMarkCount(int32_t const value);
    bool bookMarkCountIsSet() const;
    void unsetBookMarkCount();
    /// <summary>
    /// 
    /// </summary>
    int32_t getBlockedCount() const;
    void setBlockedCount(int32_t const value);
    bool blockedCountIsSet() const;
    void unsetBlockedCount();

    friend  void to_json(nlohmann::json& j, const TagAttr& o);
    friend  void from_json(const nlohmann::json& j, TagAttr& o);
protected:
    std::string m_TagUuidKey;

    int32_t m_TagRank;
    bool m_TagRankIsSet;
    int32_t m_TagScore;
    bool m_TagScoreIsSet;
    int32_t m_UpVoteCount;
    bool m_UpVoteCountIsSet;
    int32_t m_DownVoteCount;
    bool m_DownVoteCountIsSet;
    int32_t m_SharedCount;
    bool m_SharedCountIsSet;
    int32_t m_ReadCount;
    bool m_ReadCountIsSet;
    int32_t m_ShowCount;
    bool m_ShowCountIsSet;
    int32_t m_CommentCount;
    bool m_CommentCountIsSet;
    int32_t m_FollowCount;
    bool m_FollowCountIsSet;
    int32_t m_BookMarkCount;
    bool m_BookMarkCountIsSet;
    int32_t m_BlockedCount;
    bool m_BlockedCountIsSet;
    
};

} // namespace org::openapitools::server::model

#endif /* TagAttr_H_ */