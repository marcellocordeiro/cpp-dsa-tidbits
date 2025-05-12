set(HEADERS
  include/library/algorithm.hpp
  include/library/array.hpp
  include/library/bst.hpp
  include/library/functional.hpp
  include/library/graph_io.hpp
  include/library/graph.hpp
  include/library/heap.hpp
  include/library/list_io.hpp
  include/library/list.hpp
  include/library/pair.hpp
  include/library/queue.hpp
  include/library/sort.hpp
  include/library/stack.hpp
  include/library/union_find.hpp
  include/library/utility.hpp
  include/library/vector.hpp
)

add_library(library INTERFACE)

target_sources(library
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES ${HEADERS}
)

target_link_libraries(library INTERFACE
  global::warnings
)

set_target_properties(library
  PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_subdirectory(tests)
