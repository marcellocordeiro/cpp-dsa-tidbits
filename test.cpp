#include <iostream>
#include <string>

#include "lib/functional.hpp"
#include "lib/heap.hpp"
#include <algorithm>

vector<int> vectTest (vector<int> v) {
	v[1] = 999999;

	for (auto it : v)
		std::cout << it << ' ';
	std::cout << std::endl;

	return v;
}

void heapTest () {
	priority_queue<int> h;
	vector<int> v;
	
	v.push_back(2);
	v.push_back(3);
	v.push_back(6);
	v.push_back(8);
	v.push_back(1);
	v.push_back(55);
	v.push_back(45);
	v.push_back(1000);
	
	/*h.push(66);
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
	}*/

	//std::sort(v.begin(), v.end(), greater<int>());
	v =	vectTest(v);


	for (auto it : v)
		std::cout << it << ' ';
	std::cout << std::endl;
}

int main () {
	heapTest();

	return 0;
}