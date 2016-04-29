#include "list.h"
#include <iostream>

using namespace std;

namespace datastruct
{
	template<typename T>
	SLList<T>::~SLList()
	{
		while (!isEmpty())
		{
			popFront();
		}
	}

	template <typename T>
	void SLList<T>::insert(int pos, const T& data)
	{
		if (pos == 0)
		{
			pushFront(data);
		}
		else
		{
			SNode<T>* prev, *newNode = new SNode<T>(data);
			prev = goTo(pos - 1);
			newNode->next = prev->next;
			prev->next = newNode;
			size++;
		}
	
	}

	template <typename T>
	void SLList<T>::remove(int pos)
	{
		SNode<T>* current = goTo(pos);
		if (pos == 0)
		{
			popFront();
		}
		else
		{
			goTo(pos - 1)->next = current->next;
		}
		delete current;
		size--;
	}

	template<typename T>
	void SLList<T>::pushFront(const T & data)
	{
		SNode<T>* newNode = new SNode<T>(data);
		if (!isEmpty())
		{
			newNode->next = head;
		}
		head = newNode;
		size++;
	}

	template<typename T>
	T SLList<T>::popFront()
	{
		SNode<T>* current = head;
		T data = current->data;
		head = head->next;
		delete current;
		size--;
		return data;
	}

	template<typename T>
	void SLList<T>::pushBack(const T & data)
	{
		insert(size, data);
	}

	template<typename T>
	T SLList<T>::popBack()
	{
		T data = get(size - 1);
		remove(size - 1);
		return data;
	}

	template <typename T>
	T SLList<T>::get(int pos) const
	{
		return goTo(pos)->data;
	}

	template<typename T>
	bool SLList<T>::isEmpty() const
	{
		return size == 0;
	}

	template<typename T>
	int SLList<T>::getSize() const
	{
		return size;
	}

	template <typename T>
	void SLList<T>::traverse() 
	{
		SNode<T>* current = head;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

	template<typename T>
	SNode<T>* SLList<T>::goTo(int pos) const
	{
		SNode<T>* current = head;
		for (int i = 1; i <= pos; i++)
		{
			current = current->next;
		}
		return current;
	}

	template<typename T>
	DLList<T>::~DLList()
	{
		while (!isEmpty())
		{
			popFront();
		}
	}

	template<typename T>
	void DLList<T>::insert(int pos, const T & data)
	{
		if (pos == 0)
		{
			pushFront(data);
		}
		else
		{
			DNode<T>* newNode = new DNode<T>(data);
			DNode<T>* prev = goTo(pos - 1);
			newNode->prev = prev;
			newNode->next = prev->next;
			prev->next = newNode;
			if (newNode->next != nullptr)
				newNode->next->prev = newNode;
			size++;
		}
	}

	template<typename T>
	void DLList<T>::remove(int pos)
	{
		if (pos == 0)
			popFront();
		else
		{
			DNode<T>* current = goTo(pos);
			T data = current->data;
			current->prev->next = current->next;
			if (current->next != nullptr)
				current->next->prev = current->prev;
			delete current;
			size--;
		}
	}

	template<typename T>
	void DLList<T>::pushFront(const T & data)
	{
		DNode<T>* newNode = new DNode<T>(data);
		if (!isEmpty())
		{
			DNode<T>* next = head;
			newNode->next = next;
			next->prev = newNode;
		}
		head = newNode;
		size++;
	}

	template<typename T>
	T DLList<T>::popFront()
	{
		DNode<T>* current = head;
		T data = current->data;
		head = current->next;
		if (current->next != nullptr)
			current->next->prev = nullptr;
		delete current;
		size--;
		return data;
	}

	template<typename T>
	void DLList<T>::pushBack(const T & data)
	{
		insert(size, data);
	}

	template<typename T>
	T DLList<T>::popBack()
	{
		DNode<T>* current = goTo(size - 1);
		T data = current->data;
		remove(size - 1);
		return data;
	}

	template<typename T>
	T DLList<T>::get(int pos)
	{
		return goTo(pos)->data;
	}

	template<typename T>
	bool datastruct::DLList<T>::isEmpty()
	{
		return size == 0;
	}

	template<typename T>
	int DLList<T>::getSize()
	{
		return size;
	}

	template<typename T>
	void DLList<T>::traverse()
	{
		DNode<T>* current = head;
		for (int i = 0; i < size; i++)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

	template<typename T>
	void DLList<T>::reverse()
	{
		DNode<T>* current = head;
		DNode<T>* prev = head;
		while (current != nullptr)
		{
			prev = current;
			DNode<T>* temp = current->next;
			current->next = current->prev;
			current->prev = temp;
			current = temp;
		}
		head = prev;
	}

	template<typename T>
	DNode<T>* DLList<T>::goTo(int pos)
	{
		DNode<T>* current = head;
		for (int i = 1; i <= pos; i++)
		{
			current = current->next;
		}
		return current;
	}

	template <typename T>
	ArrayList<T>::ArrayList(ArrayList<T>& list)
	{
		fullSize = list.fullSize;
		size = list.size;
		ar = new T[fullSize];
		for (int i = 0; i < size; i++)
		{
			ar[i] = list.ar[i];
		}
	}

	template <typename T>
	void ArrayList<T>::insert(int pos, const T& val)
	{
		if (size == fullSize)
			resizeArray();
		for (int i = size; i > pos; i--)
		{
			ar[i] = ar[i - 1];
		}
		ar[pos] = val;
		size++;
	}

	template<typename T>
	void ArrayList<T>::remove(int pos)
	{
		for (int i = pos; i < size; i++)
		{
			ar[i] = ar[i + 1];
		}
		size--;
	}

	template<typename T>
	void ArrayList<T>::set(int pos, const T & val)
	{
		ar[pos] = val;
	}

	template<typename T>
	T& ArrayList<T>::at(int pos) const
	{
		return ar[pos];
	}

	template <typename T>
	T& ArrayList<T>::operator[](int pos) const
	{
		return ar[pos];
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(ArrayList<T>& list)
	{
		size = list.size;
		fullSize = list.fullSize;
		ar = new T[fullSize];
		for (int i = 0; i < size; i++)
		{
			ar[i] = list.ar[i];
		}
		return *this;
	}

	template<typename T>
	bool ArrayList<T>::isEmpty() const
	{
		return size == 0;
	}

	template<typename T>
	int ArrayList<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	void ArrayList<T>::resizeArray()
	{
		fullSize += INIT_ALLOC_SIZE;
		T* newAr = new T[fullSize];
		for (int i = 0; i < size; i++)
		{
			newAr[i] = ar[i];
		}
		delete[] ar;
		ar = newAr;
	}

}