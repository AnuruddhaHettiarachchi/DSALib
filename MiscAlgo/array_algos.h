#pragma once
#include <unordered_map>
#include <vector>
#include <string>

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

double convert(const string& str)
{
	string s = str;
	bool isPositive = true;
	double num = 0;
	unsigned int dpIndex = s.size();

	if (s[0] == '-')
	{
		isPositive = false;
		s = str.substr(1);
	}

	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			dpIndex = i;
			break;
		}
	}

	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (i < dpIndex)
		{
			num += (s[i] - '0') * pow(10, (dpIndex - i - 1));
		}
		if (i > dpIndex)
		{
			num += (s[i] - '0') * pow(10, (dpIndex - i));
		}
	}
	if (!isPositive)
		num = -num;
	return num;
}

void replaceSpace(string& str, int n)
{
	int dist = str.length() - n;
	for (int i = n - 1; i >= 0; i--)
	{
		str[i + dist] = str[i];
	}
	int i = 0;
	for (int j = dist; j < str.length(); j++)
	{
		if (str[j] != ' ')
		{
			str[i] = str[j];
			i++;
		}
		else
		{
			str[i] = '%'; str[i + 1] = '2'; str[i + 2] = '0';
			i += 3;
		}
	}
}


void markRowCol(int** mat, int m, int n, int row, int col)
{
	for (int i = 0; i<m; i++)
		mat[i][col] = 0;
	for (int i = 0; i<n; i++)
		mat[row][i] = 0;
}

void markZeros(int** mat, int m, int n)
{
	bool* cols = new bool[n];
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (!cols[j])
				continue;
			if (mat[i][j] == 0)
			{
				markRowCol(mat, m, n, i, j);
				cols[j] = false;
				break;
			}
		}
	}
}
