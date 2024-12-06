_dir_specs = meson.project_source_root() / 'src/specs'
_dir_srv = meson.project_source_root() / 'src/server'

_stub_sources = [
  _dir_specs / 'api/DefaultApi.cpp',
  _dir_specs / 'model/Helpers.cpp',
  _dir_specs / 'model/_public_hello_get_200_response.cpp',
  _dir_specs / 'model/_auth_echo_post_request.cpp',
  _dir_specs / 'model/_auth_echo_post_200_response.cpp',
  _dir_specs / 'model/Counter.cpp',
  _dir_specs / 'model/GpsPos.cpp',
  _dir_specs / 'model/IdKind.cpp',
  _dir_specs / 'model/ItemId.cpp',
  _dir_specs / 'model/ItemIdArray.cpp',
  _dir_specs / 'model/ItemIdList.cpp',
  _dir_specs / 'model/ItemKey.cpp',
  _dir_specs / 'model/KeyVal.cpp',
  _dir_specs / 'model/PageInfo.cpp',
  _dir_specs / 'model/ListCommon.cpp',
  _dir_specs / 'model/Signature.cpp',
  _dir_specs / 'model/StatElement.cpp',
  _dir_specs / 'model/StatList.cpp',
  _dir_specs / 'model/StatOperation.cpp',
  _dir_specs / 'model/Stats.cpp',
  _dir_specs / 'model/TagAttr.cpp',
  _dir_srv / 'service.cpp',
  _dir_srv / 'auth.cpp',
  _dir_srv / 'public.cpp',
  _dir_srv / 'restapi.cpp',
  _dir_srv / 'restapi_impl.cpp',
]

_server_inc = [
  '.',
  project_include_dirs,
]

server_lib = static_library(
  'server',
  _stub_sources,
  include_directories: _server_inc,
  dependencies: project_dependencies,
)

server_lib_dep = declare_dependency(
  include_directories: _server_inc,
)

# Unit test
#
if not meson.is_subproject()
  
endif
