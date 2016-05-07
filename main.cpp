#include <iostream>
#include <list>
#include "Sorting\sorting.cpp"
#include "Datastructs\list.cpp"
#include "Datastructs\stack.cpp"
#include "Datastructs\queue.cpp"
#include "Datastructs\tree.cpp"
#include "MiscAlgo\permucombi.h"

using namespace std;
using namespace sorting;
using namespace datastruct;


int main()
{
	vector<char> choises;
	choises.push_back('a');
	choises.push_back('b');
	choises.push_back('c');
	choises.push_back('d');
	choises.push_back('e');
	printAllCombi<char>(choises, 3, true);
	//cout << s.getTop() << endl;
}