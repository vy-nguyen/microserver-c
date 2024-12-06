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


#include "ListCommon.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

ListCommon::ListCommon()
{
    m_ExtrasIsSet = false;
    
}

void ListCommon::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool ListCommon::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool ListCommon::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "ListCommon" : pathPrefix;

        
    if (!m_PageInfo.validate(msg, _pathPrefix + ".pageInfo")) {
        msg << _pathPrefix << ": PageInfo is invalid;";
        success = false;
    }     
    if (extrasIsSet())
    {
        const std::vector<org::openapitools::server::model::ItemId>& value = m_Extras;
        const std::string currentValuePath = _pathPrefix + ".extras";
                
        
        { // Recursive validation of array elements
            const std::string oldValuePath = currentValuePath;
            int i = 0;
            for (const org::openapitools::server::model::ItemId& value : value)
            { 
                const std::string currentValuePath = oldValuePath + "[" + std::to_string(i) + "]";
                        
        success = value.validate(msg, currentValuePath + ".extras") && success;
 
                i++;
            }
        }

    }
    
    return success;
}

bool ListCommon::operator==(const ListCommon& rhs) const
{
    return
    
    
    (getPageInfo() == rhs.getPageInfo())
     &&
    
    
    ((!extrasIsSet() && !rhs.extrasIsSet()) || (extrasIsSet() && rhs.extrasIsSet() && getExtras() == rhs.getExtras()))
    
    ;
}

bool ListCommon::operator!=(const ListCommon& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ListCommon& o)
{
    j = nlohmann::json::object();
    j["pageInfo"] = o.m_PageInfo;
    if(o.extrasIsSet() || !o.m_Extras.empty())
        j["extras"] = o.m_Extras;
    
}

void from_json(const nlohmann::json& j, ListCommon& o)
{
    j.at("pageInfo").get_to(o.m_PageInfo);
    if(j.find("extras") != j.end())
    {
        j.at("extras").get_to(o.m_Extras);
        o.m_ExtrasIsSet = true;
    } 
    
}

org::openapitools::server::model::PageInfo ListCommon::getPageInfo() const
{
    return m_PageInfo;
}
void ListCommon::setPageInfo(org::openapitools::server::model::PageInfo const& value)
{
    m_PageInfo = value;
}
std::vector<org::openapitools::server::model::ItemId> ListCommon::getExtras() const
{
    return m_Extras;
}
void ListCommon::setExtras(std::vector<org::openapitools::server::model::ItemId> const& value)
{
    m_Extras = value;
    m_ExtrasIsSet = true;
}
bool ListCommon::extrasIsSet() const
{
    return m_ExtrasIsSet;
}
void ListCommon::unsetExtras()
{
    m_ExtrasIsSet = false;
}


} // namespace org::openapitools::server::model

