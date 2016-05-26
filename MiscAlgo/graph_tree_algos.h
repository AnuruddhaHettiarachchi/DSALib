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

/*
// ............... graph sum ................ //
//cannot test until btree implementation

typedef btree::node node;
queue<node> q;
unordered_map<node, bool> m;

void printPath(list<node>& path)
{
	for (node n : path)
	{
		cout << n.value() << " ";
	}
	cout << endl;
}

void searchFrom(node n, int pSum, int sum, list<node>& path)
{
	for (node child : n.children())
	{
		if (!m[child])
		{
			q.push(child);
			m[child] = true;
		}
		list<node> newPath = path;
		newPath.push_back(child);
		int newPSum = pSum + child.value();
		if (newPSum == sum)
			printPath(newPath);
		searchFrom(child, newPSum, sum, newPath);
	}
}

void printSumPath(const btree& tr, int sum)
{
	q.push(tr.root());
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		int pSum = n.value();
		list<node> path;
		path.push_back(n);
		searchFrom(n, pSum, sum, path);
	}
}

*/

/* ............ check subtrees ...............

typedef btree<int, int>::iterator node

bool isSubtree(btree<int, int>& t1, btree<int, int>& t2)
{
	node r1 = t1.root(); 	//begin() is not the same as root() 
	node r2 = t2.root();	//iterators traverse (operator++ operator--) in order

	vector<node> t1nodes, t2nodes;

	inorder(r1, t1nodes);
	inorder(r2, t2nodes);

	vector<node>::iterator t2nodesIt = t2nodes.begin();
	for (node t1node : t1nodes)
	{
		if (node.key() == (*t2nodesIt).key())
			t2nodesIt++;
		else
			t2nodesIt = t2nodes.begin();
		if (t2nodesIt == t2nodes.end())
			return true;
	}
	return false;
}

void inorder(btree<int, int>& tree, node& node, vector<node>& vec)
{
	if (node == tree.null())
	{
		vec.push_back(tree.null());
		return;
	}
	inorder(tree, node.left(), vec);
	vec.push_back(node);
	inorder(tree, node.right(), vec);
}

*/

