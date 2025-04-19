cmake_minimum_required(VERSION 3.30.5)

project(cpp-dsa-tidbits)

include("cmake/CompilerWarnings.cmake")
include("cmake/CPM.cmake")
include("cmake/StandardProjectSettings.cmake")

add_library(project-warnings INTERFACE)
set_project_warnings(project-warnings)

CPMAddPackage("gh:catchorg/Catch2#v3.8.1")

enable_testing()

add_subdirectory(executable)
add_subdirectory(library)

file(WRITE ${CMAKE_SOURCE_DIR}/.clangd
"CompileFlags:
  CompilationDatabase: ${CMAKE_BINARY_DIR}
"
)
