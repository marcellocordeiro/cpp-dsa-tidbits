#ifndef __heap_hpp_included__
#define __heap_hpp_included__

#include "algorithm.hpp"
#include "vector.hpp"

// heap de altura h <==> array de comprimento 2^h
	// raiz na posição 0
	// filhos: left(i) = 2i + 1, right(i) = 2i + 2
	
	// size(H): capacidade do array
	// heap.size(H): quantidade de elementos na heap H

template <typename T, bool (*cmp)(T, T)>
class heap {
	vector<T> H; // heap.size = H.size()
	unsigned int capacity; // size

	private:
		void bubble_up () {
			for (unsigned int i = H.size() - 1; (i > 0) && (cmp(H[i], H[(i - 1)/2])); i = (i - 1)/2)
				swap(H[i], H[(i - 1)/2]);
		}

		void heapfy (unsigned int i) {
			unsigned int l = 2*i + 1, r = 2*i + 2, m = i;

			if (l < H.size() && cmp(H[l], H[m]))
				m = l;

			if (r < H.size() && cmp(H[r], H[m]))
				m = r;

			if (m != i) {
				swap(H[i], H[m]);
				heapfy(m);
			}
		}

	public:
		heap (): capacity(1) {}

		unsigned int size () {
			return H.size();
		}

		void build (vector<T> v) {
			H = v;

			for (unsigned int i = H.size()/2; i > 0; i--)
				heapfy(i - 1);
		}

		void push (T value) {
			H.push_back(value);

			bubble_up();
		}

		T top () {
			return H[0];
		}

		void pop () {
			H[0] = H.back();
			H.pop_back();

			heapfy(0);
		}
};

#endif