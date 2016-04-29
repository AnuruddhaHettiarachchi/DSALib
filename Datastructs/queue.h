#pragma once
#include "list.h"
#include <exception>

using namespace std;

namespace exceptions
{
	class QueueFullException : public exception {
	public:
		QueueFullException() : err("queue full") {}
		const char* what() const { return err; }
	private:
		char* err;
	};

	class QueueEmptyException : public exception {
	public:
		QueueEmptyException() : err("queue empty") {}
		const char* what() const { return err; }
	private:
		char* err;
	};
}

namespace datastruct
{
	template <typename T>
	class Queue {
	public:
		virtual ~Queue() {};
		virtual void	enqueue	(const T&) = 0;
		virtual T		dequeue	() = 0;
		virtual T		getFront() const = 0;
		virtual bool	isEmpty	() const = 0;
		virtual bool	isFull	() const = 0;
		virtual int		getSize() const = 0;
		virtual void	traverse() const = 0;
	};

	template <typename T>
	class ArrayQueue : public Queue<T> {
	public:
		ArrayQueue(int s) : ar(new T[s]), size(0), arraySize(s), front(0), back(0) {}
		~ArrayQueue() { delete[] ar; }
		void	enqueue	(const T&);
		T		dequeue	();
		T		getFront() const;
		bool	isEmpty	() const;
		bool	isFull	() const;
		int		getSize	() const;
		void	traverse() const;
	private:
		T* ar;
		int size, arraySize;
		int front, back;
	};
}
