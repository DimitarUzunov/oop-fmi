#include <iostream>
#include "binary_tree.cpp"

int main() {
	BinaryTree<int> s1(2);
	BinaryTree<int> s2(3);
	BinaryTree<int> s3(5);
	BinaryTree<int> s4;
	s4.getRoot();
	BinaryTree<int> t1(1, s1, s2);
	BinaryTree<int> t2(4, s3, s4);

	BinaryTree<int> t(0, t1, t2);
	t.printTree();
	std::cout << '\n';

	t.setRightTree(s3);
	t.printTree();
	std::cout << '\n';

	t.getLeftTree().printTree();
	std::cout << '\n';

	return 0;
}
