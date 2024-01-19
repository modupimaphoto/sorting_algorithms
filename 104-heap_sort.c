#include "sort.h"

/**
 * heapify - rearrange the elements of a heap
 *
 * @array: array representing the heap
 * @heap: size of the heap
 * @i: index of the root of the current subtree
 * @size: size of the array
 *
 * Return: Nothing.
 */
void heapify(int *array, int heap, int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	 int temp;

	if (left < heap && array[left] > array[largest])
		largest = left;

	if (right < heap && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, size);

		heapify(array, heap, largest, size);
	}
}

/**
 * heap_sort - orts an array of integers in ascending order
 * using the Heap sort algorithm.
 *
 * @array: array to sort
 * @size: size of the array
 * Return: Nothng.
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		if (i > 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
