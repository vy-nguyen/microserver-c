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

#include "DefaultApi.h"
#include "Helpers.h"

namespace org::openapitools::server::api
{

using namespace org::openapitools::server::helpers;
using namespace org::openapitools::server::model;

const std::string DefaultApi::base = "";

DefaultApi::DefaultApi(const std::shared_ptr<Pistache::Rest::Router>& rtr)
    : ApiBase(rtr)
{
}

void DefaultApi::init() {
    setupRoutes();
}

void DefaultApi::setupRoutes() {
    using namespace Pistache::Rest;

    Routes::Post(*router, base + "/auth/counter", Routes::bind(&DefaultApi::auth_counter_post_handler, this));
    Routes::Post(*router, base + "/auth/setcounter", Routes::bind(&DefaultApi::auth_setcounter_post_handler, this));
    Routes::Post(*router, base + "/public/counter", Routes::bind(&DefaultApi::public_counter_post_handler, this));
    Routes::Get(*router, base + "/public/counters", Routes::bind(&DefaultApi::public_counters_get_handler, this));
    Routes::Get(*router, base + "/test/get", Routes::bind(&DefaultApi::test_get_get_handler, this));
    Routes::Post(*router, base + "/test/setcounter", Routes::bind(&DefaultApi::test_setcounter_post_handler, this));

    // Default handler, called when a route is not found
    router->addCustomHandler(Routes::bind(&DefaultApi::default_api_default_handler, this));
}

void DefaultApi::handleParsingException(const std::exception& ex, Pistache::Http::ResponseWriter &response) const noexcept
{
    std::pair<Pistache::Http::Code, std::string> codeAndError = handleParsingException(ex);
    response.send(codeAndError.first, codeAndError.second);
}

std::pair<Pistache::Http::Code, std::string> DefaultApi::handleParsingException(const std::exception& ex) const noexcept
{
    try {
        throw;
    } catch (nlohmann::detail::exception &e) {
        return std::make_pair(Pistache::Http::Code::Bad_Request, e.what());
    } catch (org::openapitools::server::helpers::ValidationException &e) {
        return std::make_pair(Pistache::Http::Code::Bad_Request, e.what());
    } catch (std::exception &e) {
        return std::make_pair(Pistache::Http::Code::Internal_Server_Error, e.what());
    }
}

void DefaultApi::handleOperationException(const std::exception& ex, Pistache::Http::ResponseWriter &response) const noexcept
{
    std::pair<Pistache::Http::Code, std::string> codeAndError = handleOperationException(ex);
    response.send(codeAndError.first, codeAndError.second);
}

std::pair<Pistache::Http::Code, std::string> DefaultApi::handleOperationException(const std::exception& ex) const noexcept
{
    return std::make_pair(Pistache::Http::Code::Internal_Server_Error, ex.what());
}

void DefaultApi::auth_counter_post_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {


    // Getting the body param
    
    ItemIdArray itemIdArray;
    
    try {
        nlohmann::json::parse(request.body()).get_to(itemIdArray);
        itemIdArray.validate();
    } catch (std::exception &e) {
        this->handleParsingException(e, response);
        return;
    }

    try {
        this->auth_counter_post(itemIdArray, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        this->handleOperationException(e, response);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void DefaultApi::auth_setcounter_post_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {


    // Getting the body param
    
    StatOperation statOperation;
    
    try {
        nlohmann::json::parse(request.body()).get_to(statOperation);
        statOperation.validate();
    } catch (std::exception &e) {
        this->handleParsingException(e, response);
        return;
    }

    try {
        this->auth_setcounter_post(statOperation, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        this->handleOperationException(e, response);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void DefaultApi::public_counter_post_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {


    // Getting the body param
    
    ItemIdArray itemIdArray;
    
    try {
        nlohmann::json::parse(request.body()).get_to(itemIdArray);
        itemIdArray.validate();
    } catch (std::exception &e) {
        this->handleParsingException(e, response);
        return;
    }

    try {
        this->public_counter_post(itemIdArray, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        this->handleOperationException(e, response);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void DefaultApi::public_counters_get_handler(const Pistache::Rest::Request &, Pistache::Http::ResponseWriter response) {
    try {


    try {
        this->public_counters_get(response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        this->handleOperationException(e, response);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void DefaultApi::test_get_get_handler(const Pistache::Rest::Request &, Pistache::Http::ResponseWriter response) {
    try {


    try {
        this->test_get_get(response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        this->handleOperationException(e, response);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void DefaultApi::test_setcounter_post_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {


    // Getting the body param
    
    TagAttr tagAttr;
    
    try {
        nlohmann::json::parse(request.body()).get_to(tagAttr);
        tagAttr.validate();
    } catch (std::exception &e) {
        this->handleParsingException(e, response);
        return;
    }

    try {
        this->test_setcounter_post(tagAttr, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        this->handleOperationException(e, response);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}

void DefaultApi::default_api_default_handler(const Pistache::Rest::Request &, Pistache::Http::ResponseWriter response) {
    response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

} // namespace org::openapitools::server::api

