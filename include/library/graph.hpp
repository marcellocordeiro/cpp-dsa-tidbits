#pragma once

#include "algorithm.hpp"
#include "functional.hpp"
#include "heap.hpp"
#include "queue.hpp"
#include "utility.hpp"
#include "vector.hpp"

#define INF 2147483647

class graph {
public:
  graph(int V) : _size(V) {
    G = new vector<pair<int, int>>[_size];
  }

  ~graph() {
    delete[] G;
  }

  int size() {
    return _size;
  }

  void add_edge(pair<int, int> edge, int weight = 1) {
    G[edge.first].push_back({edge.second, weight});
    G[edge.second].push_back({edge.first, weight});
  }

  vector<pair<int, int>>& operator[](int i) {
    return G[i];
  }

  void dfs() { // all vertices
    vector<bool> P(_size, false);

    for (int s = 0; s < _size; ++s) {
      if (P[s] == false) {
        dfs_visit(s, P);
      }
    }
  }

  void dfs(int s) { // s is the source
    vector<bool> P(_size, false);

    dfs_visit(s, P);
  }

  void dfs_visit(int s, vector<bool>& P) {
    P[s] = true;

    // pre_visit(s);

    for (const auto& it : G[s]) {
      int v = it.first;

      if (P[v] == false) {
        dfs_visit(v, P);
      }
    }

    // post_visit(s);
  }

  void bfs() {
    vector<bool> P(_size, false);

    for (int s = 0; s < _size; ++s) {
      if (P[s] == false) {
        bfs_visit(s, P);
      }
    }
  }

  void bfs(int s) {
    vector<bool> P(_size, false);

    bfs_visit(s, P);
  }

  void bfs_visit(int s, vector<bool>& P) {
    queue<int> q;

    q.push(s);

    P[s] = true;

    while (q.size()) {
      int u = q.front();
      q.pop();

      // pre_visit(u);

      for (const auto& it : G[u]) {
        int v = it.first;

        if (P[v] == false) {
          P[v] = true;
          q.push(v);
        }
      }

      // post_visit(u);
    }
  }

  pair<vector<int>, vector<int>> shortest_path(int s) {
    // D = shortest distance from A to B, F = path
    vector<int> D(_size, INF), F(_size, -1);

    D[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (const auto& it : G[u]) {
        int v = it.first;

        if (D[v] == INF) {
          D[v] = D[u] + 1;
          F[v] = u;

          q.push(v);
        }
      }
    }

    return {D, F};
  }

  pair<vector<int>, vector<int>> dijkstra(int s) {
    // D = shortest distance from A to B, F = path
    vector<int> D(_size, INF), F(_size, -1);
    priority_queue<pair<int, int>, greater<pair<int, int>>> pq;

    D[s] = 0;
    pq.push({D[s], s});

    while (!pq.empty()) {
      int u = pq.top().second;
      int w = pq.top().first;
      pq.pop();

      if (w > D[u]) {
        continue;
      }

      for (const auto& it : G[u]) {
        if (D[u] + it.second < D[it.first]) {
          D[it.first] = D[u] + it.second;
          F[it.first] = u;

          pq.push({D[it.first], it.first});
        }
      }
    }

    return {D, F};
  }

  pair<vector<int>, vector<int>> prim(int s) {
    vector<int> W(_size, INF), F(_size, -1);
    vector<bool> S(_size, false);

    W[s] = 0;

    priority_queue<pair<int, int>, greater<pair<int, int>>> pq;
    pq.push({W[s], s});

    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      S[u] = true;

      for (const auto& it : G[u]) {
        int v = it.first;
        int w = it.second;

        if (S[v] == false && W[v] > w) {
          W[v] = w;
          pq.push({W[v], v});

          F[v] = u;
        }
      }
    }

    /* graph T(V);

    for (int i = 0; i < _size; ++i) {
      if (fw.first[i] != -1) {
        T.add_edge({i, fw.first[i]}, fw.second[i]);
      }
    } */

    return {F, W};
  }

private:
  vector<pair<int, int>>* G;
  int _size;
};