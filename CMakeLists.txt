cmake_minimum_required(VERSION 3.30.5)

project(cpp-dsa-tidbits)

include("cmake/CPM.cmake")

# Library

add_library(library INTERFACE)
target_include_directories(library INTERFACE "include")

set_target_properties(
  library
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Executable

file(
  GLOB
  EXECUTABLE_SOURCES
  CONFIGURE_DEPENDS
  "src/main.cpp"
  "src/dummies/*.cpp"
)


add_executable(executable ${EXECUTABLE_SOURCES})
target_link_libraries(executable PRIVATE library)

set_target_properties(
  executable
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)


# Testing

enable_testing()

CPMAddPackage("gh:catchorg/Catch2#v3.8.1")

find_package(Catch2 3 CONFIG REQUIRED)

add_executable(tests "tests/tests.cpp")
target_link_libraries(tests PRIVATE library Catch2::Catch2WithMain)

include(CTest)
include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")

catch_discover_tests(tests)

set_target_properties(
  tests
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
