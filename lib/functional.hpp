#ifndef __functional_hpp_included__
#define __functional_hpp_included__

template <typename T>
struct less {
	bool operator() (T &x, T &y) {
		return x < y;
	}
};

template <typename T>
struct greater {
	bool operator() (T &x, T &y) {
		return x > y;
	}
};

#endif