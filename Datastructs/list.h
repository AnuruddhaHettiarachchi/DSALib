#pragma once

namespace datastruct
{

	template <typename T>
	class SLList;

	template <typename T>
	class SNode
	{
		T data;
		SNode<T>* next;
	public:
		SNode(const T& d) : data(d), next(nullptr) {}
		friend class SLList<T>;
	};

	template <typename T>
	class SLList
	{
		SNode<T>* head;
		int size;
	public:
		SLList() : head(nullptr), size(0) {}
		~SLList();
		void	insert		(int pos, const T& data);
		void	remove		(int pos);
		void	pushFront	(const T& data);
		T		popFront	();
		void	pushBack	(const T& data);
		T		popBack		();
		T		get			(int pos) const;
		bool	isEmpty		() const;
		int		getSize		() const;
		void	traverse	();
	private:
		SNode<T>*	goTo(int pos) const;
	};


	template <typename T>
	class DLList;

	template <typename T>
	class DNode
	{
	public:
		DNode(const T& d) : data(d), prev(nullptr), next(nullptr) {}
		friend class DLList<T>;
	private:
		T data;
		DNode<T>* prev, *next;
	};

	template <typename T>
	class DLList
	{
	public:
		DLList() : head(nullptr), size(0) {}
		~DLList();
		void	insert		(int pos, const T& data);
		void	remove		(int pos);
		void	pushFront	(const T& data);
		T		popFront	();
		void	pushBack	(const T& data);
		T		popBack		();
		T		get			(int pos);
		bool	isEmpty		();
		int		getSize		();
		void	traverse	();
		void	reverse		();
	private:
		DNode<T>* head;
		int size;

		DNode<T>*	goTo(int pos);
	};


	template <typename T>
	class ArrayList {
		enum {INIT_ALLOC_SIZE = 100};
	public:
		ArrayList() : ar(new T[INIT_ALLOC_SIZE]),  fullSize(INIT_ALLOC_SIZE), size(0) {}
		ArrayList(ArrayList<T>& list);
		~ArrayList() { delete[] ar; }
		void insert(int pos, const T& val);
		void remove(int pos);
		void set(int pos, const T& val);
		T& at(int pos) const;
		T& operator[](int pos) const;
		ArrayList<T>& operator=(ArrayList<T>& list);
		bool isEmpty() const;
		int getSize() const;
	private:
		void resizeArray();
		T* ar;
		int fullSize, size;
	};
}