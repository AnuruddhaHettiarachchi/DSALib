#include <iostream>
#include <list>
#include "Sorting\sorting.cpp"
#include "Datastructs\list.cpp"
#include "Datastructs\stack.cpp"
#include "Datastructs\queue.cpp"
#include "Datastructs\tree.cpp"
#include "MiscAlgo\permucombi.h"
#include "MiscAlgo\array_algos.h"
#include "MiscAlgo\list_algos.h"

using namespace std;
using namespace sorting;
using namespace datastruct;


int main()
{
	vector<char> choises;
	choises.push_back('a');
	choises.push_back('b');
	choises.push_back('c');
	choises.push_back('e');
	choises.push_back('t');

	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(2);
	l.push_back(3);
	l.push_back(3);
	l.push_back(1);

	list<int>::iterator i = l.begin();
	
	removeDups<int>(l);

	while (i != l.end())
	{
		cout << *i++ << endl;
	}

	//bool b = isUnique<char, 10>(choises);
	
}