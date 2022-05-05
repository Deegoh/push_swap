/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:55:43 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/05 18:49:15 by tpinto-m         ###   ########.fr       */
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

// int	in_range_b(t_sck *s, int a, int z, char c)
// {
// 	int	i;
// 	int	j;

// 	i = find_opti_top(s, a, z, c);
// 	j = find_opti_bot(s, a, z, c);
// 	if (i > j)
// 	{
// 		return (count_until_index(s->b, j, 'B')->i);
// 	}
// 	return (count_until_index(s->b, i, 'T')->i);
// }

void	split_by_chunck(t_sck *s, int chunck)
{
	int	len;
	int	max;
	int	mean;
	int	count;

	if (chunck == 2)
	{
		len = get_mean(s, 'A');
		max = len;
		while (max--)
		{
			opti_rot(s, in_range(s, 1, len, 'A'), 'A');
			push_ab(s, 'B');
		}
		// count = 0;
		while (s->size_b)
		{
			push_ab(s, 'A');
			// if (count)
			// 	rotate(s, "RA");
			// count = ft_bool(count);
		}
	}
	else if (chunck == 3)
	{
		len = s->size_a - s->size_a / chunck;
		max = len;
		while (max--)
		{
			opti_rot(s, in_range(s, 0, len, 'A'), 'A');
			push_ab(s, 'B');
		}
		len = s->size_b / (chunck - 1);
		max = s->size_b;
		mean = len;
		count = 0;
		while (len--)
		{
			opti_rot(s, in_range(s, mean, max, 'B'), 'B');
			push_ab(s, 'A');
			if (count++ < len)
				rotate(s, "RA");
		}
		count = 0;
		while (s->size_b)
		{
			push_ab(s, 'A');
			if (count)
				rotate(s, "RA");
			count = ft_bool(count);
		}
	}
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

int	data_in_range(t_sck *stacks, int a, int z, char c)
{
	int		i;
	int		j;

	if (a > z)
		return (0);
	// if (is_between_value())
		// swap_qs(&a, &z);
	// if (a < find_min(stacks, c))
		// return (0);
	// 	a = find_min(stacks, c);
	// if (z >= find_max(stacks, c))
		// return (0);
	// 	z = find_max(stacks, c);
	if (c == 'A')
	{
		i = find_opti_top(stacks, a, z, c);
		j = find_opti_bot(stacks, a, z, c);
		// printf("i[%d] j[%d]\n", i, j);
		stacks->a = first_node(stacks->a);
		if (i == 0)
			return (stacks->a->i);
		if (i <= j)
		{
			if (is_between_value(count_until_index(stacks->a, i, 'T')->i, a, z))
				return (0);
			return (count_until_index(stacks->a, i, 'T')->i);
		}
		// printf("i[%d] j[%d]\n", i, j);
		if (is_between_value(count_until_index(stacks->a, j, 'B')->i, a, z))
				return (0);
		return (count_until_index(stacks->a, j, 'B')->i);
	}
	else
	{
		i = find_opti_top(stacks, a, z, c);
		j = find_opti_bot(stacks, a, z, c);
		stacks->b = first_node(stacks->b);
		if (i == 0)
			return (stacks->b->i);
		if (i <= j)
			return (count_until_index(stacks->b, i, 'T')->i);
		return (count_until_index(stacks->b, j, 'B')->i);
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
	while (s->size_a)
	{
		while (s->count < s->range && s->size_a)
		{
			opti_rot(s, in_range(s, s->min, s->z + s->range, 'A'), 'A');
			push_ab(s, 'B');
			if (s->btn)
				rotate(s, "RB");
			s->count++;
			s->z++;
			if (count_char(s->op, '\n') > 7000 || (count_char(s->op, '\n') > 900 && s->sizemax <= 100))
				return ;
		}
		s->count = 0;
		s->btn = ft_bool(s->btn);
		if (count_char(s->op, '\n') > 7000 || (count_char(s->op, '\n') > 900 && s->sizemax <= 100))
			return ;
	}
	while (s->size_b)
	{
		opti_rot(s, find_max(s, 'B'), 'B');
		push_ab(s, 'A');
		if (count_char(s->op, '\n') > 7000 || (count_char(s->op, '\n') > 900 && s->sizemax <= 100))
			return ;
	}

	// s->btn = 0;
	// while (s->size_a)
	// {
	// 	s->count = 0;
	// 	while (s->count < 10)
	// 	{
	// 		opti_rot(s, find_min(s, 'A'), 'A');
	// 		push_ab(s, 'B');
	// 		// if (s->btn)
	// 		// 	rotate(s, "RB");
	// 		s->count++;
	// 	}
	// 	s->btn = ft_bool(s->btn);
	// }
	// while (s->size_b)
	// {
	// 	opti_rot(s, find_max(s, 'B'), 'B');
	// 	push_ab(s, 'A');
	// }
	(void)range;
}
