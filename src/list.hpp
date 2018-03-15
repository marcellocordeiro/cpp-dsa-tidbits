#pragma once

#include <cstddef>
#include <iterator>

template <typename T>
class list {
  struct node;

public:
  using value_type = T;
  using pointer = node*;
  using const_pointer = const node*;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;

  list() {
  }

  list(const list<value_type>& rhs) {
    for (const auto& it : rhs) {
      push_back(it);
    }
  }

  ~list() {
    clear();

    delete head;
  }

  class iterator;
  class const_iterator;

  iterator begin() {
    return iterator(head->next);
  }

  iterator end() {
    return iterator(nullptr);
  }

  const_iterator begin() const {
    return const_iterator(head->next);
  }

  const_iterator end() const {
    return const_iterator(nullptr);
  }

  bool empty() const {
    return (_size == 0);
  }

  size_type size() const {
    return _size;
  }

  reference front() const {
    return head->next->data;
  }

  reference back() const {
    return tail->data;
  }

  void push_front(const_reference value) {
    insert(value, head);

    if (_size == 1) {
      tail = head->next;
    }
  }

  void push_back(const_reference value) {
    insert(value, tail);

    tail = tail->next;
  }

  void pop_front() {
    erase(head->next);

    if (_size == 0) {
      tail = head;
    }
  }

  void pop_back() {
    tail = tail->prev;

    erase(tail->next);
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  void swap(list<value_type>& rhs) {
    pointer l_head = rhs.head;
    pointer l_tail = rhs.tail;
    size_type l_size = rhs._size;

    rhs.head = head;
    rhs.tail = tail;
    rhs._size = _size;

    head = l_head;
    tail = l_tail;
    _size = l_size;
  }

  list<value_type>& operator=(list<value_type>& rhs) {
    list<value_type> temp(rhs);

    swap(temp);

    return *this;
  }

private:
  void insert(const_reference value, pointer ptr) {
    auto temp = new node(value, ptr, ptr->next);

    if (ptr->next != nullptr) {
      ptr->next->prev = temp;
    }

    ptr->next = temp;

    _size++;
  }

  void erase(pointer ptr) {
    pointer temp = ptr;

    if (ptr->next != nullptr) {
      ptr->next->prev = ptr->prev;
    }

    ptr->prev->next = ptr->next;

    delete temp;

    _size--;
  }

  pointer head = new node;
  pointer tail = head;
  size_type _size = 0;
};

template <typename T>
struct list<T>::node {
  using value_type = list<T>::value_type;
  using pointer = list<T>::pointer;
  using reference = list<T>::reference;

  value_type data;
  pointer prev = nullptr;
  pointer next = nullptr;

  node() {
  }

  node(const_reference value, pointer prev, pointer next) : data(value), prev(prev), next(next) {
  }
};

template <typename T>
class list<T>::iterator {
public:
  using value_type = list<T>::value_type;
  using pointer = list<T>::pointer;
  using const_pointer = list<T>::const_pointer;
  using reference = list<T>::reference;
  using const_reference = list<T>::const_reference;
  using size_type = list<T>::size_type;

  // STL compatibility
  // adding : public std::iterator<std::forward_iterator_tag, T> works too
  using iterator_category = std::forward_iterator_tag;
  using difference_type = std::ptrdiff_t;

  iterator(pointer ptr) : ptr(ptr) {
  }

  pointer operator=(const_pointer rhs) {
    ptr = rhs;
    return ptr;
  }

  bool operator==(const iterator& rhs) const {
    return (ptr == rhs.ptr);
  }

  bool operator!=(const iterator& rhs) const {
    return !(*this == rhs);
  }

  pointer operator->() const {
    return ptr;
  }

  reference operator*() const {
    return ptr->data;
  }

  iterator& operator++(int) {
    ptr = ptr->next;
    return *this;
  }

  iterator& operator++() {
    ptr = ptr->next;
    return *this;
  }

private:
  pointer ptr;
};

template <typename T>
class list<T>::const_iterator {
public:
  using value_type = list<T>::value_type;
  using pointer = list<T>::pointer;
  using const_pointer = list<T>::const_pointer;
  using reference = list<T>::reference;
  using const_reference = list<T>::const_reference;
  using size_type = list<T>::size_type;

  // STL compatibility
  // adding : public std::iterator<std::forward_iterator_tag, T> works too
  using iterator_category = std::forward_iterator_tag;
  using difference_type = std::ptrdiff_t;

  const_iterator(pointer ptr) : ptr(ptr) {
  }

  pointer operator=(const_pointer rhs) {
    ptr = rhs;
    return ptr;
  }

  bool operator==(const const_iterator& rhs) const {
    return (ptr == rhs.ptr);
  }

  bool operator!=(const const_iterator& rhs) const {
    return !(*this == rhs);
  }

  const_pointer operator->() const {
    return ptr;
  }

  const_reference operator*() const {
    return ptr->data;
  }

  const_iterator& operator++(int) {
    ptr = ptr->next;
    return *this;
  }

  const_iterator& operator++() {
    ptr = ptr->next;
    return *this;
  }

private:
  pointer ptr;
};