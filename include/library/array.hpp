#pragma once

#include <cstddef>
#include <iterator>

template <typename T, std::size_t _size>
class array {
public:
  using value_type = T;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  using size_type = std::size_t;

  // STL compatibility
  // adding : public std::iterator<std::random_access_iterator_tag, T> works too
  using iterator_tag = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;

  iterator begin() {
    return arr;
  }

  iterator end() {
    return arr + _size;
  }

  const_iterator begin() const {
    return arr;
  }

  const_iterator end() const {
    return arr + _size;
  }

  bool empty() {
    return _size == 0;
  }

  constexpr size_type size() {
    return _size;
  }

private:
  value_type arr[_size];
};