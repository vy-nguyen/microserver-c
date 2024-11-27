#include <iostream>
#include <jwt-cpp/jwt.h>
#include <seal/api.h>
#include <db/connector.h>
#include <db/model/tag_attr.h>
#include <Helpers.h>

namespace seal {
using namespace Pistache;
using namespace org::openapitools::server;

// //// Test APIs.
//
void RestApi::test_get_get(Response& resp)
{
    auto pool = get_db();
    auto tag = tag_attr_t();

    tag.set_key(std::string("abcxyz"));
    auto ops = tagattr_ops();
    auto result = ops.find(pool->get(), tag.tagUuidKey);

    if (result != nullptr) {
        resp.headers().add<Http::Header::ContentType>(MIME(Application, Json));
        resp.send(Http::Code::Ok, result->to_json_obj().dump());
    } else {
        std::cout << "Not find key\n";
        resp.send(Http::Code::Ok, "Hello get is called\n");
    }
}

void RestApi::test_setcounter_post(const model::TagAttr& attr, Response& resp)
{
    auto dbattr = tag_attr_t(attr);
    auto ops = tagattr_ops();
    auto result = ops.insert(get_db()->get(), dbattr);

    resp.headers().add<Http::Header::ContentType>(MIME(Application, Json));
    if (result) {
        resp.send(Http::Code::Ok, ops.dto_json(dbattr));
    } else {
        resp.send(Http::Code::Not_Modified, "{}");
    }
}

// //// Public APIs.
//
void RestApi::public_counter_post(const model::ItemIdArray& array, Response& resp)
{
}

void RestApi::public_counters_get(Response& resp)
{
}

// //// Auth APIs
//
void RestApi::auth_setcounter_post_entry(const Request& reqt, Response resp)
{
    try {
        model::TagAttr tagAttr;
        try {
            nlohmann::json::parse(reqt.body()).get_to(tagAttr);
            tagAttr.validate();

        } catch (std::exception &e) {
            resp.send(Http::Code::Bad_Request, e.what());
            return;
        }
        try {
            this->test_setcounter_post(tagAttr, resp);

        } catch (Http::HttpError &e) {
            resp.send(static_cast<Http::Code>(e.code()), e.what());

        } catch (std::exception &e) {
            resp.send(Http::Code::Internal_Server_Error, e.what());
        }
    } catch (std::exception &e) {
        resp.send(Http::Code::Internal_Server_Error, e.what());
    }
}

void RestApi::auth_setcounter_post(const model::ItemIdArray& ids, Response& resp)
{
}

void RestApi::auth_counter_post(const model::StatOperation& stats, Response& resp)
{
}

}
