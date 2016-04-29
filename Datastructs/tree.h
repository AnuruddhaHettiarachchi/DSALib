#pragma once
#include <list>

using namespace std;

// Just an Interface

template <typename T>
class Tree {
public:
	class Iterator;

	virtual ~Tree() {}
	virtual Iterator& root() = 0;
	virtual list<Iterator>& all() = 0;
	virtual bool empty() const { return _size == 0; }
	virtual int size() const { return _size; }
private:
	int _size;
};

template <typename T>
class Tree<T>::Iterator {
public:
	virtual Iterator& parent() = 0;
	virtual list<Iterator>& children() = 0;
	virtual T& operator*() = 0;
	virtual bool isRoot() const = 0;
	virtual bool isExternal() const = 0;
};


template <typename T>
class NodeTree{
public:
	class Iterator;
private:
	class Node;
public:
	NodeTree() : _root(nullptr), _size(0) {};
	~NodeTree() {} // remove all
	void add(const T&); // cannot define yet
	void remove(const Iterator&); // cannot define yet
	list<T> preOrder();
	list<T> postOrder();
	Iterator root();
	list<Iterator> iterators();
private:
	int _size;
	Node* _root;
};

template <typename T>
class NodeTree<T>::Iterator{
	friend class NodeTree<T>;
private:
	Iterator(Node* n) : node(n) {}
public:
	Iterator parent();
	list<Iterator>& children();
	T& operator*();
	bool isRoot() const;
	bool isExternal() const;
private:
	Node* node;
};

template<typename T>
class NodeTree<T>::Node {
	friend class NodeTree<T>::Iterator;
private:
	T data;
	Node* parent;
	list<Node*> children;
};
