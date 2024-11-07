#pragma once

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

    explicit ConnectorPool(db::DbType type) : m_dbType(type) {}

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

    const std::shared_ptr<Connector> get();
    std::string to_string() const;

  private:
    db::DbType m_dbType;
    int        m_dbPort = 3306;
    std::unique_ptr<const std::string_view> m_dbHost;
    std::unique_ptr<const std::string_view> m_dbName;
    std::unique_ptr<const std::string_view> m_userName;
    std::unique_ptr<const std::string_view> m_password;
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

    std::string to_string() const;

  private:
    Connector(int port,
            const std::string_view &host,
            const std::string_view &dbName,
            const std::string_view &user,
            const std::string_view &pass);

    std::shared_ptr<soci::session> m_session;
};

}
