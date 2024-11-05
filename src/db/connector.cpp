#include <memory>
#include <iostream>
#include <soci/soci.h>
#include <db/connector.h>

namespace seal {

const Connector ConnectorPool::get()
{
    std::lock_guard<std::mutex> lock(m_mtx);

    if (m_dbType != db::MySql) {
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

std::string ConnectorPool::to_string() const
{
    std::ostringstream oss;
    int count = 0;

    oss << "Max " << m_max << ", size " << m_queue.size()
        << ", index " << m_cidx << std::endl;

    for (auto it : m_queue) {
        oss << "[" << count << "] " << it.to_string();
        count++;
    }
    return oss.str();
}

Connector::Connector(int port,
        const std::string_view &host,
        const std::string_view &dbName,
        const std::string_view &user,
        const std::string_view &pass)
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
