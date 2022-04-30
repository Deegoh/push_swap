/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:47:55 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/30 19:31:42 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*first_node(t_node *root)
{
	while (root && root->prev)
		root = root->prev;
	return (root);
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

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;
	int		count;

	i = 0;
	res = 0;
	sign = 1;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i++] - '0';
		count++;
	}
	if (count > 19 && sign == 1)
		return (sign * -1);
	if (count > 19 && sign == -1)
		return (0);
	return (res * sign);
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
