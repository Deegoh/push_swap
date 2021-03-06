/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:14:39 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/06 10:30:43 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_sck *stacks)
{
	if (stacks->a->data > stacks->a->next->data)
		swap(stacks, 'A');
}

void	sort3(t_sck *stacks)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = stacks->a->data;
	v2 = stacks->a->next->data;
	v3 = stacks->a->next->next->data;
	if (v1 > v2 && v1 < v3 && v2 < v3)
		swap(stacks, 'A');
	else if (v1 > v2 && v1 > v3 && v2 > v3)
	{
		swap(stacks, 'A');
		rotate(stacks, "RRA");
	}
	else if (v1 > v2 && v1 > v3 && v2 < v3)
		rotate(stacks, "RA");
	else if (v1 < v2 && v1 < v3 && v2 > v3)
	{
		swap(stacks, 'A');
		rotate(stacks, "RA");
	}
	else if (v1 < v2 && v1 > v3 && v2 > v3)
		rotate(stacks, "RRA");
}

void	sort4(t_sck *stacks)
{
	opti_rot(stacks, stacks->min, 'A');
	push_ab(stacks, 'B');
	sort3(stacks);
	push_ab(stacks, 'A');
}

void	sort5(t_sck *stacks)
{
	opti_rot(stacks, find_min(stacks, 'A'), 'A');
	push_ab(stacks, 'B');
	opti_rot(stacks, find_min(stacks, 'A'), 'A');
	push_ab(stacks, 'B');
	sort3(stacks);
	do_rule_nb(stacks, "PA", 2);
}

void	simple_sort(t_sck *stacks)
{
	if (stacks->size_a == 2)
		sort2(stacks);
	else if (stacks->size_a == 3)
		sort3(stacks);
	else if (stacks->size_a == 4)
		sort4(stacks);
	else if (stacks->size_a == 5)
		sort5(stacks);
	join_op(stacks, "");
	ft_remove_str(stacks->op, "pb\npa\n");
}
