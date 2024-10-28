#pragma once

#include "ItemIdArray.h"
#include <pistache/http.h>
#include <DefaultApi.h>

namespace seal {

using namespace Pistache;
using namespace org::openapitools::server;

class RestApi : public api::DefaultApi {
  public:
    using Request = Rest::Request;
    using Response = Http::ResponseWriter;

    explicit RestApi(const std::shared_ptr<Rest::Router> &router);
    ~RestApi() override = default;

    void auth_echo_post(const model::_auth_echo_post_request &reqt, Response &resp) override;
    void public_hello_get(Response &resp) override;

    void auth_counter_post(const model::StatOperation &stats, Response &resp) override;
    void public_counter_post(const model::ItemIdArray &array, Response &resp) override;
};

}
