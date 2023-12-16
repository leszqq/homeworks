add_library(split_string split_string.cpp)
target_link_libraries(split_string PUBLIC cxx_setup)

add_library(trim_string trim_string.cpp)
target_link_libraries(trim_string PUBLIC cxx_setup)

# tests

if (BUILD_TESTING)
  add_executable(split_string_test split_string_test.cpp)
  target_link_libraries(split_string_test GTest::gtest_main split_string)

  include(GoogleTest)
  gtest_discover_tests(split_string_test)
endif()