#pragma once

#include <pistache/http.h>
#include <_echo_post_request.h>
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

    void echo_post(const model::_echo_post_request &reqt, Response &resp) override;
    void hello_get(Response &resp) override;
};

}
