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

#
# Define the executable to be built from the src directory
executable(
  'trustsrv',
  sources: ['src/main.cpp'],
  dependencies: [pistache_dep],
  install: true
)
