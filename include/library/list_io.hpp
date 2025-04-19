#pragma once

#include <iostream>

#include "list.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const list<T>& L) {
  for (const auto& it : L) {
    /*if (it->prev == L.head) {
      os << "(prev: S) ";
    } else {
      os << "(prev: " << (it->prev->data) << ") ";
    }*/

    os << "(cur: " << it << ") ";

    /*if (it->next == nullptr) {
      os << "(next: N) ";
    } else {
      os << "(next: " << (it->next->data) << ") ";
    }*/

    os << '\n';
  }

  return os;
}
