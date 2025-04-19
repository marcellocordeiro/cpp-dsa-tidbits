#include <span>
#include <string_view>
#include <vector>

void withSpan(std::span<std::string_view> args) {
  (void)args;
}

auto main(int argc, char* argv[]) -> int {
  auto args = std::vector<std::string_view>(argv, argv + argc);

  withSpan(args);

  return 0;
}
