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
      SealSvc(int argc, char *argv[]) :
          m_router(std::make_shared<Rest::Router>()),
          m_opts(argc, argv) {
              init();
          }

    void init();
    void run();

  private:
    using Request = Rest::Request;
    using Response = Http::ResponseWriter;

    std::shared_ptr<ConnectorPool>  m_dbpool;
    std::shared_ptr<Rest::Router>   m_router;
    std::shared_ptr<Http::Endpoint> m_endPoint;
    ProgOpts                        m_opts;

    void connect_db();
};

}
