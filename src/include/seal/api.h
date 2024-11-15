#pragma once

#include <pistache/http.h>
#include <DefaultApi.h>
#include "ItemIdArray.h"
#include "TagAttr.h"

namespace seal {

using namespace Pistache;
using namespace org::openapitools::server;

class ConnectorPool;

class RestApi : public api::DefaultApi {
  public:
    using Request = Rest::Request;
    using Response = Http::ResponseWriter;

    explicit RestApi(const std::shared_ptr<Rest::Router> &router) : DefaultApi(router) {}
    virtual ~RestApi() override = default;

    void auth_echo_post(const model::_auth_echo_post_request &reqt, Response &resp) override;
    void auth_counter_post(const model::StatOperation &stats, Response &resp) override;

    void public_hello_entry(const Request &reqt, Response resp);
    void public_counter_post(const model::ItemIdArray &array, Response &resp) override;

    void auth_counter_post_entry(const Request &reqt, Response resp);
    void auth_setcounter_post_entry(const Request &reqt, Response resp);

  protected:
    virtual std::shared_ptr<ConnectorPool> get_db() = 0;
    virtual bool auth_jwt(const Request &reqt) const = 0;
    virtual void auth_handler(const Request &reqt, Response resp) const = 0;

  private:
    void public_hello_get(Response &resp) override;

    void auth_setcounter_post(const model::TagAttr &attr, Response &resp) override;
};

}
