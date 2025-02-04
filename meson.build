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
soci_proj = cmake.subproject('soci',
  cmake_options: [
    '-DCMAKE_CXX_STANDARD=11',
    '-DCMAKE_CXX_FLAGS:STRING=-std=c++11',
    '-DCMAKE_CXX_STANDARD_REQUIRED=ON',
    '-DCMAKE_CXX_EXTENSIONS=OFF',
    '-DSOCI_MYSQL=ON',
    '-DSOCI_TESTS=OFF',
    '-DSOCI_SHARED=ON',
    '-DSOCI_CXX11=ON',
    '-DSOCI_EMPTY=ON',
  ],
)
# message('CMake targets:\n - ' + '\n - '.join(soci_proj.target_list()))
soci_lib = [
  soci_proj.dependency('soci_core_static'),
  soci_proj.dependency('soci_mysql_static'),
]

mongo_c = cmake.subproject('mongo-c',
  cmake_options: [
    '-DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF',
    '-DCMAKE_BUILD_TYPE=Release',
  ],
)
mongo_c_lib = [
  mongo_c.dependency('mongoc_shared'),
  mongo_c.dependency('bson_shared'),
]

nlohmann_dep = dependency(
  'nlohmann',
  fallback: ['nlohmann', 'nlohmann_json_dep'],
  static: true,
)

pistache_dep = dependency(
  'pistache',
  fallback: ['pistache', 'pistache_dep'],
)

jwt_cpp_proj = cmake.subproject('jwt-cpp', cmake_options: [
    '-DUSE_BOOST_JSON=OFF',
  ],
)
jwt_cpp_lib = jwt_cpp_proj.dependency('jwt-cpp')

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
  '/usr/include/mysql',
)

subproj_include_dirs = include_directories(
  'subprojects/nlohmann/include',
  'subprojects/pistache/include',
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
