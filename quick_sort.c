/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:46:04 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/03 22:54:33 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_qs(int *a, int*b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	partition(int arr[], int l, int h)
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
			swap_qs(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_qs(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void	quicksort(int arr[], int l, int h)
{
	int	p;

	if (l < h)
	{
		p = partition(arr, l, h);
		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, h);
	}
}
