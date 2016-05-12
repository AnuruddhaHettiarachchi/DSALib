#pragma once
#include <unordered_map>
#include <vector>

using namespace std;

template<typename T, int N>
bool isUnique(vector<T>& ar)
{
	if (ar.size() > N)
		return false;
	else
	{
		unordered_map<T, bool> present;
		for (int i = 0; i < ar.size(); i++)
		{
			if (present[ar[i]] != NULL)
				return false;
			else
				present[ar[i]] = true;
		}
		return true;
	}
}

template<typename T>
int binarySearch(const vector<T>& ar, const T& val, int start, int end)
{
	int index = -1;
	if (start < end)
	{
		int middle = (start + end) / 2;
		if (ar[middle] == val)
			index = middle;
		else if (ar[middle] > val)
			index = binarySearch(ar, val, start, middle);
		else
			index = binarySearch(ar, val, middle + 1, end);
	}
	return index;

}

