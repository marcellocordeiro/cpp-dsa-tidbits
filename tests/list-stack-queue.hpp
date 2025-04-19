#pragma once

#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>

#include <library/list.hpp>

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

#include <library/stack.hpp>

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

#include <library/queue.hpp>

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

#include <library/vector.hpp>
#include <string>
#include <vector>

TEMPLATE_TEST_CASE("API matches", "[api][template]", (vector<int>), (std::vector<int>)) {
  TestType v;

  REQUIRE(v.size() == 0);
}

TEMPLATE_TEST_CASE(
  "vectors can be sized and resized",
  "[vector][template]",
  int,
  std::string,
  (std::tuple<int, float>)
) {
  std::vector<TestType> v(5);

  REQUIRE(v.size() == 5);
  REQUIRE(v.capacity() >= 5);

  SECTION("resizing bigger changes size and capacity") {
    v.resize(10);

    REQUIRE(v.size() == 10);
    REQUIRE(v.capacity() >= 10);
  }
  SECTION("resizing smaller changes size but not capacity") {
    v.resize(0);

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() >= 5);

    SECTION("We can use the 'swap trick' to reset the capacity") {
      std::vector<TestType> empty;
      empty.swap(v);

      REQUIRE(v.capacity() == 0);
    }
  }
  SECTION("reserving smaller does not change size or capacity") {
    v.reserve(0);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);
  }
}
