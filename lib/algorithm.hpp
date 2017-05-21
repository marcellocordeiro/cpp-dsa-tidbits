#ifndef __algorithm_hpp_included__
#define __algorithm_hpp_included__

#include "vector.hpp"  // ???
#include "sort.hpp" // don't flood algorithm.hpp

template <typename T>
void swap (T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

#ifndef __vector_hpp_included__ // ???
#else
template <typename T>
void fill (vector<T> &v, unsigned int size, T value) {
	v.clear();

	for (unsigned int i = 0; i < size; i++)
		v.push_back(value);
}
#endif

#endif