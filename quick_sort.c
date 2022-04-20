/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:51:40 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/20 17:29:01 by tpinto-m         ###   ########.fr       */
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

void	swapppp(t_stacks *stacks, int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
	stacks->op = stacks->op + 1;
	// printf("swapp(%d, %d)\n", *a, *b);
}

int	partition(t_stacks *stacks, int arr[], int l, int h)
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
			swapppp(stacks, &arr[i], &arr[j]);
			// swapp(&arr[i], &arr[j]);
		}
		j++;
	}
	swapppp(stacks, &arr[i + 1], &arr[h]);
	// swapp(&arr[i + 1], &arr[h]);
	return (i + 1);
}

/* This function is same in both iterative and recursive*/
int	partition_ite(t_stacks *stacks, int arr[], int l, int h)
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
				// swappp(stacks, i, j);
				swapppp(stacks, &arr[i], &arr[j]);
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
		// swappp(stacks, i + 1, h);
		swapppp(stacks, &arr[i + 1], &arr[h]);
		check_sort(*stacks);
		// printf("apres:");
		// print_arr(arr, maxarr);
		// printf("%d[%d] = partition(l[%d], h[%d])\n", i + 1, arr[i + 1], l, h);
	}
	(void)stacks;
	return (i + 1);
}

/* A[] --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */
void	quicksort(t_stacks *stacks, int arr[], int l, int h)
{
	int	p;

	if (l < h)
	{
		p = partition_ite(stacks, arr, l, h);
		quicksort(stacks, arr, l, p - 1);
		quicksort(stacks, arr, p + 1, h);
	}
}
