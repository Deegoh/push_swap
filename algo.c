/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:55:43 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:29:11 by tpinto-m         ###   ########.fr       */
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
	int	max;

	if (chunck <= 1)
		return ;
	mean = get_mean(s, 'A');
	len = s->size_a / chunck;
	while (s->size_a > len)
	{
		opti_rot(s, data_in_range(s, s->min, mean, 'A'), 'A');
		push_ab(s, 'B');
	}
	while (s->size_b)
	{
		max = find_max(s, 'B');
		opti_rot(s, data_in_range(s, s->range - max, max, 'A'), 'B');
		push_ab(s, 'A');
	}
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

void	custom_sort(t_sck *s, int chunck, int range)
{
	split_by_chunck(s, chunck);
	s->count = 0;
	s->range = 5 + range;
	s->min = s->min - 1;
	s->z = s->min + 1;
	s->btn = 0;
	while (s->size_a > 1)
	{
		while (s->count < s->range && s->size_a)
		{
			opti_rot(s, data_in_range(s, s->min, s->z + s->range, 'A'), 'A');
			push_ab(s, 'B');
			if (s->btn)
				rotate(s, "RB");
			s->count++;
			s->z++;
		}
		s->count = 0;
		s->btn = ft_bool(s->btn);
	}
	while (s->size_b)
	{
		opti_rot(s, find_max(s, 'B'), 'B');
		push_ab(s, 'A');
	}
}
