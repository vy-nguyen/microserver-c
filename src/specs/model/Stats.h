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
 * Stats.h
 *
 * 
 */

#ifndef Stats_H_
#define Stats_H_


#include "ItemId.h"
#include <vector>
#include "Counter.h"
#include <nlohmann/json.hpp>

namespace org::openapitools::server::model
{

/// <summary>
/// 
/// </summary>
class  Stats
{
public:
    Stats();
    virtual ~Stats() = default;


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

    bool operator==(const Stats& rhs) const;
    bool operator!=(const Stats& rhs) const;

    /////////////////////////////////////////////
    /// Stats members

    /// <summary>
    /// 
    /// </summary>
    org::openapitools::server::model::ItemId getItemId() const;
    void setItemId(org::openapitools::server::model::ItemId const& value);
    /// <summary>
    /// 
    /// </summary>
    int32_t getLikes() const;
    void setLikes(int32_t const value);
    bool likesIsSet() const;
    void unsetLikes();
    /// <summary>
    /// 
    /// </summary>
    int32_t getBookmark() const;
    void setBookmark(int32_t const value);
    bool bookmarkIsSet() const;
    void unsetBookmark();
    /// <summary>
    /// 
    /// </summary>
    int32_t getShares() const;
    void setShares(int32_t const value);
    bool sharesIsSet() const;
    void unsetShares();
    /// <summary>
    /// 
    /// </summary>
    std::vector<org::openapitools::server::model::Counter> getExtras() const;
    void setExtras(std::vector<org::openapitools::server::model::Counter> const& value);
    bool extrasIsSet() const;
    void unsetExtras();

    friend  void to_json(nlohmann::json& j, const Stats& o);
    friend  void from_json(const nlohmann::json& j, Stats& o);
protected:
    org::openapitools::server::model::ItemId m_ItemId;

    int32_t m_Likes;
    bool m_LikesIsSet;
    int32_t m_Bookmark;
    bool m_BookmarkIsSet;
    int32_t m_Shares;
    bool m_SharesIsSet;
    std::vector<org::openapitools::server::model::Counter> m_Extras;
    bool m_ExtrasIsSet;
    
};

} // namespace org::openapitools::server::model

#endif /* Stats_H_ */
