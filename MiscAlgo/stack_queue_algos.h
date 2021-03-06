#pragma once

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

template<typename T>
class threeStack {
public:
	threeStack(int s1, int s2, int s3);
	void push(int s, const T& val);
	T pop(int s);
	T top(int s);
	int size(int s) { return _size[s]; }
	bool empty(int s) { return _size[s] == 0; }

private:
	void resize(int s);

private:
	vector<T> ar;
	int _top[3];
	int end[3];
	int _size[3];
};

template<typename T>
threeStack<T>::threeStack(int s1, int s2, int s3) :
	ar(vector<T>(s1 + s2 + s3))
{
	_top[0] = 0; _top[1] = s1; _top[2] = s1 + s2;
	end[0] = s1 - 1; end[1] = s1 + s2 - 1; end[2] = s1 + s2 + s3 - 1;
	_size[0] = _size[1] = _size[2] = 0;
}

template<typename T>
void threeStack<T>::push(int s, const T& val)
{
	if (_top[s] <= end[s])
	{
		ar[_top[s]] = val;
		_top[s]++;
		_size[s]++;
	}
	else
	{
		resize(s);
		push(s, val);
	}
}

template<typename T>
void threeStack<T>::resize(int s)
{
	int jump = _size[s];
	ar.resize(ar.size() + jump);
	int startI = end[s] + 1;
	for (int i = end[3]; i >= startI; i--)
	{
		ar[i + jump] = ar[i];
	}
	end[s] = end[s] + jump;
	for (int i = s + 1; i < 3; i++)
	{
		_top[i] = _top[i] + jump;
		end[i] = end[i] + jump;
	}
}
 
template<typename T>
T threeStack<T>::pop(int s)
{
	if (_size[s] == 0) {
		cerr << "empty stack" << endl;
		return NULL;
	}
	else
	{
		_top[s]--;
		_size[s]--;
		return ar[_top[s] + 1];
	}
}

template<typename T>
T threeStack<T>::top(int s)
{
	if (_size[s] == 0)
	{
		cerr << "empty stack" << endl;
		return NULL;
	}
	else
	{
		return ar[_top[s]];
	}
}

class minStack {
public:
	minStack() : topIndex(0) {}
	void push(int val);
	int pop();
	int min() const;
private:
	vector<int> valStack;
	stack<int> iStack;
	int topIndex;
};

void minStack::push(int val)
{
	if(valStack.size() <= topIndex)
		valStack.push_back(0);
	valStack[topIndex] = val;
	if (iStack.empty() || valStack[iStack.top()] > val)
		iStack.push(topIndex);
	topIndex++;
}

int minStack::pop()
{
	if (topIndex == 0)
		throw "Empty stack";
	topIndex--;
	if (topIndex == iStack.top())
		iStack.pop();
	return valStack[topIndex];
}

int minStack::min() const
{
	if (topIndex == 0)
		throw "Empty stack";
	return valStack[iStack.top()];
}

/* ............ Cats and Dogs Shelter .............*/

enum class AnimalType {
	cat, dog
};

class Animal {
public:
	Animal(AnimalType t) : type(t) {}
	AnimalType getType() { return type; }
protected:
	AnimalType type;
};

class Cat : public Animal {
public:
	Cat() : Animal(AnimalType::cat) {}
};

class Dog : public Animal {
	Dog() : Animal(AnimalType::dog) {}
};

class Shelter {
public:
	void enqueue(Animal a);
	Animal dequeueAny();
	Cat dequeueCat();
	Dog dequeueDog();
private:
	list<Animal> animals;
	list<list<Animal>::iterator> catPts;
	list<list<Animal>::iterator> dogPts;
};

void Shelter::enqueue(Animal a)
{
	list<Animal>::iterator i = animals.insert(animals.end(), a);
	if (a.getType() == AnimalType::cat)
		catPts.push_back(i);
	else
		dogPts.push_back(i);
}

Animal Shelter::dequeueAny()
{
	Animal a = animals.front();
	if (a.getType() == AnimalType::cat)
		catPts.pop_front();
	else
		dogPts.pop_front();
	animals.pop_front();
	return a;
}

Cat Shelter::dequeueCat()
{
	list<Animal>::iterator ci = catPts.front();
	Cat c = *(static_cast<Cat*>(&*ci));
	animals.erase(ci);
	catPts.pop_front();
	return c;
}

Dog Shelter::dequeueDog()
{
	list<Animal>::iterator di = dogPts.front();
	Dog d = *(static_cast<Dog*>(&*di));
	animals.erase(di);
	dogPts.pop_front();
	return d;
}