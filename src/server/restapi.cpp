#include "ItemIdArray.h"
#include "StatOperation.h"
#include <seal/api.h>

namespace seal {

using namespace Pistache;
using namespace org::openapitools::server;

RestApi::RestApi(const std::shared_ptr<Rest::Router> &router) : api::DefaultApi(router)
{
}

void RestApi::auth_echo_post(const model::_auth_echo_post_request &reqt, Response &resp)
{
    resp.send(Http::Code::Ok, "Echo post is called\n");
}

void RestApi::public_hello_get(Response &resp)
{
    resp.send(Http::Code::Ok, "Hello get is called\n");
}

void RestApi::public_counter_post(const model::ItemIdArray &array, Response &resp)
{
}

void RestApi::auth_counter_post(const model::StatOperation &stats, Response &resp)
{
}

}
