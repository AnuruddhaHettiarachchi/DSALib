#include <iostream>
#include <list>
#include <thread>
#include <algorithm>

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
#include "MiscAlgo\threads.h"

using namespace std;
using namespace sorting;
using namespace datastruct;

int main()
{
	string a = "hello";

	for_each(a.begin(), a.end(), toupper);

	cout << a.c_str() << endl;
}