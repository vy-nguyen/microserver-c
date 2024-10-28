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


#include "StatElement.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

StatElement::StatElement()
{
    m_PeerIdIsSet = false;
    m_CounterIsSet = false;
    
}

void StatElement::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool StatElement::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool StatElement::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "StatElement" : pathPrefix;

        
    if (!m_ItemId.validate(msg, _pathPrefix + ".itemId")) {
        msg << _pathPrefix << ": ItemId is invalid;";
        success = false;
    }        
    return success;
}

bool StatElement::operator==(const StatElement& rhs) const
{
    return
    
    
    (getItemId() == rhs.getItemId())
     &&
    
    
    ((!peerIdIsSet() && !rhs.peerIdIsSet()) || (peerIdIsSet() && rhs.peerIdIsSet() && getPeerId() == rhs.getPeerId())) &&
    
    
    ((!counterIsSet() && !rhs.counterIsSet()) || (counterIsSet() && rhs.counterIsSet() && getCounter() == rhs.getCounter()))
    
    ;
}

bool StatElement::operator!=(const StatElement& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const StatElement& o)
{
    j = nlohmann::json::object();
    j["itemId"] = o.m_ItemId;
    if(o.peerIdIsSet())
        j["peerId"] = o.m_PeerId;
    if(o.counterIsSet())
        j["counter"] = o.m_Counter;
    
}

void from_json(const nlohmann::json& j, StatElement& o)
{
    j.at("itemId").get_to(o.m_ItemId);
    if(j.find("peerId") != j.end())
    {
        j.at("peerId").get_to(o.m_PeerId);
        o.m_PeerIdIsSet = true;
    } 
    if(j.find("counter") != j.end())
    {
        j.at("counter").get_to(o.m_Counter);
        o.m_CounterIsSet = true;
    } 
    
}

org::openapitools::server::model::ItemId StatElement::getItemId() const
{
    return m_ItemId;
}
void StatElement::setItemId(org::openapitools::server::model::ItemId const& value)
{
    m_ItemId = value;
}
org::openapitools::server::model::ItemId StatElement::getPeerId() const
{
    return m_PeerId;
}
void StatElement::setPeerId(org::openapitools::server::model::ItemId const& value)
{
    m_PeerId = value;
    m_PeerIdIsSet = true;
}
bool StatElement::peerIdIsSet() const
{
    return m_PeerIdIsSet;
}
void StatElement::unsetPeerId()
{
    m_PeerIdIsSet = false;
}
org::openapitools::server::model::Counter StatElement::getCounter() const
{
    return m_Counter;
}
void StatElement::setCounter(org::openapitools::server::model::Counter const& value)
{
    m_Counter = value;
    m_CounterIsSet = true;
}
bool StatElement::counterIsSet() const
{
    return m_CounterIsSet;
}
void StatElement::unsetCounter()
{
    m_CounterIsSet = false;
}


} // namespace org::openapitools::server::model

