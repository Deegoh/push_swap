/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:54:00 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/27 11:46:37 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	d_swap(t_stacks *stacks)
{
	swap(&stacks->a, "");
	swap(&stacks->b, "ss\n");
}

void	d_rotate(t_stacks *stacks)
{
	rotate(&stacks->a, "");
	rotate(&stacks->b, "rr\n");
}

void	d_r_rotate(t_stacks *stacks)
{
	r_rotate(&stacks->a, "");
	r_rotate(&stacks->b, "rrr");
}
