add_library(split_string split_string.cpp)
target_link_libraries(split_string PUBLIC cxx_setup)

add_library(trim_string trim_string.cpp)
target_link_libraries(trim_string PUBLIC cxx_setup)