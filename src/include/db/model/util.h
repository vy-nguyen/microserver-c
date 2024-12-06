#pragma once

#include <forward_list>
#include "PageInfo.h"
#include "StatList.h"
#include "ListCommon.h"
#include "tag_attr.h"

namespace seal {
using namespace org::openapitools::server;

class dto_counter : public model::Counter
{
  public:
    dto_counter(const std::string_view& name, uint32_t value)
    {
        m_Name = name;
        m_Value = value;
    }
};

class dto_stats : public model::Stats
{
  public:
    dto_stats(tag_attr_t& tag) : model::Stats()
    {
        setLikes(tag.upVoteCount);
        setShares(tag.sharedCount);
        setBookmark(tag.bookMarkCount);
        tag.to_counters(m_Extras);
        m_ExtrasIsSet = true;
    }
};

class dto_listcommon : public model::ListCommon
{
  public:
    dto_listcommon(int nrpgs, int curpg, int64_t seq = 0, int32_t item = 0) : model::ListCommon()
    {
        m_PageInfo.setTotal(nrpgs);
        m_PageInfo.setCurrent(curpg);
        m_PageInfo.setSeqNo(seq);
        m_PageInfo.setItemCount(item);
    }

    std::vector<model::ItemId>& get_extra() {
        return m_Extras;
    }

    static void set(model::ListCommon& comm,
            int nrpgs, int curpg, int64_t seq = 0, int32_t item = 0)
    {
        auto pginfo = model::PageInfo();
        pginfo.setTotal(nrpgs);
        pginfo.setCurrent(curpg);
        pginfo.setSeqNo(seq);
        pginfo.setItemCount(item);
        comm.setPageInfo(pginfo);
    }
};

class dto_statslist : public model::StatList
{
  public:
    dto_statslist(std::forward_list<tag_attr_t::tag_attr_ptr>& list) : model::StatList()
    {
        dto_listcommon::set(m_Page, 1, 0);
        for (const auto& it : list) {
            m_List.push_back(dto_stats(*it));
        }
        dto_listcommon::set(m_Page, 1, 0, 0, m_List.size());
    }

    std::string to_dto() const
    {
        auto json = nlohmann::json();
        to_json(json, *(static_cast<const model::StatList *>(this)));
        return json.dump();
    }
};

}
