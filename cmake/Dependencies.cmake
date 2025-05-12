include(cmake/get_cpm.cmake)

CPMAddPackage(
  URI "gh:catchorg/Catch2#v3.8.1"
)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)

find_package(Catch2 CONFIG REQUIRED)
include(CTest)
include(Catch)
