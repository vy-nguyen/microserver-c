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
    static const size_t MaxRequestSize = (64 << 10);
    static const size_t MaxResponseSize = (64 << 10);

    SealSvc(uint16_t port = 8000, unsigned int numThr = std::thread::hardware_concurrency()) :
        m_portNum(port),
        m_numThreads(numThr),
        m_address(Ipv4::any(), Port(port)),
        m_router(std::make_shared<Rest::Router>()),
        m_endPoint(std::make_shared<Http::Endpoint>(m_address))
    {
        auto opts = Http::Endpoint::options().threads(m_numThreads);
        opts.flags(Tcp::Options::ReuseAddr);
        opts.maxRequestSize(MaxRequestSize);
        opts.maxResponseSize(MaxResponseSize);
        m_endPoint->init(opts);
    }

    void run();

  private:
    using Request = Rest::Request;
    using Response = Http::ResponseWriter;

    uint16_t      m_portNum;
    unsigned int  m_numThreads;
    Address       m_address;
    std::shared_ptr<Rest::Router>   m_router;
    std::shared_ptr<Http::Endpoint> m_endPoint;
};

}
