#pragma once

#include<unordered_map>
#include<list>
#include<stack>

using namespace std;

template<typename T>
void removeDups(list<T>& l)
{
	unordered_map<T, bool> table;
	list<T>::iterator i = l.begin();

	while (i != l.end())
	{
		if (table[*i] != NULL)
			i = l.erase(i);
		else
		{
			table[*i] = true;
			i++;
		}
	}
}

typedef list<int>::iterator it;

void swapCW(it i, it j)
{
	if (i != j)
	{
		int temp = *i;
		*i = *j;
		*j = temp;
	}
}

void partition(list<int>& l, int x)
{
	it current, wall;
	current = wall = l.begin();
	while (current != l.end())
	{
		if (*current < x)
		{
			swapCW(current, wall);
			wall++;
		}
		current++;
	}
}

bool isPalindrome(list<int> l)
{
	stack<int> st;
	list<int>::iterator it = l.begin();
	int mid = l.size() / 2;

	for (int i = 1; i <= mid; i++)
	{
		st.push(*it);
		it++;
	}

	if (l.size() % 2 != 0)
		it++;

	while (it != l.end())
	{
		if (*it != st.top())
			return false;
		it++;
		st.pop();
	}
	return true;
}
