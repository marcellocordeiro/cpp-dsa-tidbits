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

void vectorTest () {
	vector<int> a, b;

	a.push_back(4);
	a.push_back(5);
	a.push_back(7);

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	a = b;

	a[1] = 10;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
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

	std::cout << "\nList 1 (gqlist1) is : ";
	std::cout << gqlist1;

	std::cout << "\nList 2 (gqlist2) is : ";
	std::cout << gqlist2;

	std::cout << "\ngqlist1.front() : " << gqlist1.front();
	std::cout << "\ngqlist1.back() : " << gqlist1.back();

	std::cout << "\ngqlist1.pop_front() : ";
	gqlist1.pop_front();
	std::cout << gqlist1;

	std::cout << "\ngqlist2.pop_back() : ";
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
		std::cout << "pop " << q.top() << '\n';
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
	heap<int, less> h;
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
	vector<int> v;
	vector<pair<int, int>> e;

	/*for (int i = 0; i < 6; i++)
		v.push_back(i);

	e.push_back({0, 1});
	e.push_back({0, 2});
	e.push_back({0, 3});
	e.push_back({2, 3});
	e.push_back({4, 5});*/

	for (int i = 0; i < 4/*8*/; i++)
		v.push_back(i);
	
	/*
	a 0
	b 1
	c 2
	d 3
	e 4
	f 5
	g 6
	h 7
	*/

	/*e.push_back({0, 1});
	e.push_back({0, 2});
	e.push_back({0, 3});
	e.push_back({0, 6});
	e.push_back({1, 4});
	e.push_back({1, 5});
	e.push_back({2, 7});
	e.push_back({2, 5});
	e.push_back({3, 5});
	e.push_back({4, 6});*/


	/*for (unsigned int i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << std::endl;

	for (unsigned int i = 0; i < e.size(); i++)
		std::cout << e[i] << std::endl;*/


	graph G(9);
	/*G.addEdge({0, 1}, 2);
	G.addEdge({0, 2}, 3);
	G.addEdge({1, 2}, 4);
	G.addEdge({2, 0}, 6);
	G.addEdge({2, 3}, 7);
	G.addEdge({3, 3}, 1);*/

	G.addEdge({0, 1}, 4);
	G.addEdge({0, 7}, 8);
	G.addEdge({1, 2}, 8);
	G.addEdge({1, 7}, 11);
	G.addEdge({2, 3}, 7);
	G.addEdge({2, 8}, 2);
	G.addEdge({2, 5}, 4);
	G.addEdge({3, 4}, 9);
	G.addEdge({3, 5}, 14);
	G.addEdge({4, 5}, 10);
	G.addEdge({5, 6}, 2);
	G.addEdge({6, 7}, 1);
	G.addEdge({6, 8}, 6);
	G.addEdge({7, 8}, 7);
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
	//vectorTest();
	//pairTest();
	//bstTest();
	graphTest();


	//heap<pair<int, int>, less> h;
	//list<pair<int, int>> l;
	//list<pair<int, int>> l;
	

	return 0;
}