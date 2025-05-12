#include <catch2/catch_test_macros.hpp>

#include "library/queue.hpp"

TEST_CASE("queue tests", "[queue.hpp]") {
  queue<int> q;

  REQUIRE(q.size() == 0);
  REQUIRE(q.empty());

  SECTION("inserting elements") {
    q.push(0);
    REQUIRE(q.front() == 0);
    REQUIRE(q.back() == 0);

    q.push(1);
    REQUIRE(q.front() == 0);
    REQUIRE(q.back() == 1);

    q.push(2);
    REQUIRE(q.front() == 0);
    REQUIRE(q.back() == 2);

    q.push(3);
    REQUIRE(q.front() == 0);
    REQUIRE(q.back() == 3);

    REQUIRE(q.size() == 4);
    REQUIRE(!q.empty());
  }

  SECTION("removing elements") {
    for (int i = 0; !q.empty(); ++i) {
      REQUIRE(q.front() == i);
      REQUIRE(q.back() == 3);
      q.pop();
    }

    REQUIRE(q.size() == 0);
    REQUIRE(q.empty());
  }
}
