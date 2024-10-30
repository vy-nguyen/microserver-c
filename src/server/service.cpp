#include <iostream>
#include <seal/service.h>
#include "restapi.h"

namespace seal {

void SealSvc::run()
{
    std::cout << "Starting server on port "
        << m_portNum << " on " << m_numThreads << " threads\n";
    auto apiHandler = RestApiImpl(m_router);

    apiHandler.init();
    m_endPoint->setHandler(m_router->handler());
    m_endPoint->serve();
    m_endPoint->shutdown();
}

}
