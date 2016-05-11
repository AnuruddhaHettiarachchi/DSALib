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