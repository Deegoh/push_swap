/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:55:43 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/29 21:00:45 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mean(t_sck	*stacks, char c)
{
	t_node	*tmp;
	int		value;
	int		i;

	if (c == 'A')
		tmp = stacks->a;
	else
		tmp = stacks->b;
	i = 0;
	value = 0;
	while (tmp)
	{
		value += tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (value / i);
}

void	split_by_chunck(t_sck *s, int chunck)
{
	int	len;
	int	mean;

	if (chunck <= 1)
		chunck = 2;
	mean = get_mean(s, 'A');
	len = s->size_a / chunck;
	while (s->size_a > len)
	{
		opti_rot(s, data_in_range(s, s->min, mean, 'A'), 'A');
		push_ab(s, 'B');
	}
	while (s->size_b)
	{
		push_ab(s, 'A');
	}
}

int	is_between_value(int value, int a, int z)
{
	if (value >= a && value <= z)
		return (1);
	return (0);
}

int	data_in_range(t_sck *stacks, int a, int z, char c)
{
	int		i;
	int		j;

	if (c == 'A')
	{
		i = find_opti_top(stacks, a, z, c);
		j = find_opti_bot(stacks, a, z, c);
		stacks->a = first_node(stacks->a);
		if (i == j)
			return (stacks->a->data);
		if (i < j)
			return (count_until_index(stacks->a, i, 'T')->data);
		return (count_until_index(stacks->a, j, 'B')->data);
	}
	else
	{
		i = find_opti_top(stacks, a, z, c);
		j = find_opti_bot(stacks, a, z, c);
		stacks->b = first_node(stacks->b);
		if (i < j)
			return (count_until_index(stacks->b, i, 'T')->data);
		return (count_until_index(stacks->b, j, 'B')->data);
	}
}
