/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:50:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/21 15:48:14 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

void	print_stacks(t_stacks stacks)
{
	int	i;
	int	j;

	i = 0;
	printf("\nstacks sizemax:%d\n", stacks.sizemax);
	printf("min[%d] max[%d] ", stacks.min, stacks.max);
	printf("pivot[%d]\n", stacks.pivot);
	while (i < stacks.a.size || i < stacks.b.size)
	{
		if (i < stacks.a.size)
		{
			j = ft_nbrlen(stacks.a.value[i]);
			ft_printf("a:");
			while (j++ < 4)
			{
				ft_printf(" ");
			}
			ft_printf("%d ", stacks.a.value[i]);
		}
		else
			ft_printf("a:     ");
		if (i < stacks.b.size)
		{
			j = ft_nbrlen(stacks.b.value[i]);
			ft_printf("b:");
			while (j++ < 4)
			{
				ft_printf(" ");
			}
			ft_printf("%d\n", stacks.b.value[i]);
		}
		else
			ft_printf("b:\n");
		i++;
	}
}

// A utility function to print contents of arr
void	print_arr(int arr[], int n)
{
	int	i;

	i = -1;
	while (i++ < n)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int	check_sort(t_stacks	stacks)
{
	int	i;

	i = 0;
	while (++i < stacks.sizemax)
	{
		if (stacks.a.value[i - 1] < stacks.a.value[i])
			continue ;
		return (1);
	}
	exit(EXIT_SUCCESS);
}
