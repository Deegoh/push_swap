/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/13 19:38:12 by tpinto-m         ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	// t_stacks	stacks2;

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_stacks(ac, av);
	// stacks2 = init_stacks(ac, av);
	check_sort(stacks);
	if (stacks.sizemax <= 5)
		simple_sort(&stacks);
	else
	{
		// quicksort_ite(&stacks, stacks.a.value, 0, stacks.a.size - 1, stacks.a.size - 1);
		sort_stack(&stacks);
	}
	// printf("quick1\n\n");
	// print_arr(stacks.a.value, stacks.a.size - 1);
	// printf("quick2\n\n");
	// swappp(&stacks2, 0, 5);
	// print_arr(stacks2.a.value, stacks2.a.size - 1);
	// swappp(&stacks2, 1, 4);
	// print_arr(stacks2.a.value, stacks2.a.size - 1);
	// swappp(&stacks2, 2, 3);
	// print_arr(stacks2.a.value, stacks2.a.size - 1);
	// print_arr(stacks2.b.value, stacks.b.size - 1);
	// opti_rot(&stacks, &stacks.a, 6, 'A');
	// do_rule_nb(&stacks, "PB", 2);
	// r_rotate(&stacks.b, "rrb\n");
	// while (stacks.a.size)
	// {
		// rotate(&stacks.b, "rb\n");
		// push_b(&stacks);
		// print_stacks(stacks);
	// }
	// opti_rot(&stacks, &stacks.b, 6, 'B');
	// do_rule_nb(&stacks, "PA", stacks.b.size);
	// print_stacks(stacks);
	return (EXIT_SUCCESS);
}
