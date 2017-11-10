#pragma once

template <typename T>
class vector {
  using size_type = unsigned int;
  using iterator = T*;
  
  T *ptr;
  size_type _size;
  size_type _capacity;

public:
  vector () : ptr(nullptr), _size(0), _capacity(32) {
    ptr = new T[_capacity];
  }

  vector (const vector<T> &v) : ptr(new T[v._capacity]), _size(v._size), _capacity(v._capacity) {
    for (size_type i = 0; i < _size; i++)
      ptr[i] = v[i];
  }

  vector (size_type n, T value) : ptr(nullptr), _size(n), _capacity(32) {
    while (n > _capacity)
      _capacity *= 2;

    ptr = new T[_capacity];

    for (size_type i = 0; i < n; i++)
      ptr[i] = value;
  }

  ~vector () {
    delete[] ptr;
  }

  inline iterator begin () {
    return ptr;
  }

  inline iterator end () {
    return ptr + _size;
  }

  inline size_type size () const {
    return _size;
  }

  inline size_type capacity () const {
    return _capacity;
  }

  inline bool empty () const {
    return (_size == 0);
  }

  inline T front () const {
    return ptr[0];
  }

  inline T back () const {
    return ptr[_size - 1];
  }

  void resize (const size_type new_size, const T value = 0) {
    // todo
  }

  void reserve (const size_type new_capacity) {
    if (new_capacity <= 32)
      return;

    if (new_capacity < _size)
      _size = new_capacity;

    bool capacity_change = false;
    
    if (new_capacity < _capacity) {
      while (_capacity/2 >= new_capacity) {
        capacity_change = true;
        _capacity /= 2;
      }
    } else if (new_capacity > _capacity) {
      while (_capacity*2 <= new_capacity) {
        capacity_change = true;
        _capacity *= 2;
      }
    }

    if (!capacity_change)
      return;

    T *temp = new T[_capacity];

    for (size_type i = 0; i < _size; i++)
      temp[i] = ptr[i];

    delete[] ptr;
    ptr = temp;
  }

  void push_back (const T value) {
    if (_size == _capacity)
      reserve(_capacity*2);

    ptr[_size++] = value;
  }

  inline void pop_back () {
    _size--;
  }

  void swap (vector<T> &v) {
    T *v_ptr = v.ptr;
    T v_size = v._size;
    T v_capacity = v._capacity;

    v.ptr = ptr;
    v._size = _size;
    v._capacity = _capacity;

    ptr = v_ptr;
    _size = v_size;
    _capacity = v_capacity;
  }

  void clear () {
    delete[] ptr;
    _size = 0;
    _capacity = 32;
    ptr = new T[_capacity];
  }

  T &operator[] (const size_type i) {
    return ptr[i];
  }

  T &operator[] (const size_type i) const {
    return ptr[i];
  }

  vector<T> &operator= (const vector<T> &rhs) {
    vector<T> temp(rhs);
    
    swap(temp);

    return *this;
  }
};