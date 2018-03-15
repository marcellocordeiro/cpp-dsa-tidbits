#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/list.hpp"

TEST_CASE("list tests", "[list.hpp]") {
  list<int> l;

  REQUIRE(l.size() == 0);
  REQUIRE(l.empty());

  SECTION("inserting elements") {
    l.push_back(1);
    REQUIRE(l.front() == 1);
    REQUIRE(l.back() == 1);

    l.push_front(4);
    REQUIRE(l.front() == 4);
    REQUIRE(l.back() == 1);

    l.push_back(9);
    REQUIRE(l.front() == 4);
    REQUIRE(l.back() == 9);

    l.push_front(8);
    REQUIRE(l.front() == 8);
    REQUIRE(l.back() == 9);

    l.push_back(10);
    REQUIRE(l.front() == 8);
    REQUIRE(l.back() == 10);

    REQUIRE(l.size() == 5);
    REQUIRE(l.empty() == false);
  }

  SECTION("inserting and removing elements") {
    l.clear();
    REQUIRE(l.size() == 0);
    REQUIRE(l.empty() == true);

    // inserting
    l.push_back(99);
    REQUIRE(l.front() == 99);
    REQUIRE(l.back() == 99);

    l.push_front(4);
    REQUIRE(l.front() == 4);
    REQUIRE(l.back() == 99);

    l.push_back(8);
    REQUIRE(l.front() == 4);
    REQUIRE(l.back() == 8);

    REQUIRE(l.size() == 3);

    // removing
    l.pop_front();
    REQUIRE(l.front() == 99);
    REQUIRE(l.back() == 8);

    l.pop_back();
    REQUIRE(l.front() == 99);
    REQUIRE(l.back() == 99);

    l.pop_front();

    REQUIRE(l.size() == 0);

    // inserting
    l.push_front(99);
    REQUIRE(l.front() == 99);
    REQUIRE(l.back() == 99);

    l.push_back(4);
    REQUIRE(l.front() == 99);
    REQUIRE(l.back() == 4);

    l.push_front(8);
    REQUIRE(l.front() == 8);
    REQUIRE(l.back() == 4);

    // removing
    l.pop_front();
    REQUIRE(l.front() == 99);
    REQUIRE(l.back() == 4);

    l.pop_back();
    REQUIRE(l.front() == 99);
    REQUIRE(l.back() == 99);

    l.pop_front();
    REQUIRE(l.size() == 0);
  }

  SECTION("multiple tests") {
    list<int> list1, list2;

    for (std::size_t i = 0; i < 10; ++i) {
      list1.push_back(i * 2);
      list2.push_front(i * 3);
    }

    list1.pop_front();
    list2.pop_back();

    auto list1_it = list1.begin();
    auto list2_it = list2.begin();

    for (std::size_t i = 1; i < 10; ++i) {
      REQUIRE(*list1_it == (i * 2));
      std::advance(list1_it, 1);
    }

    for (std::size_t i = 9; i > 0; --i) {
      REQUIRE(*list2_it == (i * 3));
      std::advance(list2_it, 1);
    }
  }
}

#include "../src/stack.hpp"

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

#include "../src/queue.hpp"

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