#ifndef __pair_hpp_included__
#define __pair_hpp_included__

template <class T1, class T2>
struct pair {
	T1 first;
	T2 second;

	pair () {}

	pair (T1 first, T2 second): first(first), second(second) {}

	bool operator< (pair<T1, T2> p) {
		return first < p.first;
	}

	bool operator> (pair<T1, T2> p) {
		return first > p.first;
	}

	void operator= (pair<T1, T2> p) {
		first = p.first;
		second = p.second;
	}

	friend std::ostream& operator<< (std::ostream &os, pair<T1, T2> &p) {
		os << '(' << p.first << ", " << p.second << ')';
		
		return os;
	}

};

#endif