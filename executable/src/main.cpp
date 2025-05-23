#include <span>
#include <string_view>
#include <vector>

// #include "tests-todo.hpp"

#if defined(__clang__)
// clang
#elif defined(__GNUC__) || defined(__GNUG__)
// gcc
#elif defined(_MSC_VER)
// MSVC
#endif

void with_span(std::span<std::string_view> args) {
  (void)args;
}

auto main(int argc, char* argv[]) -> int {
  auto args = std::vector<std::string_view>(argv, argv + argc);

  with_span(args);

  return 0;
}
