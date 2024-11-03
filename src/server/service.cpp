#include <iostream>
#include <memory>
#include <seal/service.h>
#include <seal/config.h>
#include "restapi.h"

namespace seal {

void SealSvc::run()
{
    std::cout << "Starting server on port "
        << m_portNum << " on " << m_numThreads << " threads\n";
    auto apiHandler = RestApiImpl(m_router);

    connect_db();
    apiHandler.init();
    m_endPoint->setHandler(m_router->handler());
    m_endPoint->serve();
    m_endPoint->shutdown();
}

void SealSvc::connect_db()
{
    if (m_dbpool != nullptr) {
        return;
    }
    m_dbpool = std::make_shared<ConnectorPool>(MySql);
    m_dbpool->dbHost(Config::dbHost)
        .dbName(Config::dbName)
        .userName(Config::dbUser)
        .userPassKey(Config::EnvDBPassKey);

    auto connect = m_dbpool->get();
}

}
