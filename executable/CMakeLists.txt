add_executable(executable)

target_sources(executable
  PRIVATE
  src/main.cpp
  src/tests-todo.hpp
)

target_link_libraries(executable
  PRIVATE
    global::warnings
    library
)

set_target_properties(executable
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
