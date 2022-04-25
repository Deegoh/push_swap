/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:50:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/25 18:19:27 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

void	print_stacks(t_sck stacks)
{
	t_sck	tmp;
	int		j;

	tmp = stacks;
	// ft_printf("\nstacks sizemax:%d\n", stacks.sizemax);
	ft_printf("min[%d] max[%d]\n", stacks.min, stacks.max);
	// if (stacks.pivot)
	// 	ft_printf("pivot[%d]\n", stacks.pivot->data);
	ft_printf("A size[%d] B size[%d]\n", stacks.size_a, stacks.size_b);
	// ft_printf("%p\n", tmp.a);
	while (tmp.a || tmp.b)
	{
		if (tmp.a)
		{
			j = ft_nbrlen(tmp.a->data);
			ft_printf("a:");
			while (j++ < 4)
				ft_printf(" ");
			ft_printf("%d ", tmp.a->data);
			tmp.a = tmp.a->next;
		}
		else
			ft_printf("a:     ");
		if (tmp.b)
		{
			j = ft_nbrlen(tmp.b->data);
			ft_printf("b:");
			while (j++ < 4)
				ft_printf(" ");
			ft_printf("%d\n", tmp.b->data);
			tmp.b = tmp.b->next;
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

int	check_sort(t_sck stacks)
{
	stacks.a = stacks.a->next;
	while (stacks.a && stacks.a->prev)
	{
		if (stacks.a->prev->data < stacks.a->data)
		{
			stacks.a = stacks.a->next;
			continue ;
		}
		return (1);
	}
	return (0);
}

// This function prints contents of linked list starting
// from the given node
void	print_list(t_node *node)
{
	t_node	*last;

	while (node != NULL)
	{
		ft_printf("%d\n", node->data);
		last = node;
		node = node->next;
	}
	ft_printf("\n");
}
