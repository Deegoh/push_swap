/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/12 19:28:24 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swappp(t_stacks *stacks, int i, int j)
{
	int	max;
	int	initi;
	int	initj;
	int	a;
	int	b;

	a = i;
	b = j;
	max = stacks->a.size - 1;
	initj = stacks->a.value[j];
	initi = stacks->a.value[i];
	printf("init[%d]\n", initj);
	opti_rot(stacks, stacks->a.value[i]);
	push_b(stacks);
	j = j - i - 1;
	opti_rot(stacks, stacks->a.value[j]);
	push_b(stacks);
	// print_stacks(*stacks);
	if (stacks->b.value[0] > stacks->b.value[1])
		rotate(&stacks->b, "pb\n");
	push_a(stacks);
	// print_stacks(*stacks);
	opti_rot(stacks, initj);
	// print_stacks(*stacks);
	push_a(stacks);
	// while (stacks->a.value[0] != initj)
	opti_rot(stacks, initj);
	(void)initi;
	(void)initj;
	(void)max;
	(void)a;
	(void)b;
	
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	t_stacks	stacks2;

	if (ac == 1)
		error_exit();
	stacks = init_stacks(ac, av);
	stacks2 = init_stacks(ac, av);
	check_sort(stacks);
	if (stacks.sizemax <= 5)
		simple_sort(&stacks);
	else
		quicksort_ite(&stacks, stacks.a.value, 0, stacks.a.size - 1, stacks.a.size - 1);
		// sort_stack(&stacks);
	swappp(&stacks2, 0, 5);
	print_arr(stacks2.a.value, stacks.a.size - 1);
	swappp(&stacks2, 1, 4);
	print_arr(stacks2.a.value, stacks.a.size - 1);
	// print_arr(stacks2.b.value, stacks.b.size - 1);
	print_stacks(stacks2);
	return (0);
}
