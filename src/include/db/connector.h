#pragma once

#include <queue>
#include <mutex>
#include <memory>
#include <soci/mysql/soci-mysql.h>
#include <db/db-driver.h>

namespace seal {

class Connector;

class ConnectorPool {
  public:
    explicit ConnectorPool(DbType type, int max = 10)
        : m_dbType(type), m_maxElem(max), m_elem(0) {}

    ConnectorPool &dbHost(const std::string_view &name) {
        m_dbHost = std::make_unique<std::string>(name);
        return *this;
    }

    ConnectorPool &dbName(const std::string_view &db) {
        m_dbName = std::make_unique<std::string>(db);
        return *this;
    }

    ConnectorPool &userName(const std::string_view &user) {
        m_userName = std::make_unique<std::string>(user);
        return *this;
    }

    ConnectorPool &userPassKey(const std::string_view &envKey) {
        auto value = std::getenv(envKey.data());
        if (value == nullptr) {
            throw "Missing env key " + std::string(envKey);
        }
        m_password = std::make_unique<std::string>(std::string(value));
        return *this;
    }

    ConnectorPool &port(int port) {
        m_dbPort = port;
        return *this;
    }

    std::shared_ptr<Connector> get();
    void put(std::shared_ptr<Connector> connector);

  private:
    DbType m_dbType;
    int    m_dbPort = 3306;
    int    m_maxElem;
    int    m_elem;
    std::unique_ptr<std::string> m_dbHost;
    std::unique_ptr<std::string> m_dbName;
    std::unique_ptr<std::string> m_userName;
    std::unique_ptr<std::string> m_password;

    std::mutex m_mtx;
    std::queue<std::shared_ptr<Connector>> m_queue;
};

class Connector {
  public:
    friend class ConnectorPool;

    std::shared_ptr<soci::session> session() {
        return m_session;
    }

  private:
    Connector(int port,
            const std::string &host,
            const std::string &dbName,
            const std::string &user,
            const std::string &pass);

    std::shared_ptr<soci::session> m_session;
};

}
