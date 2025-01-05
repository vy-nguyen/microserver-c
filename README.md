Build:
  Change script to use apt or dnf
  scripts/predepend
  meson setup build
  cd build && ninja

Fix the build:

- Comment out boost_json dependency on jwt-cpp subproject
- Comment out soci/include/soci_platform.h error on c++-11 check.
