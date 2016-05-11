#pragma once

#include <vector>
#include <cmath>

using namespace std;

vector<unsigned long> allPrimes(unsigned long n)
{
	vector<bool> nums(n+1, true);
	nums[0] = nums[1] = false;
	for (unsigned long i = 2; i <= (unsigned long)sqrt(n); i++)
	{
		if (nums[i])
		{
			for (unsigned long j = i*i; j <= n; j += i)
			{
				nums[j] = false;
			}
		}
	}

	vector<unsigned long> primes;
	for (unsigned long i = 2; i <= n; i++)
	{
		if (nums[i])
			primes.push_back(i);
	}
	
	return primes;
}