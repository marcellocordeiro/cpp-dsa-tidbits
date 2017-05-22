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

int main () {
	list<int> l;
	//list<int>::iterator it;
	
	for (int i = 0; i < 10; i++) {
		l.push_back(i * 2);
	}

	for (auto &it : l) {
		std::cout << it << ' ';
	}

	//std::cout << l;

	/*vector<int> v, a;

	for (int i = 0; i < 10; i++)
		v.push_back(rand() % 30);*/

	/*for (unsigned int i = 0; i < 10; i++)
		std::cout << v[i] << ' ';
	std::cout << std::endl;*/

	/*a = v;

	for (unsigned int i = 0; i < 10; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;*/

	//quick_sort(v);

	/*for (unsigned int i = 0; i < 10; i++)
		std::cout << v[i] << ' ';
	std::cout << std::endl;*/

	/*for (auto it = v.begin(); it != v.end(); it++)
		std::cout << *it << ' ';*/

	return 0;
}