/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:50:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/22 17:00:31 by tpinto-m         ###   ########.fr       */
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

	i = -1;
	ft_printf("\nstacks sizemax:%d\n", stacks.sizemax);
	ft_printf("min[%d] max[%d]\n", stacks.min, stacks.max);
	if (stacks.pivot)
		ft_printf("pivot[%d]\n", stacks.pivot->data);
	ft_printf("A size[%d] B size[%d]\n", stacks.a.size, stacks.b.size);
	while (++i < stacks.a.size || i < stacks.b.size)
	{
		if (i < stacks.a.size)
		{
			j = ft_nbrlen(stacks.a.value[i]);
			ft_printf("a:");
			while (j++ < 4)
				ft_printf(" ");
			ft_printf("%d ", stacks.a.value[i]);
		}
		else
			ft_printf("a:     ");
		if (i < stacks.b.size)
		{
			j = ft_nbrlen(stacks.b.value[i]);
			ft_printf("b:");
			while (j++ < 4)
				ft_printf(" ");
			ft_printf("%d\n", stacks.b.value[i]);
		}
		else
			ft_printf("b:\n");
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
	return (0);
}

// This function prints contents of linked list starting
// from the given node
void	print_list(t_node *node)
{
	t_node	*last;

	// printf("\nTraversal in forward direction \n");
	while (node != NULL)
	{
		ft_printf("%d ", node->data);
		last = node;
		node = node->next;
	}
	ft_printf("\n");
	(void)last;
	// printf("\nTraversal in reverse direction \n");
	// while (last != NULL)
	// {
	// 	printf(" %d ", last->data);
	// 	last = last->prev;
	// }
}
