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

// Per-thread cached data.
//
thread_local std::shared_ptr<RestApiImpl::jwt_claims_t> sCurrentClaims;
thread_local std::shared_ptr<jwt::verifier
    <jwt::default_clock, jwt::traits::kazuho_picojson>
> sVerifier;

RestApiImpl::RestApiImpl(const std::shared_ptr<Rest::Router> router,
        ConnectorPool::sh_ptr db_pool) : RestApi(router), m_db(db_pool)
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
    // Register public and test paths manually.
    //
    Rest::Routes::Get(*router, "/test/get",
            Rest::Routes::bind(&RestApiImpl::test_get_get_handler, this));
    Rest::Routes::Post(*router, "/test/setcounter",
            Rest::Routes::bind(&RestApiImpl::test_setcounter_post_handler, this));

    Rest::Routes::Get(*router, "/public/counters",
            Rest::Routes::bind(&RestApiImpl::public_counters_get_handler, this));
    Rest::Routes::Post(*router, "/public/counter",
            Rest::Routes::bind(&RestApiImpl::public_counter_post_handler, this));

    Rest::Routes::Post(*router, "/auth",
            Rest::Routes::bind(&RestApiImpl::auth_post_handler, this));
    Rest::Routes::Get(*router, "/auth",
            Rest::Routes::bind(&RestApiImpl::auth_get_handler, this));

    // Register auth paths in the private map.
    //
    m_auth_post.emplace("/auth/counter",
            Rest::Routes::bind(&RestApiImpl::auth_counter_post_handler, this));
    m_auth_post.emplace("/auth/setcounter",
            Rest::Routes::bind(&RestApiImpl::auth_setcounter_post_handler, this));

    register_auth_paths();
}

void RestApiImpl::register_auth_paths()
{
    for (const auto& it : m_auth_get) {
        Rest::Routes::Get(*router, it.first,
                Rest::Routes::bind(&RestApiImpl::auth_get_handler, this));
    }
    for (const auto& it : m_auth_post) {
        Rest::Routes::Post(*router, it.first,
                Rest::Routes::bind(&RestApiImpl::auth_post_handler, this));
    }
}

bool RestApiImpl::auth_jwt(const Request& reqt) const
{
    auto authHeader = reqt.headers().tryGet<Http::Header::Authorization>();

    if (!authHeader) {
        return false;
    }
    std::string token;
    const std::string authValue = authHeader->value();

    if (authValue.compare(0, BearerPrefix.size(), BearerPrefix) == 0) {
        token = authValue.substr(BearerPrefix.size());
        try {
            sCurrentClaims = std::make_shared<jwt_claims_t>(jwt::decode(token));

            if (sVerifier == nullptr) {
                sVerifier = std::make_shared<jwt::verifier
                    <jwt::default_clock, jwt::traits::kazuho_picojson>
                >(jwt::verify().allow_algorithm(jwt::algorithm::hs512{m_secret}));
            }
            sVerifier->verify(*sCurrentClaims);
            return true;

        } catch (const jwt::error::token_verification_exception &ex) {
            std::cerr << "Exception " << ex.what() << std::endl;
        } catch (std::exception &ex) {
            std::cerr << "Generic Exception " << ex.what() << std::endl;
        } catch (...) {
            std::cerr << "Generic unknown exception " << std::endl;
        }
        return false;
    }
    return false;
}

void RestApiImpl::auth_get_handler(const Request& reqt, Response resp) const {
    auth_handler(m_auth_get, reqt, resp);
}

void RestApiImpl::auth_post_handler(const Request& reqt, Response resp) const {
    auth_handler(m_auth_post, reqt, resp);
}

std::shared_ptr<RestApi::jwt_claims_t> RestApiImpl::curr_claims() {
    return sCurrentClaims;
}

void RestApiImpl::auth_handler(const handler_map_t& map,
        const Request& reqt, Response& resp) const
{
    if (auth_jwt(reqt)) {
        const auto path = reqt.resource();
        const auto& handler = map.find(path);
        if (handler != map.end()) {
            handler->second(reqt, std::move(resp));
        } else {
            resp.send(Http::Code::Bad_Request, "Invalid route\n\n");
        }
    } else {
        resp.send(Http::Code::Forbidden, "Invalid JWT\n\n");
    }
    sCurrentClaims = nullptr;
}

}
