#ifndef __graph_hpp_included__
#define __graph_hpp_included__

#include "algorithm.hpp"
#include "utility.hpp"
#include "list_stack_queue.hpp"
#include "heap.hpp"

#define inf 2147483647

class graph {
	list<pair<int, int>> *G;
	int _size;

	public:
		graph (int V): _size(V) {
			G = new list<pair<int, int>>[_size];
		}

		~graph () {
			delete[] G;
		}

		int size () {
			return _size;
		}

		void addEdge (pair<int, int> edge) {
			G[edge.first].push_back({edge.second, 1});
			G[edge.second].push_back({edge.first, 1}); // não dirigido
		}

		void addEdge (pair<int, int> edge,  int weight) {
			G[edge.first].push_back({edge.second, weight});
			G[edge.second].push_back({edge.first, weight}); // não dirigido
		}

		list<pair<int, int>> &operator[] (int i) {
			return G[i];
		}

		void dfs ();
		void dfs (int);
		void dfs_visit (int, vector<bool>&);

		void bfs ();
		void bfs (int);
		void bfs_visit (int, vector<bool>&);

		int shortest_path (int, int);
		void shortest_path (int, int, vector<int>&);

		void dijkstra (int);

		friend std::ostream& operator<< (std::ostream &os, graph &g) {
			for (int i = 0; i < g.size(); i++) {
				os << "===G[" << i << "]===" << std::endl;

				for (auto it : g[i])
					os << it.first << ' ';
				os << std::endl;
			}

			return os;
		}
};

// =========== DFS =========== //
void graph::dfs () { // all vertices
	vector<bool> P(_size, false);

	for (int s = 0; s < _size; s++)
		if (P[s] == false)
			dfs_visit(s, P);
}

void graph::dfs (int s) { // s is the source
	vector<bool> P(_size, false);

	dfs_visit(s, P);
}

void graph::dfs_visit (int s, vector<bool> &P) {
	P[s] = true;

	// pre_visit(s);
	std::cout << "visiting " << s << std::endl;

	for (auto it : G[s]) {
		int v = it.first;

		if (P[v] == false)
			dfs_visit(v, P);
	}

	// post_visit(s);
}
// =========================== //

// =========== BFS =========== //
void graph::bfs () {
	vector<bool> P(_size, false);

	for (int s = 0; s < _size; s++)
		if (P[s] == false)
			bfs_visit(s, P);
}

void graph::bfs (int s) {
	vector<bool> P(_size, false);

	bfs_visit(s, P);
}

void graph::bfs_visit (int s, vector<bool> &P) {
	queue<int> q;

	q.push(s);

	P[s] = true;

	while (q.size()) {
		int u = q.front();
		q.pop();

		// pre_visit(u);
		std::cout << "visiting " << u << std::endl;

		for (auto it : G[u]) {
			int v = it.first;

			if (P[v] == false) {
				q.push(v);

				P[v] = true;
			}
		}

		// post_visit(u);
	}
}
// =========================== //

int graph::shortest_path (int A, int B) {
	vector<int> D(_size, inf);

	graph::shortest_path(A, B, D);

	return D[B];
}

void graph::shortest_path (int s, int d, vector<int> &D) {
	D[s] = 0;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto it : G[u]) {
			int v = it.first;

			if (D[v] == -1) {
				D[v] = D[u] + 1;

				if (v == d)
					return;

				q.push(v);
			}
		}
	}
}

void graph::dijkstra (int s) {
	vector<int> D(_size, inf), F(_size, -1);
	priority_queue<pair<int, int>, less<pair<int, int>>> pq;

	D[0] = 0;
	pq.push(make_pair(D[s], s)); // pair.first é a chave de comparação

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (auto it : G[u]) {
			if (D[u] + it.second < D[it.first]) {
				D[it.first] = D[u] + it.second;
				F[it.first] = u;

				pq.push(make_pair(D[it.first], it.first)); // update??
			}
		}
	}

	for (auto it : D)
		std::cout << it << ' ';
	std::cout << std::endl;
}

#endif