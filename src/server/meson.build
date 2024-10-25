dir_specs = meson.project_source_root() / 'src/specs'
dir_src = meson.project_source_root() / 'src/server'

http_stub_sources = [
  dir_specs / 'api/DefaultApi.cpp',
  dir_specs / 'model/Helpers.cpp',
  dir_specs / 'model/_hello_get_200_response.cpp',
  dir_specs / 'model/_echo_post_request.cpp',
  dir_specs / 'model/_echo_post_200_response.cpp',
  dir_src / 'service.cpp',
  dir_src / 'auth.cpp',
  dir_src / 'restapi.cpp',
]

# Unit test
#
if not meson.is_subproject()
  
endif
