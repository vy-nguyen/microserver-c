#include <iostream>
#include <memory>
#include <sstream>
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

RestApiImpl::RestApiImpl(const std::shared_ptr<Rest::Router> router,
        std::shared_ptr<ConnectorPool> db_pool) : RestApi(router), m_db(db_pool)
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
                Rest::Routes::bind(&RestApiImpl::auth_post_handler, this));
    }
    for (const auto& it : m_auth_post) {
        Rest::Routes::Get(*router, it.first,
                Rest::Routes::bind(&RestApiImpl::auth_get_handler, this));
    }
}

bool RestApiImpl::auth_jwt(const Request& reqt) const
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

void RestApiImpl::auth_get_handler(const Request& reqt, Response resp) const
{
    if (auth_jwt(reqt)) {
        auto path = reqt.resource();
        auto os = std::ostringstream();
        os << "Has valid JWT " << reqt.resource() << "\n";
        resp.send(Http::Code::Ok, os.str());
    } else {
        resp.send(Http::Code::Forbidden, "Invalid JWT\n\n");
    }
}

void RestApiImpl::auth_post_handler(const Request& reqt, Response resp) const
{
    if (auth_jwt(reqt)) {
        auto path = reqt.resource();
        auto os = std::ostringstream();
        os << "Has valid JWT Post " << reqt.resource() << "\n";
        resp.send(Http::Code::Ok, os.str());
    } else {
        resp.send(Http::Code::Forbidden, "Invalid JWT\n\n");
    }
}

}
