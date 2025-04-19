#pragma once

template <typename T>
class bst {
  struct node;

public:
  bst() = default;

  ~bst() {
    delete_tree(this->root);
  }

  /*void print() {
    print_in_order(root);
    cout << "\n";
  }*/

  auto height() const -> T {
    return height(this->root);
  }

  auto search(const T value) const -> bool {
    return search(this->root, value);
  }

  void insert(const T value) {
    this->root = insert(this->root, value);
  }

  void remove(const T value) {
    this->root = remove(this->root, value);
  }

private:
  auto insert(node* root, const T value) -> node* {
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

  auto height(const node* root) const -> T {
    if (root == nullptr) {
      return 0;
    }

    auto l = height(root->left);
    auto r = height(root->right);

    return (l > r) ? (l + 1) : (r + 1);
  }

  auto search(const node* root, const T value) const -> bool {
    if (root == nullptr) {
      return false;
    }

    if (root->data > value) {
      return search(root->left, value);
    }

    if (root->data < value) {
      return search(root->right, value);
    }
    return true;
  }

  auto find_min(const node* root) const -> node* {
    if (root->left == nullptr) {
      return root;
    }

    return find_min(root->left);
  }

  auto remove(node* root, const T value) -> node* {
    if (root == nullptr) {
      return nullptr;
    }

    if (value < root->data) {
      root->left = remove(root->left, value);
    } else if (value > root->data) {
      root->right = remove(root->right, value);
    } else { // value == root->data
      if (root->left == nullptr) {
        node* temp = root->right;

        delete root;

        return temp;
      }

      if (root->right == nullptr) {
        node* temp = root->left;

        delete root;

        return temp;
      }

      node* temp = find_min(root->right);
      root->data = temp->data;
      root->right = remove(root->right, temp->data);
    }

    return root;
  }

  void delete_tree(node* root) {
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

  node* root = nullptr;
};

template <typename T>
struct bst<T>::node {
  T data;
  node* left = nullptr;
  node* right = nullptr;

  explicit node(const T value) : data(value) {}

  node(const T value, node* left, node* right) : data(value), left(left), right(right) {}
};
