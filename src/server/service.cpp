#include <iostream>
#include <seal/service.h>
#include <seal/api.h>

namespace seal {

void SealSvc::run()
{
    std::cout << "Starting server on port "
        << m_portNum << " on " << m_numThreads << " threads\n";
    auto apiHandler = RestApi(m_router);

    apiHandler.init();
    m_endPoint->setHandler(m_router->handler());
    m_endPoint->serve();
    m_endPoint->shutdown();
}

}
