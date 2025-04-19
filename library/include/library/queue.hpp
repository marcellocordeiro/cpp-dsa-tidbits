#pragma once

#include "list.hpp"

template <typename T>
class queue : public list<T> {
public:
  using value_type = typename list<T>::value_type;
  using reference = typename list<T>::reference;
  using const_reference = typename list<T>::const_reference;
  using size_type = typename list<T>::size_type;

  bool empty() const {
    return list<T>::empty();
  }

  size_type size() const {
    return list<T>::size();
  }

  reference front() const {
    return list<T>::front();
  }

  reference back() const {
    return list<T>::back();
  }

  void push(const_reference value) {
    list<T>::push_back(value);
  }

  void pop() {
    list<T>::pop_front();
  }

  void clear() {
    list<T>::clear();
  }
};