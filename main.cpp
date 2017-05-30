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
	list<int> l1, l2;

	l1.push_back(1);
	l1.push_front(3);


	l2 = l1;
	l1.push_back(444);

	std::cout << l2;
	std::cout << l1;


	return 0;
}