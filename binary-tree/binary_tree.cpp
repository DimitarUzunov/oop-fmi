#include <iostream>
#include "binary_tree.h"

template <typename T>
Node<T>::Node(const T &data, Node<T> *left, Node<T> *right)
					: data(data), left(left), right(right) {}

template <typename T>
void BinaryTree<T>::copy(Node<T> **newNode, const Node<T> *toCopy) {
	if (toCopy) {
		*newNode = new Node<T>(toCopy->data);
		copy(&(*newNode)->left, toCopy->left);
		copy(&(*newNode)->right, toCopy->right);
	}
}

template <typename T>
void BinaryTree<T>::destroy(Node<T> **toDelete) {
	if (*toDelete) {
		destroy(&(*toDelete)->left);
		destroy(&(*toDelete)->right);
		delete *toDelete;
		*toDelete = NULL;
	}
}

template <typename T>
void BinaryTree<T>::copyTree(const BinaryTree<T> &other) {
	copy(&root, other.root);
}

template <typename T>
void BinaryTree<T>::deleteTree() {
	destroy(&root);
}

template <typename T>
void BinaryTree<T>::print(const Node<T> *toPrint) const {
	if (toPrint) {
		print(toPrint->left);
		std::cout << toPrint->data << ' ';
		print(toPrint->right);
	}
}

template <typename T>
BinaryTree<T>::BinaryTree(): root(NULL) {}

template <typename T>
BinaryTree<T>::BinaryTree(const T &rootData): root(new Node<T>(rootData)) {}

template <typename T>
BinaryTree<T>::BinaryTree(const T &rootData, const BinaryTree<T> &leftTree,
													const BinaryTree<T> &rightTree) {
	root = new Node<T>(rootData);
	copy(&root->left, leftTree.root);
	copy(&root->right, rightTree.root);
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &other): root(NULL) {
	copyTree(other);
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &other) {
	if (this != &other) {
		deleteTree();
		copyTree(other);
	}

	return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	deleteTree();
}

template <typename T>
bool BinaryTree<T>::isEmpty() const {
	return root == NULL;
}

template <typename T>
T BinaryTree<T>::getRoot() const {
	if (isEmpty()) {
		std::cout << "This is the empty tree.\n";
		return T();
	}
	return root->data;
}

template <typename T>
BinaryTree<T> BinaryTree<T>::getLeftTree() const {
	BinaryTree<T> tree;
	tree.copy(&tree.root, root->left);
	return tree;
}

template <typename T>
BinaryTree<T> BinaryTree<T>::getRightTree() const {
	BinaryTree<T> tree;
	tree.copy(&tree.root, root->right);
	return tree;
}

template <typename T>
void BinaryTree<T>::printTree() const {
	print(root);
}

template <typename T>
void BinaryTree<T>::setRoot(const T &data) {
	root->data = data;
}

template <typename T>
void BinaryTree<T>::setLeftTree(const BinaryTree<T> &tree) {
	copy(&root->left, tree.root);
}

template <typename T>
void BinaryTree<T>::setRightTree(const BinaryTree<T> &tree) {
	copy(&root->right, tree.root);
}
