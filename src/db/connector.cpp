#include <memory>
#include <iostream>
#include <soci/soci.h>
#include <db/connector.h>

namespace seal {

std::shared_ptr<Connector> ConnectorPool::get() {
    std::lock_guard<std::mutex> lock(m_mtx);

    if (m_dbType != MySql) {
        return nullptr;
    }
    if (!m_queue.empty()) {
        auto connector = m_queue.front();
        m_queue.pop();
        return connector;
    }
    if (m_elem < m_maxElem) {
        try {
            auto out = std::make_shared<Connector>(Connector(
                        m_dbPort,
                        *m_dbHost,
                        *m_dbName,
                        *m_userName,
                        *m_password
                    ));
            if (++m_elem >= m_maxElem) {
                return nullptr;
            }
            return out;

        } catch (const soci::soci_error &err) {
            std::cerr << "Failed to connect: " << err.what() << std::endl;
        }
    }
    return nullptr;
}

void ConnectorPool::put(std::shared_ptr<Connector> connector) {
    std::lock_guard<std::mutex> lock(m_mtx);
    m_queue.push(connector);
}

Connector::Connector(int port,
        const std::string &host,
        const std::string &dbName,
        const std::string &user,
        const std::string &pass) {
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
