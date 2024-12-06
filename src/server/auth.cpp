#include <seal/api.h>
#include <db/model/util.h>
#include <db/model/tag_attr.h>

namespace seal {

void RestApi::auth_counter_post(const model::ItemIdArray& ids, Response& resp)
{
    auto claims = curr_claims();
    auto userUuid = claims != nullptr ? claims->get_payload_claim("userUuid").as_string() : "";
    auto itemKey = ids.getItemKey();

    if (userUuid != itemKey.getOwnerUuid() || userUuid == "") {
        auto os = std::ostringstream();
        os << "Invalid owner, expected " << userUuid;
        resp.send(Http::Code::Bad_Request, os.str());
        return;
    }
    auto query_map = std::unordered_map<std::string, bool>();
    auto query_keys = std::vector<std::string>();

    for (const auto& it : ids.getItemIds()) {
        auto uuid = it.getUuid();
        auto key = (uuid.length() > ObjectId::KeyLength) ?
            ObjectId(uuid).raw() : ObjectId(true, uuid).raw();
        query_map.emplace(key, true); 
        query_keys.emplace_back(key);
    }
    auto ops = tagattr_ops();
    auto result = ops.find(get_db()->get(), query_keys, 0);
    for (const auto& it : result) {
        query_map.erase(it->tagUuidKey);
    }
    resp.headers().add<Http::Header::ContentType>(MIME(Application, Json));
    auto out = dto_statslist(result);
    resp.send(Http::Code::Ok, out.to_dto());
}

void RestApi::auth_setcounter_post(const model::StatOperation& stats, Response& resp)
{
    auto os = std::ostringstream();
    os << "In auth counter post handler, valid JWT\n";

    const auto& key = stats.getItemKey();
    os << "\ttagUuid: " << key.getTagUuid() << ", owner: " << key.getOwnerUuid() << "\n";
    resp.send(Http::Code::Ok, os.str());
}

}
