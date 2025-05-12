set(SOURCES
  src/algorithm.cpp
  src/array.cpp
  src/bst.cpp
  src/functional.cpp
  src/graph_io.cpp
  src/graph.cpp
  src/heap.cpp
  src/list_io.cpp
  src/list.cpp
  src/pair.cpp
  src/queue.cpp
  src/sort.cpp
  src/stack.cpp
  src/template_example.cpp
  src/union_find.cpp
  src/utility.cpp
  src/vector.cpp
)

add_executable(library-tests ${SOURCES})

set_target_properties(
  library-tests
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(
  library-tests
  PRIVATE
    global::warnings
    library
    Catch2::Catch2WithMain
)

enable_testing()

catch_discover_tests(library-tests)
