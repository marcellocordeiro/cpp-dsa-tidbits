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

		//void addEdge (pair<int, int> &edge) ?

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

		//pair<vector<int>, vector<int>> dijkstra (int);
		void dijkstra (int);

		friend std::ostream& operator<< (std::ostream &os, graph &g) {
			//return os << '(' << p.first << ", " << p.second << ')';
			for (int i = 0; i < g.size(); i++) {
				os << "===G[" << i << "]===" << std::endl;

				for (auto it = g[i].begin(); it != g[i].end(); it = it->next)
					os << (it->data.first) << ' ';
				os << std::endl;
			}

			return os;
		}
};

// =========== DFS =========== //
void graph::dfs () { // all vertices
	vector<bool> P(_size);
	fill(P.begin(), P.end(), false);

	for (int s = 0; s < _size; s++)
		if (P[s] == false)
			dfs_visit(s, P);
}

void graph::dfs (int s) { // s is the source
	vector<bool> P(_size);
	fill(P.begin(), P.end(), false);

	dfs_visit(s, P);
}

void graph::dfs_visit (int s, vector<bool> &P) {
	P[s] = true;

	// pre_visit(s);
	std::cout << "visiting " << s << std::endl;

	for (auto it = G[s].begin(); it != G[s].end(); it = it->next) {
		int v = it->data.first;

		if (P[v] == false)
			dfs_visit(v, P);
	}

	// post_visit(s);
}
// =========================== //

// =========== BFS =========== //
void graph::bfs () {
	vector<bool> P(_size);
	fill(P.begin(), P.end(), false);

	for (int s = 0; s < _size; s++)
		if (P[s] == false)
			bfs_visit(s, P);
}

void graph::bfs (int s) {
	vector<bool> P(_size);
	fill(P.begin(), P.end(), false);

	bfs_visit(s, P);
}

void graph::bfs_visit (int s, vector<bool> &P) {
	queue<int> q;

	q.push(s);

	P[s] = true;

	while (q.size()) {
		int u = q.top();
		q.pop();

		// pre_visit(u);
		std::cout << "visiting " << u << std::endl;

		for (auto it = G[u].begin(); it != G[u].end(); it = it->next) { // list<T>::node não funciona (private) auto, sim (???)
			int v = it->data.first;

			if (P[v] == false) {
				q.push(v);

				P[v] = true;
			}
		}

		// post_visit(u);
	}
}
// =========================== //
//pair<vector<int>, vector<int>> graph::dijkstra (int s) {
void graph::dijkstra (int s) {
	vector<int> D(_size), F(_size);
	fill(D.begin(), D.end(), inf);
	fill(F.begin(), F.end(), -1);
	
	D[0] = 0;

	heap<pair<int, int>, less> h;
	
	h.insert({0, s}); // pair.first é a chave de comparação

	for (int k = 0; k < _size; k++) {
		pair<int, int> du = h.extract(); // du.first = d, du.second = u
		int u = du.second;

		for (auto it = G[u].begin(); it != G[u].end(); it = it->next) {
			if (D[u] + it->data.second < D[it->data.first]) {
				D[it->data.first] = D[u] + it->data.second;
				F[it->data.first] = u;

				h.insert({D[it->data.first], it->data.first}); // update??
			}
		}
	}

	for (unsigned int i = 0; i < D.size(); i++)
		std::cout << D[i] << ' ';
	std::cout << std::endl;

	//return {D, F};
}

#endif