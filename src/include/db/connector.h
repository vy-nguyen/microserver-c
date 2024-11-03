#pragma once

#include <mutex>
#include <memory>
#include <soci/mysql/soci-mysql.h>
#include <db/db-driver.h>

namespace seal {

class Connector;

class ConnectorPool {
  public:
    friend class Connector;

    ConnectorPool(const ConnectorPool &) = delete;
    ConnectorPool &operator =(const ConnectorPool &) = delete;

    explicit ConnectorPool(DbType type, int max = 10) :
        m_dbType(type), m_cidx(0), m_max(max)
    {
        m_queue.reserve(m_max);
    }

    ConnectorPool &dbHost(const std::string_view &name) {
        m_dbHost = std::make_unique<std::string_view>(name);
        return *this;
    }

    ConnectorPool &dbName(const std::string_view &db) {
        m_dbName = std::make_unique<std::string_view>(db);
        return *this;
    }

    ConnectorPool &userName(const std::string_view &user) {
        m_userName = std::make_unique<std::string_view>(user);
        return *this;
    }

    ConnectorPool &userPassKey(const std::string_view &envKey) {
        auto value = std::getenv(envKey.data());
        if (value == nullptr) {
            throw "Missing env key " + std::string(envKey);
        }
        m_password = std::make_unique<std::string_view>(std::string_view(value));
        return *this;
    }

    ConnectorPool &port(int port) {
        m_dbPort = port;
        return *this;
    }

    const Connector get();

  private:
    DbType m_dbType;
    int    m_dbPort = 3306;
    int    m_cidx;
    size_t m_max;
    std::unique_ptr<const std::string_view> m_dbHost;
    std::unique_ptr<const std::string_view> m_dbName;
    std::unique_ptr<const std::string_view> m_userName;
    std::unique_ptr<const std::string_view> m_password;

    std::mutex             m_mtx;
    std::vector<Connector> m_queue;

    void put(const Connector &connector);
};

class Connector {
  public:
    friend class ConnectorPool;
    Connector() = default;
    Connector(const Connector &) = default;
    Connector &operator =(const Connector &) = default;

    const std::shared_ptr<soci::session> session() const {
        return m_session;
    }

    bool is_valid() const {
        return m_session != nullptr;
    }

  private:
    Connector(int port,
            const std::string_view &host,
            const std::string_view &dbName,
            const std::string_view &user,
            const std::string_view &pass);

    std::shared_ptr<soci::session> m_session;
};

}
