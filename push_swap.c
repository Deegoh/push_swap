/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/22 17:53:08 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swappp(t_stacks *stacks, int i, int j)
{
	int	max;
	int	initi;
	int	initj;
	int	init;
	int	a;
	int	b;

	a = i;
	b = j;
	max = stacks->a.size - 1;
	if (j + 1 > max)
		b = 0;
	initj = stacks->a.value[b + 1];
	initi = stacks->a.value[i + 1];
	if (j == max)
		init = stacks->a.value[max];
	else
		init = stacks->a.value[0];
	// printf("init[%d]swap(%d,%d)i%dj%d\n", init, stacks->a.value[i], stacks->a.value[j], i, j);
	// print_arr(stacks->a.value, stacks->a.size - 1);
	if (i == 0 && j == max)
	{
		opti_rot(stacks, &stacks->a, stacks->a.value[j], 'A');
		swap(stacks, &stacks->a,"sa\n");
		opti_rot(stacks, &stacks->a, init, 'A');
		return ;	
	}
	opti_rot(stacks, &stacks->a, stacks->a.value[i], 'A');
	if (i + 1 == j)
	{
		swap(stacks, &stacks->a,"sa\n");
		opti_rot(stacks, &stacks->a, init, 'A');
		return ;	
	}
	push_b(stacks);
	j = j - i - 1;
	opti_rot(stacks, &stacks->a, stacks->a.value[j], 'A');
	push_b(stacks);
	// if (stacks->b.value[0] > stacks->b.value[1])
	rotate(stacks, &stacks->b, "rb\n");
	// print_stacks(*stacks);
	push_a(stacks);
	// // print_stacks(*stacks);
	// printf("initi[%d] initj[%d]\n", initi, initj);
	opti_rot(stacks, &stacks->a, initi, 'A');
	// // print_stacks(*stacks);
	push_a(stacks);
	// // while (stacks->a.value[0] != initj)
	opti_rot(stacks, &stacks->a, init, 'A');
	// print_stacks(*stacks);
	(void)init;
	(void)initi;
	(void)initj;
	(void)max;
	(void)a;
	(void)b;
}

// void	split_to_lst(char **split, int size)
// {
// 	(void)split;
// 	(void)size;
// }

// t_sck	init_list(t_stacks	stacks)
// {
// 	t_sck	sck;
// 	char	*arg;
// 	char	**split;
	// int		i;

	// arg = merge_arg(av, ac);
	// split = ft_split(arg, ' ');
	// sck.size_a = arrlen(split);
	// sck.a = split_to_arr(split, sck.size_a);
	// free(arg);
	// i = 0;
	// while (i < stacks.sizemax)
	// 	free(split[i++]);
	// free(split);
	// stacks.a.size = stacks.sizemax;
	// find_dup(stacks.a.value, stacks.a.size);
	// stacks.b.value = ft_calloc(sizeof(stacks.b), stacks.sizemax);
	// stacks.b.size = 0;
// 	(void)stacks;
// 	(void)sck;
// 	return (sck);
// }

void	custumsort(t_stacks *stacks)
{
	int	i;
	int	nbr;
	int	pivot;

	while (stacks->a.size > 1)
	{
		pivot = stacks->a.value[stacks->a.size - 1];
		push(&stacks->pivot, pivot);
		// if (stacks->pivot == stacks->max && stacks->a.size > 1)
		// {
		// 	r_rotate(stacks, &stacks->a, "rra\n");
		// 	stacks->pivot = stacks->a.value[stacks->a.size - 1];
		// }
		i = -1;
		nbr = 0;
		while (++i < stacks->a.size - 1)
			if (stacks->a.value[i] < pivot)
				nbr++;
		while (nbr--)
		{
			if (stacks->a.value[0] < pivot)
				push_b(stacks);
			else
			{
				rotate(stacks, &stacks->a, "ra\n");
				nbr++;
			}
			print_stacks(*stacks);
			// sleep(1);
		}
		opti_rot(stacks, &stacks->a, pivot, 'A');
		if (pivot != stacks->max)
			push_b(stacks);
		print_stacks(*stacks);
		//TODO check rrb
	}
	print_list(stacks->pivot);
	if (stacks->pivot->data != stacks->max)
		push(&stacks->pivot, stacks->max);
	ft_printf("piv %d\n", stacks->pivot->data);
	print_list(stacks->pivot);
	// delete_node(&stacks->pivot, stacks->pivot);
	// print_list(stacks->pivot);
	
	// opti_rot(stacks, &stacks->b, stacks->max, 'B');
	// print_stacks(*stacks);
	// stacks->pivot = stacks->a.value[stacks->a.size - 1];
	// i = -1;
	// while (++i < stacks->a.size - 1)
	// {
	// 	if (stacks->a.value[i] < stacks->pivot)
	// 		push_b(stacks);
	// }
	// opti_rot(stacks, &stacks->a, stacks->pivot, 'A');
	// push_b(stacks);
	// print_stacks(*stacks);
	// stacks->pivot = stacks->a.value[0];
	// rotate(&stacks->a, "ra\n");
	// i = -1;
	// while (++i < stacks->a.size - 1)
	// {
	// 	if (stacks->a.value[i] < stacks->pivot)
	// 		push_b(stacks);
	// }
	// opti_rot(stacks, &stacks->a, stacks->pivot, 'A');
	// push_b(stacks);
	// print_stacks(*stacks);
}

void	set_min_max(t_stacks *stacks)
{
	int	i;

	i = -1;
	stacks->max = stacks->a.value[0];
	stacks->min = stacks->a.value[0];
	while (++i < stacks->a.size - 1)
	{
		if (stacks->max < stacks->a.value[i])
			stacks->max = stacks->a.value[i];
		if (stacks->min > stacks->a.value[i])
			stacks->min = stacks->a.value[i];
	}
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	// t_node		*head;
	// t_sck		sck;

	// head = NULL;
	// append(&head, "hello");
	// append(&head, 2);
	// append(&head, 3);
	// push(&head, 7);
	// push(&head, 1);
	// append(&head, 4);
	// insert_after(head->next, 8);
	// print_list(head);
	// printf("\n");

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_stacks(ac, av);
	stacks.op = ft_strdup("");
	stacks.pivot = NULL;
	// sck = init_sck(ac, av);
	if (check_sort(stacks))
	{
		set_min_max(&stacks);
		print_stacks(stacks);
		if (stacks.sizemax <= 5)
			simple_sort(&stacks);
		else
		{
			custumsort(&stacks);
			// stacks.op = 0;
			// quicksort(&stacks, stacks.a.value, 0, stacks.sizemax - 1);
			// sort_stack(&stacks);
		}
	}
	// ft_printf("\n%s", stacks.op);
	// print_arr(stacks.a.value, stacks.a.size - 1);
	// print_stacks(stacks);
	return (EXIT_SUCCESS);
}
