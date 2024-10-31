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

jwt_cpp_proj = cmake.subproject('jwt-cpp', cmake_options: [])
jwt_cpp_lib = jwt_cpp_proj.dependency('jwt-cpp')

nlohmann_dep = dependency(
  'nlohmann',
  fallback: ['nlohmann', 'nlohmann_json_dep'],
  static: true,
)

pistache_dep = dependency(
  'pistache',
  fallback: ['pistache', 'pistache_dep'],
)

project_dependencies = [
  nlohmann_dep,
  pistache_dep,
  soci_lib,
  jwt_cpp_lib,
  dependency('openssl', static: true, required: true)
]

project_include_dirs = include_directories(
  'src/include',
  'src/specs/api',
  'src/specs/model',
)

# Build static lib for subdirs
#
subdir('src/server')
subdir('src/db')
subdir('src/lib')

#
# Define the executable to be built from the src directory
#
executable(
  'trustsrv',
  include_directories: project_include_dirs,
  dependencies: project_dependencies,
  sources: project_source,
  link_with: [
    server_lib,
    db_lib,
    seal_lib,
  ],
  install: true,
)

# Unit test dependency
#
subdir('tests')
