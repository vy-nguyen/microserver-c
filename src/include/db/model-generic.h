#pragma once

#include <memory>
#include <iostream>
#include <forward_list>
#include <ostream>
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
};

template <class T, typename S>
class DbModelOps
{
  static_assert(std::is_base_of<DbModel<S>, T>::value, "T must be derived from DbModel");

  public:
    DbModelOps(int limit = 1024) : limit(limit) {}
    virtual ~DbModelOps() = default;

    virtual std::shared_ptr<T>
    find(const std::shared_ptr<Connector> conn, const std::string& id) const = 0;

    virtual std::forward_list<std::shared_ptr<T>>
    find(const std::shared_ptr<Connector> conn,
            const std::vector<std::string>& keys, int page) const
    {
        auto list = std::forward_list<std::shared_ptr<T>>();
        auto results = std::vector<T>();
        auto keyids = to_key_set(keys);
        auto temp = T();

        try {
            soci::statement stm = (conn->session()->prepare << get_find_keys_stm(),
                    soci::use(keyids, "keyIds"),
                    soci::use(limit, "limit"),
                    soci::use(limit * page, "offset"),
                    soci::into(temp));

            stm.execute(true);
            stm.bind_clean_up();
            if (stm.got_data()) {
                while (stm.fetch()) {
                    auto elm = std::make_shared<T>(temp);
                    list.push_front(elm);
                } 
            }
        } catch (const soci::soci_error& err) {
            std::cerr << "Failed to find set " << err.what() << std::endl;
        }
        return list;
    }

    virtual bool insert(const std::shared_ptr<Connector> conn, const T& data) const
    {
        try {
            *conn->session() << get_insert_stm(), soci::use(data);
            return true;

        } catch (const soci::soci_error& err) {
            std::cerr << "Failed to insert " << err.what() << std::endl;
        }
        return false;
    }

    virtual bool update(const std::shared_ptr<Connector> conn, const T& data) const
    {
        try {
            *conn->session() << get_update_stm(), soci::use(data);
            return true;

        } catch (const soci::soci_error& err) {
            std::cerr << "Failed to update " << err.what() << std::endl;
        }
        return false;
    }

    virtual void create_table(const std::shared_ptr<Connector> conn) const
    {
        try {
            *conn->session() << get_create_stm();
        } catch (const soci::soci_error& err) {
            std::cerr << "Failed to create table " << err.what() << std::endl;
        }
    }

    virtual void delete_table(const std::shared_ptr<Connector> conn) const
    {
        try {
            *conn->session() << get_delete_stm();
        } catch (const soci::soci_error& err) {
            std::cerr << "Failed to delete table " << err.what() << std::endl;
        }
    }

    inline std::string dto_json(const T& data) const {
        S dto;
        data.to_dto(dto);
        return data.dto_json(dto);
    }

  protected:
    int limit;

    virtual const std::string_view get_find_stm() const = 0;
    virtual const std::string_view get_find_keys_stm() const = 0;
    virtual const std::string_view get_insert_stm() const = 0;
    virtual const std::string_view get_update_stm() const = 0;
    virtual const std::string_view get_create_stm() const = 0;
    virtual const std::string_view get_delete_stm() const = 0;

    std::string to_key_set(const std::vector<std::string>& array) const
    {
        std::ostringstream oss;

        for (size_t i = 0; i < array.size(); ++i) {
            oss << array[i];
            if (i != (array.size() - 1)) {
                oss << ", ";
            }
        }
        return oss.str();
    }
};

}
