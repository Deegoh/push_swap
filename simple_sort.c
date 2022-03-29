/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:14:39 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/03/29 18:04:13 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stacks *stacks)
{
	if (stacks->a.value[0] > stacks->a.value[1])
		swap(&stacks->a, "sa\n");
	check_sort(*stacks);
}

void	sort3(t_stacks *stacks)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = stacks->a.value[0];
	v2 = stacks->a.value[1];
	v3 = stacks->a.value[2];
	if (v1 > v2 && v1 < v3 && v2 < v3)
		swap(&stacks->a, "sa\n");
	else if (v1 > v2 && v1 > v3 && v2 > v3)
	{
		swap(&stacks->a, "sa\n");
		r_rotate(&stacks->a, "rra\n");
	}
	else if (v1 > v2 && v1 > v3 && v2 < v3)
		rotate(&stacks->a, "ra\n");
	else if (v1 < v2 && v1 < v3 && v2 > v3)
	{
		swap(&stacks->a, "sa\n");
		rotate(&stacks->a, "ra\n");
	}
	else if (v1 < v2 && v1 > v3 && v2 > v3)
		r_rotate(&stacks->a, "rra\n");
	check_sort(*stacks);
}
