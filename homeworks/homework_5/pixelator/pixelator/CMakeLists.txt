# TODO: Add your libraries here
# You must have the following libraries:
# - stb_image_data_view
add_library(stb_image_data_view stb_image_data_view.cpp)
target_link_libraries(stb_image_data_view PUBLIC cxx_setup stb::stb ftxui::screen ftxui::dom)
# - drawer
# - image
add_library(image image.cpp)
target_link_libraries(image PUBLIC cxx_setup ftxui::screen ftxui::dom)
# - pixelate_image

if(BUILD_TESTING)
  include(GoogleTest)

  add_executable(stb_image_data_view_test stb_image_data_view_test.cpp)
  target_link_libraries(stb_image_data_view_test gtest_main stb_image_data_view)

  add_test(
    NAME stb_image_data_view_test
    COMMAND stb_image_data_view_test
  )

  # Set properties for the test
  set_tests_properties(stb_image_data_view_test PROPERTIES ENVIRONMENT "DATADIR=${PROJECT_SOURCE_DIR}/pixelator/test_data/")
  
  # TODO: Add your tests executable with all your tests here
  # Name it pixelator_tests.
  # Also use gtest_discover_tests(pixelator_tests)
  # to register them with CTest
endif()