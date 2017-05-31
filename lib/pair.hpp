#ifndef __pair_hpp_included__
#define __pair_hpp_included__

template <typename T1, typename T2>
struct pair {
	T1 first;
	T2 second;

	pair () {}

	pair (T1 first, T2 second): first(first), second(second) {}

	inline bool operator< (const pair<T1, T2> &rhs) const {
		return first < rhs.first || (!(rhs.first < first) && second < rhs.second);
	}

	inline bool operator> (const pair<T1, T2> &rhs) const {
		return !(rhs < (*this));
	}

	friend std::ostream& operator<< (std::ostream &os, pair<T1, T2> &p) {
		os << '(' << p.first << ", " << p.second << ')';

		return os;
	}
};

template <typename T1, typename T2>
pair<T1, T2> make_pair (T1 first, T2 second) {
	return pair<T1, T2>(first, second);
}

#endif