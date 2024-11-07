#include <iostream>
#include <jwt-cpp/jwt.h>
#include <seal/api.h>
#include <db/connector.h>
#include <db/model/tag_attr.h>

namespace seal {
using namespace Pistache;
using namespace org::openapitools::server;

void RestApi::public_hello_entry(const Request &reqt, Response resp)
{
    auto pool = get_db();
    auto tag = TagAttr();

    tag.set_key(std::string("abcdef"));
    auto ops = TagAttrOps();
    auto result = ops.find(pool->get(), tag.tagUuidKey);

    if (result != nullptr) {
        resp.headers().add<Http::Header::ContentType>(MIME(Application, Json));
        resp.send(Http::Code::Ok, result->to_json().dump());
    } else {
        std::cout << "Not find key\n";
        resp.send(Http::Code::Ok, "Hello get is called\n");
    }
}

void RestApi::public_hello_get(Response &resp)
{
}

void RestApi::public_counter_post(const model::ItemIdArray &array, Response &resp)
{
}

void RestApi::auth_counter_post(const model::StatOperation &stats, Response &resp)
{
}

void RestApi::auth_echo_post(const model::_auth_echo_post_request &reqt, Response &resp)
{
    resp.send(Http::Code::Ok, "Echo post is called\n");
}

}
