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

#include <queue>
#include <vector>

using namespace std;
using namespace sorting;
using namespace datastruct;

bool func(const int a, const int b) { return a > b; }

int main()
{
	function<bool(int,int)> f = func;
	priority_queue<int, vector<int>, decltype(f)> q;
	q.push(8);
	q.push(5);
	q.push(2);
	q.push(1);

	cout << q.top() << endl;

}