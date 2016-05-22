#pragma once

#include<unordered_map>
#include<list>

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