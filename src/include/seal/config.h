#pragma once

#include <string_view>
#include <util/prog_opts.h>

namespace seal {

class Config {
  public:
    static constexpr uint16_t ListenPort       = 8000;
    static constexpr size_t   MaxRequestSize  = (64 << 10);
    static constexpr size_t   MaxResponseSize = (128 << 10);

    static constexpr std::string_view EnvSecretName = "JWT_SECRET";
    static constexpr std::string_view EnvDBPassKey  = "DB_USER_PASS";
    static constexpr std::string_view EnvDbHost     = "DB_HOST";
    static constexpr std::string_view EnvDbUser     = "DB_USER";
    static constexpr std::string_view EnvDbTable    = "DB_TABLE";
    static constexpr std::string_view dbName        = "keotrust";
    static constexpr std::string_view dbUser        = "socnet";
    static constexpr std::string_view dbHost        = "localhost";

    const std::string_view get_host() const {
        return m_host;
    }

    const std::string_view get_db_user() const {
        return m_db_user;
    }

    const std::string_view get_db_name() const {
        return m_db_name;
    }

    const std::string_view get_password() const {
        return m_password;
    }

    uint16_t get_port() const {
        return m_port;
    }

    unsigned int get_nr_thread() const {
        return m_svc_thr;
    }

    size_t get_max_reqt_sz() const {
        return m_maxreqt_sz;
    }

    size_t get_max_resp_sz() const {
        return m_maxresp_sz;
    }

    void cmdline_config(const popt_arg_t& opt);
    void setup(const ProgOpts& opts);

    ~Config() {}
    static Config& instance();

  protected:
    uint16_t         m_port;
    unsigned int     m_svc_thr;
    size_t           m_maxreqt_sz;
    size_t           m_maxresp_sz;
    std::string_view m_host;
    std::string_view m_db_user;
    std::string_view m_db_name;
    std::string_view m_password;

  private:
    Config();
};

}
