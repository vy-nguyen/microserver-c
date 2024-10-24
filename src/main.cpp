#include <memory>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/mime.h>
#include <iostream>

namespace seal {

class Service {
  public:
    Service(uint16_t port = 8000, unsigned int noThr = std::thread::hardware_concurrency()) :
        m_portNum(port),
        m_numThreads(noThr),
        m_address("localhost", port),
        m_endPoint(std::make_shared<Pistache::Http::Endpoint>(m_address)) {
    }

    void run();

  private:
    using Request = Pistache::Rest::Request;
    using Response = Pistache::Http::ResponseWriter;

    void configureRoutes();
    void hello(const Request &request, Response response);

    uint16_t m_portNum;
    unsigned int m_numThreads;
    Pistache::Address m_address;
    std::shared_ptr<Pistache::Http::Endpoint> m_endPoint;
    Pistache::Rest::Router m_router;
};

void Service::configureRoutes() {
    using namespace Pistache::Rest;

    Routes::Get(m_router, "/hello", Routes::bind(&Service::hello, this));
}

void Service::run() {
    std::cout << "Staring server on port " << m_portNum << " on " << m_numThreads << " threads\n";
    m_endPoint->init(Pistache::Http::Endpoint::options().threads(m_numThreads));

    configureRoutes();
    m_endPoint->setHandler(m_router.handler());
    m_endPoint->serve();
}

void Service::hello(const Request &request, Response response) {
    response.send(Pistache::Http::Code::Ok,
            "Hello from C++ server\n",
            MIME(Text, Plain));
}

}

int main() {
    try {
        seal::Service service;
        service.run();

    } catch (const std::exception &exp) {
        std::cerr << exp.what() << std::endl;
        return 1;
    } catch (...) {
        return 1;
    }
    return 0;
}
