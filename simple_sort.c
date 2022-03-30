/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:14:39 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/03/30 14:48:31 by tpinto-m         ###   ########.fr       */
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

void	sort5(t_stacks *stacks)
{
	int	max;
	int	avant;
	int	i;

	i = 0;
	max = stacks->a.value[i];
	avant = stacks->a.value[i];
	while (i++ < stacks->a.size)
	{
		if (avant < max && stacks->a.value[i] > avant)
			avant = stacks->a.value[i];
		if (stacks->a.value[i] > max)
			max = stacks->a.value[i];
	}
	while (avant != stacks->a.value[0])
		rotate(&stacks->a, "ra\n");
	push_b(stacks);
	while (max != stacks->a.value[0])
		rotate(&stacks->a, "ra\n");
	push_b(stacks);
	sort3(&stacks->a);
	push_a(stacks);
	push_a(stacks);
	rotate(&stacks->a, "ra\n");
	rotate(&stacks->a, "ra\n");
}
