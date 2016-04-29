#include "tree.h"

using namespace std;

template<typename T>
typename NodeTree<T>::Iterator NodeTree<T>::root()
{
	return Iterator(_root);
}

template<typename T>
typename NodeTree<T>::Iterator NodeTree<T>::Iterator::parent()
{
	return Iterator(node->parent);
}

//template<typename T>
//list<NodeTree<T>::Iterator> NodeTree<T>::Iterator::children()
//{
//	list;
//	//for(list::ite = 0; i < node.children.size() < i++)
//}

template<typename T>
T& NodeTree<T>::Iterator::operator*()
{
	return node->data;
}

template<typename T>
bool NodeTree<T>::Iterator::isRoot() const
{
	return node->parent == nullptr;
}

template<typename T> 
bool NodeTree<T>::Iterator::isExternal() const
{
	return node->children.size() == 0;
}
