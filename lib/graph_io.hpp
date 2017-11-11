#include <iostream>

#include "graph.hpp"

std::ostream& operator<< (std::ostream &os, graph &G) {
  for (int i = 0; i < G.size(); i++) {
    os << "===G[" << i << "]===" << std::endl;

    for (const auto &it : G[i]) {
      os << it.first << "(" << it.second << ")" << ' ';
    }
    os << std::endl;
  }

  return os;
}

// Alternative
/* friend std::ostream& operator<< (std::ostream &os, graph &g) {
  for (int i = 0; i < g.size(); i++) {
    os << "===G[" << i << "]===" << std::endl;

    for (const auto &it : g[i]) {
      os << it.first << "(" << it.second << ")" << ' ';
    }
    os << std::endl;
  }

  return os;
} */