#pragma once

#include <memory>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/mime.h>
#include "seal/config.h"
#include "db/connector.h"

namespace seal {

using namespace Pistache;

class SealSvc {
  public:
    SealSvc(int argc, char *argv[], uint16_t port = Config::ListenPort,
            unsigned int numThr = std::thread::hardware_concurrency()) :
        m_portNum(port),
        m_numThreads(numThr),
        m_address(Ipv4::any(), Port(port)),
        m_router(std::make_shared<Rest::Router>()),
        m_endPoint(std::make_shared<Http::Endpoint>(m_address)),
        m_opts(argc, argv)
    {
        init();
        auto opts = Http::Endpoint::options().threads(m_numThreads);
        opts.flags(Tcp::Options::ReuseAddr);
        opts.maxRequestSize(Config::MaxRequestSize);
        opts.maxResponseSize(Config::MaxResponseSize);
        m_endPoint->init(opts);
    }

    void init();
    void run();

  private:
    using Request = Rest::Request;
    using Response = Http::ResponseWriter;

    uint16_t      m_portNum;
    unsigned int  m_numThreads;
    Address       m_address;
    
    std::shared_ptr<ConnectorPool>  m_dbpool;
    std::shared_ptr<Rest::Router>   m_router;
    std::shared_ptr<Http::Endpoint> m_endPoint;
    ProgOpts                        m_opts;

    void parse_opts();
    void connect_db();
};

}
