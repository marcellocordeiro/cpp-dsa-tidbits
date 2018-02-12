#pragma once

#include "list.hpp"

template <typename T>
class stack : private list<T> {
public:
  bool empty() const {
    return list<T>::empty();
  }

  typename list<T>::size_type size() const {
    return list<T>::size();
  }

  T top() const {
    return list<T>::front();
  }

  void push(const T value) {
    list<T>::push_front(value);
  }

  void pop() {
    list<T>::pop_front();
  }
};