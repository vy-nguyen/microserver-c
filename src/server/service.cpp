#include <iostream>
#include <memory>
#include <seal/service.h>
#include <seal/config.h>
#include "restapi.h"

namespace seal {

static Config *sinst_cfg;

void SealSvc::parse_opts()
{
    m_opts.parse();
}

void SealSvc::init()
{
    m_opts.add_option("h", "-h", "--help", "Help options", false, true);
    m_opts.add_option("c", "-c", "--config", "Configuration file in json format");
    m_opts.bind_help("h");
    parse_opts();
}

void SealSvc::run()
{
    std::cout << "Starting server on port "
        << m_portNum << " on " << m_numThreads << " threads\n";
    try {
        connect_db();
    } catch(...) {
        std::cerr << "Problem connecting to db, bail out" << std::endl;
        throw;
    }

    auto apiHandler = RestApiImpl(m_router, m_dbpool);
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
    auto config = Config::instance(m_opts);
    m_dbpool = std::make_shared<ConnectorPool>(db::MySql);
    m_dbpool->dbHost(config.get_host())
        .dbName(config.get_db_name())
        .userName(config.get_db_user())
        .userPassKey(config.get_password());

    auto connect = m_dbpool->get();
}

Config::Config()
{
    auto host = std::getenv(Config::EnvDbHost.data());
    m_host = (host == nullptr) ? Config::dbHost: std::string_view(host);

    auto user = std::getenv(Config::EnvDbUser.data());
    m_db_user = (user == nullptr) ? Config::dbUser : std::string_view(user);

    auto table = std::getenv(Config::EnvDbTable.data());
    m_db_name = (table == nullptr) ? Config::dbName : std::string_view(table);
}

void Config::setup(const ProgOpts& opts)
{
    std::cout << "Using db " << m_host << ", user "
        << m_db_user << ", table " << m_db_name << std::endl;

    auto pass = std::getenv(Config::EnvDBPassKey.data());
    if (pass == nullptr) {
        std::cerr << "Missing env key " << Config::EnvDBPassKey << std::endl;
        throw "Missing env value " + std::string(Config::EnvDBPassKey);
    }
    m_password = std::string_view(pass);
}

const Config& Config::instance(const ProgOpts& opts)
{
    if (sinst_cfg == nullptr) {
        auto inst = new Config();
        inst->setup(opts);
        sinst_cfg = inst;
    }
    return *sinst_cfg;
}

}
