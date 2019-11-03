#include <iostream>
using namespace std;

template<class T>
void Swap(T* arr, int v1, int v2)
{
	T tmp = arr[v1];
	arr[v1] = arr[v2];
	arr[v2] = tmp;
}

template<class T>
void QuickSort(T* arr, int low, int high)
{
	if (low >= high) return;
	int left = low;
	int right = high;
	T key = arr[low];
	while (left < right)
	{
		while (left < right && key < arr[right]) --right;
		if (left < right) Swap(arr, left, right);
		while (left < right && arr[left] < key) ++left;
		if (left < right) Swap(arr, left, right);
	}
	QuickSort(arr, low, left - 1);
	QuickSort(arr, left + 1, high);
}

template<class T>
void InsertionSort(T* arr, int len)
{
	for (int i = 1; i < len; i++)
	{
		T key = arr[i];
		int j = 0;
		for (j = i - 1; j >= 0; j--)
			if (key < arr[j])
				arr[j + 1] = arr[j];
			else break;
		arr[j + 1] = key;
	}
}

template<class T>
void SelectionSort(T* arr, int len)
{
	int min = 0;
	for (int i = 0; i < len; i++)
	{
		min = i;
		for (int j = i; j < len; j++)
			if (arr[j] < arr[min]) min = j;
		Swap(arr, min, i);
	}
}

template<class T>
void BubbleSort(T* arr, int len)
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - 1; j++)
			if (arr[j] > arr[j + 1])
				Swap(arr, j, j + 1);
		
}

template <class T>
void AdjustHeap(T* arr, int len, int target)
{
	int l = target * 2 + 1;
	int r = target * 2 + 2;
	int max = target;
	if (l < len && arr[l] > arr[max]) max = l;
	if (r < len && arr[r] > arr[max]) max = r;
	if (max != target)
	{
		Swap(arr, max, target);
		AdjustHeap(arr, len, max);
	}
}

template <class T>
void BuildHeap(T* arr, int len)
{
	for (int i = (len - 2) / 2; i >= 0; i--)
		AdjustHeap(arr, len, i);
}

template <class T>
void HeapSort(T* arr, int len)
{
	BuildHeap(arr, len);
	for (int i = len - 1; i >= 0; i--)
	{
		Swap(arr, 0, i);
		AdjustHeap(arr, i, 0);
	}
}

template<class T>
void OutPut(T* arr, int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << "->";
	cout << endl;
}

int main(int* argc, char** argv)
{
	int arr1[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	double arr2[10] = { 100.0, 99.0, 88.0, 77.0, 66.0, 55.0, 44.0, 33.0, 22.0, 11.0 };
	//QuickSort(arr1, 0, 9);
	//InsertionSort(arr1, 10);
	//SelectionSort(arr1, 10);
	//BubbleSort(arr1, 10);
	HeapSort(arr1, 10);
	OutPut(arr1, 10);
	//QuickSort(arr2, 0, 9);
	//OutPut(arr2, 10);
	return 0;
}
