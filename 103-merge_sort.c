#include "sort.h"

/**
 * merge - merge two sorted subarrays into a sorted array
 *
 * @array: original array to be modified
 * @left: left subarray
 * @right: right subarray
 * @size: size of the original array
 *
 * Return: Nothing.
 */
void merge(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_left)
		array[k++] = left[i++];

	while (j < size_right)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - merge sort on an array
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;
	size_t i;
	int *left;
	int *right;

	if (!array || size < 2)
		return;

	mid = size / 2;
	left = (int *)malloc(mid * sizeof(int));
	right = (int *)malloc((size - mid) * sizeof(int));

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, left, right, size);

	free(left);
	free(right);
}
