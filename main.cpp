#include <iostream>
#include <string>

#include "lib/algorithm.hpp"
#include "lib/functional.hpp"
#include "lib/utility.hpp"
#include "lib/vector.hpp"
#include "lib/bst.hpp"
#include "lib/list_stack_queue.hpp"
#include "lib/heap.hpp"
#include "lib/graph.hpp"

#include <algorithm>

void vectorTest () {
	vector<int> a, b;

	a.push_back(4);
	a.push_back(5);
	a.push_back(7);

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	std::sort(a.begin(), a.end());

	for (auto it : a)
		std::cout << it << " ";
	std::cout << std::endl;

	a = b;

	a[1] = 10;

	for (auto it : a)
		std::cout << it << " ";
	std::cout << std::endl;
}

void listTest () {
	/*list<int> l;

	l.push_back(1);
	l.push_front(4); // 4 -> 1
	l.push_back(9); // 4 -> 1 -> 9
	l.push_back(8); // 8 -> 4 -> 1 -> 9

	l.pop_front();
	l.pop_front();
	l.pop_front();
	l.pop_back();

	l.push_back(99);
	l.push_front(4);
	l.push_back(8);

	l.pop_back();
	l.pop_back();
	l.pop_back();
	std::cout << l;
	//l.pop_back(); // 4 -> 1*/
	
	/*std::cout << (l.back()) << ' '; l.pop_back();
	std::cout << (l.back()) << ' '; l.pop_back();
	std::cout << (l.back()) << ' '; l.pop_back();*/

	list <int> gqlist1, gqlist2;

	for (int i = 0; i < 10; i++) {
		gqlist1.push_back(i * 2);
		gqlist2.push_front(i * 3);
	}

	std::cout << "\nList 1 (gqlist1) is : " << std::endl;
	std::cout << gqlist1;

	std::cout << "\nList 2 (gqlist2) is : " << std::endl;
	std::cout << gqlist2;

	std::cout << "\ngqlist1.front() : " << gqlist1.front();
	std::cout << "\ngqlist1.back() : " << gqlist1.back();

	std::cout << "\ngqlist1.pop_front() : " << std::endl;
	gqlist1.pop_front();
	std::cout << gqlist1;

	std::cout << "\ngqlist2.pop_back() : " << std::endl;
	gqlist2.pop_back();
	std::cout << gqlist2;
}

void stackTest () {
	stack<int> s;

	s.push(2);
	s.push(3);
	s.pop();
	s.push(2);
	s.push(66);

	std::cout << "pop " << s.top() << '\n';
	s.pop();
	std::cout << "pop " << s.top() << '\n';

	//s.print();
}

void queueTest () {
	queue<int> q;

	q.push(2);
	q.push(3);
	q.pop();
	q.push(2);
	q.push(66);

	while (q.size()) {
		std::cout << "pop " << q.front() << '\n';
		q.pop();
	}
	//std::cout << "pop " << q.pop() << '\n';

	//q.print();
}

void bstTest () {
	int n, k;
	bst<int> t;

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> k;
		t.insert(k);
	}

	std::cout << "Height: " << t.height() << "\n";
	//t.print();
}

void heapTest () {
	priority_queue<int, less<int>> h;
	/*std::*/vector<int> v;
	
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

	//h.printCap();
	
	while (h.size()) {
		std::cout << "[" << h.top() << "] " << std::endl;
		h.pop();
	}
}

void pairTest () {
	pair<int, std::string> p = {5, "huehuehu"}, k;

	p = {8, "kkk"};

	p.second = "agoravai";

	k = p;

	std::cout << k.first << ' ' << k.second << std::endl;
}

void graphTest () {
	graph G(9);

	G.addEdge(make_pair(0, 1), 4);
	G.addEdge(make_pair(0, 7), 8);
	G.addEdge(make_pair(1, 2), 8);
	G.addEdge(make_pair(1, 7), 11);
	G.addEdge(make_pair(2, 3), 7);
	G.addEdge(make_pair(2, 8), 2);
	G.addEdge(make_pair(2, 5), 4);
	G.addEdge(make_pair(3, 4), 9);
	G.addEdge(make_pair(3, 5), 14);
	G.addEdge(make_pair(4, 5), 10);
	G.addEdge(make_pair(5, 6), 2);
	G.addEdge(make_pair(6, 7), 1);
	G.addEdge(make_pair(6, 8), 6);
	G.addEdge(make_pair(7, 8), 7);
	//G.bfs(2);
	//std::cout << std::endl;
	//G.dfs(2);

	//pair<vector<int>, vector<int>> dists = 
	G.dijkstra(0);

	//for (int i = 0; i < dists.first.size(); i++)
	//	std::cout << (dists.first[i]) << ' ';

	//std::cout << G;
}

int main () {
	//listTest();
	//queueTest();
	//heapTest();
	vectorTest();
	//pairTest();
	//bstTest();
	//graphTest();


	//heap<pair<int, int>, less> h;
	//list<pair<int, int>> l;
	//list<pair<int, int>> l;
	

	return 0;
}