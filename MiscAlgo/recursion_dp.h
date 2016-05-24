#pragma once

#include <unordered_map>

using namespace std;

int n;
unordered_map<int, long long> stepCount;

unsigned long long countSteps(int from)
{
	if (stepCount[from] == 0)
	{
		if (from == n)
			stepCount[from] = 1;
		else
		{
			unsigned long long c1 = 0, c2 = 0, c3 = 0;
			if (from + 3 <= n)
				c3 = countSteps(from + 3);
			if(from + 2 <= n)
				c2 = countSteps(from + 2);
			if (from + 1 <= n)
				c1 = countSteps(from + 1);
			stepCount[from] = c1 + c2 + c3;
		}
	}
	return stepCount[from];
}

unsigned long long hopPatternCount(int _n)
{
	n = _n;
	return countSteps(0);
}

int numOfPaths(int X, int Y)
{
	int** paths = new int*[X];
	for (int i = 0; i < X; i++)
		paths[i] = new int[Y];
	paths[X - 1][Y - 1] = 1;
	for (int i = X - 1; i >= 0; i--)
	{
		for (int j = Y - 1; j >= 0; j--)
		{
			if (i == X - 1 && j == Y - 1)
				continue;
			int count = 0;
			if (i<X - 1)
				count += paths[i + 1][j];
			if (j<Y - 1)
				count += paths[i][j + 1];
			paths[i][j] = count;
		}
	}
	return paths[0][0];
}


/* not tested. only for demo

	map<pair<int, int>, bool> allowed;
	map<pair<int, int>, pair<int, int>> child;
	int X, Y;

	map<pair<int, int>, pair<int, int>> getPath()
	{
		createPath(0, 0);
		return child;
	}


	bool createPath(int x, int y)
	{
		if (child[{x, y}] != pair<int, int>{-1, -1})
			return true;
		if (!allowed[{x, y}])
			return false;
		if (x < X - 1 && createPath(x + 1, y))
		{
			child[{x, y}] = { x + 1, y };
			return true;
		}
		if (y < Y - 1 && createPath(x, y + 1))
		{
			child[{x, y}] = { x, y + 1 };
			return true;
		}
		return false;
	}

*/

bool eval(bool l, char op, bool r)
{
	switch (op)
	{
	case '&': return l & r;
	case '|': return l | r;
	case '^': return l ^r;
	}
}

map<pair<int, int>, list<bool>> cache;

list<bool> paraVals(string exp, int s, int e)
{
	if (!cache[{s, e}].empty())
		return 	cache[{s, e}];

	list<bool> results;
	if (e - s < 2)
	{
		results.push_back(exp[s] - '0');
		cache[{s, e}] = results;
		return results;
	}

	for (int i = s + 1; i<e; i += 2)
	{
		list<bool> l1 = paraVals(exp, s, i);
		list<bool> l2 = paraVals(exp, i + 1, e);
		for (list<bool>::iterator it1 = l1.begin(); it1 != l1.end(); it1++)
		{
			for (list<bool>::iterator it2 = l2.begin(); it2 != l2.end(); it2++)
			{
				results.push_back(eval(*it1, exp[i], *it2));
			}
		}
	}
	cache[{s, e}] = results;
	return results;

}

int numofParas(string exp, bool result)
{
	int count = 0;
	list<bool> l = paraVals(exp, 0, exp.length());
	for (bool b : l)
	{
		if (b == result)
			count++;
	}
	return count;
}
