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