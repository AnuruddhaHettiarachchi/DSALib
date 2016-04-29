#include "stack.h"

namespace datastruct
{
	template <typename T>
	void ArrayStack<T>::push(const T& data)
	{
		if (top == size)
			throw StackOverflowException();
		ar[top] = data;
		top++;
	}

	template <typename T>
	T ArrayStack<T>::pop()
	{
		if (top == 0)
			throw StackEmptyException();
		top--;
		return ar[top];
	}

	template <typename T>
	T ArrayStack<T>::getTop() const
	{
		if (top == 0)
			throw StackEmptyException();
		return ar[top - 1];
	}

	template <typename T>
	bool ArrayStack<T>::isEmpty() const
	{
		return top == 0;
	}

	template <typename T>
	int ArrayStack<T>::getSize() const
	{
		return top;
	}

	template<typename T>
	void datastruct::LLStack<T>::push(const T & data)
	{
		list.pushFront(data);
	}

	template<typename T>
	T LLStack<T>::pop()
	{
		return list.popFront();
	}
	template<typename T>
	T LLStack<T>::getTop() const
	{
		return list.get(0);
	}
	template<typename T>
	bool LLStack<T>::isEmpty() const
	{
		return list.isEmpty();
	}
	template<typename T>
	int LLStack<T>::getSize() const
	{
		return list.getSize();
	}
}