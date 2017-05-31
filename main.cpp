#include <iostream>
#include <string>

#include "lib/algorithm.hpp"
#include "lib/functional.hpp"
#include "lib/utility.hpp"
#include "lib/vector.hpp"
#include "lib/bst.hpp"
#include "lib/list.hpp"
#include "lib/stack.hpp"
#include "lib/queue.hpp"
#include "lib/heap.hpp"
#include "lib/graph.hpp"
#include "lib/union_find.hpp"

int main () {
	graph G(5);
	pair<vector<int>, vector<int>> df;

	G.addEdge(make_pair(0, 1), 10);
	G.addEdge(make_pair(0, 4), 3);
	G.addEdge(make_pair(1, 2), 2);
	G.addEdge(make_pair(1, 4), 4);
	G.addEdge(make_pair(2, 3), 9);
	G.addEdge(make_pair(3, 2), 7);
	G.addEdge(make_pair(4, 1), 1);
	G.addEdge(make_pair(4, 2), 8);
	G.addEdge(make_pair(4, 3), 2);

	df = G.dijkstra(0);

	for (auto it : df.first)
		std::cout << it << ' ';
	std::cout << std::endl;

	for (auto it : df.second)
		std::cout << it << ' ';
	std::cout << std::endl;

	//std::cout << G;

	return 0;
}