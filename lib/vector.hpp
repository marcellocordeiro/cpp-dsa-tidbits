#ifndef __vector_hpp_included__
#define __vector_hpp_included__

template <typename T>
class vector {
	T *ptr;
	unsigned int _size;
	unsigned int _capacity;

	typedef T* iterator;

	public:
		vector (): ptr(nullptr), _size(0), _capacity(32) {
			ptr = new T[_capacity];
		}

		vector (unsigned int size): ptr(nullptr), _size(size), _capacity(32) {
			ptr = new T[_capacity];
			resize(_size);
		}

		~vector () {
			delete[] ptr;
		}

		unsigned int size () {
			return _size;
		}

		unsigned int capacity () {
			return _capacity;
		}

		void clear () {
			delete[] ptr;
			_size = 0;
			_capacity = 32;
			ptr = new T[_capacity];
			//resize(_capacity);
		}

		void resize (unsigned int newSize) {
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

			for (unsigned int i = 0; i < _size; i++)
				temp[i] = ptr[i];

			delete[] ptr;
			ptr = temp;
		}

		void push_back (T value) {
			if (_size == _capacity)
				resize(_capacity*2);

			ptr[_size++] = value;
		}

		void pop_back () {
			_size--;
			//return ptr[--_size];
		}

		T front () {
			return ptr[0];
		}

		T back () {
			return ptr[_size - 1];
		}

		iterator begin () {
			return ptr;
		}

		iterator end () {
			return ptr + _size;
		}

		vector<T> &operator= (vector<T> &newVector) {
			delete[] ptr;

			_size = newVector.size();
			_capacity = newVector.capacity();
			ptr = new T[_capacity];

			for (unsigned int i = 0; i < _size; i++)
				ptr[i] = newVector[i];

			return *this;
		}

		T &operator[] (unsigned int i) {
			return ptr[i];
		}

		//T operator[] (unsigned int i) const {
		//	return ptr[i];
		//}
};

#endif