project(
  'SealTrust Micro', 'cpp',
  version : '1.0',
  default_options : ['cpp_std=c++17']
)

# Fetch the Pistache library as a subproject
#
pistache_dep = dependency(
  'pistache', fallback : ['pistache', 'pistache_dep']
)

# Fetch the json lib required by openapi
#
nlohmann_dep = dependency(
  'nlohmann',
  fallback : ['nlohmann', 'nlohmann_json_dep'],
  static: true,
)

# Setup cmake project for mysql connector
#
cmake = import('cmake')
soci_proj = cmake.subproject('soci', cmake_options: [
  '-DSOCI_TESTS=OFF',
  '-DSOCI_SHARED=ON',
  '-DSOCI_EMPTY=ON'
])

soci_lib = soci_proj.dependency('soci_core')
inc_dirs = include_directories(
  'src/specs/api',
  'src/specs/model',
  'subprojects/pistache/include',
  'subprojects/nlohmann/include',
)

http_specs = meson.source_root() / 'src/specs'
http_srcs = [
  http_specs / 'api/DefaultApi.cpp',
  http_specs / 'model/Helpers.cpp',
  http_specs / 'model/_hello_get_200_response.cpp',
  http_specs / 'model/_echo_post_request.cpp',
  http_specs / 'model/_echo_post_200_response.cpp',
]

http_lib = static_library(
  'http_stub_lib',
  http_srcs,
  include_directories: inc_dirs
)

#
# Define the executable to be built from the src directory
executable(
  'trustsrv',
  sources: [
    'src/main.cpp',
  ],
  link_with: [
    http_lib,
  ],
  include_directories: inc_dirs,
  dependencies: [
    soci_lib,
    nlohmann_dep,
    pistache_dep
  ],
  install: true
)
