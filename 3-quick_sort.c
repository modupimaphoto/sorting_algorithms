#include "sort.h"

/**
 * swap - swap element
 *
 * @a: first element
 * @b: second element
 *
 * Return: Nothing.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - rearranging elements within a specified range in the array
 *
 * @array: array of integers to be partitioned
 * @low: starting index of the partition range
 * @high: ending index of the partition range
 * @array_size: size of the array
 *
 * Return: the final position of the pivot element
 */
int partition(int *array, int low, int high, size_t array_size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, array_size);
			}
		}
	}
	return (i);
}
/**
 * lomuto_qsort - recursively sorts the elements in the specified
 * range of the array
 *
 * @array: sorted lomuto_qsort
 * @low: starting index of the array or sub-array to be sorted
 * @high: ending index of the array or sub-array to be sorted
 * @size: size of the array
 *
 * Return: Nothing.
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_qsort(array, low, i - 1, size);
		lomuto_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: array to sort
 * @size: the size of the array
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
