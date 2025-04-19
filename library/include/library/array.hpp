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

  auto begin() -> iterator {
    return arr;
  }

  auto end() -> iterator {
    return arr + _size;
  }

  auto begin() const -> const_iterator {
    return arr;
  }

  auto end() const -> const_iterator {
    return arr + _size;
  }

  auto empty() -> bool {
    return _size == 0;
  }

  constexpr auto size() -> size_type {
    return _size;
  }

private:
  value_type arr[_size];
};
