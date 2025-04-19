#pragma once

#include "list.hpp"

template <typename T>
class stack : public list<T> {
public:
  using value_type = typename list<T>::value_type;
  using reference = typename list<T>::reference;
  using const_reference = typename list<T>::const_reference;
  using size_type = typename list<T>::size_type;

  [[nodiscard]]
  auto empty() const -> bool {
    return list<T>::empty();
  }

  auto size() const -> size_type {
    return list<T>::size();
  }

  auto top() const -> reference {
    return list<T>::front();
  }

  void push(const_reference value) {
    list<T>::push_front(value);
  }

  void pop() {
    list<T>::pop_front();
  }

  void clear() {
    list<T>::clear();
  }
};
