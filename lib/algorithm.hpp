#pragma once

template <typename T>
void swap (T &x, T &y) {
  T temp = x;
  x = y;
  y = temp;
}

template <typename T1, typename T2>
void fill (T1 begin, T1 end, T2 value) {
  for (T1 it = begin; it != end; it++) {
    *it = value;
  }
}