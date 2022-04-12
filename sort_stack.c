/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:47:41 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/12 16:18:34 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_insert(t_stacks *stacks, int x)
{
	if (stacks->a.size == 0 || x < stacks->a.value[0])
	{
		push_a(stacks);
		return ;
	}
	push_b(stacks);
	rotate(&stacks->b, "rb\n");
	sorted_insert(stacks, x);
	r_rotate(&stacks->b, "rrb\n");
	push_a(stacks);
}

// Function to sort stack
void	sort_stack(t_stacks *stacks)
{
	if (stacks->a.size)
	{
		push_b(stacks);
		sort_stack(stacks);
		sorted_insert(stacks, stacks->b.value[0]);
	}
}
