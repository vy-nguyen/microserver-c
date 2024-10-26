project(
  'SealTrust Micro', 'cpp',
  version : '1.0',
  default_options : ['cpp_std=c++17']
)

project_source = [
  'src/main.cpp',
]

# Fetch the json lib required by openapi
#
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
  'src/include',
  'src/specs/api',
  'src/specs/model',
  'subprojects/pistache/include',
  'subprojects/nlohmann/include',
)

project_dependencies = [
  dependency('pistache', fallback : ['pistache', 'pistache_dep']),
  dependency('nlohmann', fallback : ['nlohmann', 'nlohmann_json_dep'], static: true),
  soci_lib,
]

subdir('src/server')

http_stub_lib = static_library(
  'http_stub_lib', http_stub_sources, include_directories: inc_dirs
)
http_stub_lib_dep = declare_dependency(include_directories: inc_dirs)

#
# Define the executable to be built from the src directory
executable(
  'trustsrv',
  include_directories: inc_dirs,
  dependencies: project_dependencies,
  sources: project_source,
  link_with: [
    http_stub_lib,
  ],
  install: true,
)
