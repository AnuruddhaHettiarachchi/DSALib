#pragma once
#include<iostream>
#include<vector>

using namespace std;

template <typename T>
void printAllPerm(const vector<T>& choises, int r, bool repeat = false)
{
	int count = 0;
	printAllPerm<T>(choises, vector<T>(), r, repeat, count);
	cout << endl << "Number of Permutations: " << count << endl;
}


template <typename T>
void printAllPerm(const vector<T>& choises, const vector<T>& filled, int remain, 
	const bool repeat, int& count)
{
	if (remain == 0)
	{
		printList<T>(filled);
		count++;
	}
	else
	{
		for (unsigned int i = 0; i < choises.size(); i++ )
		{
			vector<T> newFilled = filled;
			newFilled.push_back(choises[i]);
			vector<T> newChoises = choises;
			if (!repeat)
				newChoises.erase(newChoises.begin() + i);
			printAllPerm(newChoises, newFilled, remain - 1, repeat, count);
		}
	}
}

template <typename T>
void printAllCombi(const vector<T>& choises, int r, bool repeat = false)
{
	int count = 0;
	printAllCombi<T>(choises, vector<T>(), r, repeat, count);
	cout << endl << "Number of Combinations: " << count << endl;
}

template <typename T>
void printAllCombi(const vector<T>& choises, const vector<T>& filled, int remain,
	const bool repeat, int& count)
{
	if (remain == 0)
	{
		printList<T>(filled);
		count++;
	}
	else
	{
		vector<T> newChoises = choises;
		for (unsigned int i = 0; i <= choises.size() - remain; i++)
		{
			vector<T> newFilled = filled;
			newFilled.push_back(newChoises.front());
			if (!repeat)
				newChoises.erase(newChoises.begin());
			printAllCombi(newChoises, newFilled, remain - 1, repeat, count);
			if (repeat)  // does not work as intended
				newChoises.erase(newChoises.begin());
		}
	}
}

template <typename T>
void printList(const vector<T>& list)
{
	for (T val : list)
	{
		cout << val << " ";
	}
	cout << endl;
}