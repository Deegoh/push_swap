/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/20 20:45:51 by tpinto-m         ###   ########.fr       */
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
		swap(&stacks->a,"sa\n");
		opti_rot(stacks, &stacks->a, init, 'A');
		return ;	
	}
	opti_rot(stacks, &stacks->a, stacks->a.value[i], 'A');
	if (i + 1 == j)
	{
		swap(&stacks->a,"sa\n");
		opti_rot(stacks, &stacks->a, init, 'A');
		return ;	
	}
	push_b(stacks);
	j = j - i - 1;
	opti_rot(stacks, &stacks->a, stacks->a.value[j], 'A');
	push_b(stacks);
	// if (stacks->b.value[0] > stacks->b.value[1])
	rotate(&stacks->b, "rb\n");
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
	int	boo;
	int	j = 3;

	boo = 1;
	while (--j)
	{
		if (boo)
		{
			stacks->pivot = stacks->a.value[stacks->a.size - 1];
			boo = 0;
		}
		else
			stacks->pivot = stacks->a.value[0];
		i = -1;
		while (++i < stacks->a.size - 1)
		{
			if (stacks->a.value[i] < stacks->pivot)
			{
				opti_rot(stacks, &stacks->a, stacks->a.value[i], 'A');
				push_b(stacks);
			}
		}
		opti_rot(stacks, &stacks->a, stacks->pivot, 'A');
		push_b(stacks);
		print_stacks(*stacks);
	}
	
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

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	t_node		*head;
	// t_sck		sck;

	head = NULL;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insert_after(head->next, 8);
	// print_list(head);
	// printf("\n");

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_stacks(ac, av);
	// sck = init_sck(ac, av);
	check_sort(stacks);
	if (stacks.sizemax <= 5)
		simple_sort(&stacks);
	else
	{
		custumsort(&stacks);
		// stacks.op = 0;
		// quicksort(&stacks, stacks.a.value, 0, stacks.sizemax - 1);
		// sort_stack(&stacks);
	}
	// print_arr(stacks.a.value, stacks.a.size - 1);
	// printf("op:%d\n", stacks.op);
	// print_stacks(stacks);
	return (EXIT_SUCCESS);
}
