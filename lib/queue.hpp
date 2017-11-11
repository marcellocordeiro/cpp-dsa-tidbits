#pragma once

#include "list.hpp"

template <typename T>
class queue: private list<T> {
public:
  bool empty () const {
    return list<T>::empty();
  }

  typename list<T>::size_type size () const {
    return list<T>::size();
  }

  T front () const {
    return list<T>::front();
  }

  T back () const {
    return list<T>::back();
  }

  void push (const T value) {
    list<T>::push_back(value);
  }

  void pop () {
    list<T>::pop_front();
  }
};