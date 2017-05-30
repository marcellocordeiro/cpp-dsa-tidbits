#ifndef __list_stack_queue_hpp_included__
#define __list_stack_queue_hpp_included__

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

		iterator begin () {
			return iterator(head->next);
		}

		iterator end () {
			return iterator(nullptr);
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
class stack: private list<T> {
	public:
		inline bool empty () const {
			return list<T>::empty();
		}
		
		inline typename list<T>::size_type size () const {
			return list<T>::size();
		}

		inline T top () const {
			return list<T>::front();
		}

		inline void push (T value) {
			list<T>::push_front(value);
		}

		inline void pop () {
			list<T>::pop_front();
		}
};

template <typename T>
class queue: private list<T> {
	public:
		inline bool empty () const {
			return list<T>::empty();
		}

		inline typename list<T>::size_type size () const {
			return list<T>::size();
		}

		inline T front () const {
			return list<T>::front();
		}

		inline T back () const {
			return list<T>::back();
		}

		inline void push (T value) {
			list<T>::push_back(value);
		}

		inline void pop () {
			list<T>::pop_front();
		}
};

#endif