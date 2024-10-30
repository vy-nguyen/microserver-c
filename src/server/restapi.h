#pragma once

#include <jwt-cpp/jwt.h>
#include <seal/api.h>

namespace seal {
using namespace Pistache;
using namespace org::openapitools::server;

class RestApiImpl : public RestApi {
  public:
    explicit RestApiImpl(const std::shared_ptr<Rest::Router> &router);
    virtual ~RestApiImpl() override = default;

    void init() override;

  private:
    bool auth_jwt(const Request &reqt) const override;
    void auth_handler(const Request &reqt, Response resp) const override;

    std::string m_secret;
};

}
