/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:34:05 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/25 19:27:39 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_sck *stacks, char c)
{
	if (c == 'A' && stacks->size_a > 1)
	{
		push(&stacks->a, stacks->a->next->data);
		delete_node(&stacks->a, stacks->a->next->next);
	}
	if (c == 'B' && stacks->size_b > 1)
	{
		push(&stacks->b, stacks->b->next->data);
		delete_node(&stacks->b, stacks->b->next->next);
	}
}

void	rotate(t_sck *stacks, char *str)
{
	if (!ft_strncmp(str, "RA", ft_strlen(str)) && stacks->size_a > 1)
	{
		append(&stacks->a, stacks->a->data);
		delete_node(&stacks->a, stacks->a);
	}
	if (!ft_strncmp(str, "RB", ft_strlen(str)) && stacks->size_b > 1)
	{
		append(&stacks->b, stacks->b->data);
		delete_node(&stacks->b, stacks->b);
	}
	if (!ft_strncmp(str, "RRA", ft_strlen(str)) && stacks->size_a > 1)
	{
		push(&stacks->a, last_node(stacks->a)->data);
		delete_node(&stacks->a, last_node(stacks->a));
	}
	if (!ft_strncmp(str, "RRB", ft_strlen(str)) && stacks->size_b > 1)
	{
		push(&stacks->b, last_node(stacks->b)->data);
		delete_node(&stacks->b, last_node(stacks->b));
	}
}

void	push_ab(t_sck *stacks, char c)
{
	if (c == 'A' && stacks->size_b > 0)
	{
		push(&stacks->a, stacks->b->data);
		delete_node(&stacks->b, stacks->b);
		stacks->size_a++;
		stacks->size_b--;
	}
	if (c == 'B' && stacks->size_a > 0)
	{
		push(&stacks->b, stacks->a->data);
		delete_node(&stacks->a, stacks->a);
		stacks->size_a--;
		stacks->size_b++;
	}
}
