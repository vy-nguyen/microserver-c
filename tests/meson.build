unit_test_src = [
  'test_objectid.cpp',
]

gtest_dep = dependency(
  'gtest',
  required: true,
  fallback: ['gtest', 'gtest_dep'],
)

gtest_main_dep = dependency(
  'gtest_main',
  required: true,
  fallback: ['gtest', 'gtest_main_dep'],
)
 
unit_test_exe = executable(
  'utest',
  unit_test_src,
  dependencies: [
    seal_lib_dep,
    db_lib_dep,
    soci_lib,
    gtest_dep,
    gtest_main_dep,
  ],
  link_with: [
    seal_lib,
    db_lib,
  ],
  include_directories: project_include_dirs,
)

test('unit_test', unit_test_exe)
