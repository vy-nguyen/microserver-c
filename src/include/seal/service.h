#pragma once

#include <memory>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/mime.h>

namespace seal {

using namespace Pistache;

class SealSvc {
  public:
    SealSvc(uint16_t port = 8000, unsigned int numThr = std::thread::hardware_concurrency()) :
        m_portNum(port),
        m_numThreads(numThr),
        m_address("0.0.0.0", port),
        m_endPoint(std::make_shared<Http::Endpoint>(m_address)) {
    }
    void run();

  private:
    using Request = Rest::Request;
    using Response = Http::ResponseWriter;

    uint16_t      m_portNum;
    unsigned int  m_numThreads;
    Address       m_address;
    Rest::Router  m_router;
    std::shared_ptr<Http::Endpoint> m_endPoint;
};

}
