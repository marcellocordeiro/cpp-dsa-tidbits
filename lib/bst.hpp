#pragma once

template <typename T>
class bst {
  struct node;
  node *root;

private:
  node *insert (node *root, T value) {
    if (root == nullptr) {
      return new node(value);
    }

    if (root->data > value) {
      root->left = insert(root->left, value);
    } else if (root->data < value) {
      root->right = insert(root->right, value);
    }

    return root;
  }

  /*void print_in_order (node *root) {
    if (root == nullptr)
      return;

    print_in_order(root->left);
    cout << "[" << root->data << "] ";
    print_in_order(root->right);

    return;
  }*/

  T height (const node *root) const {
    T l, r;

    if (root == nullptr) {
      return 0;
    }

    l = height(root->left);
    r = height(root->right);

    return l > r ? (l + 1):(r + 1);
  }

  bool search (const node *root, const T value) const {
    if (root == nullptr) {
      return false;
    }

    if (root->data > value) {
      return search(root->left, value);
    } else if (root->data < value) {
      return search(root->right, value);
    } else {
      return true;
    }
  }

  node *find_min (const node *root) const {
    if (root->left == nullptr) {
      return root;
    } else {
      return find_min(root->left);
    }
  }

  node *remove (node *root, const T value) {
    if (root == nullptr) {
      return nullptr;
    }

    if (value < root->data) {
      root->left = remove(root->left, value);
    } else if (value > root->data) {
      root->right = remove(root->right, value);
    } else { //value == root->data
      if (root->left == nullptr) {
        node *temp = root->right;

        delete root;
        
        return temp;
      } else if (root->right == nullptr) {
        node *temp = root->left;

        delete root;
        
        return temp;
      } else {
        node *temp = find_min(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
      }
    }

    return root;
  }

  void delete_tree (node *root) {
    if (root == nullptr) {
      return;
    }

    delete_tree(root->left);
    delete_tree(root->right);

    if (root->left != nullptr) {
      delete root->left;
    }

    if (root->right != nullptr) {
      delete root->right;
    }
  }

public:
  bst () : root(nullptr) {}

  ~bst () {
    delete_tree(root);
  }

  /*void print () {
    print_in_order(root);
    cout << "\n";
  }*/

  inline T height () const {
    return height(root);
  }

  inline bool search (const T value) const {
    return search(root, value);
  }

  inline void insert (const T value) {
    root = insert(root, value);
  }

  inline void remove (const T value) {
    root = remove(root, value);
  }
};

template <typename T>
struct bst<T>::node {
  T data;
  node *left;
  node *right;

  node (const T value) : data(value), left(nullptr), right(nullptr) {}

  node (const T value, node *left, node *right) : data(value), left(left), right(right) {}
};