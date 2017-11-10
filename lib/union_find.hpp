#pragma once

class union_find {
  int *node;
  int *height;

  public:
  union_find (int size) : node(new int[size]), height(new int[size]) { // make_set
    for (int i = 0; i < size; i++) {
      node[i] = i;
    }

    for (int i = 0; i < size; i++) {
      height[i] = 0;
    }
  }

  ~union_find () {
    delete[] node;
    delete[] height;
  }

  void merge (int x, int y) { // merge = union
    x = find(x);
    y = find(y);

    if (x == y) {
      return;
    }

    if (height[x] < height[y]) {
      node[x] = y;
    } else if (height[x] > height[y]) {
      node[y] = x;
    } else {
      node[y] = x;
      height[x]++;
    }
  }

  int find (int p) {
    if (node[p] != p) {
      node[p] = find(node[p]);
    }

    return node[p];
  }
};