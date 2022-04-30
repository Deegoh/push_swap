/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:34:05 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/30 19:31:02 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_sck *stacks, char c)
{
	if (c == 'A' && stacks->size_a > 1)
	{
		push(&stacks->a, stacks->a->next->data);
		delete_node(&stacks->a, stacks->a->next->next);
		join_op(stacks, "sa\n");
	}
	if (c == 'B' && stacks->size_b > 1)
	{
		push(&stacks->b, stacks->b->next->data);
		delete_node(&stacks->b, stacks->b->next->next);
		join_op(stacks, "sb\n");
	}
}

void	rotate(t_sck *stacks, char *str)
{
	if (!ft_strncmp(str, "RA", ft_strlen(str)) && stacks->size_a > 1)
	{
		append(&stacks->a, stacks->a->data);
		delete_node(&stacks->a, stacks->a);
		join_op(stacks, "ra\n");
	}
	if (!ft_strncmp(str, "RB", ft_strlen(str)) && stacks->size_b > 1)
	{
		append(&stacks->b, stacks->b->data);
		delete_node(&stacks->b, stacks->b);
		join_op(stacks, "rb\n");
	}
	if (!ft_strncmp(str, "RRA", ft_strlen(str)) && stacks->size_a > 1)
	{
		push(&stacks->a, last_node(stacks->a)->data);
		delete_node(&stacks->a, last_node(stacks->a));
		join_op(stacks, "rra\n");
	}
	if (!ft_strncmp(str, "RRB", ft_strlen(str)) && stacks->size_b > 1)
	{
		push(&stacks->b, last_node(stacks->b)->data);
		delete_node(&stacks->b, last_node(stacks->b));
		join_op(stacks, "rrb\n");
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
		join_op(stacks, "pa\n");
	}
	if (c == 'B' && stacks->size_a > 0)
	{
		push(&stacks->b, stacks->a->data);
		delete_node(&stacks->a, stacks->a);
		stacks->size_a--;
		stacks->size_b++;
		join_op(stacks, "pb\n");
	}
}

void	check_rule(t_sck *stacks, char *str)
{
	if (!ft_strncmp(str, "PA", ft_strlen(str)))
		push_ab(stacks, 'A');
	else if (!ft_strncmp(str, "PB", ft_strlen(str)))
		push_ab(stacks, 'B');
	else if (!ft_strncmp(str, "SA", ft_strlen(str)))
		swap(stacks, 'A');
	else if (!ft_strncmp(str, "SB", ft_strlen(str)))
		swap(stacks, 'B');
	else if (!ft_strncmp(str, "RA", ft_strlen(str)))
		rotate(stacks, "RA");
	else if (!ft_strncmp(str, "RB", ft_strlen(str)))
		rotate(stacks, "RB");
	else if (!ft_strncmp(str, "RRA", ft_strlen(str)))
		rotate(stacks, "RRA");
	else if (!ft_strncmp(str, "RRB", ft_strlen(str)))
		rotate(stacks, "RRB");
}

int	do_rule_nb(t_sck *stacks, char *str, int nb)
{
	int	ret;

	ret = nb;
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		return (0);
	while (nb--)
		check_rule(stacks, str);
	return (ret);
}
