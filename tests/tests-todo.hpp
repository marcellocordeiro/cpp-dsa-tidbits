#pragma once

#include <iostream>
#include <string>

#include <library/algorithm.hpp>
#include <library/array.hpp>
#include <library/bst.hpp>
#include <library/functional.hpp>
#include <library/graph.hpp>
#include <library/graph_io.hpp>
#include <library/heap.hpp>
#include <library/list.hpp>
#include <library/list_io.hpp>
#include <library/queue.hpp>
#include <library/stack.hpp>
#include <library/union_find.hpp>
#include <library/utility.hpp>
#include <library/vector.hpp>

void vectorTest() {
  vector<int> a, b;

  a.push_back(4);
  a.push_back(5);
  a.push_back(7);

  b.push_back(1);
  b.push_back(2);
  b.push_back(3);

  // std::sort(a.begin(), a.end());

  for (auto it : a)
    std::cout << it << " ";
  std::cout << std::endl;

  a = b;

  a[1] = 10;

  for (auto it : a)
    std::cout << it << " ";
  std::cout << std::endl;
}

void stackTest() {
  stack<int> s;

  s.push(2);
  s.push(3);
  s.pop();
  s.push(2);
  s.push(66);

  std::cout << "pop " << s.top() << '\n';
  s.pop();
  std::cout << "pop " << s.top() << '\n';

  // s.print();
}

void bstTest() {
  int n, k;
  bst<int> t;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> k;
    t.insert(k);
  }

  std::cout << "Height: " << t.height() << "\n";
  // t.print();
}

void heapTest() {
  priority_queue<int, less<int>> h;
  /*std::*/ vector<int> v;

  /*v.push_back(2);
  v.push_back(3);
  v.push_back(6);
  v.push_back(8);
  v.push_back(1);

  h.build(v);*/

  h.push(66);
  h.push(5);
  h.push(9);
  h.push(1);
  h.push(888);
  h.push(77);
  h.push(666);
  h.push(4);
  h.push(11);

  // h.printCap();

  while (h.size()) {
    std::cout << "[" << h.top() << "] " << std::endl;
    h.pop();
  }
}

void pairTest() {
  pair<int, std::string> p = {5, "huehuehu"}, k;

  p = {8, "kkk"};

  p.second = "agoravai";

  k = p;

  std::cout << k.first << ' ' << k.second << std::endl;
}

void graphTest() {
  std::cout << __cplusplus << std::endl;
  {
    graph G(5);

    G.add_edge({0, 1}, 10);
    G.add_edge({0, 4}, 3);
    G.add_edge({1, 2}, 2);
    G.add_edge({1, 4}, 4);
    G.add_edge({2, 3}, 9);
    G.add_edge({3, 2}, 7);
    G.add_edge({4, 1}, 1);
    G.add_edge({4, 2}, 8);
    G.add_edge({4, 3}, 2);

    auto [d, f] = G.dijkstra(0);

    for (const auto& it : d) {
      std::cout << it << ' ';
    }
    std::cout << std::endl;

    for (const auto& it : f) {
      std::cout << it << ' ';
    }
    std::cout << std::endl;

    std::cout << G;
  }

  int V = 9;
  graph g(V);

  {
    g.add_edge({0, 1}, 4);
    g.add_edge({0, 7}, 8);
    g.add_edge({1, 2}, 8);
    g.add_edge({1, 7}, 11);
    g.add_edge({2, 3}, 7);
    g.add_edge({2, 8}, 2);
    g.add_edge({2, 5}, 4);
    g.add_edge({3, 4}, 9);
    g.add_edge({3, 5}, 14);
    g.add_edge({4, 5}, 10);
    g.add_edge({5, 6}, 2);
    g.add_edge({6, 7}, 1);
    g.add_edge({6, 8}, 6);
    g.add_edge({7, 8}, 7);

    g.bfs(2);
    g.dfs(2);

    auto [f, w] = g.prim(0);

    for (unsigned int i = 1; i < f.size(); i++) {
      std::cout << f[i] << " - " << i << std::endl;
    }

    graph T(V);

    for (const auto& it : f) {
      std::cout << it << ' ';
    }
    std::cout << std::endl;

    for (const auto& it : w) {
      std::cout << it << ' ';
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
      if (f[i] != -1) {
        T.add_edge({i, f[i]}, w[i]);
      }
    }

    std::cout << g;

    std::cout << std::endl;

    std::cout << T;
  }
}
