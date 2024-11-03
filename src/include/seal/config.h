#pragma once

#include <string_view>

namespace seal {

class Config {
  public:
    static constexpr uint16_t ListenPort       = 8000;
    static constexpr size_t   MaxRequestSize  = (64 << 10);
    static constexpr size_t   MaxResponseSize = (128 << 10);

    static constexpr std::string_view EnvSecretName = "JWT_SECRET";
    static constexpr std::string_view EnvDBPassKey  = "DB_USER_PASS";
    static constexpr std::string_view dbName        = "keotrust";
    static constexpr std::string_view dbUser        = "socnet";
    static constexpr std::string_view dbHost        = "localhost";
};

}
