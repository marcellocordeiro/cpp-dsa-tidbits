#pragma once

#include "algorithm.hpp"
#include "functional.hpp"
#include "vector.hpp"

template <typename T, class Compare = less<T>>
class priority_queue {
  using size_type = std::size_t;

public:
  priority_queue() = default;

  explicit priority_queue(const priority_queue<T>& pq) : H(pq.H), cmp(pq.cmp) {}

  explicit priority_queue(const vector<T>& v) : H(v) {
    for (size_type i = H.size() / 2; i > 0; --i) {
      heapify(i - 1);
    }
  }

  [[nodiscard]]
  auto empty() const -> bool {
    return H.empty();
  }

  [[nodiscard]]
  auto size() const -> size_type {
    return H.size();
  }

  auto top() const -> T {
    return H[0];
  }

  void push(T value) {
    H.push_back(value);

    bubble_up();
  }

  void pop() {
    H[0] = H.back();
    H.pop_back();

    heapify(0);
  }

private:
  [[nodiscard]]
  auto parent(const size_type i) const -> size_type {
    return (i - 1) / 2;
  }

  [[nodiscard]]
  auto left(const size_type i) const -> size_type {
    return (2 * i) + 1;
  }

  [[nodiscard]]
  auto right(const size_type i) const -> size_type {
    return (2 * i) + 2;
  }

  void bubble_up() {
    for (size_type i = H.size() - 1; (i > 0) && (cmp(H[parent(i)], H[i])); i = parent(i)) {
      swap(H[parent(i)], H[i]);
    }
  }

  void heapify(const size_type i) {
    size_type l = left(i);
    size_type r = right(i);
    size_type m = i;

    if (l < H.size() && cmp(H[m], H[l])) {
      m = l;
    }

    if (r < H.size() && cmp(H[m], H[r])) {
      m = r;
    }

    if (m != i) {
      swap(H[i], H[m]);
      heapify(m);
    }
  }

  vector<T> H;
  Compare cmp;
};
