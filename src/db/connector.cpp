#include <memory>
#include <iostream>
#include <soci/soci.h>
#include <db/connector.h>

namespace seal {

thread_local Connector::sh_ptr sConnector = nullptr;

const Connector::sh_ptr ConnectorPool::get()
{
    if (m_dbType != db::MySql) {
        return nullptr;
    }
    if (sConnector == nullptr) {
        try {
            sConnector = std::shared_ptr<Connector>(new Connector(
                    m_dbPort,
                    m_dbHost,
                    m_dbName,
                    m_userName,
                    m_password
                ));
        } catch (const soci::soci_error &err) {
            std::cerr << "Failed to connect: " << err.what() << std::endl;
            return nullptr;
        }
    }
    return sConnector;
}

std::string ConnectorPool::to_string() const
{
    std::ostringstream oss;
    if (sConnector == nullptr) {
        oss << "No thread\n";
    } else {
        oss << "[" << sConnector.use_count() << "]\n";
    }
    return oss.str();
}

Connector::Connector(int port,
        const std::string_view& host,
        const std::string_view& dbName,
        const std::string_view& user,
        const std::string_view& pass)
{
    std::ostringstream oss;
    oss << "db=" << dbName
        << " user=" << user
        << " password=" << pass
        << " host=" << host
        << " port=" << port;
    auto session = new soci::session(soci::mysql, oss.str());
    m_session = std::shared_ptr<soci::session>(session);
}

std::string Connector::to_string() const
{
    std::ostringstream oss;
    if (m_session != nullptr) {
        oss << "session=" << static_cast<void *>(m_session.get())
            << " ref=" << m_session.use_count() << "\n";
    } else {
        oss << "session=nullptr\n";
    }
    return oss.str();
}

}
