#include <seal/api.h>

namespace seal {

using namespace Pistache;
using namespace org::openapitools::server;

RestApi::RestApi(const std::shared_ptr<Rest::Router> &router) : api::DefaultApi(router)
{
}

void RestApi::echo_post(const model::_echo_post_request &reqt, Response &resp)
{
    resp.send(Http::Code::Ok, "Echo post is called\n");
}

void RestApi::hello_get(Response &resp)
{
    resp.send(Http::Code::Ok, "Hello get is called\n");
}

}
