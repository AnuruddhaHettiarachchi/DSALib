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