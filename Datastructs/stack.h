#pragma once
#include <iostream>
#include <exception>
#include "list.h"

using namespace std;

namespace exceptions
{
	class StackEmptyException : public exception {
	public:
		StackEmptyException() : err("empty stack"), exception() {}
		const char* what() const { return err; }
	private:
		const char* err;
	};

	class StackOverflowException : public exception {
	public:
		StackOverflowException() : err("stack overflow"), exception() {}
		const char* what() const { return err; }
	private:
		const char* err;
	};
}

using namespace exceptions;

namespace datastruct 
{
	template <typename T>
	class Stack {
	public:
		virtual ~Stack() {};
		virtual void	push(const T&) = 0;
		virtual T		pop() = 0;
		virtual T		getTop() const = 0;
		virtual bool	isEmpty() const = 0;
		virtual int		getSize() const = 0; 
	};

	template <typename T>
	class ArrayStack : public Stack<T> {
	public:
		ArrayStack(int s) : size(s), top(0), ar(new T[s]), Stack<T>() {}
		~ArrayStack() { delete[] ar; }
		void	push(const T&);
		T		pop();
		T		getTop() const;
		bool	isEmpty() const;
		int		getSize() const;
	private:
		T* ar;
		int top;
		int size;
	};

	template <typename T>
	class LLStack : public Stack<T> {
	public:
		void	push(const T&);
		T		pop();
		T		getTop() const;
		bool	isEmpty() const;
		int		getSize() const;
	private:
		SLList<T> list;
	};

}
