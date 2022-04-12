/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:50:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/12 15:51:39 by tpinto-m         ###   ########.fr       */
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
	int		i;

	i = 0;
	printf("\nstacks\n");
	printf("sizemax:%d\n", stacks.sizemax);
	printf("s_a:%d s_b:%d\n", stacks.a.size, stacks.b.size);
	while (i < stacks.sizemax)
	{
		if (i < stacks.a.size)
			ft_printf("a:%d ", stacks.a.value[i]);
		else
			ft_printf("a:  ");
		if (i < stacks.b.size)
			ft_printf("b:%d\n", stacks.b.value[i]);
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
