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


#include "ItemKey.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

ItemKey::ItemKey()
{
    m_TagUuid = "";
    m_ElemUuid = "";
    m_ElemUuidIsSet = false;
    m_OwnerUuid = "";
    m_SeqNo = 0L;
    
}

void ItemKey::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool ItemKey::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool ItemKey::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "ItemKey" : pathPrefix;

                        
    return success;
}

bool ItemKey::operator==(const ItemKey& rhs) const
{
    return
    
    
    (getTagUuid() == rhs.getTagUuid())
     &&
    
    
    ((!elemUuidIsSet() && !rhs.elemUuidIsSet()) || (elemUuidIsSet() && rhs.elemUuidIsSet() && getElemUuid() == rhs.getElemUuid())) &&
    
    (getOwnerUuid() == rhs.getOwnerUuid())
     &&
    
    (getKind() == rhs.getKind())
     &&
    
    (getSeqNo() == rhs.getSeqNo())
    
    
    ;
}

bool ItemKey::operator!=(const ItemKey& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ItemKey& o)
{
    j = nlohmann::json::object();
    j["tagUuid"] = o.m_TagUuid;
    if(o.elemUuidIsSet())
        j["elemUuid"] = o.m_ElemUuid;
    j["ownerUuid"] = o.m_OwnerUuid;
    j["kind"] = o.m_Kind;
    j["seqNo"] = o.m_SeqNo;
    
}

void from_json(const nlohmann::json& j, ItemKey& o)
{
    j.at("tagUuid").get_to(o.m_TagUuid);
    if(j.find("elemUuid") != j.end())
    {
        j.at("elemUuid").get_to(o.m_ElemUuid);
        o.m_ElemUuidIsSet = true;
    } 
    j.at("ownerUuid").get_to(o.m_OwnerUuid);
    j.at("kind").get_to(o.m_Kind);
    j.at("seqNo").get_to(o.m_SeqNo);
    
}

std::string ItemKey::getTagUuid() const
{
    return m_TagUuid;
}
void ItemKey::setTagUuid(std::string const& value)
{
    m_TagUuid = value;
}
std::string ItemKey::getElemUuid() const
{
    return m_ElemUuid;
}
void ItemKey::setElemUuid(std::string const& value)
{
    m_ElemUuid = value;
    m_ElemUuidIsSet = true;
}
bool ItemKey::elemUuidIsSet() const
{
    return m_ElemUuidIsSet;
}
void ItemKey::unsetElemUuid()
{
    m_ElemUuidIsSet = false;
}
std::string ItemKey::getOwnerUuid() const
{
    return m_OwnerUuid;
}
void ItemKey::setOwnerUuid(std::string const& value)
{
    m_OwnerUuid = value;
}
org::openapitools::server::model::IdKind ItemKey::getKind() const
{
    return m_Kind;
}
void ItemKey::setKind(org::openapitools::server::model::IdKind const& value)
{
    m_Kind = value;
}
int64_t ItemKey::getSeqNo() const
{
    return m_SeqNo;
}
void ItemKey::setSeqNo(int64_t const value)
{
    m_SeqNo = value;
}


} // namespace org::openapitools::server::model
