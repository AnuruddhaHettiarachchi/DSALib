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

}

namespace helper
{
	template <typename T>
	void swap(T* ar, int i, int j)
	{
		T temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}

}
