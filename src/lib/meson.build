_lib_dir = meson.project_source_root() / 'src/lib'
_crypto_src = _lib_dir / 'crypto'

_lib_seal_sources = [
  _crypto_src / 'objectid.cpp',
]

_lib_seal_inc = [
  '.',
  project_include_dirs,
]

seal_lib = static_library(
  'seallib',
  _lib_seal_sources,
  include_directories: _lib_seal_inc,
  dependencies: [
    dependency('openssl', static: true, required: true),
  ],
)

seal_lib_dep = declare_dependency(
  link_with: seal_lib,
  include_directories: _lib_seal_inc,
)
