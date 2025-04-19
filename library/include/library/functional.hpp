#pragma once

template <typename T>
struct less {
  auto operator()(const T& x, const T& y) const -> bool {
    return x < y;
  }
};

template <typename T>
struct greater {
  auto operator()(const T& x, const T& y) const -> bool {
    return x > y;
  }
};
