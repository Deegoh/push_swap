/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:54:00 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/21 18:04:53 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ss : sa and sb at the same time.
 */
void	d_swap(t_stacks *stacks)
{
	swap(stacks, &stacks->a, "");
	swap(stacks, &stacks->b, "ss\n");
}

/*
rr : ra and rb at the same time.
 */
void	d_rotate(t_stacks *stacks)
{
	rotate(stacks, &stacks->a, "");
	rotate(stacks, &stacks->b, "rr\n");
}

/*
rrr : rra and rrb at the same time.
 */
void	d_r_rotate(t_stacks *stacks)
{
	r_rotate(stacks, &stacks->a, "");
	r_rotate(stacks, &stacks->b, "rrr");
}
