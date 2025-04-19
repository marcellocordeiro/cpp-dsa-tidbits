# Executable

file(
  GLOB
  SOURCES
  CONFIGURE_DEPENDS
  "src/main.cpp"
  "src/dummies/*.cpp"
)

add_executable(executable ${SOURCES})
target_link_libraries(executable PRIVATE library)

set_target_properties(
  executable
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
