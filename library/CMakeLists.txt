file(
  GLOB
  SOURCES
  CONFIGURE_DEPENDS
  "include/library/*.hpp"
)

add_library(library INTERFACE)
target_sources(library PUBLIC
  FILE_SET HEADERS
  BASE_DIRS "include"
  FILES ${SOURCES}
)
target_link_libraries(library INTERFACE project-warnings)

set_target_properties(
  library
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

enable_testing()

find_package(Catch2 3 CONFIG REQUIRED)

file(
  GLOB
  TEST_SOURCES
  CONFIGURE_DEPENDS
  "tests/*.cpp"
)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE library Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE project-warnings)

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
