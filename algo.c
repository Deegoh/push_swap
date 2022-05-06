/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:55:43 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/06 11:27:46 by tpinto-m         ###   ########.fr       */
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
		value += tmp->i;
		tmp = tmp->next;
		i++;
	}
	return (value / i);
}

int	in_range(t_sck *s, int a, int z, char c)
{
	int		i;
	int		j;
	t_node	*tmp;

	if (c == 'A')
		tmp = s->a;
	else
		tmp = s->b;
	i = find_opti_top(s, a, z, c);
	j = find_opti_bot(s, a, z, c);
	if (i > j)
	{
		return (count_until_index(s->a, j, 'B')->i);
	}
	return (count_until_index(s->a, i, 'T')->i);
}

int	get_index(t_node *root, int index, char c)
{
	t_node	*tmp;

	if (c == 'T')
		tmp = root;
	else
		tmp = last_node(root);
	if (!tmp)
	{
		return (INT_MIN);
	}
	while (tmp && index--)
	{
		if (c == 'T')
			tmp = tmp->next;
		else
			tmp = tmp->prev;
	}
	return (tmp->i);
}

void	custom_sort(t_sck *s, int chunck, int range)
{
	split_by_chunck(s, chunck);
	s->range = 5 + range;
	s->min = s->min - 1;
	s->z = s->min;
	while (s->size_a)
	{
		s->count = -1;
		while (++s->count < s->range && s->size_a)
		{
			opti_rot(s, in_range(s, s->min, ++s->z + s->range, 'A'), 'A');
			push_ab(s, 'B');
			if (s->btn)
				rotate(s, "RB");
			if (is_to_long(s))
				return ;
		}
		s->btn = ft_bool(s->btn);
	}
	while (s->size_b)
	{
		opti_rot(s, find_max(s, 'B'), 'B');
		push_ab(s, 'A');
		if (is_to_long(s))
			return ;
	}
}
