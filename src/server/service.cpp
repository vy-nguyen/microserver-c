#include <iostream>
#include <fstream>
#include <memory>
#include <seal/service.h>
#include <seal/config.h>
#include "restapi.h"

namespace seal {

static Config *sinst_cfg;

void SealSvc::init()
{
    auto& config = Config::instance(); 
    m_opts.add_action("c", std::bind(&Config::cmdline_config, &config, std::placeholders::_1));
    m_opts.add_option("c", "-c", "--config", "json_file", "Configuration file in json format");
    m_opts.add_option("h", "-h", "--help", "", "Help options", false, true);
    m_opts.bind_help("h");
    m_opts.parse();
    config.setup(m_opts);

    auto port = config.get_port();
    auto nrthr = config.get_nr_thread();
    std::cout << "Starting server on port " << port << " on " << nrthr << " threads\n";

    auto address = Pistache::Address(Pistache::Ipv4::any(), Pistache::Port(port));
    auto opts = Pistache::Http::Endpoint::options().threads(nrthr);

    opts.flags(Pistache::Tcp::Options::ReuseAddr);
    opts.maxRequestSize(config.get_max_reqt_sz());
    opts.maxResponseSize(config.get_max_resp_sz());
    m_endPoint = std::make_shared<Pistache::Http::Endpoint>(address);
    m_endPoint->init(opts);
}

void SealSvc::run()
{
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
    auto& config = Config::instance();
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

    auto pass = std::getenv(Config::EnvDBPassKey.data());
    if (pass == nullptr) {
        std::cerr << "Missing env key " << Config::EnvDBPassKey << std::endl;
        throw "Missing env value " + std::string(Config::EnvDBPassKey);
    }
    m_password = std::string_view(pass);

    m_port = Config::ListenPort;
    m_svc_thr = std::thread::hardware_concurrency();
}

void Config::setup(const ProgOpts& opts)
{
    std::cout << "Using db " << m_host << ", user "
        << m_db_user << ", table " << m_db_name << std::endl;

}

void Config::cmdline_config(const popt_arg_t& opt)
{
    auto jsfile = opt.value();
    std::cout << "Using config " << jsfile << std::endl;

    try {
        std::ifstream file(jsfile);
        if (!file.is_open()) {
        }
        nlohmann::json j;
        file >> j;

        file.close();
    } catch (std::exception &e) {
    }
}

Config& Config::instance()
{
    if (sinst_cfg == nullptr) {
        sinst_cfg = new Config();
    }
    return *sinst_cfg;
}

}
