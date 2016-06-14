#pragma once

#include <vector>
#include<utility>

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

class Ranker {
public:
	void track(int);
	int getRankOfNumber(int);
private:
	map<int, int> m;
};

void Ranker::track(int val)
{
	m[val]++;
}

int Ranker::getRankOfNumber(int num)
{
	int rank = 0;
	map<int, int>::iterator i = m.begin();
	while (i != m.end() && (*i).first < num)
	{
		rank += (*i).second;
		i++;
	}
	rank += (m[num] - 1);
	return rank;
}


typedef pair<int, int> index;

index searchSubMatrix(int** matrix, int i1, int j1, int i2, int j2, int x)
{
	if (i1 == i2 || j1 == j2)
		return make_pair(-1, -1);

	int midi = (i1 + i2) / 2;
	int midj = (j1 + j2) / 2;
	index r = make_pair(midi, midj);
	int y = matrix[midi][midj];

	if (y != x)
		r = make_pair(-1, -1);

	if (y > x)
	{
		r = searchSubMatrix(matrix, i1, j1, midi, midj, x);
		if (r.first == -1)
			r = searchSubMatrix(matrix, i1, midj, midi, j2, x);
		if (r.first == -1)
			r = searchSubMatrix(matrix, midi, j1, i2, midj, x);
	}
	else if (y < x)
	{
		r = searchSubMatrix(matrix, midi+1, midj+1, i2, j2, x);
		if (r.first == -1)
			r = searchSubMatrix(matrix, i1, midj + 1, midi + 1, j2, x);
		if (r.first == -1)
			r = searchSubMatrix(matrix, midi + 1, j1, i2, midj + 1, x);
	}
	return r;
}

index searchMatrix(int** matrix, int m, int n, int x)
{
	return searchSubMatrix(matrix, 0, 0, m, n, x);
}
