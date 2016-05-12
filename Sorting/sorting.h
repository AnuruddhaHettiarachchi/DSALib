#pragma once

#include <unordered_map>
#include <vector>
#include <tuple>
#include <list>

using namespace std;

namespace sorting
{
	template <typename T>
	void insertionSort(T*, int);

	/* O(nlogn) time,  O(n) space*/
	template<typename T>
	void mergeSort(vector<T>& ar) { mergeSort<T>(ar, 0, ar.size()); }

	template<typename T>
	void mergeSort(vector<T>& ar, int start, int end);

	template<typename T>
	void quickSort(vector<T>& ar) { quickSort<T>(ar, 0, ar.size()); }

	template<typename T>
	void quickSort(vector<T>& ar, int start, int end);

	template<typename K, typename V>
	void bucketSort(vector<K>& keys, vector<V>& vals, K start, K end);

	/* only vector/string types as V */
	template<typename K, typename V>
	void radixSort(vector<V>& vals, K start, K end, unsigned int maxSize);

}

namespace helper
{
	template <typename T>
	void swap(T*, int, int);

	template <typename T>
	void swap(vector<T>&, typename vector<T>::iterator&, typename vector<T>::iterator&);

	template <typename T>
	void merge(vector<T>& ar, int startIndex, int endIndex, int splitIndex);
}