#pragma once

#include "list.hpp"

template <typename T>
class queue : public list<T> {
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

  auto front() const -> reference {
    return list<T>::front();
  }

  auto back() const -> reference {
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
