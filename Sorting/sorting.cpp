#include "sorting.h"

namespace sorting
{
	template <typename T>
	void insertionSort(T* ar, int n)
	{
		int current;
		for (int next = 1; next < n; next++)
		{
			current = next;
			while (current > 0 && ar[current] < ar[current - 1])
			{
				helper::swap<T>(ar, current, current - 1);
				current = current - 1;
			}
		}
	}

	template<typename T>
	void mergeSort(vector<T>& ar, int start, int end)
	{
		int n = end - start;
		if (n < 2)
			return;
		int splitIndex = start + n / 2;
		mergeSort<T>(ar, start, splitIndex);
		mergeSort<T>(ar, splitIndex, end);
		helper::merge<T>(ar, start, end, splitIndex);
	}

	template<typename T>
	void quickSort(vector<T>& ar, int start, int end)
	{
		if ((end - start) < 2)
			return;
		vector<T>::iterator pivot = ar.begin() + end - 1;
		vector<T>::iterator wall = ar.begin() + start;
		vector<T>::iterator current = ar.begin() + start;
		while (current != pivot)
		{
			if (*current < *pivot)
			{
				helper::swap(ar, wall, current);
				wall++;
			}
			current++;
		}
		helper::swap(ar, wall, pivot);
		quickSort(ar, start, (wall - ar.begin()));
		quickSort(ar, (wall - ar.begin()) + 1, end);
	}

	template<typename K, typename V>
	void bucketSort(vector<K>& keys, vector<V>& vals, K start, K end)
	{
		unordered_map<K, list<V>> bucketArray;
		for (unsigned int i = 0; i < vals.size(); i++)
		{
			bucketArray[keys[i]].push_back(vals[i]);
		}
		vals.clear();
		for (K it = start; it <= end; it++)
		{
			list<V> bucket = bucketArray[it];
			while (!bucket.empty())
			{
				vals.push_back(bucket.front());
				bucket.pop_front();
			}
		}
	}

	template<typename K, typename V>
	void radixSort(vector<V>& vals, K start, K end, unsigned int tupleSize)
	{
		for (int i = tupleSize - 1; i >= 0; i--)
		{
			vector<K> keys;
			for (V val : vals)
			{
				if(val.size() < i + 1)
					keys.push_back(start - 1);
				else
					keys.push_back(val[i]);
			}
			bucketSort<K, V>(keys, vals, start - 1, end);
		}
	}

}

namespace helper
{
	template <typename T>
	void swap(T* ar, int i, int j)
	{
		if (i == j)
			return;
		T temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}

	template<typename T>
	void swap(vector<T>&, typename vector<T>::iterator& i, typename vector<T>::iterator& j)
	{
		if (i == j)
			return;
		T temp = *i;
		*i = *j;
		*j = temp;
	}

	template<typename T>
	void merge(vector<T>& ar, int startIndex, int endIndex, int splitIndex)
	{
		vector<T> copy = ar; // The only copy O(n space)
		vector<T>::iterator
			startI = copy.begin() + startIndex,
			startJ = copy.begin() + splitIndex,
			end = copy.begin() + endIndex,
			k = ar.begin() + startIndex;

		vector<T>::iterator i = startI, j = startJ;
		while (i != startJ && j != end)
		{
			if (*i < *j)
			{
				*k = *i;
				i++;
			}
			else
			{
				*k = *j;
				j++;
			}
			k++;
		}
		while (i != startJ)
		{
			*k = *i;
			i++;
			k++;
		}
		while (j != end)
		{
			*k = *j;
			j++;
			k++;
		}
	}

}
