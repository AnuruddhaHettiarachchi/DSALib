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
#include "MiscAlgo\\math_problems.h"
#include "MiscAlgo\recursion_dp.h"
#include "MiscAlgo\searching_sorting_algos.h"

using namespace std;
using namespace sorting;
using namespace datastruct;


int main()
{
	
	vector<int> a = {1, 3, 5, 7, 9, 0, 0, 0, 0, 0};
	vector<int> b = {0, 2, 4, 6, 8};

	mergeArrays(a, b, 5, 5);

	for (int i : a)
		cout << i << " ";
}