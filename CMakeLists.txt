cmake_minimum_required(VERSION 3.30.5...4.0.2)

project(cpp-dsa-tidbits)

include(cmake/Compilers.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/Dependencies.cmake)
include(cmake/InterproceduralOptimization.cmake)
include(cmake/StandardProjectSettings.cmake)

add_subdirectory(executable)
add_subdirectory(library)
