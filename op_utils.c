/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:23:55 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/01 22:25:15 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_op(t_sck *s, char *op)
{
	char	*tmp;

	tmp = s->op;
	if ((!ft_strncmp(op, "ra\n", 3) && !ft_strncmp(s->l_op, "rb\n", 3))
		|| (!ft_strncmp(op, "rb\n", 3) && !ft_strncmp(s->l_op, "ra\n", 3)))
	{
		free(s->l_op);
		s->l_op = ft_strdup("rr\n");
		op = "";
	}
	if ((!ft_strncmp(op, "rra\n", 4) && !ft_strncmp(s->l_op, "rrb\n", 4))
		|| (!ft_strncmp(op, "rrb\n", 4) && !ft_strncmp(s->l_op, "rra\n", 4)))
	{
		free(s->l_op);
		s->l_op = ft_strdup("rrr\n");
		op = "";
	}
	s->op = ft_strjoin(s->op, s->l_op);
	free(s->l_op);
	s->l_op = ft_strdup(op);
	free(tmp);
}

int	opti_rot(t_sck *stacks, int value, char c)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = NULL;
	if (c == 'A')
		tmp = stacks->a;
	else if (c == 'B')
		tmp = stacks->b;
	while (tmp && value != tmp->data)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 0)
		return (0);
	if (c == 'A' && i <= -(i - stacks->size_a))
		return (do_rule_nb(stacks, "RA", i));
	else if (c == 'A' && i > -(i - stacks->size_a))
		return (do_rule_nb(stacks, "RRA", (i - stacks->size_a)));
	else if (c == 'B' && i <= -(i - stacks->size_b))
		return (do_rule_nb(stacks, "RB", i));
	else if (c == 'B' && i > -(i - stacks->size_b))
		return (do_rule_nb(stacks, "RRB", (i - stacks->size_b)));
	return (0);
}

int	find_opti_top(t_sck *stacks, int a, int z, char c)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (c == 'A')
		tmp = stacks->a;
	else
		tmp = stacks->b;
	while (tmp)
	{
		if (is_between_value(tmp->data, a, z))
			break ;
		tmp = tmp->next;
		i++;
	}
	tmp = first_node(tmp);
	return (i);
}

int	find_opti_bot(t_sck *stacks, int a, int z, char c)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (c == 'A')
		tmp = last_node(stacks->a);
	else
		tmp = last_node(stacks->b);
	while (tmp)
	{
		if (is_between_value(tmp->data, a, z))
			break ;
		tmp = tmp->prev;
		i++;
	}
	tmp = first_node(tmp);
	return (i);
}

int	is_between_value(int value, int a, int z)
{
	if (value >= a && value <= z)
		return (1);
	return (0);
}
