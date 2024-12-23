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


#include "PageInfo.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

PageInfo::PageInfo()
{
    m_Total = 1;
    m_Current = 0;
    m_SeqNo = 0L;
    m_SeqNoIsSet = false;
    m_ItemCount = 0;
    m_ItemCountIsSet = false;
    
}

void PageInfo::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool PageInfo::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool PageInfo::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "PageInfo" : pathPrefix;

                    
    return success;
}

bool PageInfo::operator==(const PageInfo& rhs) const
{
    return
    
    
    (getTotal() == rhs.getTotal())
     &&
    
    (getCurrent() == rhs.getCurrent())
     &&
    
    
    ((!seqNoIsSet() && !rhs.seqNoIsSet()) || (seqNoIsSet() && rhs.seqNoIsSet() && getSeqNo() == rhs.getSeqNo())) &&
    
    
    ((!itemCountIsSet() && !rhs.itemCountIsSet()) || (itemCountIsSet() && rhs.itemCountIsSet() && getItemCount() == rhs.getItemCount()))
    
    ;
}

bool PageInfo::operator!=(const PageInfo& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PageInfo& o)
{
    j = nlohmann::json::object();
    j["total"] = o.m_Total;
    j["current"] = o.m_Current;
    if(o.seqNoIsSet())
        j["seqNo"] = o.m_SeqNo;
    if(o.itemCountIsSet())
        j["itemCount"] = o.m_ItemCount;
    
}

void from_json(const nlohmann::json& j, PageInfo& o)
{
    j.at("total").get_to(o.m_Total);
    j.at("current").get_to(o.m_Current);
    if(j.find("seqNo") != j.end())
    {
        j.at("seqNo").get_to(o.m_SeqNo);
        o.m_SeqNoIsSet = true;
    } 
    if(j.find("itemCount") != j.end())
    {
        j.at("itemCount").get_to(o.m_ItemCount);
        o.m_ItemCountIsSet = true;
    } 
    
}

int32_t PageInfo::getTotal() const
{
    return m_Total;
}
void PageInfo::setTotal(int32_t const value)
{
    m_Total = value;
}
int32_t PageInfo::getCurrent() const
{
    return m_Current;
}
void PageInfo::setCurrent(int32_t const value)
{
    m_Current = value;
}
int64_t PageInfo::getSeqNo() const
{
    return m_SeqNo;
}
void PageInfo::setSeqNo(int64_t const value)
{
    m_SeqNo = value;
    m_SeqNoIsSet = true;
}
bool PageInfo::seqNoIsSet() const
{
    return m_SeqNoIsSet;
}
void PageInfo::unsetSeqNo()
{
    m_SeqNoIsSet = false;
}
int32_t PageInfo::getItemCount() const
{
    return m_ItemCount;
}
void PageInfo::setItemCount(int32_t const value)
{
    m_ItemCount = value;
    m_ItemCountIsSet = true;
}
bool PageInfo::itemCountIsSet() const
{
    return m_ItemCountIsSet;
}
void PageInfo::unsetItemCount()
{
    m_ItemCountIsSet = false;
}


} // namespace org::openapitools::server::model

