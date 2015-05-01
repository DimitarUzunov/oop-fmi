#include <iostream>
#include "linked_list.cpp"

int main()
{
	LinkedList<double> l;
	l.print();
	l.insertHead(1);
	l.insertTail(2);
	l.insertHead(0);
	l.insertHead(-2);
	l += 3;

	LinkedList<double> l2;
	l2 = l;
	l2.print();
	l2.removeHead();
	l2.print();
	l2.insertAt(5.6, 2);
	l2.print();
	l2.removeAt(4);
	l2.print();
	l2.removeTail();
	l2.print();
	l2 += 4;
	l2.print();
	l.print();

	std::cout << l2.search(5.6) << '\n';
	std::cout << l2[3] << '\n';

	return 0;
}
