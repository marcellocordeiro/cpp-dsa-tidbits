#ifndef __vector_hpp_included__
#define __vector_hpp_included__

template <typename T>
class vector {
	using size_type = unsigned int;
	using iterator = T*;
	
	T *ptr;
	size_type _size;
	size_type _capacity;

	public:
		vector (): ptr(nullptr), _size(0), _capacity(32) {
			ptr = new T[_capacity];
		}

		vector (const vector<T> &v): ptr(new T[v._capacity]), _size(v._size), _capacity(v._capacity) {
			for (size_type i = 0; i < _size; i++)
				ptr[i] = v[i];
		}

		vector (size_type n, T value): ptr(nullptr), _size(n), _capacity(32) {
			while (n > _capacity)
				_capacity *= 2;

			ptr = new T[_capacity];

			for (size_type i = 0; i < n; i++)
				ptr[i] = value;
		}

		~vector () {
			delete[] ptr;
		}

		inline iterator begin () {
			return ptr;
		}

		inline iterator end () {
			return ptr + _size;
		}

		inline size_type size () {
			return _size;
		}

		inline size_type capacity () {
			return _capacity;
		}

		inline bool empty () {
			return (_size == 0);
		}

		inline T front () {
			return ptr[0];
		}

		inline T back () {
			return ptr[_size - 1];
		}

		void resize (size_type newSize) {
			if (newSize <= 32)
				return;

			if (newSize < _size)
				_size = newSize;

			bool capacityChange = false;
			
			if (newSize < _capacity) {
				while (_capacity/2 >= newSize) {
					capacityChange = true;
					_capacity /= 2;
				}
			} else if (newSize > _capacity) {
				while (_capacity*2 <= newSize) {
					capacityChange = true;
					_capacity *= 2;
				}
			}

			if (!capacityChange)
				return;

			T *temp = new T[_capacity];

			for (size_type i = 0; i < _size; i++)
				temp[i] = ptr[i];

			delete[] ptr;
			ptr = temp;
		}

		// void reserve (size_type newSize)

		void push_back (T value) {
			if (_size == _capacity)
				resize(_capacity*2);

			ptr[_size++] = value;
		}

		inline void pop_back () {
			_size--;
		}

		void clear () {
			delete[] ptr;
			_size = 0;
			_capacity = 32;
			ptr = new T[_capacity];
			//resize(_capacity);
		}

		T &operator[] (size_type i) {
			return ptr[i];
		}

		T &operator[] (size_type i) const {
			return ptr[i];
		}

		vector<T> &operator= (const vector<T> &rhs) {
			delete[] ptr;

			_size = rhs._size;
			_capacity = rhs._capacity;
			ptr = new T[_capacity];

			for (size_type i = 0; i < _size; i++)
				ptr[i] = rhs[i];

			return *this;
		}
};

#endif