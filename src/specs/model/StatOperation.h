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
 * StatOperation.h
 *
 * 
 */

#ifndef StatOperation_H_
#define StatOperation_H_


#include "Signature.h"
#include "ItemKey.h"
#include "StatElement.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace org::openapitools::server::model
{

/// <summary>
/// 
/// </summary>
class  StatOperation
{
public:
    StatOperation();
    virtual ~StatOperation() = default;


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

    bool operator==(const StatOperation& rhs) const;
    bool operator!=(const StatOperation& rhs) const;

    /////////////////////////////////////////////
    /// StatOperation members

    /// <summary>
    /// 
    /// </summary>
    org::openapitools::server::model::ItemKey getItemKey() const;
    void setItemKey(org::openapitools::server::model::ItemKey const& value);
    /// <summary>
    /// 
    /// </summary>
    org::openapitools::server::model::Signature getSignature() const;
    void setSignature(org::openapitools::server::model::Signature const& value);
    /// <summary>
    /// 
    /// </summary>
    std::vector<org::openapitools::server::model::StatElement> getValues() const;
    void setValues(std::vector<org::openapitools::server::model::StatElement> const& value);

    friend  void to_json(nlohmann::json& j, const StatOperation& o);
    friend  void from_json(const nlohmann::json& j, StatOperation& o);
protected:
    org::openapitools::server::model::ItemKey m_ItemKey;

    org::openapitools::server::model::Signature m_Signature;

    std::vector<org::openapitools::server::model::StatElement> m_Values;

    
};

} // namespace org::openapitools::server::model

#endif /* StatOperation_H_ */
