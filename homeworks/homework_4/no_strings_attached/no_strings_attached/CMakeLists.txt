add_library(string_split split_string.cpp)
target_link_libraries(string_split PUBLIC cxx_setup)

add_library(string_trim trim_string.cpp)
target_link_libraries(string_trim PUBLIC cxx_setup)

# tests

if (BUILD_TESTING)
  add_executable(split_string_test split_string_test.cpp)
  target_link_libraries(split_string_test GTest::gtest_main string_split)

  add_executable(trim_string_test trim_string_test.cpp)
  target_link_libraries(trim_string_test GTest::gtest_main string_trim)

  include(GoogleTest)
  gtest_discover_tests(split_string_test)
  gtest_discover_tests(trim_string_test)

endif()