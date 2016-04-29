#include "queue.h"
#include <iostream>

using namespace exceptions;
using namespace std;

namespace datastruct
{
	template <typename T>
	void ArrayQueue<T>::enqueue(const T& data)
	{
		if (isFull())
			throw QueueFullException();
		ar[back] = data;
		back = (++back % arraySize);
		size++;
	}

	template<typename T>
	T ArrayQueue<T>::dequeue()
	{
		if (size == 0)
			throw QueueEmptyException();
		T data = ar[front];
		front = (++front % arraySize);
		size--;
		return data;
	}

	template<typename T>
	T ArrayQueue<T>::getFront() const
	{
		if (size == 0)
			throw QueueEmptyException();
		return ar[front];
	}

	template<typename T>
	bool ArrayQueue<T>::isEmpty() const
	{
		return size == 0;
	}

	template<typename T>
	bool ArrayQueue<T>::isFull() const
	{
		return (front == back && size > 0);
	}

	template<typename T>
	int ArrayQueue<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	void ArrayQueue<T>::traverse() const
	{
		bool skipCheck = false;
		if(isFull())
			skipCheck = true;
		int current = front;
		while (current != back || skipCheck)
		{
			if (skipCheck)
				skipCheck = false;
			cout << ar[current] << " " ;
			current = (++current % arraySize);
		}
		cout << endl;
	}


}