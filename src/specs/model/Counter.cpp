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


#include "Counter.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

Counter::Counter()
{
    m_Name = "";
    m_Value = 0;
    
}

void Counter::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool Counter::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool Counter::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "Counter" : pathPrefix;

            
    return success;
}

bool Counter::operator==(const Counter& rhs) const
{
    return
    
    
    (getName() == rhs.getName())
     &&
    
    (getValue() == rhs.getValue())
    
    
    ;
}

bool Counter::operator!=(const Counter& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Counter& o)
{
    j = nlohmann::json::object();
    j["name"] = o.m_Name;
    j["value"] = o.m_Value;
    
}

void from_json(const nlohmann::json& j, Counter& o)
{
    j.at("name").get_to(o.m_Name);
    j.at("value").get_to(o.m_Value);
    
}

std::string Counter::getName() const
{
    return m_Name;
}
void Counter::setName(std::string const& value)
{
    m_Name = value;
}
int32_t Counter::getValue() const
{
    return m_Value;
}
void Counter::setValue(int32_t const value)
{
    m_Value = value;
}


} // namespace org::openapitools::server::model

