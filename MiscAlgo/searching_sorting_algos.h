#pragma once

#include <vector>

template <typename T>
void mergeArrays(vector<T>& a, vector<T>& b, unsigned int m, unsigned int n)
{
	int i = m-1, j = n-1, k = a.size() - 1;
	while (i != -1 && j != -1)
	{
		if (a[i] > b[j])
		{
			a[k] = a[i];
			i--;
		}
		else
		{
			a[k] = b[j];
			j--;
		}
		k--;
	}
	while (j != -1)
	{
		a[k] = b[j];
		j--;
		k--;
	}
}