#pragma once

#include <soci/mysql/soci-mysql.h>

namespace seal {

class Connector {
  public:
    Connector() = default;

    // Connector &
  private:
    std::unique_ptr<soci::session> m_session;
};

}
