#pragma once

#include <cstddef>
#include <iterator>

template <typename T>
class vector {
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

public:
  vector() = default;

  vector(const vector<T>& v) :
    _size(v._size),
    _capacity(v._capacity),
    ptr(new value_type[v._capacity]) {
    for (size_type i = 0; i < _size; ++i) {
      ptr[i] = v[i];
    }
  }

  vector(const size_type n, const_reference value) : _size(n) {
    while (n > _capacity) {
      _capacity *= 2;
    }

    ptr = new value_type[_capacity];

    for (size_type i = 0; i < n; ++i) {
      ptr[i] = value;
    }
  }

  ~vector() {
    delete[] ptr;
  }

  iterator begin() {
    return ptr;
  }

  iterator end() {
    return ptr + _size;
  }

  const_iterator begin() const {
    return ptr;
  }

  const_iterator end() const {
    return ptr + _size;
  }

  size_type size() const {
    return _size;
  }

  size_type capacity() const {
    return _capacity;
  }

  bool empty() const {
    return (_size == 0);
  }

  reference front() const {
    return ptr[0];
  }

  reference back() const {
    return ptr[_size - 1];
  }

  /* void resize(const size_type new_size, const_reference value = value_type()) {
    // todo
  } */

  void reserve(const size_type new_capacity) {
    if (new_capacity <= 32) {
      return;
    }

    if (new_capacity < _size) {
      _size = new_capacity;
    }

    bool capacity_change = false;

    if (new_capacity < _capacity) {
      while ((_capacity / 2) >= new_capacity) {
        capacity_change = true;
        _capacity /= 2;
      }
    } else if (new_capacity > _capacity) {
      while ((_capacity * 2) <= new_capacity) {
        capacity_change = true;
        _capacity *= 2;
      }
    }

    if (!capacity_change) {
      return;
    }

    auto temp = new value_type[_capacity];

    for (size_type i = 0; i < _size; ++i) {
      temp[i] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
  }

  void push_back(const_reference value) {
    if (_size == _capacity) {
      reserve(_capacity * 2);
    }

    ptr[_size++] = value;
  }

  void pop_back() {
    --_size;
  }

  void swap(vector<T>& v) noexcept {
    pointer v_ptr = v.ptr;
    value_type v_size = v._size;
    value_type v_capacity = v._capacity;

    v.ptr = ptr;
    v._size = _size;
    v._capacity = _capacity;

    ptr = v_ptr;
    _size = v_size;
    _capacity = v_capacity;
  }

  void clear() {
    delete[] ptr;
    _size = 0;
    _capacity = 32;
    ptr = new value_type[_capacity];
  }

  auto operator[](const size_type i) -> reference {
    return ptr[i];
  }

  auto operator[](const size_type i) const -> reference {
    return ptr[i];
  }

  auto operator=(const vector<T>& rhs) -> vector<T>& {
    vector<T> temp(rhs);

    swap(temp);

    return *this;
  }

private:
  size_type _size = 0;
  size_type _capacity = 32;
  pointer ptr = new value_type[_capacity];
};
