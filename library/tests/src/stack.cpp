#include <catch2/catch_test_macros.hpp>

#include "library/stack.hpp"

TEST_CASE("stack tests", "[stack.hpp]") {
  stack<int> s;

  REQUIRE(s.size() == 0);
  REQUIRE(s.empty());

  SECTION("inserting elements") {
    for (int i = 0; i < 10; ++i) {
      s.push(i);
      REQUIRE(s.top() == i);
    }

    REQUIRE(s.size() == 10);
    REQUIRE(!s.empty());
  }

  SECTION("removing elements") {
    for (int i = 9; !s.empty(); --i) {
      REQUIRE(s.top() == i);
      s.pop();
    }

    REQUIRE(s.size() == 0);
    REQUIRE(s.empty());
  }
}
