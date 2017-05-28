#ifndef __heap_hpp_included__
#define __heap_hpp_included__

#include "algorithm.hpp"
#include "vector.hpp"

// heap de altura h <==> array de comprimento 2^h
	// raiz na posição 0
	// filhos: left(i) = 2i + 1, right(i) = 2i + 2
	
	// size(H): capacidade do array
	// heap.size(H): quantidade de elementos na heap H

template <typename T, class Compare = less<T>> // less<T> = default parameter
class priority_queue {						   // default from stl is greater?
	using size_type = unsigned int;

	vector<T> H; // heap.size = H.size()
	size_type capacity; // size
	Compare cmp;

	private:
		inline size_type parent (size_type i) {
			return (i - 1)/2;
		}

		inline size_type left (size_type i) {
			return 2*i + 1;
		}

		inline size_type right (size_type i) {
			return 2*i + 2;
		}

		void bubble_up () {
			for (size_type i = H.size() - 1; (i > 0) && (cmp(H[i], H[parent(i)])); i = parent(i))
				swap(H[i], H[parent(i)]);
		}

		void heapify (size_type i) {
			size_type l = left(i), r = right(i), m = i;

			if (l < H.size() && cmp(H[l], H[m]))
				m = l;

			if (r < H.size() && cmp(H[r], H[m]))
				m = r;

			if (m != i) {
				swap(H[i], H[m]);
				heapify(m);
			}
		}

	public:
		priority_queue (): capacity(1) {}

		priority_queue (vector<T> &v): capacity(1) {
			H = v;

			while (capacity < H.size())
				capacity *= 2;

			for (size_type i = H.size()/2; i > 0; i--)
				heapify(i - 1);
		}

		inline bool empty () {
			return (H.size() == 0);
		}

		inline size_type size () {
			return H.size();
		}

		inline T top () {
			return H[0];
		}

		void push (T value) {
			H.push_back(value);

			bubble_up();
		}

		void pop () {
			H[0] = H.back();
			H.pop_back();

			heapify(0);
		}
};

#endif