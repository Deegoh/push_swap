/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:55:43 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/04 18:22:46 by tpinto-m         ###   ########.fr       */
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

void	split_by_chunck(t_sck *s, int chunck)
{
	int	len;
	int	max;
	int	mean;

	if (chunck == 2)
	{
		len = s->size_a / chunck;
		max = len;
		while (max--)
		{
			// printf("data in r[%d] len[%d]\n", data_in_range(s, 0, len, 'A'), len);
			opti_rot(s, data_in_range(s, 0, len, 'A'), 'A');
			push_ab(s, 'B');
		}
		do_rule_nb(s, "PA", s->size_b);
	}
	else if (chunck == 3)
	{

		len = s->size_a - s->size_a / chunck;
		max = len;
		while (max--)
		{
			opti_rot(s, data_in_range(s, 0, len, 'A'), 'A');
			push_ab(s, 'B');
		}
		len = s->size_b / (chunck - 1);//166
		max = s->size_b;//333
		mean = len;
		while (--len)
		{
			opti_rot(s, data_in_range(s, mean, max, 'B'), 'B');
			push_ab(s, 'A');
		}
		while (s->size_b)
		{
			push_ab(s, 'A');
			rotate(s, "RA");
		}
	}
}

int	data_in_range(t_sck *stacks, int a, int z, char c)
{
	int		i;
	int		j;

	// if (a < find_min(stacks, c))
	// 	a = find_min(stacks, c);
	// if (z > find_max(stacks, c))
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
			return (count_until_index(stacks->a, i, 'T')->i);
		}
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
	// s->range = range;
	// s->btn = 0;
	// while (s->size_a)
	// {
	// 	if (s->count % 10 == 0)
	// 		s->btn = ft_bool(s->btn);
	// 	opti_rot(s, data_in_range(s, find_min(s, 'A'), find_min(s, 'A') + range, 'A'), 'A');
	// 	push_ab(s, 'B');
	// 	if (s->btn)
	// 		rotate(s, "RB");
	// 	s->count++;
	// 	s->z++;
	// 	if (10000 < count_char(s->op, '\n'))
	// 		return ;
	// }
	// s->range = range;
	// s->z = 0;
	// s->btn = 0;
	// while (s->size_a > 1)
	// {
	// 	s->count = 0;
	// 	while (s->count < 10 && s->size_a && s->z + s->range <= s->size_a)
	// 	{
	// 		opti_rot(s, data_in_range(s, s->z * 10, (s->z + range) * 10, 'A'), 'A');
	// 		push_ab(s, 'B');
	// 		if (s->btn)
	// 			rotate(s, "RB");
	// 		s->count++;
	// 		s->z++;
	// 	}
	// 	s->btn = ft_bool(s->btn);
	// }
	// while (s->size_b)
	// {
	// 	opti_rot(s, find_max(s, 'B'), 'B');
	// 	push_ab(s, 'A');
	// 	// if (10000 < count_char(s->op, '\n'))
	// 	// 	return ;
	// }
	// s->count = 0;
	// s->btn = 0;
	// while (s->size_a)
	// {
	// 	while (s->count < 10)
	// 	{
	// 		opti_rot(s, find_max(s, 'A'), 'A');
	// 		push_ab(s, 'B');
	// 		if (s->btn)
	// 			rotate(s, "RB");
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
