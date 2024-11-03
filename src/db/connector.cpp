#include <memory>
#include <iostream>
#include <soci/soci.h>
#include <db/connector.h>

namespace seal {

const Connector ConnectorPool::get() {
    std::lock_guard<std::mutex> lock(m_mtx);

    if (m_dbType != MySql) {
        return Connector();
    }
    if (m_queue.size() < m_max) {
        try {
            m_queue.emplace_back(Connector(m_dbPort,
                    *m_dbHost,
                    *m_dbName,
                    *m_userName,
                    *m_password
                ));
            return m_queue.back();

        } catch (const soci::soci_error &err) {
            std::cerr << "Failed to connect: " << err.what() << std::endl;
        }
        return Connector();
    }
    auto idx = m_cidx;
    m_cidx = (m_cidx + 1) % m_max;
    return m_queue[idx];
}

Connector::Connector(int port,
        const std::string_view &host,
        const std::string_view &dbName,
        const std::string_view &user,
        const std::string_view &pass) {
    std::ostringstream oss;
    oss << "db=" << dbName
        << " user=" << user
        << " password=" << pass
        << " host=" << host
        << " port=" << port;
    auto session = new soci::session(soci::mysql, oss.str());
    m_session = std::shared_ptr<soci::session>(session);
}

}
