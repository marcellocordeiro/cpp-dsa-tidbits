#ifndef __list_hpp_included__
#define __list_hpp_included__

template <typename T>
class list {
	protected:
		struct node;
		using size_type = unsigned int;

		node *head;
		node *tail;
		size_type _size;

	private:
		void erase (node *ptr) {
			node *temp = ptr;

			if (ptr->next != nullptr)
				ptr->next->prev = ptr->prev;

			ptr->prev->next = ptr->next;

			delete temp;

			_size--;
		}

		void insert (const T value, node *ptr) {
			node *temp = new node(value, ptr, ptr->next);

			if (ptr->next != nullptr)
				ptr->next->prev = temp;

			ptr->next = temp;

			_size++;
		}
		
		void delete_list (node *ptr) {
			if (ptr == nullptr)
				return;

			delete_list(ptr->next);

			delete ptr;
		}

	public:
		list (): _size(0) {
			head = new node;
			tail = head;
		}

		list (const list<T> &l): _size(0) {
			head = new node;
			tail = head;

			for (const auto &it : l)
				push_back(it);
		}

		~list () {
			delete_list(head);
		}

		class iterator;
		class const_iterator;

		iterator begin () {
			return iterator(head->next);
		}

		iterator end () {
			return iterator(nullptr);
		}

		const_iterator begin () const {
			return const_iterator(head->next);
		}

		const_iterator end () const {
			return const_iterator(nullptr);
		}

		inline bool empty () const {
			return (_size == 0);
		}

		inline size_type size () const {
			return _size;
		}

		inline T front () const {
			return head->next->data;
		}

		inline T back () const {
			return tail->data;
		}

		void push_front (const T value) {
			insert(value, head);

			if (_size == 1)
				tail = head->next;
		}

		void pop_front () {
			if (_size == 0)
				return;

			erase(head->next);

			if (_size == 0)
				tail = head;
		}

		void push_back (const T value) {
			insert(value, tail);

			tail = tail->next;
		}

		void pop_back () {
			if (_size == 0)
				return;

			tail = tail->prev;

			erase(tail->next);
		}

		void swap (list<T> &l) {
			node *l_head = l.head;
			node *l_tail = l.tail;
			size_type l_size = l._size;

			l.head = head;
			l.tail = tail;
			l._size = _size;

			head = l_head;
			tail = l_tail;
			_size = l_size;
		}

		list<T> &operator= (list<T> &rhs) {
			list<T> temp(rhs);
			
			swap(temp);
			
			return *this;
		}

		friend std::ostream& operator<< (std::ostream &os, const list<T> &l) {
			for (auto it = l.head->next; it != nullptr; it = it->next) {
				if (it->prev == l.head)
					os << "(prev: S) ";
				else
					os << "(prev: " << (it->prev->data) << ") ";

				os << "(cur: " << (it->data) << ") ";

				if (it->next == nullptr)
					os << "(next: N) ";
				else
					os << "(next: " << (it->next->data) << ") ";

				os << std::endl;				
			}

			return os;
		}

		/*
		 * todo:
		 *  search by value
		 *  search by pos
		 */
};

template <typename T>
struct list<T>::node {
	T data;
	node *prev;
	node *next;

	node (): prev(nullptr), next(nullptr) {}

	node (const T value, node *prev, node *next): data(value), prev(prev), next(next) {}
};

template <typename T>
class list<T>::iterator {
	node *ptr;

	public:
		iterator (node *it = nullptr): ptr(it) {} // nullptr = default parameter

		node *operator= (const node *rhs) {
			ptr = rhs;
			return ptr;
		}

		inline bool operator!= (iterator rhs) const {
			return !(ptr == rhs.ptr);
		}

		inline T &operator* () const {
			return ptr->data;
		}

		iterator &operator++ (int) {
			ptr = ptr->next;
			return *this;
		}

		iterator &operator++ () {
			ptr = ptr->next;
			return *this;
		}
};

template <typename T>
class list<T>::const_iterator {
	const node *ptr;

	public:
		const_iterator (const node *it = nullptr): ptr(it) {} // nullptr = default parameter

		node *operator= (const node *rhs) {
			ptr = rhs;
			return ptr;
		}

		inline bool operator!= (const const_iterator rhs) const {
			return !(ptr == rhs.ptr);
		}

		inline const T &operator* () const {
			return ptr->data;
		}

		const_iterator &operator++ (int) {
			ptr = ptr->next;
			return *this;
		}

		const_iterator &operator++ () {
			ptr = ptr->next;
			return *this;
		}
};

#endif