#ifndef __string_hpp_included__
#define __string_hpp_included__

class string {
	using size_type = unsigned int;
	using iterator = char*;
	
	char *ptr;
	size_type _size;
	size_type _capacity;

	public:
		string (): ptr(nullptr), _size(0), _capacity(32) {
			ptr = new char[_capacity];
		}

		string (const string &v): ptr(new char[v._capacity]), _size(v._size), _capacity(v._capacity) {
			for (size_type i = 0; i < _size; i++)
				ptr[i] = v[i];
		}

		string (size_type n, char value): ptr(nullptr), _size(n), _capacity(32) {
			while (n > _capacity)
				_capacity *= 2;

			ptr = new char[_capacity];

			for (size_type i = 0; i < n; i++)
				ptr[i] = value;
		}

		~string () {
			delete[] ptr;
		}

		inline iterator begin () {
			return ptr;
		}

		inline iterator end () {
			return ptr + _size;
		}

		inline size_type size () const {
			return _size;
		}

		inline size_type capacity () const {
			return _capacity;
		}

		inline bool empty () const {
			return (_size == 0);
		}

		inline char front () const {
			return ptr[0];
		}

		inline char back () const {
			return ptr[_size - 1];
		}

		void resize (const size_type new_size, const char value = 0) {
			// todo
		}

		void reserve (const size_type new_capacity) {
			if (new_capacity <= 32)
				return;

			if (new_capacity < _size)
				_size = new_capacity;

			bool capacity_change = false;
			
			if (new_capacity < _capacity) {
				while (_capacity/2 >= new_capacity) {
					capacity_change = true;
					_capacity /= 2;
				}
			} else if (new_capacity > _capacity) {
				while (_capacity*2 <= new_capacity) {
					capacity_change = true;
					_capacity *= 2;
				}
			}

			if (!capacity_change)
				return;

			char *temp = new char[_capacity];

			for (size_type i = 0; i < _size; i++)
				temp[i] = ptr[i];

			delete[] ptr;
			ptr = temp;
		}

		void push_back (const char value) {
			if (_size == _capacity)
				reserve(_capacity*2);

			ptr[_size++] = value;
		}

		inline void pop_back () {
			_size--;
		}

		void swap (string &v) {
			char *v_ptr = v.ptr;
			char v_size = v._size;
			char v_capacity = v._capacity;

			v.ptr = ptr;
			v._size = _size;
			v._capacity = _capacity;

			ptr = v_ptr;
			_size = v_size;
			_capacity = v_capacity;
		}

		void clear () {
			delete[] ptr;
			_size = 0;
			_capacity = 32;
			ptr = new char[_capacity];
		}

		char &operator[] (const size_type i) {
			return ptr[i];
		}

		char &operator[] (const size_type i) const {
			return ptr[i];
		}

		string &operator= (const string &rhs) {
			string temp(rhs);
			
			swap(temp);

			return *this;
		}

		friend std::ostream& operator<< (std::ostream &os, string &s) {
			//for (unsigned int i = 0; i < s._size; i++)
			//	os << s.ptr[i];
			os << s.ptr;

			return os;
		}

		friend std::istream &operator >>(std::istream &is, string &s) {
			s._size = 0;
			char c;
			while (std::cin.get(c) && c != ' ' && c != '\n')
				s.push_back(c);

			s.push_back('\0');
		}

		friend void getline(std::istream &is, string &s);
};

void getline(std::istream &is, string &s) {
	s._size = 0;
	char c;
	while (std::cin.get(c) && c != '\n')
		s.push_back(c);

	s.push_back('\0');
}

#endif