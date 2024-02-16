#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list);
/**
 * bubble_sort - Sorts an array of ints in ascending order using Bubble sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Desctiption: Sorts an array of integers in ascending order using Bubble sort
 */
void bubble_sort(int *array, size_t size);
/**
 * insertion_sort_list - Sorts a doubly linked list of ints in ascending order
 *                        using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list);
/**
 * selection_sort - Sorts an array of integers in ascending order
 *                   using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size);
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b);
/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, int low, int high, size_t size);
/**
 * quick_sort_recursive - Implements the recursive part of Quick Sort
 *
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size);
/**
 * quick_sort - Sorts an array of integers in ascending order
 *               using the Quick sort algorithm (Lomuto partition scheme)
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
