#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <typename T>
struct Node {
	T data;
	Node *left;
	Node *right;
	Node(const T &data = T(), Node *left = NULL, Node *right = NULL);
};

template <typename T>
class BinaryTree {
private:
	Node<T> *root;

	void copy(Node<T> **newNode, const Node<T> *toCopy);
	void destroy(Node<T> **toDelete);
	void copyTree(const BinaryTree &other);
	void deleteTree();
	void print(const Node<T> *toPrint) const;

public:
	BinaryTree();
	BinaryTree(const T &rootData);
	BinaryTree(const T &rootData, const BinaryTree &leftTree,
						const BinaryTree &rightTree);
	BinaryTree(const BinaryTree &other);
	BinaryTree &operator=(const BinaryTree &other);
	~BinaryTree();

	bool isEmpty() const;
	T getRoot() const;
	BinaryTree getLeftTree() const;
	BinaryTree getRightTree() const;
	void printTree() const;

	void setRoot(const T &data);
	void setLeftTree(const BinaryTree &tree);
	void setRightTree(const BinaryTree &tree);
};

#endif
