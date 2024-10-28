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


#include "Signature.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

Signature::Signature()
{
    m_SignedHash = "";
    m_SValue = "";
    m_RValue = "";
    m_Op = "";
    
}

void Signature::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool Signature::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool Signature::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "Signature" : pathPrefix;

                    
    return success;
}

bool Signature::operator==(const Signature& rhs) const
{
    return
    
    
    (getSignedHash() == rhs.getSignedHash())
     &&
    
    (getSValue() == rhs.getSValue())
     &&
    
    (getRValue() == rhs.getRValue())
     &&
    
    (getOp() == rhs.getOp())
    
    
    ;
}

bool Signature::operator!=(const Signature& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Signature& o)
{
    j = nlohmann::json::object();
    j["signedHash"] = o.m_SignedHash;
    j["sValue"] = o.m_SValue;
    j["rValue"] = o.m_RValue;
    j["op"] = o.m_Op;
    
}

void from_json(const nlohmann::json& j, Signature& o)
{
    j.at("signedHash").get_to(o.m_SignedHash);
    j.at("sValue").get_to(o.m_SValue);
    j.at("rValue").get_to(o.m_RValue);
    j.at("op").get_to(o.m_Op);
    
}

std::string Signature::getSignedHash() const
{
    return m_SignedHash;
}
void Signature::setSignedHash(std::string const& value)
{
    m_SignedHash = value;
}
std::string Signature::getSValue() const
{
    return m_SValue;
}
void Signature::setSValue(std::string const& value)
{
    m_SValue = value;
}
std::string Signature::getRValue() const
{
    return m_RValue;
}
void Signature::setRValue(std::string const& value)
{
    m_RValue = value;
}
std::string Signature::getOp() const
{
    return m_Op;
}
void Signature::setOp(std::string const& value)
{
    m_Op = value;
}


} // namespace org::openapitools::server::model
