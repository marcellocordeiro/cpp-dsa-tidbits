#ifndef __bst_hpp_included__
#define __bst_hpp_included__

namespace bt { // binary tree
	template <typename T>
	struct node {
		T data;
		node *left;
		node *right;

		node (T value): data(value), left(nullptr), right(nullptr) {}

		node (T value, node<T> *left, node<T> *right): data(value), left(left), right(right) {}
	};
}

template <typename T>
class bst {
	bt::node<T> *root;
	
	private:
		bt::node<T> *insert (bt::node<T> *root, T value) {
			if (root == nullptr)
				return new bt::node<T>(value);

			if (root->data > value)
				root->left = insert(root->left, value);
			else if (root->data < value)
				root->right = insert(root->right, value);

			return root;
		}

		/*void printInOrder (bt::node<T> *root) {
			if (root == nullptr)
				return;

			printInOrder(root->left);
			cout << "[" << root->data << "] ";
			printInOrder(root->right);

			return;
		}*/

		T height (bt::node<T> *root) {
			T l, r;

			if (root == nullptr)
				return 0;

			l = height(root->left);
			r = height(root->right);

			return l > r ? (l + 1):(r + 1);
		}

		bool search (bt::node<T> *root, T value) {
			if (root == nullptr)
				return false;

			if (root->data == value)
				return true;

			if (root->data > value)
				return search(root->left, value);
			else
				return search(root->right, value);
		}

		bt::node<T> *findMin (bt::node<T> *root) {
			if (root->left == nullptr)
				return root;
			else
				return findMin(root->left);
		}

		bt::node<T> *remove (bt::node<T> *root, int value) {
			if (root == nullptr)
				return nullptr;

			if (value < root->data) {
				root->left = remove(root->left, value);
			} else if (value > root->data) {
				root->right = remove(root->right, value);
			} else { //value == root->data
				if (root->left == nullptr) {
					bt::node<T> *temp = root->right;

					delete root;
					
					return temp;
				} else if (root->right == nullptr) {
					bt::node<T> *temp = root->left;

					delete root;
					
					return temp;
				} else {
					bt::node<T> *temp = findMin(root->right);
					root->data = temp->data;
					root->right = remove(root->right, temp->data);
				}
			}

			return root;
		}

		void deleteTree (bt::node<T> *root) {
			if (root == nullptr)
				return;

			deleteTree(root->left);
			deleteTree(root->right);

			if (root->left != nullptr)
				delete root->left;

			if (root->right != nullptr)
				delete root->right;
		}

	public:
		bst (): root(nullptr) {}

		~bst () {
			deleteTree(root);
		}

		/*void print () {
			printInOrder(root);
			cout << "\n";
		}*/

		T height () {
			return height(root);
		}

		void insert (T value) {
			root = insert(root, value);
		}

		void remove (T value) {
			root = remove(root, value);
		}

		bool search (T value) {
			return search(root, value);
		}
};

#endif