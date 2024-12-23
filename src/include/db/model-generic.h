#pragma once

#include <memory>
#include <iostream>
#include <ostream>
#include <sstream>
#include <forward_list>
#include <soci/soci.h>
#include <nlohmann/json.hpp>
#include <db/connector.h>

namespace seal {

struct int_field_val_t final {
    int                    value;
    const std::string_view field;
};

template <typename DTO>
extern void to_json(nlohmann::json &j, const DTO &o);

template <class DTO>
class DbModel
{
  public:
    using DbModel_ptr = std::shared_ptr<DTO>;

    DbModel() = default;
    virtual ~DbModel() = default;

    virtual nlohmann::json to_json_obj() const = 0;
    virtual void to_dto(DTO& dto) const = 0;

    inline std::string db_json() const {
        return to_json_obj().dump();
    }

    inline std::string dto_json(const DTO& dto) const {
        nlohmann::json json;
        to_json(json, dto);
        return json.dump();
    }

    static void
    db_json(std::ostringstream &os,
            const std::forward_list<DbModel_ptr>& array, const std::string_view tag, bool full)
    {
        if (full) {
            os << "{";
        }
        os << '"' << tag << "\": [";
        auto count = 0;
        for (const auto& it : array) {
            if (count++ > 0) {
                os << ", ";
            }
            os << it->db_json();
        }
        if (full) {
            os << "] }";
        } else {
            os << "], ";
        }
    }
};

template <class T, typename S>
class DbModelOps
{
  static_assert(std::is_base_of<DbModel<S>, T>::value, "T must be derived from DbModel");

  public:
    DbModelOps(int limit = 1024) : limit(limit) {}
    virtual ~DbModelOps() = default;

    virtual std::shared_ptr<T>
    find(const Connector::sh_ptr conn, const std::string& id) const = 0;

    virtual std::forward_list<std::shared_ptr<T>>
    find(const Connector::sh_ptr conn,
            const std::vector<std::string>& keys, int page) const
    {
        auto list = std::forward_list<std::shared_ptr<T>>();
        auto stm = get_find_stm(conn, keys, limit, page);
        auto temp = T();
        stm->exchange(soci::into(temp));
        exec_stm(stm, false);

        if (stm->got_data()) {
            do {
                auto elm = std::make_shared<T>(temp);
                list.push_front(elm);
            } while (stm->fetch());
        }
        return list;
    }

    virtual bool insert(const Connector::sh_ptr conn, const T& data) const = 0;

    virtual bool update(const Connector::sh_ptr conn, const T& data) const
    {
        auto stm = get_update_stm(conn);
        // TODO: fill in data.
        exec_stm(stm);
        return stm->got_data();
    }

    virtual void create_table(const Connector::sh_ptr conn) const
    {
        auto stm = get_create_stm(conn);
        exec_stm(stm);
    }

    virtual void delete_table(const Connector::sh_ptr conn) const
    {
        auto stm = get_delete_stm(conn);
        exec_stm(stm);
    }

    inline std::string dto_json(const T& data) const {
        S dto;
        data.to_dto(dto);
        return data.dto_json(dto);
    }

  protected:
    int limit;

    virtual std::shared_ptr<soci::statement>
    get_find_stm(const Connector::sh_ptr) const = 0;

    virtual std::shared_ptr<soci::statement>
    get_find_stm(const Connector::sh_ptr, const std::vector<std::string>&, int, int) const = 0;

    virtual std::shared_ptr<soci::statement>
    get_insert_stm(const Connector::sh_ptr) const = 0;

    virtual std::shared_ptr<soci::statement>
    get_update_stm(const Connector::sh_ptr) const = 0;

    virtual std::shared_ptr<soci::statement>
    get_create_stm(const Connector::sh_ptr) const = 0;

    virtual std::shared_ptr<soci::statement>
    get_delete_stm(const Connector::sh_ptr) const = 0;

    void exec_stm(std::shared_ptr<soci::statement> stm, bool cleanup = true) const
    {
        try {
            stm->define_and_bind();
            stm->execute(true);
            if (cleanup) {
                stm->bind_clean_up();
            }
        } catch (const soci::soci_error& err) {
            std::cout << "Failed to exec statement: " << err.what() << std::endl;
        }
    }

    std::shared_ptr<T> find_intern(const Connector::sh_ptr conn,
            const std::string& uuid, const char *idKey) const
    {
        auto out = std::make_shared<T>();
        auto stm = get_find_stm(conn);
        stm->exchange(soci::use(uuid, idKey));
        stm->exchange(soci::into(*out));
        exec_stm(stm);

        if (stm->got_data()) {
            return out;
        }
        return nullptr;
    }
 };

}
