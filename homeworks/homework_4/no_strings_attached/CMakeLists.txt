cmake_minimum_required(VERSION 3.16)
project(no_strings_attached
  VERSION 0.0.1
  DESCRIPTION "Library for strings operations"
  LANGUAGES CXX)

include(cmake/UpdateSubmodules.cmake)
add_subdirectory(external)