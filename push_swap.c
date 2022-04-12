/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/12 16:23:35 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swappp(t_stacks *stacks, int i, int j)
{
	int	max;

	max = stacks->a.size - 1;
	opti_rot(stacks, stacks->a.value[i]);
	push_b(stacks);
	j = j - i - 1;
	opti_rot(stacks, stacks->a.value[j]);
	push_b(stacks);
	rotate(&stacks->b, "pb\n");
	push_a(stacks);
	opti_rot(stacks, stacks->a.value[j + i]);
	push_a(stacks);
	opti_rot(stacks, stacks->a.value[max]);
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	// t_stacks	stacks2;

	if (ac == 1)
		error_exit();
	stacks = init_stacks(ac, av);
	// stacks2 = init_stacks(ac, av);
	check_sort(stacks);
	if (stacks.sizemax <= 5)
		simple_sort(&stacks);
	else
		sort_stack(&stacks);
	// quicksort_ite(&stacks, stacks.a.value, 0, stacks.a.size - 1, stacks.a.size - 1);
	// swappp(&stacks, 1, 4);
	// print_stacks(stacks);
	return (0);
}
