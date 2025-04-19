#pragma once

#include "algorithm.hpp"
#include "vector.hpp"

template <typename T>
void merge(vector<T>& v, vector<T>& a, unsigned int l, unsigned int r) {
  unsigned int i;
  unsigned int j;
  unsigned int k;
  unsigned int m;

  for (k = l; k <= r; k++) {
    a[k] = v[k];
  }

  m = (l + r) / 2;
  i = l;
  j = m + 1;

  for (k = l; k <= r; k++) {
    if (i == m + 1) {
      v[k] = a[j++];
    } else if (j == r + 1) {
      v[k] = a[i++];
    } else if (a[i] <= a[j]) {
      v[k] = a[i++];
    } else {
      v[k] = a[j++];
    }
  }
}

template <typename T>
void merge_sort(vector<T>& v, vector<T>& a, unsigned int l, unsigned int r) {
  if (l == r) {
    return;
  }

  unsigned int m = (l + r) / 2;

  merge_sort(v, a, l, m);
  merge_sort(v, a, m + 1, r);

  merge(v, a, l, r);
}

template <typename T>
void quick_sort(vector<T>& v, unsigned int l, unsigned int r) {
  unsigned int i;
  unsigned int j;
  unsigned int p;

  // p = v[pivot(v, l, r)];
  p = v[((l + r) / 2)];

  i = l;
  j = r;

  while (i < j) {
    while (v[i] < p) {
      i++;
    }

    while (v[j] > p) {
      j--;
    }

    if (i <= j) {
      swap(v[i], v[j]);
      i++;
      j--;
    }
  }

  if (l < j) {
    quick_sort(v, l, j);
  }

  if (i < r) {
    quick_sort(v, i, r);
  }
}

template <typename T>
void merge_sort(vector<T>& v) {
  vector<T> a;

  a = v;

  merge_sort(v, a, 0, v.size() - 1);
}

template <typename T>
void quick_sort(vector<T>& v) {
  quick_sort(v, 0, v.size() - 1);
}
