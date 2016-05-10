#pragma once

#include<cmath>

template<typename T>
class binaryTree {
public:
	class iterator;
public:
	iterator root() { return iterator(); }

public:
	class iterator {
		friend class binaryTree<T>;
	private:
		iterator() {};
	public:
		iterator leftChild() { return iterator(); }
		iterator rightChild() { return iterator(); }
		const iterator leftChild() const { return iterator(); }
		const iterator rightChild() const { return iterator(); }
		bool isExternal() const { return false; }
	};
};

/*	Only for illustration
*	Need to implement a proper binary tree for testing
*/

template<typename T>
int height(typename const binaryTree<T>::iterator& i, bool& balanced)
{
	if (!balanced)
		return 0;
	int a = 0, b = 0;
	if (i.leftChild() != NULL)
		a = height(i.leftChild(), balanced) + 1;
	if (i.rightChild() != NULL)
		b = height(i.rightChild(), balanced) + 1;
	if (abs(a - b) > 1)
	{
		balanced = false;
		return 0;
	}
	return max(a, b);
}

template<typename T>
bool balanced(binaryTree<T>& t)
{
	typename binaryTree<T>::iterator i = t.root();
	bool balanced  = true;
	height<T>(i, balanced);
	return balanced;
}