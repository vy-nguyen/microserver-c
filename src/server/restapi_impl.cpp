#include <iostream>
#include <memory>
#include <string_view>
#include <jwt-cpp/jwt.h>
#include <seal/config.h>
#include <jwt-cpp/traits/kazuho-picojson/traits.h>
#include "restapi.h"

namespace seal {
using namespace Pistache;
using namespace org::openapitools::server;

static constexpr std::string_view BearerPrefix = "Bearer ";
thread_local std::shared_ptr<jwt::verifier
    <jwt::default_clock, jwt::traits::kazuho_picojson>
> sVerifier;

RestApiImpl::RestApiImpl(const std::shared_ptr<Rest::Router> &router) : RestApi(router)
{
    auto key = std::string(Config::EnvSecretName);
    auto value = std::getenv(key.c_str());
    if (value == nullptr) {
        m_secret = std::string("invalid");
    } else {
        m_secret = std::string(value);
    }
}

void RestApiImpl::init()
{
    Rest::Routes::Post(*router, "/auth",
            Rest::Routes::bind(&RestApiImpl::auth_handler, this));
    Rest::Routes::Get(*router, "/auth",
            Rest::Routes::bind(&RestApiImpl::auth_handler, this));
}

bool RestApiImpl::auth_jwt(const Request &reqt) const
{
    auto authHeader = reqt.headers().tryGet<Http::Header::Authorization>();

    if (!authHeader) {
        std::cout << "Don't have JWT token header";
        return false;
    }
    std::string token;
    const std::string authValue = authHeader->value();

    if (authValue.compare(0, BearerPrefix.size(), BearerPrefix) == 0) {
        token = authValue.substr(BearerPrefix.size());
        try {
            auto decodedToken = jwt::decode(token);

            if (sVerifier == nullptr) {
                sVerifier = std::make_shared<jwt::verifier
                    <jwt::default_clock, jwt::traits::kazuho_picojson>
                >(jwt::verify().allow_algorithm(jwt::algorithm::hs512{m_secret}));
            }
            sVerifier->verify(decodedToken);
            return true;

        } catch (const jwt::error::token_verification_exception &ex) {
            std::cout << "Exception " << ex.what() << std::endl;
        } catch (std::exception &ex) {
            std::cout << "Generic Exception " << ex.what() << std::endl;
        } catch (...) {
            std::cout << "Generic unknown exception " << std::endl;
        }
        return false;
    }
    return false;
}

void RestApiImpl::auth_handler(const Request &reqt, Response resp) const
{
    if (auth_jwt(reqt)) {
        resp.send(Http::Code::Ok, "Has valid JWT\n");
    } else {
        resp.send(Http::Code::Forbidden, "Invalid JWT\n\n");
    }
}

}
