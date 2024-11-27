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
    RestApiImpl(const std::shared_ptr<Rest::Router> router,
            std::shared_ptr<ConnectorPool> db_pool);

    virtual ~RestApiImpl() override = default;

    void init() override;

  protected:
    bool auth_jwt(const Request &reqt) const override;
    void auth_get_handler(const Request &reqt, Response resp) const override;
    void auth_post_handler(const Request &reqt, Response resp) const override;
    void register_auth_paths();

    std::shared_ptr<ConnectorPool> get_db() override {
        return m_db;
    }

    std::string m_secret;
    std::shared_ptr<ConnectorPool> m_db;
    std::unordered_map<std::string, Rest::Route::Handler> m_auth_get;
    std::unordered_map<std::string, Rest::Route::Handler> m_auth_post;
};

}
