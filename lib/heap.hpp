#pragma once

#include "algorithm.hpp"
#include "vector.hpp"

template <typename T, class Compare = less<T>>
class priority_queue {
  using size_type = unsigned int;

public:
  priority_queue () {}

  priority_queue (const priority_queue<T> &pq) : H(pq.H), cmp(pq.cmp) {}

  priority_queue (const vector<T> &v) {
    H = v;

    for (size_type i = H.size()/2; i > 0; i--) {
      heapify(i - 1);
    }
  }

  bool empty () const {
    return (H.size() == 0);
  }

  size_type size () const {
    return H.size();
  }

  T top () const {
    return H[0];
  }

  void push (T value) {
    H.push_back(value);

    bubble_up();
  }

  void pop () {
    H[0] = H.back();
    H.pop_back();

    heapify(0);
  }

private:
  size_type parent (const size_type i) const {
    return (i - 1)/2;
  }

  size_type left (const size_type i) const {
    return 2*i + 1;
  }

  size_type right (const size_type i) const {
    return 2*i + 2;
  }

  void bubble_up () {
    for (size_type i = H.size() - 1; (i > 0) && (cmp(H[parent(i)], H[i])); i = parent(i)) {
      swap(H[parent(i)], H[i]);
    }
  }

  void heapify (const size_type i) {
    size_type l = left(i), r = right(i), m = i;

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