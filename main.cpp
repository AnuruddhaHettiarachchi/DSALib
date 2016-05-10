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
#include "MiscAlgo\stack_queue_algos.h"
#include "MiscAlgo\graph_tree_algos.h"
#include "MiscAlgo\bit_manipulator.h"

using namespace std;
using namespace sorting;
using namespace datastruct;


int main()
{
	threeStack<int> s(2, 2, 2);
	s.push(0, 0);
	s.push(0, 1);
	s.push(0, 2);
	s.push(0, 3);
	s.push(0, 4);

	s.push(1, 10);
	s.push(1, 11);
	s.push(1, 12);
	s.push(1, 13);
	s.push(1, 14);

	s.push(2, 21);

	s.empty(2);

	int v = -1;
	clearLSBsUntil(v, 30);

	int m = 0b1010;
	int n = 0b1010101;

	int c = 2/4;

	cout << insertBetween(m, n, 5, 2) << endl;

	
//	while (i != l.end())
//	{
//		cout << *i++ << endl;
//	}

}