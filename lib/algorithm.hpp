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

template <typename T1, typename T2>
void fill (T1 begin, T1 end, T2 value) {
	for (T1 it = begin; it != end; it++)
		*it = value;
}

#endif