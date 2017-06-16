#ifndef __graph_hpp_included__
#define __graph_hpp_included__

#include "algorithm.hpp"
#include "utility.hpp"
#include "vector.hpp"
#include "queue.hpp"
#include "heap.hpp"

#define inf 2147483647

class graph {
	vector<pair<int, int>> *G;
	int _size;

	public:
		graph (int V): _size(V) {
			G = new vector<pair<int, int>>[_size];
		}

		~graph () {
			delete[] G;
		}

		int size () {
			return _size;
		}

		void add_edge (pair<int, int> edge, int weight = 1) {
			G[edge.first].push_back(make_pair(edge.second, weight));
			G[edge.second].push_back(make_pair(edge.first, weight));
		}

		vector<pair<int, int>> &operator[] (int i) {
			return G[i];
		}

		void dfs ();
		void dfs (int);
		void dfs_visit (int, vector<bool>&);

		void bfs ();
		void bfs (int);
		void bfs_visit (int, vector<bool>&);

		pair<vector<int>, vector<int>> shortest_path (int);

		pair<vector<int>, vector<int>> dijkstra (int);

		pair<vector<int>, vector<int>> prim (int);

		friend std::ostream& operator<< (std::ostream &os, graph &g) {
			for (int i = 0; i < g.size(); i++) {
				os << "===G[" << i << "]===" << std::endl;

				for (auto it : g[i])
					os << it.first << "(" << it.second << ")" << ' ';
				os << std::endl;
			}

			return os;
		}
};

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

pair<vector<int>, vector<int>> graph::shortest_path (int s) {
	vector<int> D(_size, inf), F(_size, -1); // D = shortest distance from A to B, F = path

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
				F[v] = u;

				q.push(v);
			}
		}
	}

	return make_pair(D, F);
}

pair<vector<int>, vector<int>> graph::dijkstra (int s) {
	vector<int> D(_size, inf), F(_size, -1); // D = shortest distance from A to B, F = path
	priority_queue<pair<int, int>, less<pair<int, int>>> pq;

	D[s] = 0;
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

	return make_pair(D, F);
}

pair<vector<int>, vector<int>> graph::prim (int s) {
	vector<int> W(_size, inf), F(_size, -1);
	vector<bool> S(_size, false);

	W[s] = 0;

	priority_queue<pair<int, int>, less<pair<int, int>>> pq;
	pq.push(make_pair(W[s], s));

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		S[u] = true;

		for (auto it : G[u]) {
			int v = it.first;
			int w = it.second;

			if (S[v] == false && W[v] > w) {
				W[v] = w;
				pq.push(make_pair(W[v], v));
				
				F[v] = u;
			}
		}
	}

	/*graph T(V);

	for (int i = 0; i < _size; i++)
		if (fw.first[i] != -1)
			T.add_edge(make_pair(i, fw.first[i]), fw.second[i]);*/

	return make_pair(F, W);
}

#endif