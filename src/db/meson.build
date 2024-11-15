_db_dir = meson.project_source_root() / 'src/db'
_db_model_dir = _db_dir / 'model'

_db_sources = [
  _db_dir / 'connector.cpp',
  _db_dir / 'db-driver.cpp',
  _db_dir / 'db-model.cpp',
  _db_dir / 'repository.cpp',
  _db_model_dir / 'tag_attr.cpp',
]

_db_include = [
  '.',
  '../specs',
  project_include_dirs,
  subproj_include_dirs,
]

db_lib = static_library(
  'db',
  _db_sources,
  include_directories: _db_include,
  dependencies: [
    soci_lib,
    nlohmann_dep,
  ],
)

db_lib_dep = declare_dependency(
  link_with: db_lib,
  include_directories: _db_include,
)
