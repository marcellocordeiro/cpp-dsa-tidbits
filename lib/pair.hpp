#pragma once

template <typename T1, typename T2>
struct pair {
  T1 first;
  T2 second;

  pair () {}

  pair (T1 first, T2 second) : first(first), second(second) {}

  bool operator< (const pair<T1, T2> &rhs) const {
    return first < rhs.first || (!(rhs.first < first) && second < rhs.second);
  }

  bool operator> (const pair<T1, T2> &rhs) const {
    return !(rhs < (*this));
  }
};

template <typename T1, typename T2>
pair<T1, T2> make_pair (T1 first, T2 second) {
  return pair<T1, T2>(first, second);
}