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

cmake = import('cmake')
soci_proj = cmake.subproject('soci', cmake_options: [
  '-DSOCI_TESTS=OFF',
  '-DSOCI_SHARED=ON',
  '-DSOCI_EMPTY=ON'
])
message('CMake targets:\n - ' + '\n - '.join(soci_proj.target_list()))

soci_lib = soci_proj.dependency('soci_core')

#soci_dep = dependency(
#  'soci', fallback: ['soci', 'soci_dep']
#)

#
# Define the executable to be built from the src directory
executable(
  'trustsrv',
  sources: ['src/main.cpp'],
  dependencies: [
    soci_lib,
    pistache_dep
  ],
  install: true
)
