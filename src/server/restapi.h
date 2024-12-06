#pragma once

#include <jwt-cpp/jwt.h>
#include <seal/api.h>
#include <db/connector.h>
#include <unordered_map>

namespace seal {
using namespace Pistache;
using namespace org::openapitools::server;

class ConnectorPool;

class RestApiImpl : public RestApi {
  public:
    RestApiImpl(const std::shared_ptr<Rest::Router> router, ConnectorPool::sh_ptr db_pool);

    virtual ~RestApiImpl() override = default;
    void init() override;

  protected:
    using handler_map_t = std::unordered_map<std::string, Rest::Route::Handler>;

    void register_auth_paths();
    bool auth_jwt(const Request& reqt) const;

    std::shared_ptr<RestApi::jwt_claims_t> curr_claims() override;
    void auth_get_handler(const Request& reqt, Response resp) const override;
    void auth_post_handler(const Request& reqt, Response resp) const override;
    void auth_handler(const handler_map_t& map, const Request& reqt, Response& resp) const;

    ConnectorPool::sh_ptr get_db() override {
        return m_db;
    }

    std::string           m_secret;
    handler_map_t         m_auth_get;
    handler_map_t         m_auth_post;
    ConnectorPool::sh_ptr m_db;
};

}
