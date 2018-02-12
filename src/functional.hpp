#pragma once

template <typename T>
struct less {
  bool operator()(const T& x, const T& y) const {
    return x < y;
  }
};

template <typename T>
struct greater {
  bool operator()(const T& x, const T& y) const {
    return x > y;
  }
};