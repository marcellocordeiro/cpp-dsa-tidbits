cmake_minimum_required(VERSION 3.30.5...4.0.2)

project(cpp-dsa-tidbits)

include("cmake/CompilerWarnings.cmake")
include("cmake/Dependencies.cmake")
include("cmake/StandardProjectSettings.cmake")

add_library(project-warnings INTERFACE)
set_project_warnings(project-warnings)

enable_testing()

add_subdirectory(executable)
add_subdirectory(library)
