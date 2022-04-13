/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:51:40 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/13 15:35:06 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A utility function to swap two elements
void	swapp(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
	printf("swapp(%d, %d)\n", *a, *b);
}

/* This function is same in both iterative and recursive*/
int	partition_ite(t_stacks *stacks, int arr[], int l, int h, int maxarr)
{
	int	x;
	int	i;
	int	j;

	x = arr[h];
	i = (l - 1);
	j = l;
	while (j <= h - 1)
	{
		if (arr[j] <= x)
		{
			i++;
			if (&arr[i] != &arr[j])
			{
				// printf("i[%d] j[%d]\n", i, j);
				// printf("avant:");
				// print_arr(arr, maxarr);
				swappp(stacks, i, j);
				// swapp(&arr[i], &arr[j]);
				check_sort(*stacks);
				// printf("apres:");
				// print_arr(arr, maxarr);
				// printf("%d[%d] = partition(l[%d], h[%d])\n", i + 1, arr[i + 1], l, h);
			}
		}
		j++;
	}
	if (&arr[i + 1] != &arr[h])
	{
		// printf("i + 1[%d] h[%d]\n", i + 1, h);
		// printf("avant:");
		// print_arr(arr, maxarr);
		// swapp(&arr[i + 1], &arr[h]);
		swappp(stacks, i + 1, h);
		check_sort(*stacks);
		// printf("apres:");
		// print_arr(arr, maxarr);
		// printf("%d[%d] = partition(l[%d], h[%d])\n", i + 1, arr[i + 1], l, h);
	}
	(void)stacks;
	(void)maxarr;
	return (i + 1);
}

/* A[] --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */
void	quicksort_ite(t_stacks *stacks, int arr[], int l, int h, int maxarr)
{
	// printf("quick: l[%d] h[%d]\n      ", l, h);
	// print_arr(arr, h);
	// Create an auxiliary stack
	int stack[h - l + 1];

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty
	while (top >= 0)
	{
		// Pop h and l
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position
		// in sorted array
		int p = partition_ite(stacks, arr, l, h, maxarr);
		// printf("quick: p[%d]\n", p);
		// If there are elements on left side of pivot,
		// then push left side to stack
		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		
		// If there are elements on right side of pivot,
		// then push right side to stack
		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}
