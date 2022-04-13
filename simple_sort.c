/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:14:39 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/13 18:51:31 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *stack)
{
	if (stack->value[0] > stack->value[1])
		swap(stack, "sa\n");
}

void	sort3(t_stack *stack)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = stack->value[0];
	v2 = stack->value[1];
	v3 = stack->value[2];
	if (v1 > v2 && v1 < v3 && v2 < v3)
		swap(stack, "sa\n");
	else if (v1 > v2 && v1 > v3 && v2 > v3)
	{
		swap(stack, "sa\n");
		r_rotate(stack, "rra\n");
	}
	else if (v1 > v2 && v1 > v3 && v2 < v3)
		rotate(stack, "ra\n");
	else if (v1 < v2 && v1 < v3 && v2 > v3)
	{
		swap(stack, "sa\n");
		rotate(stack, "ra\n");
	}
	else if (v1 < v2 && v1 > v3 && v2 > v3)
		r_rotate(stack, "rra\n");
}

void	sort4(t_stacks *stacks)
{
	int	max;
	int	i;

	i = -1;
	max = stacks->a.value[0];
	while (++i < stacks->a.size)
		if (stacks->a.value[i] < max)
			max = stacks->a.value[i];
	opti_rot(stacks, &stacks->a, max, 'A');
	push_b(stacks);
	sort3(&stacks->a);
	push_a(stacks);
}

void	sort5(t_stacks *stacks)
{
	int	top;
	int	i;

	i = -1;
	top = stacks->a.value[0];
	while (++i < stacks->a.size)
		if (stacks->a.value[i] < top)
			top = stacks->a.value[i];
	opti_rot(stacks, &stacks->a, top, 'A');
	push_b(stacks);
	// print_stacks(*stacks);
	top = stacks->a.value[0];
	i = -1;
	while (++i < stacks->a.size)
		if (stacks->a.value[i] < top)
			top = stacks->a.value[i];
	opti_rot(stacks, &stacks->a, top, 'A');
	push_b(stacks);
	// print_stacks(*stacks);
	sort3(&stacks->a);
	do_rule_nb(stacks, "PA", 2);
}

void	simple_sort(t_stacks *stacks)
{
	if (stacks->sizemax == 2)
		sort2(&stacks->a);
	else if (stacks->sizemax == 3)
		sort3(&stacks->a);
	else if (stacks->sizemax == 4)
		sort4(stacks);
	else if (stacks->sizemax == 5)
		sort5(stacks);
}
